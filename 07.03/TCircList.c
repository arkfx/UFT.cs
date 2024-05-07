#include "TCircList.h"
#include <stddef.h>
#include <stdlib.h>

TCircList *TCircList_create() {
  TCircList *list = (TCircList *)malloc(sizeof(TCircList));
  if (list) {
    list->head = NULL;
    list->size = 0;
  }
  return list;
}

bool TCircList_insert(TCircList *list, int valor) {
  TNo *novo = (TNo *)malloc(sizeof(TNo));
  if (!novo)
    return false;
  novo->valor = valor;
  if (!list->head) {
    list->head = novo;
    novo->prox = novo;
  } else {
    TNo *aux = list->head;
    while (aux->prox != list->head)
      aux = aux->prox;
    aux->prox = novo;
    novo->prox = list->head;
  }
  list->size++;
  return true;
}

void TCircList_print(TCircList *list) {
  if (!list->head)
    return;
  TNo *aux = list->head;
  do {
    printf("%d ", aux->valor);
    aux = aux->prox;
  } while (aux != list->head);
  printf("\n");
}