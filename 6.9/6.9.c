// Online C compiler to run C program online
#include <stdio.h>

int main() {
    // Write C code here
    
    int senha = 1;
    char nome[50];

    printf("nome: ");
    scanf("%s", & nome);
     while(strcmp(nome, "fim")){
        printf("%s", nome);
        printf("%d", senha);
        senha++;
        if(senha >= 50){
            break;
        }
    printf("nome: ");
    scanf("%s", & nome);
    
    }
    return 0;
    printf("fim");
}