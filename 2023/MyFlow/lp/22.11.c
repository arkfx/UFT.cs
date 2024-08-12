#include <stdio.h>

//lista de contatos
//funcoes:
//criar nova lista
//ler lista
//atualizar lista
//deletar lista
//reorganizar listas

typedef struct {
    char *chave;
    char *valor;
    int tipo; //1 = float, 2 = string.
} AtributoCustomizado;

typedef struct {
    char *cep;
    char *pais;
    char *estado;
    char *cidade;
    char *bairro;
    char *rua;
    int numero;
    AtributoCustomizado *atributos;
} Endereco;

typedef struct {
    char *nome;
    int telefone;
    char *email;
    Endereco endereco;
    AtributoCustomizado *atributos;
} Contato;

typedef struct {
    Contato *contatos;
    int tamanho;
    AtributoCustomizado *atributos;
} ListaDeContatos;

typedef struct {
    ListaDeContatos *listasDeContatos;
    int tamanho;
} ListaDeListasDeContatos;
listaDeListasDeContatos[1];

int main() {
    menu();
    return 0;  
}

void menu(){
    printf("1 - criar nova lista\n");
    printf("2 - ler lista\n");
    printf("3 - atualizar lista\n");
    printf("4 - deletar lista\n");
    printf("5 - criar uma lista de listas de contatos\n");
    int opcao;
    scanf("%d", &opcao);
    switch(opcao){
        case 1:
            criarNovaLista();
            break;
        case 2:
            lerLista();
            break;
        case 3:
            atualizarLista();
            break;
        case 4:
            deletarLista();
            break;
        default:
            menu();
    }
}

void criarNovaLista(){
    printf("criar nova lista\n");

    listaDeListasDeContatos[0].
