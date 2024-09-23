#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

typedef struct {
    int items[MAX];
    int front;
    int rear;
} PQUEUE;

PQUEUE createQueue() {
    PQUEUE queue;
    queue.front = -1;
    queue.rear = -1;
    return queue;
}

int isFull(PQUEUE queue) {
    return queue.rear == MAX - 1;
}

void insertQueue(PQUEUE* queue, int x) {
    if (isFull(*queue)) {
        printf("Queue full");
        exit(0);
    }
    queue->items[++queue->rear] = x;
}

int isEmpty(PQUEUE queue) {
    return queue.front == queue.rear;
}

int deleteQueue(PQUEUE* queue) {
    if (isEmpty(*queue)) {
        printf("Queue empty");
        exit(0);
    }
    int max = queue->front + 1;
    for (int i = queue->front + 2; i <= queue->rear; i++)
        if (queue->items[i] > queue->items[max]) max = i;
    int del = queue->items[max];
    for (int i = max; i <= queue->rear; i++)
        queue->items[i] = queue->items[i + 1];
    queue->rear--;
    return del;
}