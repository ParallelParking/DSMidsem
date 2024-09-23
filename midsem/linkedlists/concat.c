#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

int main() {
    NODE* head1 = createNode(0);
    NODE* head2 = createNode(0);

    while (1) {
        int ch;
        printf("1.Enter list1,2.Enter list2,3.concatenate\n");
        scanf("%d", &ch);
        if (ch == 3) break;
        int n;
        printf("Enter no.\n");
        scanf("%d", &n);
        switch(ch) {
        case 1:
            head1 = insertRear(head1, n);
            break;
        case 2:
            head2 = insertRear(head2, n);
            break;
        }
    }
    display(head1);
    display(head2);
    NODE* rear1;
    for(rear1 = head1; rear1->next != NULL; rear1 = rear1->next);

    for (NODE* trav = head2->next; trav->next != NULL; trav = trav->next) {
        rear1->next = trav;
        rear1 = rear1->next;
    }
    display(head1);
}