/* search binary tree
    1.create
    4.insert
    2.print in order
    3.print pre order
 */

#include <stdio.h>
#include <stdlib.h>
#include "26.08.h"

int main() {
    Arvore *arvore = criarArvore();
    char folhas[] = "12 5 18 2 9 15 19 13 17";
    preencherArvore(arvore, folhas);
    printf("In Order: ");
    imprimirEmOrdem(arvore->raiz);
    printf("\nPre Order: ");
    imprimirPreOrdem(arvore->raiz);
    printf("\nPos Order: ");
    imprimirEmPosOrdem(arvore->raiz);
    return 0;
}