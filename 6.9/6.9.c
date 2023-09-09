#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char ask[100];

float rFLOAT = 0;
char rSTRING[100];
char rCHAR[100];
bool rBOOL = false;
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

void readChar(){
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

    int ReadProd = 1; 
    bool ProdRead = true;

    while(ProdRead){

        strcpy(ask, "nome do produto: ");
        readString();
        strcpy(filiais[InpFilial].produtos[ReadProd].nome, rSTRING);

        strcpy(ask, "preço do produto: ");
        readFloat();
        filiais[InpFilial].produtos[ReadProd].preço = rFLOAT;

        strcpy(ask, "quantidade do produto: ");
        readFloat();
        filiais[InpFilial].produtos[ReadProd].quantidade = rFLOAT;

        strcpy(ask, "tipo do produto: (m para merceria, l para limpeza, p para pereciveis)");
        readTipo();
        filiais[InpFilial].produtos[ReadProd].tipo = rTIPO;

        strcpy(ask, "deseja adicionar mais um produto? (s/n)");
        readChar();


    }

}