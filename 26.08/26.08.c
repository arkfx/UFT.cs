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

    return 0;
}