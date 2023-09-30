#include <stdio.h>
#include <string.h>
#include <stdbool.h>


char ask[1000];

float rFLOAT = 0;
char  rFLOATs [100];
bool validF = false;

char rSTRING[100];

bool rBOOL = false;
char rCHARs[10];
char rCHAR;

char rTIPOs[10];
char rTIPO;


void clearIN(){
    rFLOAT = 0;
    strcpy(rFLOATs, "");
    validF = false;

    strcpy(rSTRING, "");
    
    rBOOL = false;
    rCHAR = '\0';

    strcpy(rTIPOs, "");
    rTIPO = '\0';
}

void clearOUT(){
    clearIN();
    printf("entrada invalida, tente novamente.\n");
    printf("\n");
}

void validFloat() {
    const char* valid_chars = "0123456789.-";
    size_t len = strspn(rFLOATs, valid_chars);
    if (len != strlen(rFLOATs)) {
        validF = false;
    } else if (strchr(rFLOATs, '-') != strrchr(rFLOATs, '-') ||
        strchr(rFLOATs, '.') != strrchr(rFLOATs, '.') ||
        strchr(rFLOATs+1, '-') != NULL) {
        validF = false;
    } else {
        // Input string is a valid floating-point number
        validF = true;
    }
}
    

void readFloat(){
    clearIN();
    while (strcmp(rFLOATs, "") == 0){
        printf("%s", ask);
        scanf(" %s", &rFLOATs);
        validFloat();
        if(validF == true){
            rFLOAT = atof(rFLOATs);
        } else{
            if (strcmp(rFLOATs, "//") == 0){
                Menu();
            }
            clearOUT();
        }
    }
}

void readString(){
    clearIN();
    while (strlen(rSTRING) == 0){
        printf("%s", ask);
        scanf(" %s", & rSTRING);
        if(rSTRING[0] == '-'){
            Menu();
        }
        if(strlen(rSTRING) == 0){
            clearOUT();
        }
    }
}

void readBool(){
    clearIN();
    while (rCHAR != 's' && rCHAR!= 'n' && rCHAR != 'S' && rCHAR != 'N'){
        printf("%s", ask);
        scanf(" %c", & rCHAR);
        if(rCHAR == '-'){
            Menu();
        }
        if(rCHAR != 's' && rCHAR != 'n' && rCHAR != 'S' && rCHAR != 'N'){
            clearOUT();
        }
    }
    if(rCHAR == 's' || rCHAR == 'S'){
        rBOOL = true;
    }
    if(rCHAR == 'n' || rCHAR == 'N'){
        rBOOL = false;
    }
}

void readTipo(){
    clearIN();
    while (rTIPO != 'm' && rTIPO != 'l' && rTIPO != 'p' && rTIPO != 'M' && rTIPO != 'L' && rTIPO != 'P'){
        printf("%s", ask);
        scanf(" %c", & rTIPO);
        printf("%c", rTIPO);
        if(rTIPO == '-'){
            Menu();
        }
        if(rTIPO != 'm' && rTIPO != 'l' && rTIPO != 'p' && rTIPO != 'M' && rTIPO != 'L' && rTIPO != 'P'){
            clearOUT();
        }
    }
    rTIPO = toupper(rTIPO);
    if(rTIPO == 'M'){
        strcpy(rTIPOs, "Merceria");
    }
    if(rTIPO == 'L'){
        strcpy(rTIPOs, "Limpeza");
    }
    if(rTIPO == 'P'){
        strcpy(rTIPOs, "Pereciveis");
    }
}

typedef struct {
    char nome[100];
    float preco;
    int quantidade;
    char tipo[100];
} Produto;

typedef struct {
    Produto ProdutoMaisCaro;
    Produto ProdutoMaisBarato;
} ProdutoMais;

typedef struct {
    Produto produtos[100001];
    float valorEmEstoque;
    float porcentagemMerceria;
    float porcentagemLimpeza;
    float porcentagemPereciveis;
    ProdutoMais ProdutoMaisCaro;
    ProdutoMais ProdutoMaisBarato;  
} Filial;
Filial filiais[35];

