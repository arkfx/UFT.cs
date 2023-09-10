#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char ask[100];


float rFLOAT = 0;

char rSTRING[100];

bool rBOOL = false;
char rCHAR[100];

char rTIPO[100];



void clearIN(){
    rFLOAT = 0;
    strcpy(rSTRING, "");
    strcpy(rCHAR, "");
    rBOOL = false;
    strcpy(rTIPO, "");
}
void clearOUT(){
    while((getchar()) != '\n');
}

void readFloat(){
    clearIN();
    while (rFLOAT <= 0){
        printf("%s", ask);
        scanf(" %f", & rFLOAT);
        if(rFLOAT <= 0){
            clearOUT();
        }
    }
}

void readString(){
    clearIN();
    while (strlen(rSTRING) == 0){
        printf("%s", ask);
        scanf(" %s", & rSTRING);
        if(strlen(rSTRING) == 0){
            clearOUT();
        }
    }
}

void readBool(){
    clearIN();
    while (rCHAR != 's' && rCHAR!= 'n' && rCHAR != 'S' && rCHAR != 'N'){
        printf("%s", ask);
        scanf(" %c", & rCHAR);
        if(rCHAR != 's' && rCHAR != 'n' && rCHAR != 'S' && rCHAR != 'N'){
            clearOUT();
        }
    }
    if(rCHAR == 's' || rCHAR == 'S'){
        rBOOL = true;
    }
    if(rCHAR == 'n' || rCHAR == 'N'){
        rBOOL = false;
    }
}

void readTipo(){
    clearIN();
    while (rTIPO != 'm' && rTIPO != 'l' && rTIPO != 'p' && rTIPO != 'M' && rTIPO != 'L' && rTIPO != 'P'){
        printf("%s", ask);
        scanf(" %c", & rTIPO);
        if(rTIPO != 'm' && rTIPO != 'l' && rTIPO != 'p' && rTIPO != 'M' && rTIPO != 'L' && rTIPO != 'P'){
            clearOUT();
        }
    }
}

typedef struct {
    char nome[100];
    float preço;
    int quantidade;
    char tipo; 
} Produto;

typedef struct {
    Produto produtos[1000];
    int valorEmEstoque;
} Filial;
Filial filiais[34];



int main() {

    printf("----Bem vindo ao sistema de estoque----");
    printf("\n");

    printf("O que deseja fazer?");
    printf("\n");
    printf("1 - Adicionar produto");
    printf("3 - Editar ou remover um produto");
    printf("4 - Listar produtos");
    printf("5 - Listar produtos por filial");



    int InpFilial;
    while(InpFilial > 34 || InpFilial < 1){
        strcpy(ask, "selecione a filial (1-34): ");
        readFloat();
        InpFilial = rFLOAT;
    }

    printf("----Filial:");
    printf("%d", InpFilial);
    printf("----");
    printf("\n");


    return 0;
}

void AddProduto(int filial){
    int ReadProd;
    for(int i = 1; i <= 1000; i++){
        if(filiais[filial].produtos[i].nome == NULL){
            ReadProd = i;
            break;
        }
    } 

    strcpy(ask, "nome do produto: ");
    readString();
    strcpy(filiais[filial].produtos[ReadProd].nome, rSTRING);

    strcpy(ask, "preço do produto: ");
    readFloat();
    filiais[filial].produtos[ReadProd].preço = rFLOAT;

    strcpy(ask, "quantidade do produto: ");
    readFloat();
    filiais[filial].produtos[ReadProd].quantidade = rFLOAT;

    strcpy(ask, "tipo do produto: (m para merceria, l para limpeza, p para pereciveis)");
    readTipo();
    filiais[filial].produtos[ReadProd].tipo = rTIPO;

    strcpy(ask, "deseja adicionar mais um produto? (s/n)");
    readBool();
    if(rBOOL == true){
        AddProduto(filial);
    }
}

void printFilial(int filial){
    printf("----Filial: ");
    printf("%d", filial);
    printf("----");
    printf("\n");
    for(int i = 1; i <= 1000; i++){
        if(filiais[filial].produtos[i].nome != NULL){
            printf("%d", i);
            printf(" - ");
            printf("%s", filiais[filial].produtos[i].nome);
            printf(" - preço: ");
            printf("%f", filiais[filial].produtos[i].preço);
            printf(" - quantidade: ");
            printf("%d", filiais[filial].produtos[i].quantidade);
            printf(" - tipo: ");
            printf("%c", filiais[filial].produtos[i].tipo);
            printf("\n");
        }
    }
}

void printAll(){
    for(int i = 1; i <= 34; i++){
        printFilial(i);
    }
}