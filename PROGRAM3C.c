#include <stdio.h>
#define MAX 10

int pq[MAX];
int size = 0;   
void insert(int x) {
    if(size == MAX) {
        printf("\nQueue Overflow! Cannot insert %d\n", x);
        return;
    }

    
    int i = size - 1;
    while(i >= 0 && pq[i] < x) {
        pq[i + 1] = pq[i];
        i--;
    }
    pq[i + 1] = x;
    size++;

    printf("\nInserted %d into priority queue.\n", x);
}


void del() {
    if(size == 0) {
        printf("\nQueue Underflow! Priority Queue is empty.\n");
        return;
    }

    printf("\nDeleted element: %d\n", pq[0]);

    
    for(int i = 1; i < size; i++) {
        pq[i - 1] = pq[i];
    }
    size--;
}


void display() {
    if(size == 0) {
        printf("\nPriority Queue is empty.\n");
        return;
    }

    printf("\nPriority Queue (highest priority first):\n");
    for(int i = 0; i < size; i++) {
        printf("%d ", pq[i]);
    }
    printf("\n");
}

int main() {
    int choice, value;

    while(1) {
        printf("\n----- Menu -----\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(value);
                break;
            case 2:
                del();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("\nExiting program...\n");
                return 0;
            default:
                printf("\nInvalid choice! Try again.\n");
        }
    }
}
