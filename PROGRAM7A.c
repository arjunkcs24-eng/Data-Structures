#include <stdio.h>
#include <stdlib.h>

struct Node{
    int info;
    struct Node*prev;
    struct Node*next;
};

struct Node*head=NULL;
struct Node*createDLL(int item){
    struct Node*p=(struct Node*)malloc(sizeof(struct Node));
    p->info=item;
    p->next=NULL;
    p->prev=NULL;
    if(head==NULL){
        head=p;
    }
    else{
        p->next=head;
        head->prev=p;
        head=p;
    }
    return head;
}

struct Node* InsertnewNode(int item,int pos){
    struct Node*p=(struct Node*)malloc(sizeof(struct Node));
    p->info=item;
    p->next=NULL;
    p->prev=NULL;
    if(head==NULL){
        printf("list empty");
    }
    if(pos==1){
        p->next=head;
        head->prev=p;
        head=p;
    }
    else{
        struct Node*temp=head;
        struct Node*follow;
        for(int i=1;i<pos&&temp!=NULL;i++){
            follow=temp;
            temp=temp->next;
        }
        if(temp==NULL){
            printf("position out of range\n");
        }
        p->next = temp;
        p->prev = follow;
        follow->next = p;
    }
    return head;
}

struct Node*DeleteNode(int val){
    struct Node*follow;
    if(head==NULL){
        printf("list is empty\n");
    }
    else{
        struct Node*temp=head;
        while(temp->next!=NULL && temp->info!=val){
            follow=temp;
            temp=temp->next;
        }
        if(temp==NULL){
            printf("value not found\n");
        }
        follow->next=temp->next;
        temp->next->prev=follow;
        free(temp);
    }
    return head;
}

void displayDLL(){
    if(head==NULL){
        printf("list is empty\n");
    }
    else{
        struct Node*temp=head;
        printf("HEAD->");
        while(temp!=NULL){
            printf("%d->",temp->info);
            temp=temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int choice, item, pos, val;

    
    printf("\n\n---- Doubly Linked List Menu ----");
    printf("\n1. Create (Insert at beginning)");
    printf("\n2. Insert at position");
    printf("\n3. Delete a node by value");
    printf("\n4. Display list");
    printf("\n5. Exit");
    while(1){
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
    

        switch (choice) {
            case 1:
                printf("Enter item to insert: ");
                scanf("%d", &item);
                createDLL(item);
                break;

            case 2:
                printf("Enter item to insert: ");
                scanf("%d", &item);
                printf("Enter position: ");
                scanf("%d", &pos);
                InsertnewNode(item, pos);
                break;

            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &val);
                DeleteNode(val);
                break;

            case 4:
                printf("Doubly Linked List: ");
                displayDLL();
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice!");
        }
    }

    return 0;
}
