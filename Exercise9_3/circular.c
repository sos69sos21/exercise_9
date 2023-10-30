#include "circular.h"

void CircularInitialize(CircularQueue* q) {
    q->head = 0;
    q->tail = 0;
    q->itemCount = 0;
}

void CircularEnqueue(CircularQueue* q, int value) {
    //Insert element / value into our queue.
    if (q->itemCount < QUEUE_SIZE) {
        q->items[q->head] = value;
        q->head = (q->head + 1) % QUEUE_SIZE;
        q->itemCount++;
    } else {
        //Our queue is full here. We overwrite the oldest element / value.
        q->tail = (q->tail + 1) % QUEUE_SIZE;
        q->items[q->head] = value;
        q->head = (q->head + 1) % QUEUE_SIZE;
    }
}

int CircularDequeue(CircularQueue* q, int* pValue) {
    if (q->itemCount > 0) {
        *pValue = q->items[q->tail];
        q->tail = (q->tail + 1) % QUEUE_SIZE;
        q->itemCount--;
        return 1;
    } else {
        return 0;
    }
}