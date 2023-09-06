// Online C compiler to run C program online
#include <stdio.h>
#include <string.h>

int main() {
    // Write C code here
    
    int senha = 1;
    char nome[50];

    printf("nome: ");
    scanf("%s", & nome);
    while(strcmp(nome, "fim")){
        printf("\n");
        printf("%s", nome);
        printf("\n");
        printf("%d", senha);
        printf("\n");
        senha++;
        if(senha >= 50){
            break;
        }
    printf("nome: ");
    scanf("%s", & nome);
    
    }
    printf("\n");
    printf("fim");
    return 0;
   
}