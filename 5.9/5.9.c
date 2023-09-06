#include <stdio.h>
#include <string.h>

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
    else if(rCHAR == 'n' || rCHAR == 'N'){
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
    strcpy(ask, "temperatura ? ");
    readFloat();
    float temperatura = rFLOAT;

    strcpy(ask, "falta de ar ? (s/n): ");
    readChar();
    bool faltaDeAr = rBOOL;

    printf("temperatura: %f", temperatura);
    return 0;




}