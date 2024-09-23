#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

int main() {
    STACK stack = createStack();
    int ch;
    do {
        printf("1.push,2.pop,3.exit\n");
        scanf("%d", &ch);
        switch(ch) {
        case 1:
            int x;
            printf("Enter number\n");
            scanf("%d", &x);
            push(&stack, x);
            break;
        case 2:
            printf("popped: %d\n", pop(&stack));
            break;
        }
    } while (ch != 3);
    return 0;
}