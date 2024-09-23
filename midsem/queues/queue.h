#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

typedef struct {
    int items[MAX];
    int front;
    int rear;
} QUEUE;

QUEUE createQueue() {
    QUEUE queue;
    queue.front = -1;
    queue.rear = -1;
    return queue;
}

int isFull(QUEUE queue) {
    return queue.rear == MAX - 1;
}

void insertQueue(QUEUE* queue, int x) {
    if (isFull(*queue)) {
        printf("Queue full");
        exit(0);
    }
    queue->items[++queue->rear] = x;
}

int isEmpty(QUEUE queue) {
    return queue.front == queue.rear;
}

int deleteQueue(QUEUE* queue) {
    if (isEmpty(*queue)) {
        printf("Queue empty");
        exit(0);
    }
    return queue->items[++queue->front];
}