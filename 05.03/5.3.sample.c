#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[128];
    int telefone;
} contato;

contato Agenda[500];

int main() {
    printf("Hello, World!\n");
    menu();
    return 0;
}

void menu(){
    printf("1 - Criar contato\n");
    printf("2 - Listar contatos\n");
    printf("3 - Atualizar contato\n");
    printf("4 - Deletar contato\n");
    
    switch (getchar()) {
        case '1':
            createContact();
            break;
        case '2':
            readContact();
            break;
        case '3':
            updateContact();
            break;
        case '4':
            removeContact();
            break;
        default:
            printf("Opção inválida\n");
            break;
    }
    menu();   
}

void createContact(){
    int currentContact = -1;
    for (int i = 0; i < sizeof(Agenda) / sizeof(Agenda[0]); i++) {
        if ((strcmp(Agenda[i].nome, "") == 0) && (Agenda[i].telefone == 0)){
            currentContact = i;
            break;
        }
    }
    if (currentContact == -1) {
        printf("Agenda cheia\n");
        return;
    }

    printf("Digite o nome do contato: ");
    scanf("%s", &Agenda[currentContact].nome);
    printf("Digite o telefone do contato: ");
    scanf("%d", &Agenda[currentContact].telefone);

}
void readContact(){
    printf("mostrar todos os contatos ou buscar por um específico: ");
    printf("1 - Todos\n");
    printf("2 - Específico\n");
    switch (getchar()) {
        case '1':
            for (int i = 0; i < sizeof(Agenda) / sizeof(Agenda[0]); i++) {
                if (strcmp(Agenda[i].nome, "") != 0) {
                    printf("Nome: ");
                    printf("%s", Agenda[i].nome);
                    printf("Telefone: ");
                    printf("%d\n", Agenda[i].telefone);
                }
            }
            break;
        case '2':
            printf("buscar contato por: ");
            printf("1 - Nome\n");
            printf("2 - Telefone\n");
            switch (getchar()) {
                case '1':{
                    char nome[128];
                    printf("Digite o nome do contato: ");
                    scanf("%s", &nome);
                    for (int i = 0; i < sizeof(Agenda) / sizeof(Agenda[0]); i++) {
                        if (strcmp(Agenda[i].nome, nome) == 0) {
                            printf("Nome: %s\n", Agenda[i].nome);
                            printf("Telefone: %d\n", Agenda[i].telefone);
                            break;
                        }
                    }
                    printf("Contato não encontrado\n");
                }
                case '2':{
                    int telefone;
                    printf("Digite o telefone do contato: ");
                    scanf("%d", &telefone);
                    for (int i = 0; i < sizeof(Agenda) / sizeof(Agenda[0]); i++) {
                        if (Agenda[i].telefone == telefone) {
                            printf("Nome: %s\n", Agenda[i].nome);
                            printf("Telefone: %d\n", Agenda[i].telefone);
                            break;
                        }
                    }
                    printf("Contato não encontrado\n");
                    break;
                default:
                    printf("Opção inválida\n");
                    break;
                }
            }
            break;
        default:
            printf("Opção inválida\n");
            break;
    }
}

void updateContact(){
    printf("buscar contato por: ");
    printf("1 - Nome\n");
    printf("2 - Telefone\n");
    switch (getchar()) {
        case '1':{
            char nome[128];
            printf("Digite o nome do contato: ");
            scanf("%s", &nome);
            for (int i = 0; i < sizeof(Agenda) / sizeof(Agenda[0]); i++) {
                if (strcmp(Agenda[i].nome, nome) == 0) {
                    printf("Digite o novo nome do contato: ");
                    scanf("%s", &Agenda[i].nome);
                    printf("Digite o novo telefone do contato: ");
                    scanf("%d", &Agenda[i].telefone);
                    break;
                }
            }
            printf("Contato não encontrado\n");
        }
        case '2':{
            int telefone;
            printf("Digite o telefone do contato: ");
            scanf("%d", &telefone);
            for (int i = 0; i < sizeof(Agenda) / sizeof(Agenda[0]); i++) {
                if (Agenda[i].telefone == telefone) {
                    printf("Digite o novo nome do contato: ");
                    scanf("%s", &Agenda[i].nome);
                    printf("Digite o novo telefone do contato: ");
                    scanf("%d", &Agenda[i].telefone);
                    break;
                }
            }
            printf("Contato não encontrado\n");
            break;
        default:
            printf("Opção inválida\n");
            break;
        }   
    }
}


void removeContact(){
    printf("deseja deletar todos os contatos ou buscar por um específico: ");
    printf("1 - Todos\n");
    printf("2 - Específico\n");
    switch (getchar()) {
        case '1':
            for (int i = 0; i < sizeof(Agenda) / sizeof(Agenda[0]); i++) {
                if (strcmp(Agenda[i].nome, "") != 0) {
                    strcpy(Agenda[i].nome, "");
                    Agenda[i].telefone = 0;
                }
            }
            break;
        case '2':
            printf("buscar contato por: ");
            printf("1 - Nome\n");
            printf("2 - Telefone\n");
            switch (getchar()) {
                case '1':{
                    char nome[128];
                    printf("Digite o nome do contato: ");
                    scanf("%s", &nome);
                    for (int i = 0; i < sizeof(Agenda) / sizeof(Agenda[0]); i++) {
                        if (strcmp(Agenda[i].nome, nome) == 0) {
                            strcpy(Agenda[i].nome, "");
                            Agenda[i].telefone = 0;
                            break;
                        }
                    }
                    printf("Contato não encontrado\n");
                }
                case '2':{
                    int telefone;
                    printf("Digite o telefone do contato: ");
                    scanf("%d", &telefone);
                    for (int i = 0; i < sizeof(Agenda) / sizeof(Agenda[0]); i++) {
                        if (Agenda[i].telefone == telefone) {
                            strcpy(Agenda[i].nome, "");
                            Agenda[i].telefone = 0;
                            break;
                        }
                    }
                    printf("Contato não encontrado\n");
                    break;
                }
                default:
                    printf("Opção inválida\n");
                    break;
            }
            break;
        default:
            printf("Opção inválida\n");
            break;
    }
}

