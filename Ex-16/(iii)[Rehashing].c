NAME: VISHWA.J
ROLL.NO: 230701384
EX-16: Implementation of collision resolution techniques(Rehashing)


#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

struct Node {
    int data;
    struct Node* next;
};

struct HashTable {
    struct Node* table[SIZE];
};

struct HashTable* createHashTable() {
    struct HashTable* ht = (struct HashTable*)malloc(sizeof(struct HashTable));
    for (int i = 0; i < SIZE; i++) {
        ht->table[i] = NULL;
    }
    return ht;
}

int hashFunction(int key) {
    return key % SIZE;
}

void insert(struct HashTable* ht, int key) {
    int index = hashFunction(key);
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = key;
    newNode->next = NULL;

    if (ht->table[index] == NULL) {
        ht->table[index] = newNode;
    } else {
        struct Node* temp = ht->table[index];
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void display(struct HashTable* ht) {
    for (int i = 0; i < SIZE; i++) {
        printf("Index %d: ", i);
        struct Node* temp = ht->table[i];
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    struct HashTable* ht = createHashTable();

    insert(ht, 5);
    insert(ht, 15);
    insert(ht, 25);
    insert(ht, 35);
    insert(ht, 45);
    insert(ht, 55);
    insert(ht, 65);
    insert(ht, 75);
    insert(ht, 85);
    insert(ht, 95);

    display(ht);

    return 0;
}
