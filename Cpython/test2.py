# Abre o arquivo 'output.txt' gerado pelo programa em C
with open('output.txt', 'r') as arquivo:
    valor = arquivo.read()

# Imprime o valor lido do arquivo
print("O valor lido do arquivo é:", valor)
