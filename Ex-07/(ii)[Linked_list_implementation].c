NAME: VISHWA.J
ROLL.NO: 230701384
EX-7: Implementation of Queue using LinkedList

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
} *front = NULL, *rear = NULL;


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int isEmpty() {
    return (front == NULL);
}

void enqueue(int data) {
    struct Node* newNode = createNode(data);
    if (isEmpty()) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

int dequeue() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return -1;
    } else {
        struct Node* temp = front;
        int data = temp->data;
        front = front->next;
        free(temp);
        return data;
    }
}

void displayQueue() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
    } else {
        struct Node* temp = front;
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {

    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);

    printf("Queue: ");
    displayQueue();

    printf("Dequeued element: %d\n", dequeue());
    printf("Dequeued element: %d\n", dequeue());

    printf("Queue after dequeue: ");
    displayQueue();

    return 0;
}
