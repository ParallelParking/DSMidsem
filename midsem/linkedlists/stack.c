#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

int pop(NODE** head) {
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
    //top of stack is actually head->next.

    int ch;
    do {
        printf("1.push,2.pop,3.display,4.exit\n");
        scanf("%d", &ch);
        switch(ch) {
        case 1:
            int n;
            printf("Enter no.\n");
            scanf("%d", &n);
            head = insertStart(head, n);
            break;
        case 2:
            //head = deleteStart(head); doesnt return popped value. rewritten here.
            printf("Popped: %d\n", pop(&head));
            break;
        case 3:
            printf("Stack:\n");
            display(head);
            break;
        }
    } while (ch != 4);
}