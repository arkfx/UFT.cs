%{
#include <stdio.h>
%}

DIGIT   [0-9]
ID      [a-zA-Z_][a-zA-Z0-9_]*

%%

[ \t\r\n]+                ;  /* ignora espaços */

"=="                      { puts("EIGUAL"); }
"="                       { puts("IGUAL"); }
"+"                       { puts("MAIS"); }
"-"                       { puts("MENOS"); }
"*"                       { puts("MUL"); }
"/"                       { puts("DIV"); }
"("                       { puts("PARENESQ"); }
")"                       { puts("PARENDIR"); }
";"                       { puts("PONTOEV"); puts(""); }

{DIGIT}+                  { printf("INT(%s)\n", yytext); }
{ID}                      { printf("ID(%s)\n", yytext); }

.                         { printf("CHAR(%s)\n", yytext); }

%%

int main(void) {
    yylex();
    return 0;
}