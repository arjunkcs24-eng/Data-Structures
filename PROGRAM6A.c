#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};


struct Node* insertEnd(struct Node* head, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;

    if (head == NULL) return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}


void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


struct Node* sortList(struct Node* head) {
    if (head == NULL) return head;

    for (struct Node* i = head; i != NULL; i = i->next) {
        for (struct Node* j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                int temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
    return head;
}


struct Node* reverse(struct Node* head) {
    struct Node *prev = NULL, *curr = head, *next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;
    }
    return prev;
}


struct Node* concatenate(struct Node* head1, struct Node* head2) {
    if (head1 == NULL) return head2;

    struct Node* temp = head1;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = head2;
    return head1;
}

int main() {
    struct Node *list1 = NULL, *list2 = NULL;

    // create list1
    list1 = insertEnd(list1, 30);
    list1 = insertEnd(list1, 10);
    list1 = insertEnd(list1, 20);

    printf("List 1: ");
    display(list1);

    // sort
    list1 = sortList(list1);
    printf("Sorted List 1: ");
    display(list1);

    // reverse
    list1 = reverse(list1);
    printf("Reversed List 1: ");
    display(list1);

    // create list2
    list2 = insertEnd(list2, 100);
    list2 = insertEnd(list2, 200);

    printf("List 2: ");
    display(list2);

    // concatenate
    list1 = concatenate(list1, list2);
    printf("Concatenated List: ");
    display(list1);

    return 0;
}
