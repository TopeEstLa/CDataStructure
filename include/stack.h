#ifndef STACK_H
#define STACK_H

#include <stdlib.h>

typedef struct stack_node {
    void* data;
    struct stack_node* last;
} StackNode;

typedef struct stack {
    StackNode* top;
    int size;
} Stack;

Stack* createStack();

/**
 * Add an item to the top of the stack.
 * @param stack stack to add the data to.
 * @param data data to add to the stack.
 * @return 0 if the data was added, -1 otherwise.
 */
int push(Stack* stack, void* data);

/**
 * Remove the top item from the stack.
 * @param stack stack to remove the data from.
 * @return the data that was removed or NULL if the stack is empty.
 */
void* pop(Stack* stack);

/**
 * Get the top item from the stack without removing it.
 * @param stack stack to get the data from.
 * @return the data that was removed or NULL if the stack is empty.
 */
void* peak(Stack* stack);

/**
 * Print the stack.
 * @param stack
 */
void printStack(Stack* stack);

#endif //STACK_H
