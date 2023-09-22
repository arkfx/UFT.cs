#include <stdio.h>
#define N 2

typedef struct{
    float idade;
} p;
p pessoas[N];

int main() {
    float somaDaIdade = 0;
    float media = 0;

    int PessoasComIdadeMenorQueAMedia = 0;
    float PorcentagemComIdadeMenorQue18 = 0;
    float IdadeDaPessoaMaisVelha = 0;

    for(int i = 1; i <= N; i++){
        printf("Digite a idade da pessoa %d: ", i);
        scanf("%f", &pessoas[i].idade);
        somaDaIdade += pessoas[i].idade;
        if (pessoas[i].idade > IdadeDaPessoaMaisVelha){
            IdadeDaPessoaMaisVelha = pessoas[i].idade;
        }
        if (pessoas[i].idade < 18){
            PorcentagemComIdadeMenorQue18++;
        }
    }
    media = somaDaIdade / N;
    PorcentagemComIdadeMenorQue18 = (PorcentagemComIdadeMenorQue18 / N) * 100;

    for(int i = 1; i <= N; i++){
        if (pessoas[i].idade < media){
            PessoasComIdadeMenorQueAMedia++;
        }
    }

    printf("Media das idades: %f\n", media);
    printf("Porcentagem de pessoas com idade menor que 18: %.2f%%\n", PorcentagemComIdadeMenorQue18);
    printf("Idade da pessoa mais velha: %f\n", IdadeDaPessoaMaisVelha);
    printf("Quantidade de pessoas com idade menor que a media: %d\n", PessoasComIdadeMenorQueAMedia);

    return 0;
}