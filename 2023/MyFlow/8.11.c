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

Relatório geral (mostre todos os veículos e seus dados, a quantidade total de
veículos e a percentagem de ocupação das garagens), relatório por cor (dada a cor, mostre a
quantidade total e todos os veículos desta cor), relatório por código (dado o código, mostre a
quantidade total e todos os veículos com o código e seus dados), busca por veículo (Dados o
código do veículo e sua cor, mostre a quantidade. Se o veículo for encontrado, a busca deve ser
interrompida). Pode ocorrer a necessidade de cadastrar um veículo que tenha sido adquirido
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
    printf("---CONCESSIONÁRIA---");
    printf("\n");
    printf("---ADICIONAR-CARROS---");
    printf("\n");
    
    addCar();

    menu();
    return 0;
}

void addCar(){
    if (garages[0].total >= 150){
        printf("---QUANTIDADE-MAXIMA-DE-VEICULOS-ALCANÇADA---");
        return;
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
        return;
    }

    for (int i = 1; i <= 25; i++){
        if (localCode == garages[0].typecars[i].code && localColor == garages[0].typecars[i].color){
            garages[0].typecars[i].amount = localAmount;
            garages[0].total += localAmount;

            return;
        }
    }
    for (int i = 1; i <=25; i++){
        if(garages[0].typecars[i].color == 0){
            garages[0].typecars[i].code = localCode;
            garages[0].typecars[i].color = localColor;
            garages[0].typecars[i].amount = localAmount;
            garages[0].total += localAmount;
            
            return;
        }
    }
    printf("---LIMITE-DE-TIPOS-ALCANÇADO---");
    printf("\n");

    menu();
}

void menu(){
    printf("o que deseja fazer ?");
    printf ("1 = adicionar outro veiculo; 2 = imprimir um relatorio: ");
    int action;
    scanf("%d", & action);
    if (action == 1){
        addCar();
    } else if (action == 2){
        relatorios();
    }

}

void relatorios(){
    printf("qual relatorio deseja imprimir ? ");
    printf("1 = relatorio geral; 2 = relatorio por cor; 3 = relatorio por codigo; 4 = busca por veiculo: ");
    int relatorio;
    scanf("%d", & relatorio);
    switch(relatorio){
        case 1:
            relatorioGeral();
        case 2:
            relatorioPorCor();
        case 3:
            relatorioPorCodigo();
        case 4:
            buscaPorVeiculo();
    }
}


void relatorioGeral(){
    for (int i = 1; i <=25; i++; ){
        if (garages[0].typecars[i].color != 0){
            printf("carro %d", i);
            printf("%d", garages[0].typecars[i].code);
            printf("%d", garages[0].typecars[i].color);
            printf("%d", garages[0].typecars[i].amount);
        }
    }
    printf("quantidade total de veiculos = ");
    printf("%d", garages[0].total);
}

void relatorioPorCor(){

}

void relatorioPorCodigo(){

}

void buscaPorVeiculo(){
    
}
