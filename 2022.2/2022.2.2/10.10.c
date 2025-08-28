//mplementar o seguinte problema em linguagem C e apresentar o programa dia 05/12. 
//A implementação deve ter alguma matriz (de 2 ou de 3 dimensões) e deve ter pelo menos uma função (com parâmetro e valor de retorno)

//Uma fábrica de argamassas vende 3 produtos: argamassa AC3 20kg, argamassa AC2 20kg e rejunte5kg. 
//Suas entregas são feitas em Palmas ou Porto Nacional. Durante o último ano, esta fábrica manteve registros de pedidos de 2 grandes clientes. 
//Cada cliente fez um número indeterminado de pedidos (no máximo 10), 
//sendo que cada pedido tem o tipo do produto, a quantidade de pacotes e a localidade da entrega.

//Faça um programa em Linguagem C que leia os dados dos pedidos de cada cliente
//e imprima um dos seguintes relatórios:-
//- Relatório por pedido: dado o número do cliente e do pedido, mostre o tipo e a quantidade do produto, a localidade e o valor do frete.
//- Relatório por cliente: dado o número do cliente mostre a média de peso dos seus pedidos e o número de pedidos feitos no período.
//- Relatório geral: mostre quantos kg de material foram vendidos no período e quais pedidos tem menos de 1000kg.
//- Após imprimir um relatório, deve ser possível ao usuário imprimir outro caso queira.

//Obs.:Cálculo do frete: Se o pedido tem menos que 1000kg, o frete é grátis. 
//Se tem de 1001kg a 2000kg, ofrete é R$ 100,00 para Palmas e 200,00 para Porto Nacional. 
//Se tiver mais que 2000kg, o valor do frete será 2 reais por pacote

#include <stdio.h>
#include <stdlib.h>
#include <string.h> // para memset

typedef struct {
    //quantidade
    int argamassaAC3;
    int argamassaAC2;
    int rejunte;

    //1 = palmas; 2 = porto nacional.
    int LocalDeEntrega;
    int peso;
    int valorDoFrete;
} pedido;

typedef struct{
    pedido pedidos[11];
} cliente;
cliente clientes[3];

int main(){

    printf("Press Enter to continue...");
    while(getchar() != '\n');

    repetirInput:
    printf("\n");

    printf("numero do cliente ?: ");
    int cliente;
    scanf("%d", & cliente);

    if (cliente < 1 || cliente > 2){
        printf("cliente inexistente");
        goto repetirInput;
    }

    printf("\n");

    printf("numero do pedido ?: ");
    int pedido;
    scanf("%d", & pedido);

    memset(&clientes[cliente].pedidos[pedido], 0, sizeof(clientes[cliente].pedidos[pedido]));
    
    printf("debug local de entrega: %d", clientes[cliente].pedidos[pedido].LocalDeEntrega );

    if (pedido < 1 || pedido > 10){
        printf("pedido invalido");
        goto repetirInput;
    }

    printf("\n");

    printf("local de entrega ?: (1 para palmas; 2 para porto nacional) ");
    scanf("%d", & clientes[cliente].pedidos[pedido].LocalDeEntrega);

    printf("\n");

    printf("quantidade de argamassaAC3?: ");
    scanf("%d", & clientes[cliente].pedidos[pedido].argamassaAC3);

    printf("\n");

    printf("quantidade de argamassaAC2?: ");
    scanf("%d", & clientes[cliente].pedidos[pedido].argamassaAC2);

    printf("\n");
    
    printf("quantidade de rejunte?: ");
    scanf("%d", & clientes[cliente].pedidos[pedido].rejunte);

    calcularfrete(cliente, pedido);

    printf("deseja adicionar outro pedido ?: (1 para sim 2 para não)");
    int continuar;
    scanf("%d", &continuar);

    if (continuar == 1){
        goto repetirInput;
    } else{
        printarRelatorio();
    }

}

