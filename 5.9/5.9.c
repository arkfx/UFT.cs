#include <stdio.h>
#include <string.h>
#include <stdbool.h>

//as funções readInt, readFloat, readChar, clearIN e clearOUT foram feitas para facilitar a leitura e entrada de dados do usuário.
//impedindo que o programa receba entradas inválidas.
//como letras em uma entrada de int, ou números em uma entrada de char, por exemplo.

//a função readInt lê um inteiro e armazena em rINT.
//a função readFloat lê um float e armazena em rFLOAT.
//a função readChar lê um char e armazena em rCHAR, e converte rCHAR para bool, armazenando em rBOOL.
//essa conversão de char para bool é feita para que o usuário possa responder as perguntas com s ou n, ao invés de 1 ou 0.
//e também para evitar uma dupla verificação de entrada, uma para o char maiúsculo e outra para o minúsculo. 

//o strcpy copia uma string de uma pergunta para a variável ask, que é usada nas funções read, para printar a pergunta ao usuário.
//nas linhas seguintes, depois de uma chamada das funções read, é feita uma verificação para ver se a entrada foi válida.
//se não foi, o loop while faz com que uma nova solicitação de input do usuário seja feita, até que uma entrada válida seja feita.
//apos uma entrada válida, a função read é finalizada, e o programa segue para a próxima linha, na função main.
//apos o termino de uma função read, a variável em que queremos armazenar o valor da entrada é igualada as variáveis rINT, rFLOAT, rCHAR ou rBOOL.

//a função clearIN limpa as variáveis rINT, rFLOAT, rCHAR e rBOOL, para que possam ser usadas novamente.
//a função clearOUT limpa o buffer de entrada, para que o programa ignore entradas inválidas, como o \n deixado pelo scanf apos um enter.



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

    printf("responda as perguntas não-numericas com s ou n\n");

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
    if (temperatura <= 37.5 && temperatura >= 35){
        consultaClinicoGeral = true;
    }
    if (desacordado || temperatura < 35){
        emergencia = true;
    }
    
    printf("o paciente precisa ser encaminhado para: \n"); 

    if (exameDeSangueEurina){
        printf("exame de sangue e urina\n");
    }
    if (tomografiaDoPulmao){
        printf("tomografia do pulmao\n");
    }
    if (consultaClinicoGeral){
        printf("consulta com clinico geral\n");
    }
    if (emergencia){
        printf("emergencia\n");
    }

    return 0;
}