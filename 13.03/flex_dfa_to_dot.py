#!/usr/bin/env python3
"""Generate a Graphviz DOT graph for a flex-generated DFA.

This script parses the transition tables embedded in a flex-generated `lex.yy.c`
and reconstructs the DFA transition function as executed by `yylex()`.

Usage:
  python3 flex_dfa_to_dot.py lex.yy.c dfa.dot

Then render:
  dot -Tsvg dfa.dot -o dfa.svg
"""

from __future__ import annotations

import re
import sys
from dataclasses import dataclass
from pathlib import Path
from typing import Iterable


@dataclass
class FlexTables:
    accept: list[int]
    base: list[int]
    default: list[int]
    nxt: list[int]
    chk: list[int]
    ec: list[int]
    meta: list[int]
    meta_threshold: int


@dataclass
class FlexProgramInfo:
    start_state: int
    rule_labels: dict[int, str]


def _strip_c_comments(s: str) -> str:
    # Remove /* ... */ and // ... comments.
    s = re.sub(r"/\*.*?\*/", "", s, flags=re.S)
    s = re.sub(r"//.*?$", "", s, flags=re.M)
    return s


def _extract_int_list(source: str, array_name: str) -> list[int]:
    # Matches: <name>[<n>] = { ... } ;
    # (flex may vary the exact type/prefix formatting).
    pattern = re.compile(
        rf"\b{re.escape(array_name)}\s*\[\s*\d+\s*\]\s*=\s*\{{(.*?)\}}\s*;",
        re.S,
    )
    m = pattern.search(source)
    if not m:
        raise ValueError(f"Could not find array '{array_name}' in lex.yy.c")
    body = _strip_c_comments(m.group(1))
    ints = [int(x) for x in re.findall(r"-?\d+", body)]
    if not ints:
        raise ValueError(f"Array '{array_name}' parsed but contained no integers")
    return ints


def _extract_meta_threshold(source: str) -> int:
    # In the transition loop flex emits: if ( yy_current_state >= <N> ) yy_c = yy_meta[yy_c];
    m = re.search(r"yy_current_state\s*>=\s*(\d+)\s*\)\s*yy_c\s*=\s*yy_meta\[yy_c\]", source)
    if not m:
        # Fallback: use accept length if available.
        return -1
    return int(m.group(1))


def _extract_start_state(source: str) -> int:
    # This scanner uses yy_current_state = (yy_start);
    # and initializes yy_start to 1 when it is zero.
    # We'll treat INITIAL as start_state=1.
    m = re.search(r"\(yy_start\)\s*=\s*1\s*;\s*/\*\s*first start state\s*\*/", source)
    if m:
        return 1
    # Fallback: if code uses yy_current_state = (yy_start); assume 1.
    if re.search(r"yy_current_state\s*=\s*\(yy_start\)\s*;", source):
        return 1
    return 1


def _extract_rule_labels(source: str) -> dict[int, str]:
    """Best-effort mapping of rule number -> human label.

    For this generated scanner, yy_accept[state] is directly the rule number
    selected in `switch (yy_act)`.
    """

    labels: dict[int, str] = {}

    # Capture blocks like:
    # case 3:
    # YY_RULE_SETUP
    # #line ...
    # { puts("IGUAL"); }
    # YY_BREAK
    case_re = re.compile(r"^case\s+(\d+)\s*:\s*$", re.M)
    matches = list(case_re.finditer(source))
    for i, m in enumerate(matches):
        rule = int(m.group(1))
        start = m.end()
        end = matches[i + 1].start() if i + 1 < len(matches) else len(source)
        block = source[start:end]

        # Whitespace rule: in our lexer.l it's an empty action with a comment.
        if re.search(r"ignora\s+espa", block, flags=re.I):
            labels[rule] = "WS"
            continue

        put = re.search(r"puts\(\s*\"([^\"]+)\"\s*\)", block)
        if put:
            labels[rule] = put.group(1)
            continue

        # INT(%s) / ID(%s) / CHAR(%s)
        mprintf = re.search(r"printf\(\s*\"([A-Z]+)\(", block)
        if mprintf:
            labels[rule] = mprintf.group(1)
            continue

    return labels


