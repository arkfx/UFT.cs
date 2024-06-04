#include <stdio.h>
#include "Stack.h"
#include <stdlib.h>
#include <stdbool.h>

struct _stack {
    unsigned int size;
    int top;
    int *data;
};

Stack* Stack_create(unsigned int size) {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->size = size;
    stack->top = -1;
    stack->data = (int *)malloc(size * sizeof(int));
    return stack;
}

bool Stack_push(Stack *stack, int value) {
    if (Stack_is_full(stack)) {
        // Stack is full, increase size by one
        Stack_change_size(stack, stack->size + 1);
    }
    stack->data[++stack->top] = value;
    return true;
}

bool Stack_pop(Stack *stack, int *value) {
    if (Stack_is_empty(stack)) {
        return false;
    }
    if (Stack_size(stack) == 1) {
        *value = stack->data[stack->top];
        stack->top = -1;
        return true;
    }
    Stack_change_size(stack, stack->size - 1);
    *value = stack->data[stack->top--];
    return true;
}

uint Stack_size(Stack *stack) {
    return stack->size;
}

bool Stack_is_empty(Stack *stack) {
    return stack->top == -1;
}

bool Stack_is_full(Stack *stack) {
    return stack->top == stack->size - 1;
}

void Stack_change_size(Stack *stack, unsigned int size) {
    stack->data = (int *)realloc(stack->data, size * sizeof(int));
    stack->size = size;
    //remove elements if the new size is smaller than the current size, until the new size is reached
    while (stack->top > size) {
        printf("removing %d\n", stack->data[stack->top]);
        stack->top--;
    }
}