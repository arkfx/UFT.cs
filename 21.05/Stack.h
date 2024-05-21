#ifndef STACK_H
#define STACK_H
#include <stdbool.h>
typedef unsigned int uint;
typedef struct _stack Stack;
/*
 * Cria instâncias de pilhas com um tamanho específico.
 * @param unsigned int size - Tamanho da pilha.
 * @return Stack* - Ponteiro para a pilha
 */
Stack *Stack_create(unsigned int size);
/**
 * Insere um elemento na pilha.
 * @param Stack* stack - Ponteiro para a pilha
 * @param int value - Valor a ser inserido
 * @return bool - true se a inserção foi bem sucedida, false caso contrário
 */
bool Stack_push(Stack *, int);
/**
 * Remove um elemento da pilha.
 * @param Stack* stack - Ponteiro para a pilha
 * @param int* value - Ponteiro para a variável que receberá o valor removido
 * @return bool - true se a remoção foi bem sucedida, false caso contrário
 */
bool Stack_pop(Stack *, int *);
/**
 * Retorna o tamanho da pilha.
 * @param Stack* stack - Ponteiro para a pilha
 * @return unsigned int - Tamanho ocupado da pilha
 */
uint Stack_size(Stack *);
/**
 * Checa se a pilha está vazia
 * @param Stack* stack - Ponteiro para a pilha
 * @return bool - true se a pilha estiver vazia, false caso contrário
 */
bool Stack_is_empty(Stack *);
/**
 * Checa se a pilha está cheia
 * @param Stack* stack - Ponteiro para a pilha
 * @return bool - true se a pilha estiver cheia, false caso contrário
 */
bool Stack_is_full(Stack *);

#endif