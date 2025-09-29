# include <stdio.h>
#include <stdlib.h>

# define N 5 
int stack[N];
int top = -1;

void push();
void pop();
void peek();
void display();

int main()
{
    int choice;
    while(1){
        printf("\nStack Menu\n");
        printf("\n 1.Push \n 2.Pop \n 3.Peek\n 4.display \n 5.Exit \n");
        printf("Enter your choice:");
        scanf("%d",&choice);
       
        switch(choice){
            case 1:
            push();
            break;

            case 2:
            pop();
            break;

            case 3:
            peek();
            break;

            case 4:
            display();
            break;

            case 5:
            exit(0);
            default :
            printf("Invalid choice!");
        }
    }
    return 0;
}

void push(){
    int value;
    printf("Enter the value to push: ");
    scanf("%d",&value);
    if (top==N-1){
        printf("Stack overflow! cannot push value %d", value);
    }
    else{
        top++;
        stack [top]=value;
        printf("value %d pushed successfully \n",value);
    }
}

void pop(){
    int item;
    if(top==-1){
        printf("Stack Underflow! Cannot pop from an empty stack\n");
    }
    else{
        item=stack [top];
        top--;
        printf("Poped value:%d",item);
    }
}
void peek(){
    if (top==-1){
        printf("Stack is empty! nothing to peek \n");
    }
    else{
        printf("Top ELement:%d\n",stack[top]);
    }
}

void display(){
    if (top==-1){
        printf("Stack is empty");
    }
    else{
        printf("Elements in Stack: \n");
        for(int i= top;i>=0;i--){
            printf("%d\n",stack[i]);
        }
    }
}