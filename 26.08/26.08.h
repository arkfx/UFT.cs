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
void imprimirPreOrdem(Arvore *raiz);
void imprimirEmOrdem(Arvore *raiz);
void preencherArvore(Arvore *raiz, char *arvore); //CHAR SEPARADO POR ESPAÇO


//Implementação das funções

Arvore *criarArvore() {
    Arvore *raiz = (Arvore *) malloc(sizeof(Arvore));
    raiz->raiz = NULL;
    return raiz;
}

No *criarNo(int valor, No *pai) {
    No *no = (No *) malloc(sizeof(No));
    no->valor = valor;
    no->esquerda = NULL;
    no->direita = NULL;
    no->pai = pai;
    return no;
}

void inserirNo(Arvore *raiz, int valor) {
    if (raiz->raiz == NULL) {
        raiz->raiz = criarNo(valor, NULL);
    } else {
        No *atual = raiz->raiz;
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

void imprimirPreOrdem(Arvore *raiz) {
    if (raiz->raiz != NULL) {
        printf("%d, ", raiz->raiz->valor);
        imprimirPreOrdem(raiz->raiz->esquerda);
        imprimirPreOrdem(raiz->raiz->direita);
    }
}

void imprimirEmOrdem(Arvore *raiz) {
    if (raiz->raiz != NULL) {
        imprimirEmOrdem(raiz->raiz->esquerda);
        printf("%d, ", raiz->raiz->valor);
        imprimirEmOrdem(raiz->raiz->direita);
    }
}

void preencherArvore(Arvore *raiz, char *arvore) {
    char *token = strtok(arvore, " ");
    while (token != NULL) {
        inserirNo(raiz, atoi(token));
        token = strtok(NULL, " ");
    }
}

#endif // BINARY_TREE_H