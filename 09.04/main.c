#include "StaticList.h"
#include <stdio.h>

void insertUI(StaticList *list) {
  int value;
  printf("Digite o valor a ser inserido: ");
  if (scanf("%d", &value) == 1) {
    if (StaticList_insert(list, value))
      puts("Inserido com sucesso!");
    else
      puts("Não foi possível inserir!");
  }
}

void removeUI(StaticList *list) {
  int value;
  printf("Digite o valor a ser removido: ");
  if (scanf("%d", &value) == 1) {
    if (StaticList_remove(list, value))
      puts("Removido com sucesso!");
    else
      puts("Não foi possível remover!");
  }
}

void searchUI(StaticList *list) {
  int value, index;
  printf("Digite o valor a ser buscado: ");
  if (scanf("%d", &value) == 1) {
    if (StaticList_search(list, value, &index))
      printf("Encontrado na posição %d\n", index);
    else
      puts("404 Not found!");
  }
}

int menuUI() {
  printf("Mundo da lista!\n1-> Inserir\n2-> "
         "Buscar\n3-> Remover\n4-> Imprimir\n0-> Sair\n");
  int op;
  return (scanf("%d", &op) == 1) ? op : 0;
}

int main(void) {

  StaticList *lista1 = StaticList_create();
  

  return 0;
}