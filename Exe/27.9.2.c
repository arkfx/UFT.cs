//incluir bibliotecas
#include <stdio.h>

//int main
int x = 2;
int main() {
    //declarar vetores e matrizes
    int V[100];
    int M[100][100];

    for (int i = 0; i<=5; i++)
        V[i] = i + x; // V = {2, 3, 4, 5, 6, 7}
    for (int i = 0; i<=3; i++){
        for (int j = 0; j<=5; j++){
            M[i][j] = V[j] + i; 
        }   
    }

    printf("%d %d %d", V[x], M[0][0], M[1][4]);
}