#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int main(void){

    //Durante 6 meses, 30 funcionários de um shopping participaram de um programa de exercícios
    //ocupacionais. Durante o programa foram registrados, para cada funcionário, sua idade, medições
    //mensais de frequência cardíaca e várias medições do peso corporal. Elabore um algoritmo que,
    //para cada funcionário, mostre seu peso médio e a maior frequência cardíaca registrada durante o
    //programa. No final mostre ainda a percentagem de funcionários que tiveram sua maior frequência
    //cardíaca ultrapassando 105 bpm e quantos tiveram o peso médio maior que seu peso final,
    //quantos tiveram o peso médio menor que seu peso final e quantos forram iguais.
    //obs.: Na leitura das medições do peso, utilize o valor -1 para indicar que a sequência de medições
    //finalizou (o valor -1 na entrada é o código para a parada da estrutura de repetição e não deve ser
    //processado). Considere que os valores de peso e frequência cardíaca são valores reais.

    typedef struct{
        int idade;
        float peso[1001];
        float frequencia[7];
        float mediapeso;
        float maiorfrequencia;
    } funcionario;
    funcionario funcionarios[31];

    int funcionarioLido;
    printf("Digite o numero do funcionario --> ");
    scanf("%d", &funcionarioLido);

    for(int mes = 1; mes <=6; mes ++){
        printf("Digite a frequencia cardiaca do funcionario %d no mes %d --> ", funcionarioLido, mes);
        scanf("%f", &funcionarios[funcionarioLido].frequencia[mes]);
    
    }
    do{
        if (i )
        printf("Digite os pesos medidos do funcionario %d --> ", funcionarioLido);
        int pesolido;
        scanf("%d", &pesolido);
        if(pesolido < 0){
            break;
        } else{
            
        }
        i++;
        }while(true);









    return 0;
}