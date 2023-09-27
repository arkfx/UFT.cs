#include <stdio.h>

int main() {
    float matriz[3][3];

    //leitura da matriz
    printf("entre os valores para a matriz 3x3\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Linha '%d' e Coluna '%d': ", i+1, j+1);
            scanf("%f", &matriz[i][j]);
        }
    }

    //print da matriz
    printf("a matriz é\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%.2f ", matriz[i][j]);
        }
        printf("\n");
    }

    float x = 0;
    printf("entre com um valor para procurar na matriz: ");
    scanf("%f", &x);

    //procure por x na matriz
    int enc = 0;
    printf("procurando por %.2f na matriz\n", x);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (matriz[i][j] == x) {
                printf("encontrado na posição [%d][%d]\n", i+1, j+1);
                goto encontrado;
            }
        }
    }
    printf("valor não encontrado\n");
    goto fim;

    encontrado:
    printf("valor encontrado\n");



    fim:
    return 0;












































}
