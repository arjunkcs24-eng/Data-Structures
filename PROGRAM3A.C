#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void insert(int x) {
    if (rear == MAX - 1) {
        printf("Queue Overflow!\n");
    } else {
        if (front == -1) front = 0;
        queue[++rear] = x;
        printf("Inserted %d\n", x);
    }
}

void del() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow!\n");
    } else {
        printf("Deleted %d\n", queue[front]);
        front++;
    }
}

void display() {
    if (front == -1 || front > rear) {
        printf("Queue is Empty!\n");
    } else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}

int main() {
    int choice, x;

    while (1) {
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &x);
                insert(x);
                break;
            case 2:
                del();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}