def load_tables(lex_yy_c: Path) -> FlexTables:
    src = lex_yy_c.read_text(encoding="utf-8", errors="replace")

    accept = _extract_int_list(src, "yy_accept")
    base = _extract_int_list(src, "yy_base")
    default = _extract_int_list(src, "yy_def")
    nxt = _extract_int_list(src, "yy_nxt")
    chk = _extract_int_list(src, "yy_chk")
    ec = _extract_int_list(src, "yy_ec")
    meta = _extract_int_list(src, "yy_meta")

    meta_threshold = _extract_meta_threshold(src)
    if meta_threshold < 0:
        meta_threshold = len(accept)

    return FlexTables(
        accept=accept,
        base=base,
        default=default,
        nxt=nxt,
        chk=chk,
        ec=ec,
        meta=meta,
        meta_threshold=meta_threshold,
    )


def load_program_info(lex_yy_c: Path) -> FlexProgramInfo:
    src = lex_yy_c.read_text(encoding="utf-8", errors="replace")
    return FlexProgramInfo(
        start_state=_extract_start_state(src),
        rule_labels=_extract_rule_labels(src),
    )


def dfa_step(t: FlexTables, state: int, ch: int) -> int:
    """One DFA transition as implemented by flex's compressed tables."""

    # In flex-generated scanners, state 0 is a dummy/dead state.
    # It's not used as a normal DFA state for matching; treat it as a sink.
    if state == 0:
        return 0

    yy_c = t.ec[ch]

    while True:
        idx = t.base[state] + yy_c
        if 0 <= idx < len(t.chk) and t.chk[idx] == state:
            return t.nxt[idx]

        next_state = t.default[state]
        if next_state == state:
            # No further fallback possible; sink.
            return 0
        state = next_state
        if state >= t.meta_threshold:
            yy_c = t.meta[yy_c]


def _format_char(c: int) -> str:
    if c == 9:
        return r"\\t"
    if c == 10:
        return r"\\n"
    if c == 13:
        return r"\\r"
    if 32 <= c <= 126 and c not in (34, 92):  # exclude '"' and '\\'
        return chr(c)
    if c == 34:
        return r"\\\""
    if c == 92:
        return r"\\\\"
    return f"\\x{c:02X}"


def _ranges_label(chars: list[int]) -> str:
    if not chars:
        return ""
    chars = sorted(set(chars))
    ranges: list[tuple[int, int]] = []
    start = prev = chars[0]
    for x in chars[1:]:
        if x == prev + 1:
            prev = x
            continue
        ranges.append((start, prev))
        start = prev = x
    ranges.append((start, prev))

    parts: list[str] = []
    for a, b in ranges:
        if a == b:
            parts.append(_format_char(a))
        elif b == a + 1:
            parts.append(_format_char(a))
            parts.append(_format_char(b))
        else:
            parts.append(f"{_format_char(a)}-{_format_char(b)}")
    return ",".join(parts)


def _group_destinations(t: FlexTables, state: int, chars: Iterable[int]) -> dict[int, list[int]]:
    dest_to_chars: dict[int, list[int]] = {}
    for ch in chars:
        dest = dfa_step(t, state, ch)
        dest_to_chars.setdefault(dest, []).append(ch)
    return dest_to_chars


def _reachable_states(t: FlexTables, start_state: int, categories: dict[str, set[int]]) -> set[int]:
    n_states = len(t.accept)
    seen: set[int] = set()
    stack: list[int] = [start_state]
    while stack:
        s = stack.pop()
        if s in seen or not (0 <= s < n_states):
            continue
        seen.add(s)
        for chars in categories.values():
            for dest in _group_destinations(t, s, chars).keys():
                if dest not in seen:
                    stack.append(dest)
    return seen


