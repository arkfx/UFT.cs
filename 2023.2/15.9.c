#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char ask[1000];

char rSTRING;
float rFLOAT = 0;

bool rBOOL = false;
char rCHAR;


void clearIN(){

    rFLOAT = 0;
    rBOOL = false;
    rCHAR = '\0';
}

void clearOUT(){ 
    while((getchar()) != '\n');
    printf("entrada invalida, tente novamente.\n");
    printf(">> ");
    printf("\n");
}

void readFloat(){
    clearIN();
    while (rFLOAT <= 0){
        printf("s", ask);
        scanf(" %f", & rFLOAT);
        if (rFLOAT <= 0){
            clearOUT();
            if (rFLOAT == -1){
                return;

            }
        }
    }
}



int main() {
    printf("Hello world");


    return 0;
}