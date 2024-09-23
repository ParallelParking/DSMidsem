#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef struct {
    int items[MAX];
    int front;
    int rear;
} CQUEUE;

CQUEUE createQueue() {
    CQUEUE queue;
    queue.front = 0;
    queue.rear = 0;
    return queue;
}

int isFull(CQUEUE queue) {
    return (queue.rear + 1) % MAX == queue.front;
}

void insertQueue(CQUEUE* queue, int x) {
    if (isFull(*queue)) {
        printf("Queue full");
        exit(0);
    }
    queue->rear = (queue->rear + 1) % MAX;
    queue->items[queue->rear] = x;
}

int isEmpty(CQUEUE queue) {
    return queue.front == queue.rear;
}

int deleteQueue(CQUEUE* queue) {
    if (isEmpty(*queue)) {
        printf("Queue empty");
        exit(0);
    }
    queue->front = (queue->front + 1) % MAX;
    return queue->items[queue->front];
}