void Menu(){
    start:
    printf("\n");
    float action = 0;
    while(action > 4 || action < 1){
        strcpy(ask, "1 - Adicionar produtos\n2 - Editar produtos\n3 - Remover produtos\n4 - Listar produtos\nO que deseja fazer? (1-4): ");
        readFloat();
        action = rFLOAT;
        if (action > 4 || action < 1){
            clearOUT();
        }
    }
    if(action == 3){
        strcpy(ask, "deseja remover todos os produtos de todas as filiais? (s/n): ");
        readBool();
        if(rBOOL == true){
            removeAll();
            goto start;
        }
    }

    if(action == 4){
        strcpy(ask, "deseja listar os produtos de todas as filiais? (s/n): ");
        readBool();
        if(rBOOL == true){
            printAll();
            goto start;
        }
    }

    int InpFilial = 0;
    while(InpFilial > 34 || InpFilial < 1){
        strcpy(ask, "selecione a filial (1-34): ");
        readFloat();
        InpFilial = rFLOAT;
    }
    
    if(action == 1){
        AddProduto(InpFilial);
        printf("\n");
        goto start;
    }
    if(action == 2){
        if(filiais[InpFilial].produtos[1].nome[0] == '\0'){
            printf("----Nenhum produto cadastrado nessa filial----");
            printf("\n");
            goto start;
        }
        EditProduto(InpFilial);
        printf("\n");
        goto start;
    }
    if(action == 3){
        if(filiais[InpFilial].produtos[1].nome[0] == '\0'){
            printf("----Nenhum produto cadastrado nessa filial----");
            printf("\n");
            goto start;
        }
        strcpy(ask, "deseja remover todos os produtos dessa filial? (s/n): ");
        readBool();
        if(rBOOL == true){
            removeFilial(InpFilial);
            goto start;
        }
        RemoverProduto(InpFilial);
        printf("\n");
        goto start;
    }
    if(action == 4){
        printFilial(InpFilial);
        printf("\n");
        goto start;
    }

}

int main() {
    printf("----Bem vindo ao sistema de estoque----");
    printf("\n");
    printf("digite // para voltar ao menu\n");
    Menu();

    return 0;
}

void AddProduto(int filial){
    printf("\n");
    printf("----Filial: ");
    printf("%d", filial);
    printf("----");
    printf("\n");
    int ReadProd;
    AddProduto:
    printf("\n");
    for(int i = 1; i <= 100000; i++){
        if(filiais[filial].produtos[i].nome[0] == '\0'){
            ReadProd = i;
            break;
        }
    } 

    strcpy(ask, "nome do produto: ");
    readString();
    strcpy(filiais[filial].produtos[ReadProd].nome, rSTRING);

    strcpy(ask, "preço do produto: ");
    readFloat();
    filiais[filial].produtos[ReadProd].preco = rFLOAT;

    strcpy(ask, "quantidade do produto: ");
    readFloat();
    filiais[filial].produtos[ReadProd].quantidade = rFLOAT;
    filiais[filial].valorEmEstoque += filiais[filial].produtos[ReadProd].preco * filiais[filial].produtos[ReadProd].quantidade;

    strcpy(ask, "tipo do produto: (M para merceria, L para limpeza, P para pereciveis): ");
    readTipo();
    strcpy(filiais[filial].produtos[ReadProd].tipo, rTIPOs);

    strcpy(ask, "deseja adicionar mais um produto nessa filial ? (s/n): ");
    readBool();
    if(rBOOL == true){
        goto AddProduto;
    }
}

void EditProduto(int filial){
    printFilial(filial);
    printf("\n");

    strcpy(ask, "Selecione pelo numero o produto da lista que deseja editar: ");
    readFloat();
    int ReadProd = rFLOAT;
    if (filiais[filial].produtos[ReadProd].nome[0] == '\0'){
        printf("\n");
        printf("----Produto não encontrado----");
        printf("\n");
        EditProduto(filial);
    }
    printf("\n");
    int valorAntigo = filiais[filial].produtos[ReadProd].preco * filiais[filial].produtos[ReadProd].quantidade;

    strcpy(ask, "nome do produto: ");
    readString();
    strcpy(filiais[filial].produtos[ReadProd].nome, rSTRING);

    strcpy(ask, "preço do produto: ");
    readFloat();
    filiais[filial].produtos[ReadProd].preco = rFLOAT;

    strcpy(ask, "quantidade do produto: ");
    readFloat();
    filiais[filial].produtos[ReadProd].quantidade = rFLOAT;
    filiais[filial].valorEmEstoque -= valorAntigo;
    filiais[filial].valorEmEstoque += filiais[filial].produtos[ReadProd].preco * filiais[filial].produtos[ReadProd].quantidade;

    strcpy(ask, "tipo do produto: (M para merceria, L para limpeza, P para pereciveis): ");
    readTipo();
    strcpy(filiais[filial].produtos[ReadProd].tipo, rTIPOs);

    printf("\n");
    strcpy(ask, "deseja editar mais um produto dessa filial ? (s/n): ");
    readBool();
    if(rBOOL == true){
        EditProduto(filial);
    }
}

