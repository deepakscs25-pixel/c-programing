#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node * next;
};


struct node *top = NULL;


struct node *front = NULL;
struct node *rear = NULL;


struct node* createNode(int value) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (!newnode) {
        printf("Memory allocation error\n");
        return NULL;
    }
    newnode->data = value;
    newnode->next = NULL;
    return newnode;
}


void push(int value){
    struct node *newnode = createNode(value);
    
    if(top == NULL){
        top = newnode;
    }
    else{
        newnode->next = top; 
        top = newnode;       
    }
    printf("Pushed %d to Stack\n", value);
}

void pop(){
    if(top == NULL){
        printf("Stack Underflow (Empty)\n");
    }
    else{
        struct node *temp = top;
        printf("Popped element: %d\n", temp->data);
        top = top->next; 
        free(temp);      
    }
}

void displayStack() {
    struct node *temp = top;
    if(top == NULL) {
        printf("Stack is Empty\n");
        return;
    }
    printf("Stack: ");
    while(temp != NULL) {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
}



void enque(int value){
    struct node *newnode = createNode(value);
    
    if (front == NULL){
        front = rear = newnode; 
    }
    else{
        rear->next = newnode; 
        rear = newnode;       
    }
    printf("Enqueued %d to Queue\n", value);
}

void deque(){
    if (front == NULL){
        printf("Queue Underflow (Empty)\n");
    }
    else {
        struct node *temp = front;
        printf("Dequeued element: %d\n", temp->data);
        
        front = front->next; 
        
        if (front == NULL) {
            rear = NULL;
        }
        
        free(temp);
    }
}

void displayQueue() {
    struct node *temp = front;
    if(front == NULL) {
        printf("Queue is Empty\n");
        return;
    }
    printf("Queue: ");
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}


int main()
{
    int choice, val;
    
    while(1) {
        printf("\n--- MENU ---\n");
        printf("1. Stack Push\n2. Stack Pop\n3. Display Stack\n");
        printf("4. Queue Enque\n5. Queue Deque\n6. Display Queue\n7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &val);
                push(val);
                break;
            case 2:
                pop();
                break;
            case 3:
                displayStack();
                break;
            case 4:
                printf("Enter value to enqueue: ");
                scanf("%d", &val);
                enque(val);
                break;
            case 5:
                deque();
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
    return 0;
}