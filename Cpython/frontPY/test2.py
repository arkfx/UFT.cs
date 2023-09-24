
# Agora, quando você abrir o arquivo, o caminho será relativo a "/caminho/do/seu/projeto"
with open("/workspaces/UFT.cs/Cpython/output.txt", "r") as file:
    contents = file.read().strip()
    print(contents)
