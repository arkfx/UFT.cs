#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char ask[1000];


float rFLOAT = 0;

char rSTRING[100];

bool rBOOL = false;
char rCHAR;

char rTIPO;



void clearIN(){
    rFLOAT = 0;
    strcpy(rSTRING, "");
    rCHAR = '\0';
    rBOOL = false;
    rTIPO = '\0';
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
    float preco;
    int quantidade;
    char tipo; 
} Produto;

typedef struct {
    Produto produtos[1000];
    int valorEmEstoque;
} Filial;
Filial filiais[35];



int main() {
    start:
    printf("----Bem vindo ao sistema de estoque----");
    printf("\n");
    int action = 0;
    
    while(action > 4 || action < 1){
        strcpy(ask, "1 - Adicionar produtos\n2 - Editar produtos\n3 - Remover produtos\n4 - Listar produtos\nO que deseja fazer? (1-4): ");
        readFloat();
        action = rFLOAT;
    }
    if(action == 4){
        strcpy(ask, "deseja listar os produtos de todas as filiais? (s/n): ");
        readBool();
        if(rBOOL == true){
            printAll();
            goto start;
        }
    }

    int InpFilial = 0;
    while(InpFilial > 34 || InpFilial < 1){
        strcpy(ask, "selecione a filial (1-34): ");
        readFloat();
        InpFilial = rFLOAT;
    }
    
    if(action == 1){
        AddProduto(InpFilial);
        printf("\n");
        goto start;
    }
    if(action == 2){
        EditProduto(InpFilial);
        printf("\n");
        goto start;
    }
    if(action == 3){
        RemoverProduto(InpFilial);
        printf("\n");
        goto start;
    }
    if(action == 4){
        printFilial(InpFilial);
        printf("\n");
        goto start;
    }


    return 0;
}

void AddProduto(int filial){
    printf("\n");
    printf("----Filial: ");
    printf("%d", filial);
    printf("----");
    printf("\n");
    int ReadProd;
    AddProduto:
    printf("\n");
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
    filiais[filial].produtos[ReadProd].preco = rFLOAT;

    strcpy(ask, "quantidade do produto: ");
    readFloat();
    filiais[filial].produtos[ReadProd].quantidade = rFLOAT;

    strcpy(ask, "tipo do produto: (m para merceria, l para limpeza, p para pereciveis): ");
    readTipo();
    filiais[filial].produtos[ReadProd].tipo = rTIPO;

    strcpy(ask, "deseja adicionar mais um produto nessa filial ? (s/n): ");
    readBool();
    if(rBOOL == true){
        goto AddProduto;
    }
}

void EditProduto(int filial){
    printFilial(filial);
    printf("\n");

    strcpy(ask, "Selecione pelo numero o produto da lista que deseja editar: ");
    readFloat();
    int ReadProd = rFLOAT;
    printf("\n");

    strcpy(ask, "nome do produto: ");
    readString();
    strcpy(filiais[filial].produtos[ReadProd].nome, rSTRING);

    strcpy(ask, "preço do produto: ");
    readFloat();
    filiais[filial].produtos[ReadProd].preco = rFLOAT;

    strcpy(ask, "quantidade do produto: ");
    readFloat();
    filiais[filial].produtos[ReadProd].quantidade = rFLOAT;

    strcpy(ask, "tipo do produto: (m para merceria, l para limpeza, p para pereciveis): ");
    readTipo();
    filiais[filial].produtos[ReadProd].tipo = rTIPO;

    printf("\n");
    strcpy(ask, "deseja editar mais um produto dessa filial ? (s/n): ");
    readBool();
    if(rBOOL == true){
        EditProduto(filial);
    }
}

void RemoverProduto(int filial){
    printFilial(filial);
    strcpy(ask, "selecione pelo numero o produto da lista que deseja remover: ");
    readFloat();
    int ReadProd = rFLOAT;

    strcpy(filiais[filial].produtos[ReadProd].nome, "");
    filiais[filial].produtos[ReadProd].preco = 0;
    filiais[filial].produtos[ReadProd].quantidade = 0;
    filiais[filial].produtos[ReadProd].tipo = '\0';

    strcpy(ask, "deseja remover mais um produto dessa filial ? (s/n): ");
    readBool();
    if(rBOOL == true){
        RemoverProduto(filial);
    }
}


void printFilial(int filial){
    printf("\n");
    printf("----Filial: ");
    printf("%d", filial);
    printf("----");
    printf("\n");
    float valorTotal = 0;
    for(int i = 1; i <= 1000; i++){
        if(filiais[filial].produtos[i].nome[0] != '\0'){
            printf("%d", i);
            printf(" - nome: ");
            printf("%s", filiais[filial].produtos[i].nome);

            printf("  - preço: ");
            printf("%f", filiais[filial].produtos[i].preco);

            printf("  - quantidade: ");
            printf("%d", filiais[filial].produtos[i].quantidade);
            valorTotal += filiais[filial].produtos[i].preco * filiais[filial].produtos[i].quantidade;

            printf("  - tipo: ");
            printf("%c", filiais[filial].produtos[i].tipo);
            printf("\n");
        }
    }
    printf("Valor total R$: ");
    printf("%2.f", valorTotal);
    printf("\n");
}

void printAll(){
    for(int i = 1; i <= 34; i++){
        printFilial(i);
    }
    printf("\n");
    
}