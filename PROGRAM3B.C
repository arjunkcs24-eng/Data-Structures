#include <stdio.h>
#define MAX 5

int cq[MAX];
int front = -1, rear = -1;

void insert(int x) {
    if ((rear + 1) % MAX == front) {
        printf("Circular Queue Overflow!\n");
    } else {
        if (front == -1)
            front = 0;
        rear = (rear + 1) % MAX;
        cq[rear] = x;
        printf("Inserted %d\n", x);
    }
}

void del() {
    if (front == -1) {
        printf("Circular Queue Underflow!\n");
    } else {
        printf("Deleted %d\n", cq[front]);
        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % MAX;
    }
}

void display() {
    if (front == -1) {
        printf("Circular Queue is Empty!\n");
    } else {
        printf("Circular Queue elements: ");
        int i = front;
        while (1) {
            printf("%d ", cq[i]);
            if (i == rear) break;
            i = (i + 1) % MAX;
        }
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
