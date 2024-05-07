#ifndef LINKED_CIRC_LIST_H
#define LINKED_CIRC_LIST_H
#include <stdbool.h>

/**
 * @struct TNo
 * @brief A node in the circular linked list.
 *
 * @var TNo::valor
 * Member 'valor' contains the value of the node.
 *
 * @var TNo::prox
 * Member 'prox' is a pointer to the next node in the list.
 */
typedef struct TNo {
    int valor;
    struct TNo *prox;
} TNo;

/**
 * @struct TCircList
 * @brief A circular linked list.
 *
 * @var TCircList::head
 * Member 'head' is a pointer to the head node of the list.
 *
 * @var TCircList::size
 * Member 'size' contains the size of the list.
 */
typedef struct TCircList {
    TNo *head;
    int size;
} TCircList;

/**
 * @brief Creates a new circular linked list.
 *
 * @return A pointer to the newly created list.
 */
TCircList *TCircList_create();

/**
 * @brief Inserts a new value into the list.
 *
 * @param list A pointer to the list.
 * @param valor The value to be inserted.
 * @return True if the insertion was successful, false otherwise.
 */
bool TCircList_insert(TCircList *, int);

/**
 * @brief Prints the list.
 *
 * @param list A pointer to the list.
 */
void TCircList_print(TCircList *);

#endif