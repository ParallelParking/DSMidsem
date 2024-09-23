#include <stdio.h>
#include <stdlib.h>

typedef struct node NODE;

struct node {
    int data;
    struct node* next;
};

//ALL OF THESE FUNCTIONS ASSUME A DUMMY HEADER NODE WITH NO REAL DATA.

NODE* createNode(int x) {
    NODE* node = (NODE*) malloc(sizeof(NODE));
    if (!node) {
        printf("heap full\n");
        exit(0);
    }
    node->data = x;
    node->next = NULL;
    return node;
}

NODE* insertStart(NODE* head, int x) {
    NODE* newnode = createNode(x);
    newnode->next = head->next;
    head->next = newnode;
    return head;
}

NODE* insertRear(NODE* head, int x) {
    NODE* newnode = createNode(x);
    if (head->next == head) {
        newnode->next = head->next;
        head->next = newnode;
        return head;
    }
    NODE* t = head->next;
    while (t->next != head)
        t = t->next;
    newnode->next = t->next;
    t->next = newnode;
    return head;
}

NODE* insertPos(NODE* head, int x, int pos) {
    //head->next indicates pos 1.
    NODE* prev = head;
    int curr = 1;
    while (prev->next != head && curr < pos) {
        prev = prev->next;
        curr++;
    }
    if (curr < pos) {
        printf("Cannot insert.\n");
        return head;
    }
    NODE* newnode = createNode(x);
    newnode->next = prev->next;
    prev->next = newnode;
    return head;
}

NODE* deleteStart(NODE* head) {
    if (head->next == head) {
        printf("Empty.\n");
        return head;
    }
    NODE* temp = head->next;
    head->next = temp->next;
    free(temp);
    return head;
}

NODE* deleteRear(NODE* head) {
    if (head->next == head) {
        printf("Empty.\n");
        return head;
    }
    NODE* prev = head;
    while (prev->next->next != head)
        prev = prev->next;
    free(prev->next);
    prev->next = head;
    return head;
}

NODE* deletePos(NODE* head, int pos) {
    if (head->next == head) {
        printf("Empty.\n");
        return head;
    }
    int curr = 1;
    NODE* prev = head;
    while (prev->next->next != head && curr < pos) {
        prev = prev->next;
        curr++;
    }
    if (curr < pos) {
        printf("out of range.\n");
        return head;
    }
    NODE* temp = prev->next;
    prev->next = temp->next;
    free(temp);
    return head;
}

void display(NODE* head) {
    for (NODE* node = head->next; node != head; node = node->next) {
        printf("%d\t", node->data);
    }
    printf("\n");
}