#include <stdio.h>
#include "Stack.h"
#include <stdlib.h>
#include <stdbool.h>

struct _stack {
    unsigned int size;
    int top;
    int *data;
};

int main() {
    printf("Dynamic Stack\n");
    printf("--------------");
    printf("\n--interface--\n");

    START:
    printf("\n 1 - Stack creation \n 2 - push \n 3 - pop \n 4 - read top \n 5 - print data \n 6 - destroy stack\n");
    int op, value;
    scanf("%d", &op);
    switch (op) {
        case 1:
            printf("Stack Created\n");
            Stack *stack = Stack_create(1);
            break;
        case 2:
            printf("Value: ");
            scanf("%d", &value);
            if (Stack_push(stack, value)) {
                printf("Value inserted successfully");
            } else {
                printf("Failed to insert value");
            }
            break;
        case 3:
            if (Stack_pop(stack, &value)) {
                printf("Value removed: %d", value);
            } else {
                printf("Failed to remove value, stack is empty");
            }
            break;
        case 4:
            printf("Top value: %d", stack->data[stack->top]);
            break;
        case 5:
            printf("what data do you want to print? \n");
            printf("1 - all \n 2 - size \n 3 - if is empty or full \n");
            int op2;
            scanf("%d", &op2);
            switch (op2) {
                case 1:
                    printf("Data:");
                    //if stack is empty, print a message
                    if (Stack_is_empty(stack)) {
                        printf(" Stack is empty");
                    }
                    for (int i = 0; i <= stack->top; i++) {
                        printf("%d ", stack->data[i]);
                    }
                    if (Stack_is_empty(stack)){
                        printf("\n");
                        printf("Size: 0");
                    } else {
                        printf("\n");
                        printf("Size: %d", Stack_size(stack));
                    }
                    break;
                case 2:
                    printf("Size: %d", Stack_size(stack));
                    break;
                case 3:
                    if (Stack_is_empty(stack)) {
                        printf("Empty");
                    } else if (Stack_is_full(stack)) {
                        printf("Full");
                    } else {
                        printf("Not empty or full");
                    }
                    break;
                default:
                    printf("Invalid option");
                    break;
            }
            break;

        case 6:
            stack->data = NULL;
            stack->top = -1;
            stack->size = 0;
            printf("Stack destroyed");
            break;
        default:
            printf("Invalid option");
            break;
    } 
    goto START;
    return 0;
}

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