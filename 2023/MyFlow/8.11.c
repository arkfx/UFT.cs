#include <stdio.h>

/* Uma concessionária de veículos mantêm o cadastro de seus veículos desta forma:

código do veículo (número inteiro),
código da cor (número inteiro, 1 para branco, 2 para preto, 3 para vermelho e 4 para cinza),
quantidade.

A capacidade máxima de armazenagem nas suas garagens é de 150 veículos.
Não permita que sejam cadastrados mais veículos do que a capacidade.

Faça um programa que inicialmente leia os dados dos vários veículos que estão atualmente na concessionária.
Serão cadastrados, no máximo 25 tipos de veículos (tipo = codeColor).
Não permita código do veículo com mesma cor em linhas diferentes.
Após esta leitura inicial, ofereça ao vendedor, sempre que desejar, a possibilidade de consultar um
destes relatórios: 

Relatório geral (mostre todos os veículos e seus dados, a quantidade total de veículos e a percentagem de ocupação das garagens),

relatório por cor (dada a cor, mostre a quantidade total e todos os veículos desta cor), 

relatório por código (dado o código, mostre a quantidade total e todos os veículos com o código e seus dados)

busca por veículo (Dados o código do veículo e sua cor, mostre a quantidade. Se o veículo for encontrado, a busca deve ser interrompida). 

Pode ocorrer a necessidade de cadastrar um veículo que tenha sido adquirido
esporadicamente, então o programa deve ser capaz de inserir um veículo (apenas 1) a qualquer
momento. */

typedef struct {
    int code;
    //code = defined by user;

    int color;
    //1 = branco;
    //2 = preto;
    //3 = vermelho;
    //4 = cinza;

    int amount;
    
} typecar;

typedef struct {
    typecar typecars[26];
    int total;
    //total = sum of int amount of all typecars
    //max total = 150;
} garage;
garage garages[1];


int main() {
    printf("\n");
    printf("---CONCESSIONÁRIA---");
    printf("\n");
    menu();
    return 0;
}

void menu(){
    printf("\n");
    printf("o que deseja fazer ?: ");
    printf ("1 = adicionar um veiculo; \n 2 = imprimir um relatorio? ");
    int action;
    scanf(" %d", & action);
    if (action == 1){
        printf("\n");
        addCar();
    } else if (action == 2){
        printf("\n");
        relatorios();
    }

    printf("\n");
    menu();
}

void addCar(){
    printf("\n");
    printf("---ADICIONAR-VEICULO---");
    printf("\n");

    printf("\n");
    if (garages[0].total >= 150){
        printf("---QUANTIDADE-MAXIMA-DE-VEICULOS-ALCANÇADA---");
        printf("\n");
        menu();
    }

    int localCode;
    int localColor;
    int localAmount;

    printf("codigo do veiculo ? ");
    scanf("%d", &localCode);

    printf("cor do veiculo ? ");
    scanf("%d", &localColor);

    printf("quantidade ? ");
    scanf("%d", &localAmount);
    if((localAmount + garages[0].total) > 150){
        printf("---QUANTIDADE EXCEDE O LIMITE TOTAL DE VEICULOS");
        printf("\n");
        menu();
    }

    for (int i = 1; i <= 25; i++){
        if (localCode == garages[0].typecars[i].code && localColor == garages[0].typecars[i].color){
            garages[0].typecars[i].amount += localAmount;
            garages[0].total += localAmount;
            printf("veiculo adicionado no já existente tipo %d", i);
            printf("\n");
            menu();
        }
    }
    for (int i = 1; i <= 25; i++){
        if(garages[0].typecars[i].amount == 0){
            garages[0].typecars[i].code = localCode;
            garages[0].typecars[i].color = localColor;
            garages[0].typecars[i].amount = localAmount;
            garages[0].total += localAmount;
            printf("veiculo adicionado no tipo %d", i);
            printf("\n");
            menu();
        }
    }
    printf("---LIMITE-DE-TIPOS-DE-CARROS-ALCANÇADO---");

    printf("\n");
    menu();
}

void relatorios(){
    printf("\n");
    printf("qual relatorio deseja imprimir ? ");
    printf("1 = relatorio geral; \n 2 = relatorio por cor; \n 3 = relatorio por codigo; \n 4 = busca por veiculo? ");
    int relatorio;
    scanf("%d", & relatorio);
    switch(relatorio){
        case 1:
            printf("\n");
            relatorioGeral();
        case 2:
            printf("\n");
            relatorioPorCor();
        case 3:
            printf("\n");
            relatorioPorCodigo();
        case 4:
            printf("\n");
            buscaPorVeiculo();
    }

    printf("\n");
    menu();
}


