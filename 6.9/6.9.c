// Online C compiler to run C program online
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char ask[50];

float rFLOAT = 0;
char answer[50];

int InpFilial = 0;

void clearIN(){
    rFLOAT = 0;
    strcpy(answer, "");
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

typedef struct {
    float preço;
    char nome[100];
    float quantidade;
    char tipo; 
} Produto;

typedef struct {
    Produto produtos[1000];
    int valorEmEstoque;
} Filial;
Filial filiais[34];



int main() {
    // Write C code here

    while(InpFilial > 34 && InpFilial < 1){
        strcpy(ask, "Filial (1-34): ");
        readFloat();
        InpFilial = rFLOAT;
    }
    int intF = InpFilial;
    printf("----Filial:");
    printf("%d", intF);
    printf("\n");

    int ReadProd = 0;
    bool ProdRead = true;
    while(ProdRead){
        strcpy(ask, "nome do produto: ");
        readString();
        strcpy(filiais[intF].produtos[ReadProd].nome, answer);
        strcpy(ask, "preço do produto: ");



    strcpy(ask, "Nome do produto: ");
    readString();
    strcpy(filiais[intF].produtos[0].nome, answer); 


    



}

  