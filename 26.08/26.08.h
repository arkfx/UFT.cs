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

#endif // BINARY_TREE_H