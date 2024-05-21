#include <stdio.h>
#include <Stack.h>

struct _stack {
    unsigned int size;
    int top;
    int *data;
};

int main() {
    printf("Dynamic Stack");

    printf("--interface--");
    printf("1 - Stack creation \n 2 - push \n 3 - pop \n 4 - read top \n 5 - stack delete \n 6 - print data");
    int op;
    scanf("%d", &op);
    switch (op) {
        case 1:
            printf("stack size: ");
            unsigned int size;
            scanf("%d", &size);
            Stack *stack = Stack_create(size);
            break;
        case 2:
            printf("Value: ");
            int value;
            scanf("%d", &value);
            if (Stack_push(stack, value)) {
                printf("Value inserted successfully");
            } else {
                printf("Failed to insert value");
            }
            break;
        case 3:
            int value;
            if (Stack_pop(stack, &value)) {
                printf("Value removed: %d", value);
            } else {
                printf("Failed to remove value");
            }
            break;
        case 4:
            printf("Top value: %d", stack->data[stack->top]);
            break;
        case 5:
            free(stack->data);
            free(stack);
            break;
        case 6:
            printf("what data do you want to print? ");
            printf("1 - all \n 2 - size 3 - if is empty or full");
            int op2;
            scanf("%d", &op2);
            switch (op2) {
                case 1:
                    for (int i = 0; i <= stack->top; i++) {
                        printf("%d ", stack->data[i]);
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
        default:
            printf("Invalid option");
            break;
    } 
    
    return 0;
}

Stack_create(unsigned int size) {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->size = size;
    stack->top = -1;
    stack->data = (int *)malloc(size * sizeof(int));
    return stack;
}

bool Stack_push(Stack *stack, int value) {
    if (Stack_is_full(stack)) {
        return false;
    }
    stack->data[++stack->top] = value;
    return true;
}

bool Stack_pop(Stack *stack, int *value) {
    if (Stack_is_empty(stack)) {
        return false;
    }
    *value = stack->data[stack->top--];
    return true;
}

uint Stack_size(Stack *stack) {
    return stack->top + 1;
}

bool Stack_is_empty(Stack *stack) {
    return stack->top == -1;
}

bool Stack_is_full(Stack *stack) {
    return stack->top == stack->size - 1;
}