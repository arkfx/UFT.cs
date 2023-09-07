#include <stdio.h>
#include <string.h>

char ask[50];
float rFLOAT = 0;

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

void clearIN(){
    rFLOAT = 0;
}

void clearOUT(){
    while((getchar()) != '\n');
}

typedef struct{
    char nomeDoMes[20];
    float indicePluviometrico;
    float temperaturaMedia;
} mes;
mes meses[12];

int main () {
    strcpy(meses[1].nomeDoMes, "Janeiro");
    strcpy(meses[2].nomeDoMes, "Fevereiro");
    strcpy(meses[3].nomeDoMes, "Marco");
    strcpy(meses[4].nomeDoMes, "Abril");
    strcpy(meses[5].nomeDoMes, "Maio");
    strcpy(meses[6].nomeDoMes, "Junho");
    strcpy(meses[7].nomeDoMes, "Julho");
    strcpy(meses[8].nomeDoMes, "Agosto");
    strcpy(meses[9].nomeDoMes, "Setembro");
    strcpy(meses[10].nomeDoMes, "Outubro");
    strcpy(meses[11].nomeDoMes, "Novembro");
    strcpy(meses[12].nomeDoMes, "Dezembro");


    for (int i = 1; i >= 12; i++){
        printf("para o mes: %c", meses[i].nomeDoMes);

        printf("\n");
        strcpy(ask, "temperatura media: ");
        readFloat();
        meses[i].temperaturaMedia = rFLOAT;

        printf("\n");
        strcpy(ask, "Indice pluviometrico do mes: ");
        readFloat();
        meses[i].indicePluviometrico = rFLOAT;
    }
    

    return 0;
}