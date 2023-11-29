#include <stdio.h>

typedef struct{
    char nome[50];
    float nota1;
    float nota2;
    int freq;

    float mediafinal;
    //media aritmetica de nota1 e nota2;
} aluno;

typedef struct{
    aluno alunos[30];

    int nAlunos;
    //numero de alunos;    
} turma;
turma turmas[3];


int main() {
    menu();
    return 0;
}

void menu(){
    printf("o que deseja fazer ?");
    printf("(1 - adicionar um novo aluno \n 2 - realizar uma consulta) ");
    int act;
    scanf("%d", &act);

    switch (act) {
    case 1:
        lerAluno();
    
    case 2:
        consultas();

    default:
        return;

    }
}

void lerAluno(){

    printf("Numero da turma a ser lida ? ");
    int nTurma;
    scanf("%d", &nTurma);
    nTurma--;
    int nAluno = turmas[nTurma].nAlunos;

    if (turmas[nTurma].nAlunos > 29){
        printf("numero total de alunos para essa turma excedido");
        menu();
        return;
    }


    printf("nome do aluno ? ");
    scanf("%s", turmas[nTurma].alunos[nAluno].nome);

    printf("nota 1 do aluno ? ");
    scanf("%f", &turmas[nTurma].alunos[nAluno].nota1);

    printf("nota 2 do aluno ? ");
    scanf("%f", &turmas[nTurma].alunos[nAluno].nota2);

    printf("numero de faltas do aluno? ");
    scanf("%d", &turmas[nTurma].alunos[nAluno].freq);

    turmas[nTurma].alunos[nAluno].mediafinal = (turmas[nTurma].alunos[nAluno].nota1 + turmas[nTurma].alunos[nAluno].nota2) / 2;

    turmas[nTurma].nAlunos ++;


    printf("deseja ler outro aluno ? (1 - sim \n 0 - não) ");
    int act;
    scanf("%d", &act);
    if (act == 1){
        lerAluno();
    }

    return;

}

void consultas(){

    printf("qual consulta será realizada ? ");
    printf("(1 - Consulta por aluno \n 2 - Consulta por turma) ");
    int act;
    scanf("%d", &act);

    switch (act){
    case 1:
        consultaAluno();
        return;
        
    case 2:
        consultaTurma();
        return;

    default:
        return;

    }

}

void consultaAluno(){
    printf("numero do aluno ? ");
    int nAluno;
    scanf("%d", &nAluno);

    printf("numero da turma ? ");
    int nTurma;
    scanf("%d", &nTurma);

    nAluno--;
    nTurma--;

    printf("nome do aluno: ");
    printf("%s", turmas[nTurma].alunos[nAluno].nome);

    printf("nota 1: ");
    printf("%f", turmas[nTurma].alunos[nAluno].nota1);
    
    printf("nota 2: ");
    printf("%f", turmas[nTurma].alunos[nAluno].nota2);

    printf("media final: ");
    printf("%f", turmas[nTurma].alunos[nAluno].mediafinal);

    printf("numero de faltas: ");
    printf("%d", turmas[nTurma].alunos[nAluno].freq);
    

    printf("status do aluno: ");

    if(turmas[nTurma].alunos[nAluno].freq > 10){
        printf("reprovado por falta");
        return;
    }

    if(turmas[nTurma].alunos[nAluno].mediafinal < 5){
        printf("reprovado por nota");
        return;
    } else if(turmas[nTurma].alunos[nAluno].mediafinal < 7){
        printf("fará substutiva");
        return;
    } else {
        printf ("aprovado");
    }

    return;
}

void consultaTurma(){
    printf("numero da turma ? ");
    int nTurma;
    scanf("%d", &nTurma);
    nTurma--;


    int acima8;
    int algum0;
    int subst;
    float mediaTurma;
    for (int i = 0; i < turmas[nTurma].nAlunos; i++){
        mediaTurma += turmas[nTurma].alunos[i].mediafinal;
        if(turmas[nTurma].alunos[i].mediafinal > 8){
            acima8++;
        }
        if(turmas[nTurma].alunos[i].nota1 == 0 || turmas[nTurma].alunos[i].nota2 == 0){
            algum0++;
        }
        if(turmas[nTurma].alunos[i].freq <= 10 && turmas[nTurma].alunos[i].mediafinal >= 5 && turmas[nTurma].alunos[i].mediafinal < 7){
            subst++;
        }
    }
    mediaTurma = (mediaTurma / (turmas[nTurma].nAlunos + 1));


    
    printf("numero de alunos da turma: ");
    printf("%d", turmas[nTurma].nAlunos);

    printf("numero de alunos com media final acima de 8: ");
    printf("%d", acima8);

    printf("numero de alunos que tiveram 0 em alguma nota: ");
    printf("%d", algum0);

    printf("numero de alunos que farao prova substutiva: ");
    printf("%d", subst);

    printf("media geral da turma: ");
    printf("%f", mediaTurma);


    return;
}

