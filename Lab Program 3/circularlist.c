#include <stdio.h>
#include <stdlib.h>
#define N 5

int queue[N];
int front=-1, rear=-1;

void enqueue(){
    int x;
    if((rear+1) % N==front){
        printf("Queue Overflow\n");
        return;
    }
    else{
        printf("Enter the element to be inserted: ");
        scanf("%d",&x);
        if(front==-1 && rear==-1){
            front=0;
            rear=0;
        }
        else{
            rear=(rear+1) % N;
        }
        queue[rear]=x;
        printf("Element %d inserted\n",x);
    }
}

void dequeue(){
    if(rear==-1 && front==-1){
        printf("Queue Underflow\n");
        return;
    }
    else if(front==rear){
        printf("Element %d deleted\n",queue[front]);
        front=-1;
        rear=-1;
    }
    else{
        printf("Element %d deleted\n",queue[front]);
        front=(front+1) % N;
    }
}

void display(){
    int i;
    if(front==-1 && rear==-1){
        printf("Queue Underflow!\n");
        return;
    }
    printf("Queue elements: ");
    while(i!=rear){
        printf("%d ",queue[i]);
        i=(i+1) % N;
    }
    printf("%d\n",queue[rear]);
}

int main(){
    int ch;
    while(1){
        printf("\nCircular Queue Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}