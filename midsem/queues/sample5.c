#include <stdio.h>
#include <stdlib.h>
#include "deque.h"

int main() {
    DEQUE queue = createQueue();
    int ch, n;
    do {
        printf("1.enqf,2.enqr,3.deqf,4.deqr,5.exit\n");
        scanf("%d", &ch);
        switch(ch) {
        case 1:
            printf("Enter no.\n");
            scanf("%d", &n);
            insertFront(&queue, n);
            break;
        case 2:
            printf("Enter no.\n");
            scanf("%d", &n);
            insertRear(&queue, n);
            break;
        case 3:
            printf("deleted %d\n", deleteFront(&queue));
            break;
        case 4:
            printf("deleted %d\n", deleteRear(&queue));
            break;
        }
    } while (ch != 5);
}