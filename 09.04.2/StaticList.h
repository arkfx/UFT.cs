#ifndef STATICLIST_H
#define STATICLIST_H
#include <stdbool.h>

typedef struct _list StaticList;

/**
 * Cria instâncias da StaticList;
 * @return ponteiro para a instância criada
 */
StaticList *StaticList_create();
/**
 * Libera os recursos de memória de uma lista estática;
 * @param list ponteiro para a lista estática
 */
void StaticList_delete(StaticList *);

/**
 * Inserção de um elemento na lista;
 * @param list ponteiro para a lista estática
 * @param value valor a ser inserido
 * @return true se a inserção foi bem sucedida, false caso contrário
 */
bool StaticList_insert(StaticList *, int);
/**
 * Busca por um elemento;
 * @param StaicList ponteiro para a lista estática
 * @param value valor a ser buscado
 * @param int* ponteiro para que seja gravada a posição do elemento buscado,
 * caso seja encontrado.
 * @return true se a busca foi bem sucedida, false caso contrário
 */
bool StaticList_search(StaticList *, int, int *);
/**
 * Tenta remover um elemento da lista;
 * @param StaticList* ponteiro para a lista estática
 * @param value valor a ser removido
 * @return true se a remoção foi bem sucedida, false caso contrário
 */
bool StaticList_remove(StaticList *, int);

// Funções auxiliares :
/**
 * Retorna o Tamanho atual da lista;
 * @param StaticList* ponteiro para a lista estática
 * @return tamanho atual da lista
 */
unsigned int StaticList_size(StaticList *);
/**
 * Retorna se a lista está vazia
 * @param StaticList* ponteiro para a lista estática
 * @return true se a lista está vazia, false caso contrário
 */
bool StaticList_is_empty(StaticList *);
/**
 * Retorna se a lista está cheia
 * @param StaticList* ponteiro para a lista estática
 * @return true se a lista está cheia, false caso contrário
 */
bool StaticList_is_full(StaticList *);
/**
 * Imprime a lista formatada;
 * @param StaticList* ponteiro para a lista estática
 */
void StaticList_print(StaticList *);
#endif