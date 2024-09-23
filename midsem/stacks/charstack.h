#include <stdlib.h>
#include <stdio.h>
int MAX = 1000;

typedef struct {
    char* items;
    int top;
} STACK;

void stackFull(STACK* stack) {
    MAX *= 2;
    stack->items = (char*) realloc(stack->items, MAX * sizeof(char));
}

STACK createStack() {
    STACK stack;
    stack.items = (char*) malloc(MAX * sizeof(char));
    if (!(stack.items)) {
        printf("Heap full!\n");
        exit(0);
    } 
    stack.top = -1;
    return stack;
}

int isFull(STACK stack) {
    return stack.top == MAX - 1;
}

void push(STACK* stack, char x) {
    if (isFull(*stack)) {
        stackFull(stack);
    }
    stack->items[++stack->top] = x;
}

int isEmpty(STACK stack) {
    return stack.top == -1;
}

char pop(STACK* stack) {
    if (isEmpty(*stack)) {
        printf("Empty stack!\n");
        exit(0);
    }
    return stack->items[stack->top--];
}

char peek(STACK stack) {
    if (isEmpty(stack)) {
        printf("Empty stack!\n");
        exit(0);
    }
    return stack.items[stack.top];
}