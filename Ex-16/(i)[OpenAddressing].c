NAME: VISHWA.J
ROLL.NO: 230701384
EX-16: Implementation of collision resolution techniques(OpenAddressing)

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

typedef struct {
    int key;
    int value;
} Entry;

Entry hashTable[SIZE];

void initializeHashTable() {
    for (int i = 0; i < SIZE; i++) {
        hashTable[i].key = -1;
        hashTable[i].value = -1;
    }
}

int hashFunction(int key) {
    return key % SIZE;
}

void insert(int key, int value) {
    int index = hashFunction(key);

    while (hashTable[index].key != -1) {
        index = (index + 1) % SIZE;
    }

    hashTable[index].key = key;
    hashTable[index].value = value;
}

int search(int key) {
    int index = hashFunction(key);

    while (hashTable[index].key != -1) {
        if (hashTable[index].key == key) {
            return hashTable[index].value;
        }
        index = (index + 1) % SIZE;
    }

    return -1;
}

void displayHashTable() {
    printf("Hash Table:\n");
    printf("-----------\n");
    for (int i = 0; i < SIZE; i++) {
        if (hashTable[i].key != -1) {
            printf("Index %d: Key = %d, Value = %d\n", i, hashTable[i].key, hashTable[i].value);
        }
    }
}

int main() {
    initializeHashTable();

    insert(5, 10);
    insert(15, 20);
    insert(25, 30);
    insert(35, 40);

    displayHashTable();

    int key = 15;
    int value = search(key);
    if (value != -1) {
        printf("Value for key %d: %d\n", key, value);
    } else {
        printf("Key %d not found\n", key);
    }

    return 0;
}
