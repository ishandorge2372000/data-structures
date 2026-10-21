#include <stdio.h>
#define SIZE 10
int queue[SIZE];
int front = -1;
int rear = -1;

int isFull() {
    return rear == SIZE - 1;
}

int isEmpty() {
    return front == -1 || front > rear;
}

void enqueue(int value) {
    if (isFull()) {
        printf("Queue Overflow! Cannot enqueue %d\n", value);
    } else {
        if (front == -1) front = 0; // Initialize front on first insertion
        rear++;
        queue[rear] = value;
        printf("Enqueued: %d\n", value);
    }
}

int dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow! Nothing to dequeue.\n");
        return -1;
    } else {
        int item = queue[front];
        front++;
        // Reset the queue pointers if it becomes empty
        if (front > rear) {
            front = rear = -1;
        }
        return item;
    }
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}