#include <stdlib.h>
#include <stdio.h>
#include "stack.h" //calls integer stack header file
#define MAX 1000

int main() {
    char* expr = "123+*4*";

    STACK stack = createStack();

    while (*expr != '\0') {
        char c = *expr;

        if (c >= '0' && c <= '9')
            push(&stack, c - 48);
        else {
            int y = pop(&stack);
            int x = pop(&stack);
            int r;
            switch(c) {
                case '+': r = x + y; break;
                case '-': r = x - y; break;
                case '*': r = x * y; break;
                case '/': r = x / y; break;
                default: exit(0);
            }
            push(&stack, r);
        }
        expr++;
    }
    printf("%d", pop(&stack));
}