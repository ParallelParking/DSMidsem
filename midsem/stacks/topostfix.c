#include <stdlib.h>
#include <stdio.h>
#include "charstack.h"
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
    
    char postfix[MAX];
    int i = 0;

    STACK stack = createStack();

    while (*expr != '\0') {
        char c = *expr;

        if (c >= '0' && c <= '9') 
            postfix[i++] = c;

        else if (c == '(')
            push(&stack, c);

        else if (c == ')') {
            while (peek(stack) != '(')
                postfix[i++] = pop(&stack);
            pop(&stack);
        }

        else {
            while (!isEmpty(stack) && getPrecedence(peek(stack)) >= getPrecedence(c))
                postfix[i++] = pop(&stack);
            push(&stack, c);
        }
        
        expr++;
    }
    while (!isEmpty(stack))
        postfix[i++] = pop(&stack);
    postfix[i] = '\0';

    printf("%s", postfix);
}