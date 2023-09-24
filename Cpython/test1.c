#include <stdio.h>
#include <stdlib.h>

int main() {
    char input[100]; // Declara um array de caracteres para armazenar a entrada do usuário

    printf("Digite um valor: ");
    scanf("%s", input); // Lê a entrada do usuário e armazena em 'input'

    // Imprime a entrada no arquivo 'output.txt' na mesma pasta do programa em C
    FILE *arquivo;
    arquivo = fopen("output.txt", "w");
    fprintf(arquivo, "%s", input);
    fclose(arquivo);

    return 0;
}
