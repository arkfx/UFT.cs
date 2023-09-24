#include <stdio.h>

int main() {
    char input[100]; // Declara um array de caracteres para armazenar a entrada do usuário

    printf("Digite um valor: ");
    scanf("%s", input); // Lê a entrada do usuário e armazena em 'input'

    // Imprime a entrada em um arquivo (output.txt)
    FILE *arquivo;
    arquivo = fopen("output.txt", "w");
    fprintf(arquivo, "%s", input);
    fclose(arquivo);

    return 0;
}
