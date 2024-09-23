#include <stdio.h>
#include <stdlib.h>
#include "descpriorityqueue.h"

int main() {
    PQUEUE queue = createQueue();
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
            printf("deleted %d\n", deleteQueue(&queue));
            break;
        }
    } while (ch != 3);
}