// Online C compiler to run C program online
#include <stdio.h>
#include <string.h>

char ask[50];

int valorEmEstoque = 0;
int InpFilial = 0;
float rFLOAT = 0;

clear(){ 
    while((getchar()) != '\n');
}

void readFloat(){
    rFLOAT = 0;
    while (rFLOAT == 0){
        printf("%s", ask);
        scanf(" %f", & rFLOAT);
        if(rFLOAT == 0){
            clear();
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
} Filial;
Filial filiais[34];



int main() {
    // Write C code here

    while(InpFilial > 34 && InpFilial < 1){
        strcpy(ask, "Filial (1-34): ");
        readFloat();
        InpFilial = rFLOAT;
    }
    printf("----Filial %d--",InpFilial,"----");
    printf("\n");

    i



}

  