def build_dot(t: FlexTables, start_state: int = 1, rule_labels: dict[int, str] | None = None) -> str:
    # Flex's accept table length corresponds to the "normal" DFA states.
    n_states = len(t.accept)

    # Build equivalence classes to reduce edge labels.
    max_class = max(t.ec)
    class_to_chars: dict[int, list[int]] = {k: [] for k in range(max_class + 1)}
    for ch in range(len(t.ec)):
        class_to_chars[t.ec[ch]].append(ch)

    lines: list[str] = []
    lines.append("digraph flex_dfa {")
    lines.append("  rankdir=LR;")
    lines.append("  node [shape=circle, fontsize=10];")
    lines.append("  start [shape=point];")
    lines.append(f"  start -> S{start_state};")

    # Accepting states
    for s in range(n_states):
        act = t.accept[s]
        if act != 0:
            label = f"{s} (a={act})"
            if rule_labels and act in rule_labels:
                label = f"{s} ({rule_labels[act]}/{act})"
            lines.append(f"  S{s} [shape=doublecircle, label=\"{label}\"]; ")
        else:
            lines.append(f"  S{s} [label=\"{s}\"]; ")

    # Transitions grouped by destination.
    for s in range(n_states):
        dest_to_chars: dict[int, list[int]] = {}
        for cls, chars in class_to_chars.items():
            if not chars:
                continue
            rep = chars[0]
            dest = dfa_step(t, s, rep)
            dest_to_chars.setdefault(dest, []).extend(chars)

        for dest, chars in sorted(dest_to_chars.items(), key=lambda x: x[0]):
            # Hide NUL (\x00): it's the internal end-of-buffer sentinel in flex.
            chars = [c for c in chars if c != 0]
            label = _ranges_label(chars)
            if not label:
                continue
            # Graphviz labels can get large; keep it somewhat readable.
            if len(label) > 200:
                label = label[:200] + "..."
            lines.append(f"  S{s} -> S{dest} [label=\"{label}\"]; ")

    lines.append("}")
    return "\n".join(lines)


def build_dot_readable(
    t: FlexTables,
    start_state: int,
    rule_labels: dict[int, str] | None = None,
) -> str:
    """A more readable DFA graph focused on common token categories.

    It intentionally restricts edges to a small set of categories so the output
    stays readable for assignments and reports.
    """

    n_states = len(t.accept)

    categories: dict[str, set[int]] = {
        "WS": {9, 10, 13, 32},
        "DIGIT": set(range(ord("0"), ord("9") + 1)),
        "LETTER": set(range(ord("A"), ord("Z") + 1))
        | set(range(ord("a"), ord("z") + 1))
        | {ord("_")},
        "=": {ord("=")},
        "+": {ord("+")},
        "(": {ord("(")},
        ")": {ord(")")},
        ";": {ord(";")},
    }

    reachable = _reachable_states(t, start_state, categories)

    lines: list[str] = []
    lines.append("digraph flex_dfa_readable {")
    lines.append("  rankdir=LR;")
    lines.append("  node [shape=circle, fontsize=10];")
    lines.append("  start [shape=point];")
    lines.append(f"  start -> S{start_state};")

    for s in sorted(reachable):
        act = t.accept[s] if 0 <= s < n_states else 0
        if act != 0:
            label = f"{s} (a={act})"
            if rule_labels and act in rule_labels:
                label = f"{s} ({rule_labels[act]}/{act})"
            lines.append(f"  S{s} [shape=doublecircle, label=\"{label}\"]; ")
        else:
            lines.append(f"  S{s} [label=\"{s}\"]; ")

    # Edges: for each category, potentially split if category chars diverge.
    for s in sorted(reachable):
        for cat, chars in categories.items():
            dest_to_chars = _group_destinations(t, s, chars)
            for dest, subchars in sorted(dest_to_chars.items(), key=lambda x: x[0]):
                if dest not in reachable:
                    continue
                if dest == 0:
                    # Omit sink edges to keep the graph clean.
                    continue
                if len(dest_to_chars) == 1:
                    label = cat
                else:
                    # Rare: split inside category. Keep compact by showing subset.
                    label = f"{cat}:{_ranges_label([c for c in subchars if c != 0])}"
                    if len(label) > 80:
                        label = cat
                lines.append(f"  S{s} -> S{dest} [label=\"{label}\"]; ")

    lines.append("}")
    return "\n".join(lines)


