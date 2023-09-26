#include <stdio.h>

int i, j, op, contarturma = 0, maiormedia = 0;

typedef struct
{
    float nota;
    char nome;
} aluno;
typedef struct
{
    aluno alunos[31];
    float media;
    int contaraluno;
} turma;
turma turmas[1000];

int main(void)
{

    for (j = 1; j <= 1000; j++)
    {
        for (i = 1; i <= 30; i++)
        {
            printf("Insira a nota do aluno %d\n", i);
            scanf("%f", turmas[j].alunos[i].nota);

            if (turmas[j].alunos[i].nota == -1)
            {
                break;
            }
            turmas[j].media += turmas[j].alunos[i].nota;
            turmas[j].contaraluno++;

            printf("Insira o nome do aluno:\n");
            scanf("%s", &turmas[j].alunos[i].nome);
        }
        contarturma++;
        turmas[j].media / i;
        printf("Voce deseja continuar? Insira '1' para sim e '0' para nao:\n");
        scanf("%d", &op);
        if (op == 0)
        {
            break;
        }
    }
    do
    {
        printf("Insira a opcao que deseja:\n1 - Nota individual\n2 - Media da turma\n"
               "3 - Alunos acima da media\n4 - Maior media\n5 - Adicionar aluno\n6 - Adicionar turma\n 7 - Modificar/apagar aluno\n"
               "8 - Sair\n");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("Insira a turma que deseja ver:\n");
            scanf("%d", &j);
            if (j > contarturma && j < 1)
            {
                printf("Turma invalida, tente outra turma\n");
                break;
            }
            printf("Insira o aluno que deseja ver:\n");
            scanf("%d", &i);
            if (i > turmas[j].contaraluno && i < 1)
            {
                printf("Aluno invalido, tente outro aluno\n");
                break;
            }
            printf("Turma:%d\nAluno %d\nNome:%s\nNota:%.2f\n", j, i, turmas[j].alunos[i].nome, turmas[j].alunos[i].nota);
        case 2:
            printf("Insira a turma que deseja ver:\n");
            scanf("%d", &j);
            if (j > contarturma && j < 1)
            {
                printf("Turma invalida, tente outra turma\n");
                break;
            }
            printf("A media da turma escolhida foi: %.2f", turmas[j].media);
        case 3:
            printf("Insira a turma que deseja ver:\n");
            scanf("%d", &j);
            if (j > contarturma && j < 1)
            {
                printf("Turma invalida, tente outra turma\n");
                break;
            }
            for (i = 1; i <= turmas[j].contaraluno; i++)
            {
                if (turmas[j].alunos[i].nota >= turmas[j].media)
                {
                    printf("Aluno %d possui nota maior ou igual que a media da turma\n", i);
                }
            }
        case 4:
            for (j = 1; j <= contarturma; j++)
            {
                if (turmas[j].media > maiormedia)
                {
                    maiormedia = j;
                }
            }
            printf("A turma com maior media foi: %d\n", maiormedia);
        case 5:
            printf("Insira a turma que deseja ver:\n");
            scanf("%d", &j);
            if (j > contarturma && j < 1)
            {
                printf("Turma invalida, tente outra turma\n");
                break;
            }
            if (turmas[j].contaraluno >= 30)
            {
                printf("Turma lotada, tente outra turma");
                break;
            }
            for (i = turmas[j].contaraluno; i <= 30; i++)
            {
                printf("Insira a nota do aluno %d\n", i);
                scanf("%f", turmas[j].alunos[i].nota);

                if (turmas[j].alunos[i].nota == -1)
                {
                    break;
                }
                turmas[j].media += turmas[j].alunos[i].nota;
                turmas[j].contaraluno++;

                printf("Insira o nome do aluno:\n");
                scanf("%s", &turmas[j].alunos[i].nome);
            }
        }

    } while (op != 8);
}