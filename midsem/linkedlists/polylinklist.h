#include <stdio.h>
#include <stdlib.h>

typedef struct node TERM;

struct node {
    int coeff;
    int exp;
    struct node* next;
};

TERM* createNode(int c, int e) {
    TERM* node = (TERM*) malloc(sizeof(TERM));
    if (!node) {
        printf("heap full\n");
        exit(0);
    }
    node->coeff = c;
    node->exp = e;
    node->next = NULL;
    return node;
}

TERM* insert(TERM* head, int c, int e) {
    TERM* newnode = createNode(c, e);
    if (head->next == NULL) {
        head->next = newnode;
        return head;
    }
    TERM* trav = head->next;
    while (trav->next != NULL && e < trav->next->exp) 
        trav = trav->next;
    newnode->next = trav->next;
    trav->next = newnode;
    return head;
}

void display(TERM* head) {
    for (TERM* node = head->next; node != NULL; node = node->next) {
        printf("%dx%d\t", node->coeff, node->exp);
    }
    printf("\n");
}