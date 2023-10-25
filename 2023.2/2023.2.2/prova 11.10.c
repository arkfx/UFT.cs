//Produtores de hortaliças de uma região do estado mantém uma cooperativa para a distribuição de
//alface e repolho que abastecem os mercados da cidade.
//Semanalmente a cooperativa recebe carregamentos de alface e repolho dos
//produtores associados (no máximo 50 produtores) e
//anota o número de pés de alface e o número de pés repolho entregues por cada produtor.
//A cooperativa quer fazer um levantamento sobre as hortaliças entregues nas últimas 15 semanas.
//Faça um algoritmo que leia, para cada semana,
// o número de pés de alface e o número de pés repolho entregues por cada produtor
//após as leituras, mostre 1 destes relatórios:

//- Relatório por semana: dado a semana, mostrar a quantidade de alface e de repolho entregues nesta semana.

//- Relatório por produtor: dado o produtor, mostrar a quantidade de alface e de repolho entregues no período por este produtor.

//- Relatório de análise de abastecimento: Mostre a quantidade total de alface e de repolho entregues no período
// Se a quantidade total de hortaliças for inferior a 500, emita um sinal de “Risco de desabastecimento”,
//se a quantidade de alface for superior a 1300 ou a quantidade de repolho for superior a 1200, emita um sinal de “Super produção”.
//Diga também se houve alguma semana no período que não houve entregas

#include <stdio.h>

typedef struct {
    int alface;
    int repolho;
    int naoEntregou;
} semana;

typedef struct {
    semana semanas[16];
} produtor;

produtor produtores[51];


void relatorios(){

    printf("\n");
    printf("qual relatorio deseja ler ? \n 1 = relatorio por semana. \n 2 = relatorio por produtor \n 3 = relatorio de analise de abastecimento");
    int relatorio;
    scanf("%d", & relatorio);
    printf("\n");

    if(relatorio == 1){
        relatorioPorSemana();
    } else if (relatorio == 2){
        relatorioPorProdutor();
    } else if (relatorio == 3){
        relatorioDeAbastecimento();
    }

    printf("\n");
    printf("deseja ler outro relatorio ? (1 para sim 0 para não)");
    int confirm;
    scanf("%d", & confirm);
    if (confirm == 1){
        relatorios();
    } else if (confirm == 0){
        printf("\n");
        printf("---FIM---");
        printf("\n");
    }
}

void relatorioPorSemana(){
    printf("\n");
    printf("---RELATORIO-POR-SEMANA---");
    printf("\n");

    printf("qual semana deseja ler?: ");
    int semanaInp;
    scanf("%d", & semanaInp);

    int semanaAlface;
    int semanaRepolho;

    for (int i = 1; i <= 50; i++){
        semanaAlface += produtores[i].semanas[semanaInp].alface;
        semanaRepolho += produtores[i].semanas[semanaInp].repolho;
    }

    printf("\n");
    printf("quantidade de alfaces entregues nessa semana: ");
    printf("%d", semanaAlface);
    printf("\n");

    printf("\n");
    printf("quantidade de repolhos entregues nessa semana: ");
    printf("%d", semanaRepolho);
    printf("\n");
}

void relatorioPorProdutor(){
    printf("\n");
    printf("---RELATORIO-POR-PRODUTOR---");
    printf("\n");

    printf("numero do produtor? ");
    int produtorInp;
    scanf("%d", & produtorInp);

    int produtorAlface;
    int produtorRepolho;

    for (int i = 1; i <= 15; i++){
        produtorAlface += produtores[produtorInp].semanas[i].alface;
        produtorRepolho += produtores[produtorInp].semanas[i].repolho;
    }
    printf("\n");
    printf("quantidade de alfaces entregues por esse produtor: ");
    printf("%d", produtorAlface);
    printf("\n");

    printf("\n");
    printf("quantidade de repolhos entregues por esse produtor: ");
    printf("%d", produtorRepolho);
    printf("\n");
}

void relatorioDeAbastecimento(){
    printf("\n");
    printf("---RELATORIO-DE-ANALISE-DE-ABASTECIMENTO---");
    printf("\n");

    int TotalAlface;
    int TotalRepolho;

    int sEntrega;

    for (int i = 1; i <= 50; i++){
        for (int j = 1; j <= 15; j++){
            TotalAlface += produtores[i].semanas[j].alface;
            TotalRepolho += produtores[i].semanas[j].repolho;
            if (produtores[i].semanas[j].alface && produtores[i].semanas[j].repolho == 0){
                produtores[i].semanas[j].naoEntregou = 1;
                sEntrega++;
            }
        }
    }  

    if (sEntrega > 50){
        printf("houve uma semana sem entragas");
    }

    printf("\n");
    printf("quantidade total de alfaces entregues no periodo: ");
    printf("%d", TotalAlface);
    printf("\n");

    printf("\n");
    printf("quantidade total de repolhos entregues no periodo");
    printf("%d", TotalRepolho);
    printf("\n");

    printf("\n");
    printf("\n");

    if(TotalAlface + TotalRepolho < 500){
        printf("\n");
        printf("---RISCO-DE-DESABASTECIMENTO---");
        printf("\n");
    }
    if(TotalAlface > 1300 || TotalRepolho > 1200){
        printf("\n");
        printf("---SUPER-PRODUCAO---");
        printf("\n");
    }

}

int main() {

    printf("\n");
    repetirInput:
    printf("\n");

    printf("numero do produtor ?: ");
    int produtorInp;
    scanf(" %d", & produtorInp);
    int i;
    for (i = 1; i <= 15; i++){
        printf("\n");
        printf("para a semana: ");
        printf("%d", i);
        printf("\n");

        printf("numero de alfaces entregues ?: ");
        scanf(" %d", & produtores[produtorInp].semanas[i].alface);

        printf("numero de repolhos entregues ?: ");
        scanf(" %d", & produtores[produtorInp].semanas[i].repolho);

        printf("\n");
    }

    printf("\n");
    printf("deseja ler outro produtor ? (1 para sim 0 para não): ");
    int confirm;
    scanf(" %d", & confirm);
    printf("\n");

    if (confirm == 1){
        goto repetirInput;
    } else if (confirm == 0){
        relatorios();
    }

    printf("\n");
    printf("---FIM---");
    printf("\n");

    return 0;
}
