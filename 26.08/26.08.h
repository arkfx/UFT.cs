#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura No
typedef struct No {
    int valor;
    struct No *esquerda;
    struct No *direita;
} No;

// Definição da estrutura Raiz
typedef struct Raiz {
    No *raiz;
} Raiz;

// Funções para manipulação da árvore binária
Raiz *criarRaiz();
No *criarNo(int valor);
void inserirNo(No *raiz, int valor);
void imprimirPreOrdem(No *raiz);
void imprimirEmOrdem(No *raiz);
void preencherArvore(Raiz *raiz, char *arvore);
void InserirDados();
void PrintPreOrder();
void PrintInOrder();

#endif // BINARY_TREE_H