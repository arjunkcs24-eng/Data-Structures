/*WAP to Implement Singly Linked List with following operations
a) Create a linked list.
b) Deletion of first element, specified element and last element in the list.
c) Display the contents of the linked list.*/

/* WAP to Implement Singly Linked List with following operations
a) Create a linked list.
b) Deletion of first element, specified element and last element in the list.
c) Display the contents of the linked list.
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;


void createSLL(int item) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = item;
    new_node->next = head;
    head = new_node;
}

void deleteAtBeg() {
    if (head == NULL) {
        printf("Linked list is empty\n");
        return;
    }
    struct node *temp = head;
    head = head->next;
    free(temp);
}


void deleteAtPos(int pos) {
    if (head == NULL) {
        printf("Linked list is empty\n");
        return;
    }

    if (pos == 1) {
        deleteAtBeg();
        return;
    }

    struct node *temp = head;
    struct node *prev = NULL;

    for (int i = 1; i < pos && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}


void deleteAtEnd() {
    if (head == NULL) {
        printf("Linked list is empty\n");
        return;
    }

    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }

    struct node *temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
}


void display() {
    if (head == NULL) {
        printf("Linked list is empty\n");
        return;
    }

    struct node *temp = head;
    printf("HEAD -> ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, item, pos;

    printf("\n--- MENU ---\n");
    printf("1. Create Linked List\n");
    printf("2. Delete at Beginning\n");
    printf("3. Delete at Position\n");
    printf("4. Delete at End\n");
    printf("5. Display\n");
    printf("6. Exit\n");

    while (1) {
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter item: ");
                scanf("%d", &item);
                createSLL(item);
                break;

            case 2:
                deleteAtBeg();
                break;

            case 3:
                printf("Enter position: ");
                scanf("%d", &pos);
                deleteAtPos(pos);
                break;

            case 4:
                deleteAtEnd();
                break;

            case 5:
                display();
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
