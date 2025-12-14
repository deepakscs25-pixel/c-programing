#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
    struct node *prev;
};

struct node*head=NULL;
void createList(int n){
    struct node *newnode, *temp;
    int data,i;

    if(n<=0){
        printf("Number of nodes should be greater than 0.\n");
        return;
    }

    for(i=1; i<=n; i++)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        if (newnode == NULL){
            printf("Memory allocation failed.\n");
            return;
        }
        
        printf("Enter the data for node %d: ", i );
        scanf("%d" ,&data);
        newnode->data=data;
        newnode->next=NULL;
        newnode->prev=NULL;

        if(head == NULL){
            head=newnode;
        }
        else{
            temp->next=newnode;
            newnode->prev=temp;
        }
        temp=newnode;

    }
    printf("Doubly Linked List created Successfully.\n");
}

void insertAtFront(int data){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = head;
    newnode->prev = NULL;
    if(head != NULL){
        head->prev = newnode;
    }
    head = newnode;
    printf("Inserted %d at the front.\n", data);
}

void insertAtEnd(int data){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    if(head == NULL){
        newnode->prev = NULL;
        head = newnode;
    }
    else{
        struct node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->prev = temp;
    }
    printf("Inserted %d at the end.\n", data);
}

void deleteAtValue(int value){
    struct node *temp=head;

    if(head==NULL){
        printf("No elements to delete");
        return;
    }
    while(temp!=NULL && temp->data!= value){
        temp=temp->next;
    }
    if(temp==NULL){
        printf("Value not found");
        return;
    }
    if(temp->prev != NULL){
        temp->prev->next = temp->next;
    } else {
        head = temp->next; // Deleting head
    }
    if(temp->next != NULL){
        temp->next->prev = temp->prev;
    }
    printf("Deleted value is %d",temp->data);
    free(temp);
}

void display(){
    struct node *temp= head;
    if(head==NULL){
        printf("List is empty");
        return;
    }
    printf("Doubly Linked list: ");
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

int main(){
    int choice, n, value;

    while(1){
        printf("\nDoubly Linked List Operations Menu:\n");
        printf("1. Create List\n");
        printf("2. Insert at Front\n");
        printf("3. Insert at End\n");
        printf("4. Delete by Value\n");
        printf("5. Display List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("Enter number of nodes: ");
                scanf("%d",&n);
                createList(n);
                break;
            case 2:
                printf("Enter value to insert at front: ");
                scanf("%d",&value);
                insertAtFront(value);
                break;
            case 3:
                printf("Enter value to insert at end: ");
                scanf("%d",&value);
                insertAtEnd(value);
                break;
            case 4:
                printf("Enter value to delete: ");
                scanf("%d",&value);
                deleteAtValue(value);
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
