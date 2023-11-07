#include <stdio.h>


/* Uma escola de idiomas ministrará um curso intensivo de 1 ano. 
Serão abertas 2 turmas de no máximo 5 alunos em cada. 

Os alunos recebem 3 notas ao longo do ano,
a média final destas notas consiste na média aritmética das notas do aluno
e a nota para receber o certificado é no mínimo 7,0 pontos. 
Oaluno deve ter também no máximo 10 faltas, caso contrário será reprovado por falta. 
Se o aluno tiver média final abaixo de 5,0 também será reprovado.
O aluno que não foi aprovado, nem reprovado, terá a chance de 
fazer uma prova substitutiva.

Elabore um programa em linguagem C que leia para cada aluno,
seu nome, suas 3 notas, sua frequência e mostre um dos os seguintes relatórios

:- Consulta por aluno:Dado o número do aluno e de sua turma, mostre 
seu nome, suas notas, sua média final, sua frequência e 
uma das mensagens: “Reprovado por falta”, “Reprovado por nota”,
“Certificado Liberado” ou “Fará substitutiva”.

- Consulta por turma:Dado o número da turma,
mostre quantos alunos tem a turma, quantos tiveram média final acima de 8,
quantos alunos tiveram algum zero em suas notas, quantos farão prova substitutiva
e qual é a média de notas geral da turma.

Após imprimir um relatório, deve ser possível ao usuário imprimir outro caso queira.

Obs.: Implementar pelo menos uma função que
receba como parâmetros média final e frequência de um aluno e
retorne 0 se foi reprovado por falta, 1 se reprovado por nota, 
2 se o certificado foi liberado ou 3 se fará prova substitutiva */

//um a mais para as arrays para não ter que ficar fazendo +1
//ex: turmas[0] = turma1
//for começando em 1 para não ter que ficar fazendo +1
//e para não ter que ficar fazendo -1 na hora de imprimir o nome do aluno

typedef struct {
    char nome[50];
    float nota1;
    float nota2;
    float nota3;
    float mediaFinal;
    int faltas;

    int status;
    //0 = reprovado por falta
    //1 = reprovado por nota
    //2 = certificado liberado
    //3 = fará prova substitutiva
} Aluno;

typedef struct {
    Aluno alunos[6];
} Turma;
Turma turmas[3];

int main() {
    lerAlunos();
    relatorios();

    return 0;
}

void lerAlunos() {
    for (int i = 1; i <= 2; i++) {
        for (int j = 1; j <= 5; j++) {
            printf("Digite o nome do aluno %d da turma %d: ", j, i);
            scanf("%s", turmas[i].alunos[j].nome);

            printf("Digite a nota 1 do aluno %d da turma %d: ", j, i);
            scanf("%f", &turmas[i].alunos[j].nota1);

            printf("Digite a nota 2 do aluno %d da turma %d: ", j, i);
            scanf("%f", &turmas[i].alunos[j].nota2);

            printf("Digite a nota 3 do aluno %d da turma %d: ", j, i);
            scanf("%f", &turmas[i].alunos[j].nota3);
            
            printf("Digite a quantidade de faltas do aluno %d da turma %d: ", j, i);
            scanf("%d", &turmas[i].alunos[j].faltas);

            turmas[i].alunos[j].mediaFinal = (turmas[i].alunos[j].nota1 + turmas[i].alunos[j].nota2 + turmas[i].alunos[j].nota3) / 3;
            if (turmas[i].alunos[j].faltas > 10) {
                turmas[i].alunos[j].status = 0;
            } else if (turmas[i].alunos[j].mediaFinal < 5) {
                turmas[i].alunos[j].status = 1;
            } else if (turmas[i].alunos[j].mediaFinal >= 7) {
                turmas[i].alunos[j].status = 2;
            } else {
                turmas[i].alunos[j].status = 3;
            }
        }
    }
}

void relatorios() {
    int opcao;
    do {
        printf("Digite 1 para consultar por aluno ou 2 para consultar por turma: ");
        scanf("%d", &opcao);
        if (opcao == 1) {
            consultaPorAluno();
        } else if (opcao == 2) {
            consultaPorTurma();
        }
    } while (opcao == 1 || opcao == 2);
}

void consultaPorAluno() {
    int turma, aluno;
    printf("Digite o número da turma: ");
    scanf("%d", &turma);
    printf("Digite o número do aluno: ");
    scanf("%d", &aluno);

    printf("Nome: %s\n", turmas[turma].alunos[aluno].nome);
    printf("Nota 1: %.2f\n", turmas[turma].alunos[aluno].nota1);
    printf("Nota 2: %.2f\n", turmas[turma].alunos[aluno].nota2);
    printf("Nota 3: %.2f\n", turmas[turma].alunos[aluno].nota3);
    printf("Média final: %.2f\n", turmas[turma].alunos[aluno].mediaFinal);
    printf("Faltas: %d\n", turmas[turma].alunos[aluno].faltas);

    if (turmas[turma].alunos[aluno].status == 0) {
        printf("Reprovado por falta\n");
    } else if (turmas[turma].alunos[aluno].status == 1) {
        printf("Reprovado por nota\n");
    } else if (turmas[turma].alunos[aluno].status == 2) {
        printf("Certificado liberado\n");
    } else {
        printf("Fará prova substitutiva\n");
    }
}

void consultaPorTurma() {
    int turma;
    printf("Digite o número da turma: ");
    scanf("%d", &turma);

    int alunos = 5;
    int acimaDe8 = 0;
    int zero = 0;
    int substitutiva = 0;
    float media = 0;

    for (int i = 1; i <= 5; i++) {
        if (turmas[turma].alunos[i].mediaFinal > 8) {
            acimaDe8++;
        }
        if (turmas[turma].alunos[i].status == 3) {
            substitutiva++;
        }
        if (turmas[turma].alunos[i].nota1 == 0 || turmas[turma].alunos[i].nota2 == 0 || turmas[turma].alunos[i].nota3 == 0) {
            zero++;
        }

        media += turmas[turma].alunos[i].mediaFinal;
    }

    media /= alunos;

    printf("Alunos: %d\n", alunos);
    printf("Acima de 8: %d\n", acimaDe8);
    printf("Zero: %d\n", zero);
    printf("Substitutiva: %d\n", substitutiva);
    printf("Média: %.2f\n", media);
}

