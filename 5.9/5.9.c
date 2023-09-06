#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char ask[50];

int rINT = 0;
float rFLOAT = 0;
char rCHAR = 'k';
bool rBOOL = false;


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
    if(rCHAR == 's' || rCHAR == 'S'){
        rBOOL = true;
    }
    if(rCHAR == 'n' || rCHAR == 'N'){
        rBOOL = false;
    }
}

void clearIN(){
    rINT = 0;
    rFLOAT = 0;
    rCHAR = 'k';
    rBOOL = false;
}

void clearOUT(){
    while((getchar()) != '\n');
}


int main () {
    bool exameDeSangueEurina = false;
    bool tomografiaDoPulmao = false;
    bool consultaClinicoGeral = false;
    bool emergencia = false;

    printf("responda as perguntas com s ou n");
    printf("\n");

    strcpy(ask, "temperatura ? ");
    readFloat();
    float temperatura = rFLOAT;

    strcpy(ask, "falta de ar ? ");
    readChar();
    bool faltaDeAr = rBOOL;

    strcpy(ask, "desacordado ? ");
    readChar();
    bool desacordado = rBOOL;
        
    if (temperatura > 37.5){
        exameDeSangueEurina = true;
    }
    if (faltaDeAr){
        tomografiaDoPulmao = true;
    }
    if (temperatura <= 37.5 && >= 35){
        consultaClinicoGeral = true;
        printf("consulta com clinico geral");
    }
    if (desacordado || temperatura < 35){
        emergencia = true;
    }





    return 0;


    
    
}