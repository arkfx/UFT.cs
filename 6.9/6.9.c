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
    int action;
    printf("----Bem vindo ao sistema de estoque----");
    start:
    printf("\n");
    printf("O que deseja fazer?");
    printf("\n");
    
    while(action > 4 || action < 1){
        strcpy(ask, "1 - Adicionar produtos\n2 - Editar produtos\n3 - Remover produtos\n4 - Listar produtos\n");
        readFloat();
        action = rFLOAT;
    }
    if(action == 4){
        strcpy(ask, "deseja listar os produtos de todas as filiais? (s/n)");
        readBool();
        if(rBOOL == true){
            printAll();
            goto start;
        }
    }

    int InpFilial;
    while(InpFilial > 34 || InpFilial < 1){
        strcpy(ask, "selecione a filial (1-34): ");
        readFloat();
        InpFilial = rFLOAT;
    }
    
    if(action == 1){
        AddProduto(InpFilial);
        goto start;
    }
    if(action == 2){
        EditProduto(InpFilial);
        goto start;
    }
    if(action == 3){
        RemoverProduto(InpFilial);
        goto start;
    }
    if(action == 4){
        printFilial(InpFilial);
        goto start;
    }


    return 0;
}

void AddProduto(int filial){
    printf("----Filial:");
    printf("%d", filial);
    printf("----");
    printf("\n");
    AddProduto:
    int ReadProd;
    for(int i = 1; i <= 1000; i++){
        if(filiais[filial].produtos[i].nome[0] == '\0'){
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

    strcpy(ask, "deseja adicionar mais um produto nessa filial ? (s/n)");
    readBool();
    if(rBOOL == true){
        goto AddProduto;
    }
}

void EditProduto(int filial){
    printFilial(filial);
    printf("selecione pelo numero o produto da lista que deseja editar: ");
    readFloat();
    int ReadProd = rFLOAT;

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

    strcpy(ask, "deseja editar mais um produto dessa filial ? (s/n)");
    readBool();
    if(rBOOL == true){
        EditProduto(filial);
    }
}

void RemoverProduto(int filial){
    printFilial(filial);
    printf("selecione pelo numero o produto da lista que deseja remover: ");
    readFloat();
    int ReadProd = rFLOAT;

    strcpy(filiais[filial].produtos[ReadProd].nome, "");
    filiais[filial].produtos[ReadProd].preço = 0;
    filiais[filial].produtos[ReadProd].quantidade = 0;
    strcpy(filiais[filial].produtos[ReadProd].tipo, "");

    strcpy(ask, "deseja remover mais um produto dessa filial ? (s/n)");
    readBool();
    if(rBOOL == true){
        RemoverProduto(filial);
    }
}


void printFilial(int filial){
    printf("----Filial: ");
    printf("%d", filial);
    printf("----");
    printf("\n");
    int valorTotal;
    for(int i = 1; i <= 1000; i++){
        if(filiais[filial].produtos[i].nome[0] != '\0'){
            printf("%d", i);
            printf(" - ");
            printf("%s", filiais[filial].produtos[i].nome);
            printf(" - preço: ");
            printf("%f", filiais[filial].produtos[i].preço);
            valorTotal += filiais[filial].produtos[i].preço;
            printf(" - quantidade: ");
            printf("%d", filiais[filial].produtos[i].quantidade);
            printf(" - tipo: ");
            printf("%c", filiais[filial].produtos[i].tipo);
            printf("\n");
        }
        printf("valor total em estoque R$: ");
        printf("%d", valorTotal);
    }
    
}

void printAll(){
    for(int i = 1; i <= 34; i++){
        printFilial(i);
    }
}