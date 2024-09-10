#include <stack.h>

#include <stdio.h>

Stack *createStack() {
    Stack *stack = malloc(sizeof(Stack));
    if (stack == NULL) {
        return NULL;
    }

    stack->top = NULL;
    stack->size = 0;
    return stack;
}

int push(Stack* stack, void* data) {
    if (stack == NULL) return -1;
    if (data == NULL) return -1;

    StackNode *newNode = malloc(sizeof(StackNode));
    if (newNode == NULL) {
        return -1;
    }

    newNode->data = data;
    newNode->last = stack->top;

    stack->top = newNode;
    stack->size++;
    return 0;
}

void* pop(Stack* stack) {
    if (stack == NULL) return NULL;
    if (stack->top == NULL) return NULL;

    StackNode *top = stack->top;
    stack->top = top->last;
    stack->size--;

    void *data = top->data;
    free(top);
    return data;
}

void* peak(Stack* stack) {
    if (stack == NULL) return NULL;
    if (stack->top == NULL) return NULL;

    return stack->top->data;
}

void printStack(Stack* stack) {
    if (stack == NULL) return;
    if (stack->top == NULL) return;

    StackNode *current = stack->top;
    while (current != NULL) {
        printf("%p\n", current->data);
        current = current->last;
    }
}
