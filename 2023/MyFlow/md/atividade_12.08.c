#include <stdio.h>
#include <string.h>
#include <strings.h>

/* 8.Crie um programa que armazene o conjunto de todas as idades possíveis para um ser humano em um vetor. 
 Ao receber um número, o programa informa se este número é uma idade válida para um ser humano típico.

9.Crie um programa que armazene o conjunto dos top cinco jogadores de futebol da atualidade. 
 Ao receber o nome de uma jogador, informar se este pertence ao conjunto top cinco. */

int main(){
    int programa;

    printf("Digite o número do programa que deseja executar: ");
    scanf("%d", &programa);
    printf("\n");

    while (programa != 0){
        switch (programa){
            case 1:
                programa1();
                break;
            case 2:
                programa2();
                break;
            default:
                printf("Programa não encontrado\n");
                break;
        }

        printf("Digite o número do programa que deseja executar: ");
        scanf("%d", &programa);
        printf("\n");

    }
    return 0;
}

void programa1(){
    int idades[130];
    for (int i = 0; i < 120; i++){
        idades[i] = i;
    }
    int idade;

    printf("Digite uma idade: ");
    scanf("%d", &idade);
    printf("\n");

    if (idade > 0 && idade <= 110){
        printf("Idade válida para um ser humano típico\n");
    } else {
        printf("Idade inválida para um ser humano típico\n");
    }

    return;
}

void programa2(){
    char jogadores[5][50] = {"Messi", "Cristiano Ronaldo", "Neymar", "Mbappé", "Haaland"};
    char jogador[50];

    printf("Digite o nome de um jogador: ");
    scanf("%s", jogador);
    printf("\n");

    for (int i = 0; i < 5; i++){
        if (strcasecmp(jogador, jogadores[i]) == 0){
            printf("O jogador %s pertence ao top 5\n", jogador);
            return;
        } 
    }
    printf("O jogador %s não pertence ao top 5\n", jogador);
    return;

}