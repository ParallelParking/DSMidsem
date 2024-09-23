#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

int main() {
    NODE* head = createNode(0); //dummy node.

    int ch, n, pos;
    do {
        printf("1.ins(s),2.ins(r),3.ins(p),4.del(s),5.del(r),6.del(p),7.display,8.exit\n");
        scanf("%d", &ch);
        switch(ch) {
        case 1:
            printf("Enter no.\n");
            scanf("%d", &n);
            head = insertStart(head, n);
            break;
        case 2:
            printf("Enter no.\n");
            scanf("%d", &n);
            head = insertRear(head, n);
            break;
        case 3:
            printf("Enter no.\n");
            scanf("%d", &n);
            printf("Enter position\n");
            scanf("%d", &pos);
            head = insertPos(head, n, pos);
            break;
        case 4:
            head = deleteStart(head);
            break;
        case 5:
            head = deleteRear(head);
            break;
        case 6:
            printf("Enter position\n");
            scanf("%d", &pos);
            head = deletePos(head, pos);
            break;
        case 7:
            printf("List:\n");
            display(head);
            break;
        }
    } while (ch != 8);
}