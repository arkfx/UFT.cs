#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


char ask[1000];

float rFLOAT = 0;
char  rFLOATs [1000];
bool validF = false;

char rSTRING[1000];

bool rBOOL = false;
char rCHARs[1000];

char rTIPOs[1000];
char rInTYPEs[1000];


void clearIN(){
    rFLOAT = 0;
    strcpy(rFLOATs, "");
    validF = false;

    strcpy(rSTRING, "");
    
    rBOOL = false;
    strcpy(rCHARs, "");

    strcpy(rTIPOs, "");
    strcpy(rInTYPEs, "");
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
    strchr(rFLOATs+1, '-') != NULL ||
    strncmp(rFLOATs, ".", 1) == 0 ||
    rFLOATs[strlen(rFLOATs)-1] == '.') {
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
        scanf(" %s", rFLOATs);
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
        if(strcmp(rSTRING, "//") == 0){
            Menu();
        }
        if(strlen(rSTRING) == 0){
            clearOUT();
        }
    }
}

void readBool(){
    clearIN();
    while (strcmp(rCHARs, "s") != 0 && strcmp(rCHARs, "n") != 0 && strcmp(rCHARs, "S") != 0 && strcmp(rCHARs, "N") != 0){
        printf("%s", ask);
        scanf(" %s", & rCHARs);
        if(strcmp(rCHARs, "//") == 0){
            Menu();
        }
        if(strcmp(rCHARs, "s") != 0 && strcmp(rCHARs, "n") != 0 && strcmp(rCHARs, "S") != 0 && strcmp(rCHARs, "N") != 0){
            clearOUT();
        }
    }
    if(strcmp(rCHARs, "s") == 0 || strcmp(rCHARs, "S") == 0){
        rBOOL = true;
    }
    if(strcmp(rCHARs, "n") == 0 || strcmp(rCHARs, "N") == 0){
        rBOOL = false;
    }
}

void readTipo(){
    clearIN();
    while (strcmp(rInTYPEs, "M") != 0 && strcmp(rInTYPEs, "L") != 0 && strcmp(rInTYPEs, "P") != 0){
        printf("%s", ask);
        scanf(" %s", & rInTYPEs);
        rInTYPEs[0] = toupper(rInTYPEs[0]);
        if(strcmp(rInTYPEs, "//") == 0){
            Menu();
        }
        if(strcmp(rInTYPEs, "M") != 0 && strcmp(rInTYPEs, "L") != 0 && strcmp(rInTYPEs, "P") != 0){
            clearOUT();
        }
    }
    if(strcmp(rInTYPEs, "M") == 0){
        strcpy(rTIPOs, "Merceria");
    }
    if(strcmp(rInTYPEs, "L") == 0){
        strcpy(rTIPOs, "Limpeza");
    }
    if(strcmp(rInTYPEs, "P") == 0){
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
    Produto produtos[100001];
    float valorEmEstoque;
    float porcentagemMerceria;
    float porcentagemLimpeza;
    float porcentagemPereciveis;
} Filial;
Filial filiais[35];

void Menu(){
    start:
    printf("\n");
    printf("\n");
    printf("----------------------------------------------------------------");
    printf("\n");
    printf("\n");
    float action = 0;
    while(action != 1 && action != 2 && action != 3 && action != 4){
        strcpy(ask, "1 - Adicionar produtos\n2 - Editar produtos\n3 - Remover produtos\n4 - Listar produtos\nO que deseja fazer? (1-4): ");
        readFloat();
        action = rFLOAT;
        if (action != 1 && action != 2 && action != 3 && action != 4){
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
    //printf("----Bem vindo ao sistema de estoque----");
    printf("\n");
    printf("digite // para voltar ao menu");
    printf("\n");
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

void saveFilial(int filial){
    char nomeDoArquivo[100];
    sprintf(nomeDoArquivo, "filial-%d.txt", filial);
    FILE *fp;   
    fp = fopen(nomeDoArquivo, "w");
    for (int i = 1; i <= 100000; i++){
        fprintf(fp, "%s", filiais[filial].produtos[i].nome);
        fprintf(fp, "%s", "\n");
        fprintf(fp, "%f", filiais[filial].produtos[i].preco);
        fprintf(fp, "%s", "\n");
        fprintf(fp, "%d", filiais[filial].produtos[i].quantidade);
        fprintf(fp, "%s", "\n");
        fprintf(fp, "%s", filiais[filial].produtos[i].tipo);
        fprintf(fp, "%s", "\n");
    }
    fclose(fp);
}

void saveAll(){
    for(int i = 1; i <= 34; i++){
        saveFilial(i);
    }
}

void loadFilial(int filial){
    FILE *fp;
    fp = fopen("filial.txt", "r");
    for (int i = 1; i <= 100000; i++){
        if (filiais[filial].produtos[i].nome[0] == '\0'){
            fscanf(fp, "%s", & filiais[filial].produtos[i].nome);
            fscanf(fp, "%f", & filiais[filial].produtos[i].preco);
            fscanf(fp, "%d", & filiais[filial].produtos[i].quantidade);
        }   fscanf(fp, "%s", & filiais[filial].produtos[i].tipo);
    }
    fclose(fp);
}

void loadAll(){
    for(int i = 1; i <= 34; i++){
        loadFilial(i);
    }
}