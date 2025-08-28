#include <stdio.h>

/* Exercício de CRUD em C: Gerenciamento de Lista de Contatos
Crie um programa em C para gerenciar uma lista de contatos.
O programa deve permitir que o usuário realize as seguintes operações:

Create (Criar): O usuário deve poder adicionar um novo contato à lista. 
Cada contato deve incluir um nome e um número de telefone. 
Os contatos devem ser armazenados em uma estrutura de dados, como uma matriz.

Read (Ler): O usuário deve poder listar todos os contatos na lista, 
exibindo seus nomes e números de telefone.

Update (Atualizar): O usuário deve poder atualizar o 
número de telefone de um contato existente. 
Isso deve ser feito selecionando um contato da lista pelo nome
e atualizando seu número de telefone.

Delete (Excluir): O usuário deve poder excluir um contato da lista, 
selecionando-o pelo nome.

Lembre-se de fornecer um menu de opções ao usuário e garantir que o programa 
possa lidar com múltiplos contatos na lista. */
//https://prod.liveshare.vsengsaas.visualstudio.com/join?F3ACCC26421BD711F13DDC638C623FD3E2E5

typedef struct {
    char name[50];
    int number;
} contact;
contact contacts[1000];

int main() {    
    printf("\n");
    printf("1 = Criar Contato \n 2 = Ler contato \n 3 = Atualizar Contato \n 4 = Deletar Contato");
    int resp;
    scanf("%d", & resp);
    switch (expression)
    {




    return 0;
}
