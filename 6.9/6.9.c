// Online C compiler to run C program online
#include <stdio.h>
#include <string.h>

int valorEmEstoque = 0;
int InpFilial;
float rFLOAT;

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
    typedef struct {
        float preço;
        char nome[100];
        float quantidade;
        char tipo; 
    } Produto;
    Produto produtos[1000];
} Filial;
Filial filiais[33];


int main() {
    // Write C code here

    while(InpFilial > 34 && InpFilial < 1){
        strcpy(ask, "Filial (1-34): ");
        readFloat();
        InpFilial = rFLOAT;
    }
    printf("----Filial %d--",InpFilial,"----");
    printf("\n");

    int p;
    printf("Produto: ");
    scanf(" %d", &p);

    printf("Preço: ");
    scanf(" %f", &filiais[InpFilial-1].produtos[p].preço);

    printf("Nome: ");
    scanf(" %s", &filiais[InpFilial-1].produtos[p].nome);

    printf("Quantidade: ");
    scanf(" %f", &filiais[InpFilial-1].produtos[p].quantidade); 

    printf("Tipo: ");
    scanf(" %c", &filiais[InpFilial-1].produtos[p].tipo);



}

  