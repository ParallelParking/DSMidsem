#include <stdlib.h>
#include <stdio.h>
#include "charstack.h"
#include <string.h>
#define MAX 1000

int getPrecedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

int main() {
    char* expr = "1*(2+3)*4";

    char prefix[MAX];
    int i = 0;

    STACK stack = createStack();

    for (int j = strlen(expr) - 1; j >= 0; j--) {
        char c = expr[j];
        if (c >= '0' && c <= '9') 
            prefix[i++] = c;
        
        else if (c == ')')
            push(&stack, c);
        
        else if (c == '(') {
            while (peek(stack) != ')')
                prefix[i++] = pop(&stack);
            pop(&stack);
        }

        else {
            while (!isEmpty(stack) && getPrecedence(peek(stack)) >= getPrecedence(c))
                prefix[i++] = pop(&stack);
            push(&stack, c);
        }
    }
    while (!isEmpty(stack))
        prefix[i++] = pop(&stack);
    prefix[i] = '\0';

    strrev(prefix);

    printf("%s", prefix);
}