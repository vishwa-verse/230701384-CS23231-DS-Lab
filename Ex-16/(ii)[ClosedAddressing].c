NAME: VISHWA.J
ROLL.NO: 230701384
EX-16: Implementation of collision resolution techniques(ClosedAddressing)


#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

struct Node {
    int key;
    int value;
    struct Node* next;
};

struct Node* hashTable[SIZE];

struct Node* createNode(int key, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

void insert(int key, int value) {
    int index = key % SIZE;
    struct Node* newNode = createNode(key, value);

    if (hashTable[index] == NULL) {
        hashTable[index] = newNode;
    }
    else {
        struct Node* temp = hashTable[index];
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

int search(int key) {
    int index = key % SIZE;
    struct Node* temp = hashTable[index];

    while (temp != NULL) {
        if (temp->key == key) {
            return temp->value;
        }
        temp = temp->next;
    }

    return -1;
}

void display() {
    for (int i = 0; i < SIZE; i++) {
        printf("Index %d: ", i);
        struct Node* temp = hashTable[i];
        while (temp != NULL) {
            printf("(%d, %d) ", temp->key, temp->value);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = NULL;
    }

    insert(1, 10);
    insert(2, 20);
    insert(3, 30);
    insert(4, 40);
    insert(5, 50);

    display();

    int key = 3;
    int value = search(key);
    if (value != -1) {
        printf("Value for key %d: %d\n", key, value);
    } else {
        printf("Key not found\n");
    }

    return 0;
}
