#include <stdio.h>
#include <stdlib.h>

#define SIZE 10   // You can change this

int deque[SIZE];
int front = -1, rear = -1;

// ================== INSERT FRONT ===================
void insertFront(int value) {
    if ((front == 0 && rear == SIZE - 1) || (front == rear + 1)) {
        printf("Deque is FULL!\n");
        return;
    }

    if (front == -1) {  // First element
        front = rear = 0;
    } 
    else if (front == 0) {
        front = SIZE - 1;
    } 
    else {
        front--;
    }

    deque[front] = value;
}

// ================== INSERT REAR ===================
void insertRear(int value) {
    if ((front == 0 && rear == SIZE - 1) || (front == rear + 1)) {
        printf("Deque is FULL!\n");
        return;
    }

    if (front == -1) {  // First element
        front = rear = 0;
    } 
    else if (rear == SIZE - 1) {
        rear = 0;
    } 
    else {
        rear++;
    }

    deque[rear] = value;
}

// ================== DELETE FRONT ===================
void deleteFront() {
    if (front == -1) {
        printf("Deque is EMPTY!\n");
        return;
    }

    int val = deque[front];
    printf("Deleted from front: %d\n", val);

    if (front == rear) { // Only one element
        front = rear = -1;
    } 
    else if (front == SIZE - 1) {
        front = 0;
    } 
    else {
        front++;
    }
}

// ================== DELETE REAR ===================
void deleteRear() {
    if (rear == -1) {
        printf("Deque is EMPTY!\n");
        return;
    }

    int val = deque[rear];
    printf("Deleted from rear: %d\n", val);

    if (front == rear) { // Only one element
        front = rear = -1;
    } 
    else if (rear == 0) {
        rear = SIZE - 1;
    } 
    else {
        rear--;
    }
}

// ================== DISPLAY ===================
void display() {
    if (front == -1) {
        printf("Deque is EMPTY!\n");
        return;
    }

    printf("Deque elements: ");

    int i = front;
    while (i != rear) {
        printf("%d ", deque[i]);
        i = (i + 1) % SIZE;
    }
    printf("%d\n", deque[rear]);
}

// ================== MAIN ===================
int main() {
    int choice, value;

    while (1) {
        printf("\n--- DOUBLE ENDED QUEUE ---\n");
        printf("1. Insert Front\n");
        printf("2. Insert Rear\n");
        printf("3. Delete Front\n");
        printf("4. Delete Rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertFront(value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertRear(value);
                break;

            case 3:
                deleteFront();
                break;

            case 4:
                deleteRear();
                break;

            case 5:
                display();
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }
}
