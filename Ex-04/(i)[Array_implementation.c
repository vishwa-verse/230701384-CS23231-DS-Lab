#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int stack[MAX_SIZE];
int top = -1;

int isEmpty() { return top == -1; }
int isFull() { return top == MAX_SIZE; }

void push(int val) {
     if(isFull()){
         printf("\nThs stack is full!. - Stack Overflow\n");
         return;
     }
     stack[top + 1] = val;
     top++;
     return;
}

int pop() {
    if(isEmpty()) {
        printf("\nThe stack is empty!. - Stack Underflow\n");
        return -1;
    }
    int temp = stack[top];
    top--;
    return temp;
}

void displayStack() {
    if (isEmpty()) {
         printf("\nStack is Empty!. No elements to display.\n");
         return;
    }
    int i = 0;
    while(i <= top) {
        printf("%d ", stack[i]);
        i++;
    }
    printf("\n");

    return;
}

int main() {
        int choice, value;

        do {

        printf("\nMenu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display Stack\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

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
                displayStack();
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
