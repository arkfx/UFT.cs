#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura No
typedef struct No {
    int valor;
    struct No *esquerda;
    struct No *direita;
    struct No *pai;
} No;

// Definição da estrutura Arvore
typedef struct Arvore {
    No *raiz; //raiz da árvore
} Arvore;


// Funções para manipulação da árvore binária

Arvore *criarArvore();
No *criarNo(int valor, No *pai);
void inserirNo(Arvore *raiz, int valor);
void imprimirPreOrdem(No *no);
void imprimirEmOrdem(No *no);
void preencherArvore(Arvore *raiz, char *arvore); //CHAR SEPARADO POR ESPAÇO


//Implementação das funções

Arvore *criarArvore() {
    Arvore *arvore = (Arvore *) malloc(sizeof(Arvore));
    arvore->raiz = NULL;
    return arvore;
}

No *criarNo(int valor, No *pai) {
    No *no = (No *) malloc(sizeof(No));
    no->valor = valor;
    no->esquerda = NULL;
    no->direita = NULL;
    no->pai = pai;
    return no;
}

void inserirNo(Arvore *arvore, int valor) {
    if (arvore->raiz == NULL) {
        arvore->raiz = criarNo(valor, NULL);
    } else {
        No *atual = arvore->raiz;
        No *pai = NULL;
        while (atual != NULL) {
            pai = atual;
            if (valor < atual->valor) {
                atual = atual->esquerda;
            } else {
                atual = atual->direita;
            }
        }
        if (valor < pai->valor) {
            pai->esquerda = criarNo(valor, pai);
        } else {
            pai->direita = criarNo(valor, pai);
        }
    }
}

void imprimirPreOrdem(No *no) {
    if (no != NULL) {
        printf("%d, ", no->valor);
        imprimirPreOrdem(no->esquerda);
        imprimirPreOrdem(no->direita);
    }
}

void imprimirEmOrdem(No *no) {
    if (no != NULL) {
        imprimirEmOrdem(no->esquerda);
        printf("%d, ", no->valor);
        imprimirEmOrdem(no->direita);
    }
}

void imprimirEmPosOrdem(No *no) {
    if(no != NULL) {
        imprimirEmPosOrdem(no->esquerda);
        imprimirEmPosOrdem(no->direita);
        printf("%d, ", no->valor);
    }
}

void preencherArvore(Arvore *arvore, char *folhas) {
    char *token = strtok(folhas, " ");
    while (token != NULL) {
        inserirNo(arvore, atoi(token));
        token = strtok(NULL, " ");
    }
}

void transplantar(Arvore *arvore, No *u, No *v) {
    if(u->pai == NULL) {
        arvore->raiz = v;
    } else if(u == u->pai->esquerda) {
        u->pai->esquerda = v;
    } else {
        u->pai->direita = v;
    }
    if(v != NULL) {
        v->pai = u->pai;
    }
}

No* minimo(Arvore *arvore, No *no) {
    while(no->esquerda != NULL) {
        no = no->esquerda;
    }
    return no;
}

No* buscarNo(No *no, int valor) {
    if(no == NULL || no->valor == valor) {
        return no;
    }
    if(valor < no->valor) {
        return buscarNo(no->esquerda, valor);
    } else {
        return buscarNo(no->direita, valor);
    }
}

void removerNo(Arvore *arvore, No *no) {
    if(no->esquerda == NULL) {
        transplantar(arvore, no, no->direita);
    } else if(no->direita == NULL) {
        transplantar(arvore, no, no->esquerda);
    } else {
        No *y = minimo(arvore, no->direita);
        if(y->pai != no) {
            transplantar(arvore, y, y->direita);
            y->direita = no->direita;
            y->direita->pai = y;
        }
        transplantar(arvore, no, y);
        y->esquerda = no->esquerda;
        y->esquerda->pai = y;
    }
    free(no);
}


#endif // BINARY_TREE_H