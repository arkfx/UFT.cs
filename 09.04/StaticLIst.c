#include "StaticList.h"
#include <stdio.h>
#include <stdlib.h>
#define MAX 5

struct _list {
  unsigned int qty;
  int data[MAX];
};

StaticList *StaticList_create() {
  StaticList *list = (StaticList *)malloc(sizeof(StaticList));
  if (list != NULL) {
    list->qty = 0;
  }
  return list;
}

/**
 * Busca por um elemento;
 * @param StaicList ponteiro para a lista estática
 * @param value valor a ser buscado
 * @param int* ponteiro para que seja gravada a posição do elemento buscado,
 * caso seja encontrado.
 * @return true se a busca foi bem sucedida, false caso contrário
 */
bool StaticList_search(StaticList *list, int valor, int *index) {
  // Tentar encontrar o valor no vetor dados da lista
  for (int i = 0; i < list->qty; i++)
    if (list->data[i] == valor) // encontrei!
    {
      *index = i;
      return true;
    }
  return false;
}
/**
 * Inserção de um elemento na lista;
 * @param list ponteiro para a lista estática
 * @param value valor a ser inserido
 * @return true se a inserção foi bem sucedida, false caso contrário
 */
bool StaticList_insert(StaticList *list, int novoItem) {
  if (!StaticList_is_full(list)) {
    list->data[list->qty++] = novoItem;
    return true;
  }
  return false;
}

/**
 * Tenta remover um elemento da lista;
 * @param StaticList* ponteiro para a lista estática
 * @param value valor a ser removido
 * @return true se a remoção foi bem sucedida, false caso contrário
 */
bool StaticList_remove(StaticList *list, int valor) {
  int index;
  if (StaticList_search(list, valor, &index)) {
    for (int i = index; i < list->qty - 1; i++)
      list->data[i] = list->data[i + 1];
    list->qty--;
    return true;
  }
  return false;
}

bool StaticList_is_full(StaticList *list) { return list->qty == MAX; }

void StaticList_print(StaticList *list) {
  for (int i = 0; i < list->qty; i++)
    printf("%d, ", list->data[i]);
  putchar('\n');
}

unsigned int StaticList_size(StaticList *list) { return list->qty; }
