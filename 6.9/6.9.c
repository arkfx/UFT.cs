// Online C compiler to run C program online
#include <stdio.h>
#include <string.h>

int InpFilial;

clear(){ 
    while((getchar()) != '\n');
}

int valorEmEstoque = 0;

typedef struct {
    int mercearia;
    int limpeza;
    int pereciveis;
} Filial;
Filial filiais[34];


int main() {
    // Write C code here

    while(InpFilial > 34 || InpFilial < 1){
        printf("Filial (1-34): ");
        scanf(" %d", & InpFilial);
        clear();
    }

    if (InpFilial >= 1 && InpFilial <= 34) {
        filiais[InpFilial - 1].mercearia = 10;
}

  
}