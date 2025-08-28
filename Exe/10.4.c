#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


//printar uma matriz 10x10 em ordem numerica crescente

int matriz[10][10] = {{0}};

// declarar um vetor aleatorio
void matrizAleatoria(int matriz[10][10]){
    int i, j;
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            matriz[i][j] = rand() % 10;
        }
    }
}

int main (){
    matrizAleatoria(matriz);

    int i, j, k, l, m, n, o, p, q, r;
    for(i = 0; i < 3    ; i++){
        for(j = 0; j < 3; j++){
            for(k = 0; k 
        }
        printf("\n");
    }
} 

