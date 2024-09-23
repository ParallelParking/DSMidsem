#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main() {
    QUEUE queue = createQueue();
    int ch;
    do {
        printf("1.enq,2.deq,3.exit\n");
        scanf("%d", &ch);
        switch(ch) {
        case 1:
            int n;
            printf("Enter no.\n");
            scanf("%d", &n);
            insertQueue(&queue, n);
            break;
        case 2:
            printf("deleted %d\n1", deleteQueue(&queue));
            break;
        }
    } while (ch != 3);
}