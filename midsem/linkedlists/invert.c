#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

int main() {
    NODE* head = createNode(0);
    while (1) {
        int n, ch;
        printf("1.enter element,2.reverse\n");
        scanf("%d", &ch);
        if (ch == 2) break;
        printf("Enter: "); scanf("%d", &n);
        head = insertRear(head, n);
    }
    display(head);
    NODE* revhead = createNode(0);
    NODE* trav;
    for (trav = head->next; trav->next != NULL; trav = trav->next);
    revhead->next = trav; //new head.
    while (head->next != NULL) {
        NODE* prev = head;
        while (prev->next->next != NULL) {
            prev = prev->next;
        }
        prev->next->next = prev;
        prev->next = NULL;
    }
    revhead = deleteRear(revhead); //delete old head.
    head = revhead;
    display(head);

    return 0;
}