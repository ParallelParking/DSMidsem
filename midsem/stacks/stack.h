#include <stdlib.h>
#include <stdio.h>
int MAX = 1000;

typedef struct {
    int* items;
    int top;
} STACK;

void stackFull(STACK* stack) {
    MAX *= 2;
    stack->items = (int*) realloc(stack->items, MAX * sizeof(int));
}

STACK createStack() {
    STACK stack;
    stack.items = (int*) malloc(MAX * sizeof(int));
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

void push(STACK* stack, int x) {
    if (isFull(*stack)) {
        stackFull(stack);
    }
    stack->items[++stack->top] = x;
}

int isEmpty(STACK stack) {
    return stack.top == -1;
}

int pop(STACK* stack) {
    if (isEmpty(*stack)) {
        printf("Empty stack!\n");
        return -1;
    }
    return stack->items[stack->top--];
}