void RemoverProduto(int filial){
    printFilial(filial);
    strcpy(ask, "selecione pelo numero o produto da lista que deseja remover: ");
    readFloat();
    int ReadProd = rFLOAT;
    if (filiais[filial].produtos[ReadProd].nome[0] == '\0'){
        printf("\n");
        printf("----Produto não encontrado----");
        printf("\n");
        RemoverProduto(filial);
    }
    printf("\n");
    filiais[filial].valorEmEstoque -= filiais[filial].produtos[ReadProd].preco * filiais[filial].produtos[ReadProd].quantidade;

    strcpy(filiais[filial].produtos[ReadProd].nome, "");
    filiais[filial].produtos[ReadProd].preco = 0;
    filiais[filial].produtos[ReadProd].quantidade = 0;
    strcpy(filiais[filial].produtos[ReadProd].tipo, "");
    for(int i = 1; i <= 100000; i++){
        if(filiais[filial].produtos[i].nome[0] == '\0'){
            if(filiais[filial].produtos[i+1].nome[0] != '\0'){
                strcpy(filiais[filial].produtos[i].nome, filiais[filial].produtos[i+1].nome);
                filiais[filial].produtos[i].preco = filiais[filial].produtos[i+1].preco;
                filiais[filial].produtos[i].quantidade = filiais[filial].produtos[i+1].quantidade;
                strcpy(filiais[filial].produtos[i].tipo, filiais[filial].produtos[i+1].tipo);

                strcpy(filiais[filial].produtos[i+1].nome, "");
                filiais[filial].produtos[i+1].preco = 0;
                filiais[filial].produtos[i+1].quantidade = 0;
                strcpy(filiais[filial].produtos[i+1].tipo, "");
            }
        }
    }

    strcpy(ask, "deseja remover mais um produto dessa filial ? (s/n): ");
    readBool();
    if(rBOOL == true){
        RemoverProduto(filial);
    }
}


void printFilial(int filial){
    printf("\n");
    printf("----Filial: ");
    printf("%d", filial);
    printf("----");
    printf("\n");
    for(int i = 1; i <= 100000; i++){
        if(filiais[filial].produtos[i].nome[0] != '\0'){
            printf("%d", i);
            printf(" - nome: ");
            printf("%s", filiais[filial].produtos[i].nome);

            printf("  - preço: ");
            printf("%.2f", filiais[filial].produtos[i].preco);

            printf("  - quantidade: ");
            printf("%d", filiais[filial].produtos[i].quantidade);

            printf("  - tipo: ");
            printf("%s", filiais[filial].produtos[i].tipo);
            printf("\n");
        } else if (i == 1){
            printf("- Nenhum produto cadastrado nessa filial");
            printf("\n");
        }
        }
        printf("Valor total R$: ");
        printf("%.2f", filiais[filial].valorEmEstoque);
        printf("\n");
    }

void printAll(){
    for(int i = 1; i <= 34; i++){
        printFilial(i);
    }
    printf("\n");
    
}

void removeFilial(int filial){
    for(int i = 1; i <= 100000; i++){
        filiais[filial].valorEmEstoque = 0;
        strcpy(filiais[filial].produtos[i].nome, "");
        filiais[filial].produtos[i].preco = 0;
        filiais[filial].produtos[i].quantidade = 0;
        strcpy(filiais[filial].produtos[i].tipo, "");
    }
}

void removeAll(){
    for(int i = 1; i <= 34; i++){
        removeFilial(i);
    }
}
    