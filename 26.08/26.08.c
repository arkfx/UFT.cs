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
    Arvore *raiz = criarArvore();
    char arvore[] = "10 5 15 3 7 12 20";
    preencherArvore(raiz, arvore);
    printf("In Order: ");
    imprimirEmOrdem(raiz);
    printf("\nPre Order: ");
    imprimirPreOrdem(raiz);
    return 0;
}