def build_dot_readable_min(
    t: FlexTables,
    start_state: int,
    rule_labels: dict[int, str] | None = None,
) -> str:
    """A very small, token-growth focused DFA view.

    Flex DFAs often contain intermediate transitions used only for backing up
    to the last accepting state. For readability, this view keeps:
    - Edges out of the start state for the main categories/symbols.
    - Edges that *extend the same token* (accept rule stays the same), e.g.
      ID continues on LETTER/DIGIT, INT continues on DIGIT, WS continues on WS.
    - The special IGUAL -> EIGUAL transition on '='.
    """

    n_states = len(t.accept)
    categories: dict[str, set[int]] = {
        "WS": {9, 10, 13, 32},
        "DIGIT": set(range(ord("0"), ord("9") + 1)),
        "LETTER": set(range(ord("A"), ord("Z") + 1))
        | set(range(ord("a"), ord("z") + 1))
        | {ord("_")},
        "=": {ord("=")},
        "+": {ord("+")},
        "(": {ord("(")},
        ")": {ord(")")},
        ";": {ord(";")},
    }

    def keep_edge(src: int, dest: int, cat: str) -> bool:
        if dest == 0:
            return False
        if src == start_state:
            return True
        a_src = t.accept[src] if 0 <= src < n_states else 0
        a_dest = t.accept[dest] if 0 <= dest < n_states else 0
        if a_src == 0 or a_dest == 0:
            return False
        if a_src == a_dest:
            return True
        # Special case: '=' followed by '=' becomes '=='
        if a_src == 3 and a_dest == 2 and cat == "=":
            return True
        return False

    # Reachable under kept edges
    reachable: set[int] = set()
    stack: list[int] = [start_state]
    while stack:
        s = stack.pop()
        if s in reachable or not (0 <= s < n_states):
            continue
        reachable.add(s)
        for cat, chars in categories.items():
            dest_to_chars = _group_destinations(t, s, chars)
            for dest in dest_to_chars.keys():
                if keep_edge(s, dest, cat):
                    stack.append(dest)

    lines: list[str] = []
    lines.append("digraph flex_dfa_readable_min {")
    lines.append("  rankdir=LR;")
    lines.append("  node [shape=circle, fontsize=10];")
    lines.append("  start [shape=point];")
    lines.append(f"  start -> S{start_state};")

    for s in sorted(reachable):
        act = t.accept[s]
        if act != 0:
            label = f"{s} (a={act})"
            if rule_labels and act in rule_labels:
                label = f"{s} ({rule_labels[act]}/{act})"
            lines.append(f"  S{s} [shape=doublecircle, label=\"{label}\"]; ")
        else:
            lines.append(f"  S{s} [label=\"{s}\"]; ")

    for s in sorted(reachable):
        for cat, chars in categories.items():
            dest_to_chars = _group_destinations(t, s, chars)
            for dest, subchars in sorted(dest_to_chars.items(), key=lambda x: x[0]):
                if dest not in reachable:
                    continue
                if not keep_edge(s, dest, cat):
                    continue
                if len(dest_to_chars) == 1:
                    label = cat
                else:
                    label = cat
                    # In case of divergence, keep the label short.
                    if s == start_state:
                        subset = _ranges_label([c for c in subchars if c != 0])
                        if subset and len(subset) <= 30:
                            label = f"{cat}:{subset}"
                lines.append(f"  S{s} -> S{dest} [label=\"{label}\"]; ")

    lines.append("}")
    return "\n".join(lines)


def main(argv: list[str]) -> int:
    if len(argv) not in (3, 4):
        print(
            "Usage: python3 flex_dfa_to_dot.py <lex.yy.c> <out.dot> [--readable|--readable-min]",
            file=sys.stderr,
        )
        return 2

    in_path = Path(argv[1])
    out_path = Path(argv[2])

    mode = argv[3] if len(argv) == 4 else ""

    t = load_tables(in_path)
    info = load_program_info(in_path)
    if mode == "--readable":
        dot = build_dot_readable(t, start_state=info.start_state, rule_labels=info.rule_labels)
    elif mode == "--readable-min":
        dot = build_dot_readable_min(t, start_state=info.start_state, rule_labels=info.rule_labels)
    else:
        dot = build_dot(t, start_state=info.start_state, rule_labels=info.rule_labels)
    out_path.write_text(dot, encoding="utf-8")
    return 0


if __name__ == "__main__":
    raise SystemExit(main(sys.argv))
