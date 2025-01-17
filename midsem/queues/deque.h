#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

typedef struct {
    int items[MAX];
    int front;
    int rear;
} DEQUE;

DEQUE createQueue() {
    DEQUE queue;
    queue.front = -1;
    queue.rear = -1;
    return queue;
}

int isFull(DEQUE queue) {
    return queue.rear == MAX - 1 && queue.front == 0;
}

int isEmpty(DEQUE queue) {
    return queue.front == -1 && queue.rear == -1;
}

void insertRear(DEQUE* queue, int x) {
    if (isFull(*queue)) {
        printf("Queue full");
        exit(0);
    }
    if (queue->rear == MAX - 1) {
        printf("invalid");
        exit(0);
    }
    if (isEmpty(*queue)) {
        queue->rear = 0;
        queue->front = 0;
    }
    queue->items[++queue->rear] = x;
}

void insertFront(DEQUE* queue, int x) {
    if (isFull(*queue)) {
        printf("Queue full");
        exit(0);
    }
    if (queue->front == 0) {
        printf("invalid");
        exit(0);
    }
    if (isEmpty(*queue)) {
        queue->rear = 0;
        queue->front = 0;
    }
    queue->items[queue->front] = x;
}

int deleteRear(DEQUE* queue) {
    if (isEmpty(*queue)) {
        printf("Queue empty");
        exit(0);
    }
    int del = queue->items[queue->rear--];
    if (queue->rear == queue->front) {
        queue->front = -1;
        queue->rear = -1;
    }
    return del;
}

int deleteFront(DEQUE* queue) {
    if (isEmpty(*queue)) {
        printf("Queue empty");
        exit(0);
    }
    int del = queue->items[queue->front++];
    if (queue->rear == queue->front) {
        queue->front = -1;
        queue->rear = -1;
    }
    return del;
}