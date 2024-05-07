#ifndef LINKED_CIRC_LIST_H
#define LINKED_CIRC_LIST_H
#include <stdbool.h>

typedef struct TNo {
    int valor;
    struct TNo *prox;
} TNo;

typedef struct TCircList {
    TNo *head;
    int size;
} TCircList;


TCircList *TCircList_create();

bool TCircList_insert(TCircList *, int);

void TCircList_print(TCircList *);

#endif