"""
This module reads a file called output.txt and prints its contents to the console.
"""

with open('output.txt', 'r', encoding='utf-8') as file:
    contents = file.read()
    print(contents)
