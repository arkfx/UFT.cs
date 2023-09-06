// Online C compiler to run C program online
#include <stdio.h>
#include <string.h>

int InpFilial;

clear(){ 
    while((getchar()) != '\n');
}

int valorEmEstoque = 0;

void Filial1(){
    int mercearia;
    int limpeza;
    int pereciveis;
}

int main() {
    // Write C code here

    while(InpFilial > 34 || InpFilial < 1){
        printf("Filial (1-34): ");
        scanf(" %d", & InpFilial);
        clear();
    }

    if (InpFilial == 1) {
        Filial1();
    }
        
}

