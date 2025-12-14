#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node * next;
};

struct node * head=NULL;

void createList(int n){
    struct node *newnode, *temp;
    int data,i;

    if(n<0){
        printf("Number of nodes should be greater than 0.\n");
    }

    for(i=1; i<=n; i++)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        if (newnode == NULL){
            printf("Memory allocation failed.\n");
        }
        
        printf("Enter the data for node %d", i );
        scanf("%d" ,&data);
        newnode->data=data;
        newnode->next=NULL;

        if(head == NULL){
            head=newnode;
        }
        else{
            temp->next=newnode;
        }
        temp=newnode;

    }
    printf("Linked List created Successfully.\n");
}

void insertAtfront(int data){
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=head;
    head=newnode;
    printf("Node inserted at the Begining");
}

void insertAtend(int data){
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;

    if(head==NULL){
        head=newnode;
    }
    else{
        struct node *temp = head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
    }
    printf("Node inserted at end");
}

void insertAtPosition(int data, int pos){
    int i;
    struct node *newnode, *temp =head;

    if(pos<1){
        printf("Invalid position.\n");
    }
    if(pos==1){
        insertAtfront(data);
    }
    for(i=1;i<pos-1 && temp != NULL;i++){
        temp = temp->next;
    }

    if(temp==NULL){
        printf("Position out of range.\n");
        free(newnode);
    }

    else{
        newnode->next = temp->next;
        temp->next=newnode;  
        printf("Node inserted at position %d",pos);
    }

}

void display(){
    struct node *temp= head;
    if(head=NULL){
        printf("List is empty");
        return;
    }
    printf("Linked list: ");
    while(temp!=NULL){
        printf("%d ->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}


int main(){
    int choice, n , data , pos;

    while(1){
        printf("\nSingly Linked List Menu:\n");
        printf("1. create Linked list\n");
        printf("2. Insert at Begining\n");
        printf("3. Insert at Any Position\n");
        printf("4. Insert at End\n");
        printf("5. Display List\n");
        printf("6. Exit\n");
        printf("Enter the choice:");
        scanf("%d",&choice);

        switch(choice){
            case 1:
            printf("Enter the number of Nodes:");
            scanf("%d",&n);
            createList(n);
            break;

            case 2:
            printf("Enter the data to insert: ");
            scanf("%d",&data);
            insertAtfront(data);
            break;

            case 3:
            printf("Enter the data and position:");
            scanf("%d,%d",&data,&pos);
            insertAtPosition(data,pos);
            break;

            case 4:
            printf("Enter the data to insert: ");
            scanf("%d",&data);
            insertAtend(data);
            break;

            case 5:
            display();
            break;
            
            case 6:
            return 0;
            break;

            default:
            printf("Invalid choice!!");

        }
    }
    return 0;

}
