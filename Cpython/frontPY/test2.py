#start

import tkinter as tk

# Create a new window
window = tk.Tk()

# Set the window title
window.title("somaN")

# Create a label widget
label1 = tk.Label(window, text="Numero 1: ")
label1.pack()   

# Create an entry widget
entry1 = tk.Entry(window)
entry1.pack()

# Create another label widget
label2 = tk.Label(window, text="Numero 2: ")
label2.pack()

# Create another entry widget
entry2 = tk.Entry(window)
entry2.pack()

# Start the main event loop
window.mainloop()

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