int calcularfrete(int cliente, int pedido){
    clientes[cliente].pedidos[pedido].peso += (clientes[cliente].pedidos[pedido].argamassaAC3 * 20);
    clientes[cliente].pedidos[pedido].peso += (clientes[cliente].pedidos[pedido].argamassaAC2 * 20);
    clientes[cliente].pedidos[pedido].peso += (clientes[cliente].pedidos[pedido].rejunte * 5);

    if (clientes[cliente].pedidos[pedido].peso < 1000){
        clientes[cliente].pedidos[pedido].valorDoFrete = 0;
    } else if (clientes[cliente].pedidos[pedido].peso >= 1000 && clientes[cliente].pedidos[pedido].peso <= 2000){
        if (clientes[cliente].pedidos[pedido].LocalDeEntrega = 1){
            clientes[cliente].pedidos[pedido].valorDoFrete = 100;
        } else {
            clientes[cliente].pedidos[pedido].valorDoFrete = 200;
        }
    } else if (clientes[cliente].pedidos[pedido].peso > 2000){
            int nDePacotes = (clientes[cliente].pedidos[pedido].argamassaAC2 + clientes[cliente].pedidos[pedido].argamassaAC3 + clientes[cliente].pedidos[pedido].rejunte);
            clientes[cliente].pedidos[pedido].valorDoFrete = (nDePacotes * 2);
    }

}

void printarRelatorio(){
    printf("\n");

    printf("relatorio por: (1 para pedido; 2 para cliente; 3 para geral)");
    int relatorio;
    scanf("%d", &relatorio);

    if (relatorio == 1){
        relatorioPedido();
    } else if (relatorio == 2){
        relatorioCliente();
    } else if (relatorio == 3){
        relatorioGeral();
    }
    
}

void relatorioPedido(){
    printf("\n");
    printf("numero do cliente ?: ");
    int cliente;
    scanf("%d", & cliente);
    printf("\n");
    printf("numero do pedido ?: ");
    int pedido;
    scanf("%d", & pedido);
    printf("\n");
    printf("tipo do produto: ");
    if (clientes[cliente].pedidos[pedido].argamassaAC3 > 0){
        printf("argamassaAC3");
    } else if (clientes[cliente].pedidos[pedido].argamassaAC2 > 0){
        printf("argamassaAC2");
    } else if (clientes[cliente].pedidos[pedido].rejunte > 0){
        printf("rejunte");
    }
    printf("\n");
    printf("quantidade do produto: ");
    if (clientes[cliente].pedidos[pedido].argamassaAC3 > 0){
        printf("%d", clientes[cliente].pedidos[pedido].argamassaAC3);
    } 
    if (clientes[cliente].pedidos[pedido].argamassaAC2 > 0){
        printf("%d", clientes[cliente].pedidos[pedido].argamassaAC2);
    }
    if (clientes[cliente].pedidos[pedido].rejunte > 0){
        printf("%d", clientes[cliente].pedidos[pedido].rejunte);
    }
    printf("\n");
    printf("local de entrega: ");
    if (clientes[cliente].pedidos[pedido].LocalDeEntrega == 1){
        printf("palmas");
    } else if (clientes[cliente].pedidos[pedido].LocalDeEntrega == 2){
        printf("porto nacional");
    }
    printf("\n");
    printf("valor do frete: %d", clientes[cliente].pedidos[pedido].valorDoFrete);
    printf("\n");
    printf("deseja imprimir outro relatorio ?: (1 para sim 2 para não)");
    int continuar;
    scanf("%d", &continuar);
    if (continuar == 1){
        printarRelatorio();
    }
}

void relatorioCliente(){
    printf("\n");
    printf("numero do cliente ?: ");
    int cliente;
    scanf("%d", & cliente);
    printf("\n");

    printf("\n");
    printf("\n");

    printf("media de peso dos pedidos feitos no periodo: ");
    int pesoTotal;
    int nPedidos;
    int mediaPeso;

    for (int i = 1; i <= 10; i++){
        if (clientes[cliente].pedidos[i].peso > 0){
            nPedidos++;
            pesoTotal += clientes[cliente].pedidos[i].peso;
        }
    }
    mediaPeso = pesoTotal / nPedidos;
    printf("%d", mediaPeso);


    printf("\n");
    printf("\n");
   
    printf("numero de pedidos feitos no periodo: ");
    printf("%d", nPedidos);
    printf("\n");
    printf("deseja imprimir outro relatorio ?: (1 para sim 2 para não)");
    int continuar;
    scanf("%d", &continuar);
    if (continuar == 1){
        printarRelatorio();
    }

}

void relatorioGeral(){
    printf("\n");
    printf("\n");

    int kgTotal;
    int menosDe1k;

    printf("kg de material vendidos no periodo: ");

    for(int i = 1; i <=2; i++){
        for(int j = i; j <= 10; j++){
            kgTotal += clientes[i].pedidos[j].peso;
            if (clientes[i].pedidos[j].peso < 1000){
                menosDe1k++;
            }
        }
    }
    printf("%d", kgTotal);

    printf("quantidade de pedidos com menos de 1000kg: ");
    printf("%d", menosDe1k);    

}

