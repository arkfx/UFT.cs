#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char ask[100];

float rFLOAT = 0;
char answer[100];
char rTipo[100];

void clearIN(){
    rFLOAT = 0;
    strcpy(answer, "");
    strcpy(rTipo, "");
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
    while (strlen(answer) == 0){
        printf("%s", ask);
        scanf(" %s", answer);
        if(strlen(answer) == 0){
            clearOUT();
        }
    }
}

void readTipo(){
    clearIN();
    while (rTipo != 'm' && rTipo != 'l' && rTipo != 'p' && rTipo != 'M' && rTipo != 'L' && rTipo != 'P'){
        printf("%s", ask);
        scanf(" %c", & rTipo);
        if(rTipo != 'm' && rTipo != 'l' && rTipo != 'p' && rTipo != 'M' && rTipo != 'L' && rTipo != 'P'){
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
    int InpFilial;
    while(InpFilial > 34 || InpFilial < 1){
        strcpy(ask, "Filial (1-34): ");
        readFloat();
        InpFilial = rFLOAT;
    }

    
    printf("----Filial:");
    printf("%d", InpFilial);
    printf("----");
    printf("\n");

    printf("deseja adicionar ou modificar um produto? (a/m): ");
    int ReadProd = 1; 
    bool ProdRead = true

    while(ProdRead){

        strcpy(ask, "nome do produto: ");
        readString();
        strcpy(filiais[InpFilial].produtos[ReadProd].nome, answer);

        strcpy(ask, "preço do produto: ");
        readFloat();
        filiais[InpFilial].produtos[ReadProd].preço = rFLOAT;

        strcpy(ask, "quantidade do produto: ");
        readFloat();
        filiais[InpFilial].produtos[ReadProd].quantidade = rFLOAT;

        strcpy(ask, "tipo do produto: ");
        readTipo();
        filiais[InpFilial].produtos[ReadProd].tipo = rTipo;



    }

}