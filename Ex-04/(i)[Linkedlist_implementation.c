#include <stdio.h>
#include <stdlib.h>

struct node {
        int val;
        struct node* next;
} *head = NULL;

struct node* createNode(int val){

        struct node* new = malloc(sizeof(struct node));

        new -> val = val;

        new -> next = NULL;

}

int isEmpty() { return head == NULL ;}

void push(int val){

        struct node* new = createNode(val);

        if(isEmpty()) {
                head = new;
                return;
        }

        new -> next = head;
        head = new;
}

int pop() {
        if(isEmpty()){
                printf("\nNo Element to Pop!. \n");
                return -1;
        }

        int tempVal = head -> val;
        struct node* tempNode = head;

        head = head -> next;

        free(tempNode);
        return tempVal;
}

void display() {
        struct node* current = head;
        if(isEmpty()){
                printf("\nThe stack is empty!\n");
                return;
        }

        while(current != NULL) {
                printf("%d ", current -> val);
                current = current -> next;
        }
        printf("\n");
        return;
}

int main(){
    int choice, value;

    do {
        printf("\nMenu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display Stack\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Perform actions based on user choice
        switch(choice) {
            case 1:
                printf("Enter the value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 4.\n");
        }
    } while(choice != 4);

    return 0;
}
