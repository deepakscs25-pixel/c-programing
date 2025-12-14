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
            return;
        }
        
        printf("Enter the data for node %d: ", i );
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

void deleteAtFront(){
    struct node *temp=head;
    if(head==NULL){
        printf("No elements to delete");
        return;
    }
    head=head->next;
    printf("Deleted element is %d",temp->data);
    free(temp);
}

void deleteAtLast(){
    struct node * temp=head, * prev=NULL;

    if(head==NULL){
        printf("No element to Delete");
    }
    if(head->next==NULL){
        printf("Deleted element is %d",head->data);
        free(head);
       
    }
    while(temp->next!=NULL){
        prev=temp;
        temp=temp->next;
    }
    
    printf("Deleted element is %d",temp->data);
    free(temp);    
}

void deleteValue(int value){
    struct node *temp=head, *prev=NULL;
    if(head==NULL){
        printf("No elements to delete");
    }
    if(head->data==value){
        head=head->next;
        printf("Deleted element is %d",temp->data);
        free(temp);
        return;
    }
    while(temp!=NULL && temp->data!= value){
        prev=temp;
        temp=temp->next;
    }
    if(temp==NULL){
        printf("Not found");
        return;
    }
    prev->next=temp->next;
    printf("Deleted value is %d",temp->data);
    free(temp);

}

void display(){
    struct node *temp= head;
    if(head==NULL){
        printf("List is empty");
        return;
    }
    printf("Linked list: ");
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}


int main(){
    int choice, n, value;

    while(1){
        printf("\nSingly Linked List Menu:\n");
        printf("1. create Linked list\n");
        printf("2. Delete First element\n");
        printf("3. Delete Specific value\n");
        printf("4. Delete last element \n");
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
            deleteAtFront();
            break;

            case 3:
            printf("Enter the Value to delete: ");
            scanf("%d",&value);
            deleteValue(value);
            break;

            case 4:
            deleteAtLast();
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
