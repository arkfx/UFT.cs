#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ncurses.h>


typedef struct {
    bool Aplicada;
}   VacinaDia;

typedef struct {
    VacinaDia Dias[21];
}   Mes;
Mes Meses[5];

typedef struct {
    Mes Meses[5];
}   PostoDeSaude;
PostoDeSaude Postos[6];

int main(){
    bool continuar = true;
    int mes;
    int posto;
    RepeatAll:
    printf("digite o posto de saúde: ");
    scanf("%d", &posto);
    Repeat:
    printf("\n");
    printf("Digite o mês: ");
    scanf("%d", &mes);
    for (int i = 1; i <= 20; i++){
        printf("\n");
        printf("Digite 1 se a vacina foi aplicada no dia %d ou 0 se não foi: ", i);
        scanf("%d", &Postos[posto].Meses[mes].Dias[i].Aplicada);
    }

    printf("\n");
    printf("deseja ler mais algum mes ? 1 para sim e 0 para não: ");
    scanf("%d", &continuar);
    if (continuar == 1){
        goto Repeat;
    }
    printf("deseja ler mais algum posto de saúde ? 1 para sim e 0 para não: ");
    scanf("%d", &continuar);
    if (continuar == 1){
        goto RepeatAll;
    }



    PrintAll:
    printf("\n");
    printf("\n");
    printf("Qual posto de saúde deseja printar ? ");

    scanf("%d", &posto);
    printf("\n");
    printf("\n");


    
    printf("\033[34m\033[6m\033[1m%-20s%d\033[0m\n", "Posto de Saúde ", posto);
    printf("\033[6m\033[1m%-10s%-15s%s\033[0m\n", "Mês", "Dia", "Vacinação");
    for (int i = 1; i <= 4; i++){
        if (i != 1){
            printf("\n");
        }
        printf("\033[1m%-10d\033[0m", i);
        for (int j = 1; j <= 20; j++){
            if (j != 1){
                printf("%-10s", " ");
            }
            printf("%-15d", j);
            if (Postos[posto].Meses[i].Dias[j].Aplicada == true){
                printf("\033[32m%s\033[0m\n", "Aplicada");
            }
            else{
            printf("\033[31m%s\033[0m\n", "Não aplicada");
            }
        }
    }
    printf("deseja printar outro posto de saúde ? 1 para sim e 0 para não: ");
    scanf("%d", &continuar);
    if (continuar == 1){
        goto PrintAll;
    }

}