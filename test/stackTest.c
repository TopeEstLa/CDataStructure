#include <stack.h>

#include <stdio.h>

void main() {
    Stack *stack = createStack();
    int a = 1;
    int b = 2;
    int c = 3;
    int d = 4;
    int e = 5;

    //Testing the append function
    printf("Testing append function\n");
    push(stack, &a);
    push(stack, &b);
    push(stack, &c);
    push(stack, &d);
    push(stack, &e);
    printStack(stack);

    //ok where are ok for append now remove
    printf("Testing remove function\n");
    int *value = (int *) pop(stack);
    printf("Popped value: %d\n", *value);
    printStack(stack);

    //now trying to get value
    printf("Testing get function\n");
    printf("%d\n", *(int *) peak(stack));

    //remove the rest of the stack
    printStack(stack);
    printf("Removing all\n");
    int size = stack->size - 1;
    for (int i = 0; i <= size; i++) {
        printf("Popped value: %d\n", *(int *) pop(stack));
    }

    printf("Empty stack\n");
    printStack(stack);
}
