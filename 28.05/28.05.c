#include <stdio.h>
#include "Stack.h"
#include <stdlib.h>
#include <stdbool.h>
#include "Stack.c"

int main() {
    printf("Dynamic Stack\n");
    printf("--------------");
    printf("\n--interface--\n");

    START:
    printf("\n 1 - Stack creation \n 2 - push \n 3 - pop \n 4 - read top \n 5 - print data \n 6 - destroy stack\n 7 - compare parenthesis\n");
    int op, value;
    while ((getchar()) != '\n');
    scanf("%d", &op);
    while ((getchar()) != '\n');
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
            printf(" 1 - all \n 2 - size \n 3 - if is empty or full \n");
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
        case 7:
            //Escreva um programa que utilize uma pilha para verificar se expressões aritméticas estão com a parentização correta.
            // O programa deve verificar expressões para ver se cada “abre parênteses” tem um “fecha parênteses” correspondente
            // e se estão na ordem correta. Por exemplo, a expressão (a+b) está correta, mas a expressão )a+b( não está.
            printf("verificar se expressões aritméticas estão com a parentização correta\n");
            char input[1000];
            printf("Enter the expression: ");

            scanf("%s", input);

            //flush input buffer
            while ((getchar()) != '\n');

            Stack *parenthesis = Stack_create(1);
            bool correct = true;
            for (int i = 0; input[i] != '\0'; i++) {
                if (input[i] == '(') {
                    Stack_push(parenthesis, 1);
                } else if (input[i] == ')') {
                    if (Stack_is_empty(parenthesis)) {
                        correct = false;
                        break;
                    }
                    if(Stack_pop(parenthesis, &value)) {
                        continue;
                    } else {
                        correct = false;
                        break;
                    }
                }
            }
            if (correct && Stack_is_empty(parenthesis)) {
                printf("\n");
                printf("Parentização correta");
                printf("\n");
            } else {
                printf("\n");
                printf("Parentização incorreta");
                printf("\n");
            }
        default:
            printf("Invalid option");
            break;
    } 
    goto START;
    return 0;
}