void relatorioGeral(){
    printf("\n");
    for (int i = 1; i <= 25; i++){
        if (garages[0].typecars[i].amount != 0){
            printf("\n");
            printf("tipo de veiculo: ");
            printf("%d", i);

            printf("\n");
            printf("codigo do veiculo: ");
            printf("%d", garages[0].typecars[i].code);

            printf("\n");
            printf("cor do veiculo: ");
            switch(garages[0].typecars[i].color){
                case 1:
                    printf("branco");
                    break;
                case 2:
                    printf("preto");
                    break;
                case 3:
                    printf("vermelho");
                    break;
                case 4:
                    printf("cinza");
                    break;
            }

            printf("\n");
            printf("quantidade de veiculos desse tipo: ");
            printf("%d", garages[0].typecars[i].amount);
        }
    }
    printf("\n");
    printf("quantidade total de veiculos: ");
    printf("%d", garages[0].total);

    printf("\n");
    printf("porcentagem de ocupação da garagem: ");
    float porcentagem = 0;
    float total = garages[0].total;
    porcentagem = ((total * 100) / 150);
    printf("%.2f%%", porcentagem);

    printf("\n");
    menu();
}

void relatorioPorCor(){
    printf("qual cor deseja buscar: 1 = branco; \n 2 = preto; \n 3 = vermelho; \n 4 = cinza? ");
    int localColor;
    scanf("%d", & localColor);

    int totalColor = 0;
    for (int i = 1; i <= 25; i++){
        if(localColor == garages[0].typecars[i].color){
            printf("\n");
            printf("tipo de veiculo: ");
            printf("%d", i);

            printf("\n");
            printf("codigo do veiculo: ");
            printf("%d", garages[0].typecars[i].code);

            printf("\n");
            printf("cor do veiculo: ");
            switch(garages[0].typecars[i].color){
                case 1:
                    printf("branco");
                    break;
                case 2:
                    printf("preto");
                    break;
                case 3:
                    printf("vermelho");
                    break;
                case 4:
                    printf("cinza");
                    break;
            }

            printf("\n");
            printf("quantidade de veiculos desse tipo: ");
            printf("%d", garages[0].typecars[i].amount);
            totalColor += garages[0].typecars[i].amount;
        }
    }
    printf("\n");
    printf("quantidade total de veiculos dessa cor: ");
    printf("%d", totalColor);

    printf("\n");
    menu();
}

void relatorioPorCodigo(){
    printf("codigo? ");
    int localCode;
    scanf("%d", & localCode);

    int totalCode = 0;
    for (int i = 1; i <= 25; i++){
        if(localCode == garages[0].typecars[i].code){
            printf("\n");
            printf("tipo de veiculo: ");
            printf("%d", i);

            printf("\n");
            printf("codigo do veiculo: ");
            printf("%d", garages[0].typecars[i].code);

            printf("\n");
            printf("cor do veiculo: ");
            switch(garages[0].typecars[i].color){
                case 1:
                    printf("branco");
                    break;
                case 2:
                    printf("preto");
                    break;
                case 3:
                    printf("vermelho");
                    break;
                case 4:
                    printf("cinza");
                    break;
            }

            printf("\n");
            printf("quantidade de veiculos desse tipo: ");
            printf("%d", garages[0].typecars[i].amount);
            totalCode += garages[0].typecars[i].amount;
        }
    }
    printf("\n");
    printf("quantidade total de veiculos desse codigo: ");
    printf("%d", totalCode);

    printf("\n");
    menu();
}

void buscaPorVeiculo(){
    int localCode;
    int localColor;

    printf("codigo ? ");
    scanf("%d", &localCode);

    printf("cor ? ");
    scanf("%d", &localColor);

    for (int i = 1; i <= 25; i++){
        if (localCode == garages[0].typecars[i].code && localColor == garages[0].typecars[i].color){
            printf("\n");
            printf("tipo de veiculo: ");
            printf("%d", i);

            printf("\n");
            printf("quantidade de veiculos desse tipo encontrados: ");
            printf("%d", garages[0].typecars[i].amount);

            break;
        }
    }

    printf("\n");
    menu();
}
