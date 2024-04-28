#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char numStr[] = "1617";
    char subStr[3];

    strncpy(subStr, &numStr[2], 2); // Copia o terceiro e o quarto caracteres
    subStr[2] = '\0'; // Adiciona o caractere nulo no final

    int num = atoi(subStr);

    printf("O número é: %d\n", num);

    return 0;
}