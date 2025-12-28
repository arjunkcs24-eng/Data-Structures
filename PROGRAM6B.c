#include <stdio.h>
#include <stdlib.h>

/* Node structure */
struct node {
    int data;
    struct node *next;
};

struct node *top = NULL;     // For stack
struct node *front = NULL;   // For queue
struct node *rear = NULL;

/* -------- STACK OPERATIONS -------- */

void push(int value) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    printf("Pushed %d into stack\n", value);
}

void pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return;
    }
    struct node *temp = top;
    printf("Popped %d from stack\n", temp->data);
    top = top->next;
    free(temp);
}

void displayStack() {
    struct node *temp = top;
    if (temp == NULL) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

/* -------- QUEUE OPERATIONS -------- */

void enqueue(int value) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("Enqueued %d into queue\n", value);
}

void dequeue() {
    if (front == NULL) {
        printf("Queue Underflow\n");
        return;
    }
    struct node *temp = front;
    printf("Dequeued %d from queue\n", temp->data);
    front = front->next;

    if (front == NULL)
        rear = NULL;

    free(temp);
}

void displayQueue() {
    struct node *temp = front;
    if (temp == NULL) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

/* -------- MAIN FUNCTION -------- */

int main() {
    int choice, value;

    while (1) {
        printf("\n1.Push(Stack)\n2.Pop(Stack)\n3.Display Stack");
        printf("\n4.Enqueue(Queue)\n5.Dequeue(Queue)\n6.Display Queue");
        printf("\n7.Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value: ");
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
            printf("Enter value: ");
            scanf("%d", &value);
            enqueue(value);
            break;

        case 5:
            dequeue();
            break;

        case 6:
            displayQueue();
            break;

        case 7:
            exit(0);

        default:
            printf("Invalid choice\n");
        }
    }
}
