#start

current_line = 0

def read_line():
    global current_line
    with open('/workspaces/UFT.cs/Cpython/backC/output.txt', 'r') as file:
        for i, line in enumerate(file):
            if i == current_line:
                current_line += 1
                return line.strip()
        return None

def writeToFile(content):
    with open('/workspaces/UFT.cs/Cpython/frontPY/input.txt', 'a') as file:
        file.write(content + '\n')

writeToFile('primeira linha de input')
writeToFile('segunda linha de input')

line = read_line()
print(line)

line = read_line()
print(line)

line = read_line()
print(line)