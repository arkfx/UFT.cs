"""
This module reads the contents of a file named 'output.txt' and prints it to the console.
"""

#start

with open("/workspaces/UFT.cs/Cpython/backC/output.txt", "r", encoding="utf-8") as file:
    contents = file.read().strip()
    print(contents)
