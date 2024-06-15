#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int q[MAX_SIZE];
int front = 0;
int rear = -1;

void enqueue(int value) {
    if (rear == MAX_SIZE - 1) {
        printf("Queue is full\n");
        return;
    }
    rear++;
    q[rear] = value;
}

int dequeue() {
    if (front > rear) {
        printf("Queue is empty\n");
        return -1;
    }
    int item = q[front];
    front++;
    return item;
}

void display() {
    if (front > rear) {
        printf("Queue is empty\n");
        return;
    }
    for (int i = front; i <= rear; i++) {
        printf("%d ", q[i]);
    }
    printf("\n");
}

int main() {

    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();

    int item = dequeue();
    printf("Dequeued item: %d\n", item);

    display();

    return 0;
}

