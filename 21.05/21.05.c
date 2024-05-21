#include <stdio.h>
#include <Stack.h>

int main() {
    printf("Dynamic Pile");

    printf("--interface--");
    printf("1 - Pile creation \n 2 - push \n 3 - pop \n 4 - read top \n 5 - pile delete \n 6 - print data");
    int op;
    scanf("%d", &op);
    switch 
    
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