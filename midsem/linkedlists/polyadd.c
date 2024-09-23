#include <stdio.h>
#include <stdlib.h>
#include "polylinklist.h"

int main() {
    TERM* poly1 = createNode(0, INT_MAX);
    TERM* poly2 = createNode(0, INT_MAX);

    while (1) {
        int ch;
        printf("1.Enter poly1,2.Enter poly2,3.calculate\n");
        scanf("%d", &ch);
        if (ch == 3) break;
        int c, e;
        printf("Enter coefficient & exponent\n");
        scanf("%d%d", &c, &e);
        switch(ch) {
        case 1:
            poly1 = insert(poly1, c, e);
            break;
        case 2:
            poly2 = insert(poly2, c, e);
            break;
        }
    }
    display(poly1);
    display(poly2);

    TERM* polysum = createNode(0, INT_MAX);
    poly1 = poly1->next;
    poly2 = poly2->next;
    while (poly1 && poly2) {
        if (poly1->exp == poly2->exp) {
            polysum = insert(polysum, poly1->coeff + poly2->coeff, poly1->exp);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
        else if (poly1->exp > poly2->exp) {
            polysum = insert(polysum, poly1->coeff, poly1->exp);
            poly1 = poly1->next;
        }
        else {
            polysum = insert(polysum, poly2->coeff, poly2->exp);
            poly2 = poly2->next;
        }
    }
    while (poly1) {
        polysum = insert(polysum, poly1->coeff, poly1->exp);
        poly1 = poly1->next;
    }
    while (poly2) {
        polysum = insert(polysum, poly2->coeff, poly2->exp);
        poly2 = poly2->next;
    }

    printf("Result:\n");
    display(polysum);
}