#include<stdio.h>
#include<stdlib.h>
#define N 5

int queue[N];
int front=-1;
int rear=-1;

void enque()
{
    int x;
    if(rear==N-1)
    {
        printf("Queue Overflow!");
    }
    else
    {
        printf("Enter the Element to Enqueue:");
        scanf("%d",&x);
        if(front==-1 && rear==-1)
        {
            front=rear=0;
        }
        else 
        {
            rear++;
        }
        queue[rear]=x;
        printf("ELement %d was successfully enqueued",x);
    }
}
void deque()
{
    if(front == -1 && rear == -1)
    {
        printf("Queue underflow!\n");
        return;
    }
    
    printf("Element deleted was: %d\n", queue[front]);

    if(front == rear) 
    {
        front = rear = -1;
    }
    else
    {
        front++;
    }
}


void display()
{
    if(front==-1 && rear==-1)
    {
        printf("Queue Underflow!");
    }
    else{
        printf("Elements in Queue are:");
        for(int i=front;i<=rear;i++)
        {
            printf("\n%d",queue[i]);
        }
    }
}
void peek()
{
    if(front==-1 && rear==-1)
    {
        printf("Queue Underflow!");
    }
    else{
        printf("First Element of Queue is:%d",queue[front]);
    }
}

int main()
{
    int ch;
    
    while(1)
    {
        printf("\nQueue Menu\n");
        printf(" 1.Enqueue \n 2.Dequeue \n 3.Display \n 4.Peek \n 5.Exit");
        printf("\nEnter the choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            enque();
            break;
            case 2:
            deque();
            break;
            case 3:
            display();
            break;
            case 4:
            peek();
            break;
            case 5:
            return 0;
            default:
            printf("Enter the Right choice!!");
        }
    }
    return 0;
}