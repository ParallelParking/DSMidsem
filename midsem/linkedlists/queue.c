#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

int dequeue(NODE** head) {
    if ((*head)->next == NULL) {
        printf("Empty.\n");
        exit(0);
    }
    NODE* temp = (*head)->next;
    (*head)->next = temp->next;
    int x = temp->data;
    free(temp);
    return x;
}

int main() {
    NODE* head = createNode(0); //dummy node.
    //front of queue is actually head->next.

    int ch;
    do {
        printf("1.enq,2.deq,3.display,4.exit\n");
        scanf("%d", &ch);
        switch(ch) {
        case 1:
            int n;
            printf("Enter no.\n");
            scanf("%d", &n);
            head = insertRear(head, n);
            break;
        case 2:
            //head = deleteStart(head); doesnt return popped value. rewritten here.
            printf("Dequeued: %d\n", dequeue(&head));
            break;
        case 3:
            printf("Queue:\n");
            display(head);
            break;
        }
    } while (ch != 4);
}