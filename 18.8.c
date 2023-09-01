// Online C compiler to run C program online
#include <stdio.h>
#include <string.h>

char ask[50];

int rINT = 0;
float rFLOAT = 0;
char rCHAR = 'k';

void readInt(){
    clearIN();
    while (rINT == 0){
        printf("%s", ask);
        scanf(" %d", & rINT);
        if(rINT == 0){
            clearOUT();
        }
    }
}

void readFloat(){
    clearIN();
    while (rFLOAT == 0){
        printf("%s", ask);
        scanf(" %f", & rFLOAT);
        if(rFLOAT == 0){
            clearOUT();
        }
    }
}

void readChar(){
    clearIN();
    while(rCHAR != 's' && rCHAR != 'n' && rCHAR != 'S' && rCHAR != 'N'){
        printf("%s", ask);
        scanf(" %c", & rCHAR);
    }
}

void clearIN(){
    rINT = 0;
    rFLOAT = 0;
    rCHAR = 'k';
}

void clearOUT(){
    while((getchar()) != '\n');
}

void clear(){
    clearIN();
    clearOUT();
}

void ALG1(){
    printf("ALG1");
    
    printf("\n");
    printf("\n");
    printf("\n");
    
    float vc;
    float vp;
    
    strcpy(ask, "valor da compra: ");
    readFloat();
    vc = rFLOAT;
    
    if (vc > 100){
        vp = vc * 0.90;
        
        printf("desconto de 10 por cento \n");
    }else {
        vp = vc;
        printf("sem desconto \n");
    }
    
    printf("o valor a ser pago é igual a: R$");
    printf("%.2f", vp);
    printf(" reais");
    
    printf("\n");
    printf("\n");
    printf("\n");
    
}

void ALG2(){
    printf("ALG2");
    
    printf("\n");
    printf("\n");
    printf("\n");
    
    float altura;
    printf ("altura ");
    scanf (" %f", & altura);
    
    float largura;
    printf ("largura ");
    scanf (" %f", & largura);
    
    float area;
    area = altura * largura;
    
    printf("\n");
    printf("\n");
    
    printf("a area total a ser pintada é igual a: ");
    printf("%.2f", area);
    printf("m²");
    
    printf("\n");
    printf("\n");
    
    float vpA = 10;
    float vpL = 15;
    
    vpA = area * vpA;
    vpL = area * vpL;
    
    printf("o valor a ser pago em tinta acrilica é igual a: R$");
    printf("%.2f", vpA);
    
    printf("\n");
    
    printf("o valor a ser pago em tinta lavavel é igual a: R$");
    printf("%.2f", vpL);
    
    printf("\n");
    printf("\n");
    printf("\n");
    
}

void ALG3(){
    printf("ALG3");
    
    printf("\n");
    printf("\n");
    printf("\n");
    
    char md = 'k';
    
    while(md != 's' && md != 'n' && md != 'S' && md != 'N'){
        printf("precisa de material didatico ? (S=SIM N=NÃO): ");
        scanf(" %c", & md);
    }
}

int main() {
    start:
    int alg = 0;
    
    printf("ALG: (1); (2); (3); ");
    scanf("%d", & alg);
    if(alg != 1 && alg != 2 && alg != 3){
        goto end;
    } else if(alg == 1){
        alg = 0;
        ALG1();
    } else if(alg == 2){
        alg = 0;
        ALG2();
    } else if(alg == 3){
        alg = 0;
        ALG3();
    } else if(alg == 0){
        goto start;
    }

    end:
    
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    
    printf("FIM");
    
    return 0;
}
