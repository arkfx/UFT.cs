#include <stdio.h>
#include <stdlib.h>
#include "26.08.h"

int main() {
    Arvore *arvore = criarArvore();
    char folhas[] = "5 2 3 4 1 6";
    preencherArvore(arvore, folhas);

    printf("\nPre Order: ");
    imprimirPreOrdem(arvore->raiz);

    printf("\nIn Order: ");
    imprimirEmOrdem(arvore->raiz);

    printf("\nPos Order: ");
    imprimirEmPosOrdem(arvore->raiz);

    printf("\nQual número deseja remover? ");
    int valor;
    scanf("%d", &valor);

    No *no = buscarNo(arvore->raiz, valor);

    if(no != NULL) {
        removerNo(arvore, no);
        printf("\nNúmero removido com sucesso!\n");
    } else {
        printf("\nNúmero não encontrado!\n");
    }

    return 0;
}