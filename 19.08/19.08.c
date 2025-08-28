#include <stdio.h>
#include <stdlib.h>

/* 
Uma das formas de representação de árvores é usando parênteses. 
Seu trabalho aqui é fazer um programa que leia uma árvore binária formatada em parênteses.
Assuma que o formato parentesado fornecido está correto (não precisa checar por erros na entrada).
Após a leitura da árvore, imprima-a usando o caminho pré-ordem e em ordem simétrica.
A entrada é formada por uma linha de no máximo 4096 caracteres,
representando uma árvore binária formatada em parênteses.
Veja os exemplos a seguir. Assuma que os rótulos das árvores a serem lidas são números inteiros. 
*/

/*
Exemplo de entrada 1
(7(5()(6))(10()(12)))
Exemplo de saída 1
PREORDER: 7, 5, 6, 10, 12,
INORDER: 5, 6, 7, 10, 12 
*/

/* 
Exemplo de entrada 2
(12(5()(6))(10()(1)))
Exemplo de saída 2
PREORDER: 12, 5, 6, 10, 1, 
INORDER: 5, 6, 12, 10, 1,
*/

typedef struct No {
    int valor;
    struct No *esquerda;
    struct No *direita;
} No;
typedef struct No No;

typedef struct Raiz {
    No *raiz;
} Raiz;
typedef struct Raiz Raiz;


Raiz *criarRaiz() {
    Raiz *raiz = (Raiz *) malloc(sizeof(Raiz));
    raiz->raiz = NULL;
    return raiz;
}

No *criarNo(int valor) {
    No *no = (No *) malloc(sizeof(No));
    no->valor = valor;
    no->esquerda = NULL;
    no->direita = NULL;
    return no;
}

void inserirNo(No *raiz, int valor) {
    if (raiz == NULL) {
        raiz = criarNo(valor);
    } else {
        if (valor < raiz->valor) {
            if (raiz->esquerda == NULL) {
                raiz->esquerda = criarNo(valor);
            } else {
                inserirNo(raiz->esquerda, valor);
            }
        } else {
            if (raiz->direita == NULL) {
                raiz->direita = criarNo(valor);
            } else {
                inserirNo(raiz->direita, valor);
            }
        }
    }
}

void imprimirPreOrdem(No *raiz) {
    if (raiz != NULL) {
        printf("%d, ", raiz->valor);
        imprimirPreOrdem(raiz->esquerda);
        imprimirPreOrdem(raiz->direita);
    }
}

void imprimirEmOrdem(No *raiz) {
    if (raiz != NULL) {
        imprimirEmOrdem(raiz->esquerda);
        printf("%d, ", raiz->valor);
        imprimirEmOrdem(raiz->direita);
    }
}

void preencherArvore(Raiz *raiz, char *arvore) {
    int i = 0;
    while (arvore[i] != '\0') {
        if (arvore[i] == '(') {
            i++;
            if (arvore[i] != ')') {
                int valor = arvore[i] - '0';
                inserirNo(raiz->raiz, valor);
            }
        }
        i++;
    }
}

int main() {
    int opcao = 0;
    do{
        int opcao = 0;
        printf("1 - Inserir dados\n");
        printf("2 - Imprimir PreOrder\n");
        printf("3 - Imprimir InOrder\n");
        scanf("%d", &opcao);
        switch (opcao) {
        case 1:
            InserirDados();
            break;
        
        case 2:
            PrintPreOrder();
            break;
        case 3: 
            PrintInOrder();
            break;
        }
    } while(opcao < 1 || opcao > 3);


    return 0;
}

void InserirDados(){
    char arvore[4096];
    printf("Digite a árvore binária formatada em parênteses: ");
    scanf("%s", arvore);
    preencherArvore(criarRaiz(), arvore);
}

void PrintPreOrder(){
    printf("PREORDER: ");
    imprimirPreOrdem(criarRaiz()->raiz);
    printf("\n");
}

void PrintInOrder(){
    printf("INORDER: ");
    imprimirEmOrdem(criarRaiz()->raiz);
    printf("\n");
}

