#include <stdio.h>

typedef struct{
    float idade;
} p;
p pessoas[50];

int main() {
    int somaDaIdade = 0;
    float media = 0;

    int PessoasComIdadeMenorQueAMedia = 0;
    float PorcentagemComIdadeMenorQue18 = 0;
    int IdadeDaPessoaMaisVelha = 0;

    for(int i = 0; i < 50; i++){
        printf("Digite a idade da pessoa %d: ", i + 1);
        scanf("%f", &pessoas[i].idade);
        somaDaIdade += pessoas[i].idade;
        if (pessoas[i].idade > IdadeDaPessoaMaisVelha){
            IdadeDaPessoaMaisVelha = pessoas[i].idade;
        }
        if (pessoas[i].idade < 18){
            PorcentagemComIdadeMenorQue18++;
        }
    }
    media = somaDaIdade / 50;
    PorcentagemComIdadeMenorQue18 = (PorcentagemComIdadeMenorQue18 / 50) * 100;
    for(int i = 0; i < 50; i++){
        if (pessoas[i].idade < media){
            PessoasComIdadeMenorQueAMedia++;
        }
    }

    printf("Media das idades: %.2f\n", media);
    printf("Porcentagem de pessoas com idade menor que 18: %.2f%%\n", PorcentagemComIdadeMenorQue18);
    printf("Idade da pessoa mais velha: %d\n", IdadeDaPessoaMaisVelha);
    printf("Quantidade de pessoas com idade menor que a media: %d\n", PessoasComIdadeMenorQueAMedia);

    return 0;
}