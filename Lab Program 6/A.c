#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node * next;
};


void createlist(struct node **head, int n)
{
    struct node *newnode;
    struct node *temp = *head; 
    int data, i;

    if (n <= 0) 
    {
        printf("no of node must be greater than 0\n");
        return;
    }

    for (i = 1; i <= n; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));

        printf("enter data for node %d : ", i);
        scanf("%d", &data);
        newnode->data = data;
        newnode->next = NULL;

        if (*head == NULL)
        {
            *head = newnode;
        }
        else
        {   
            if(temp != NULL) { 
                temp->next = newnode; 
            }
        }
        
        temp = newnode;
    }
    printf("linked list created successfully\n");
}

void display(struct node *head)
{
    if (head == NULL)
    {
        printf("list is empty\n");
        return;
    }
    
    struct node *temp = head;
    printf("\nlist elements are: ");
    while(temp != NULL)
    {
        printf("%d ", temp->data); 
        if(temp->next != NULL) printf(", "); 
        temp = temp->next;
    }
    printf("\n");
}

void sortlist(struct node **head)
{
    struct node *i, *j;
    int tempdata;

    if (*head == NULL) return;

    for (i = *head; i->next != NULL; i = i->next)
    {
        for (j = i->next; j != NULL; j = j->next)
        {
            if (i->data > j->data)
            {
                tempdata = i->data;
                i->data = j->data;
                j->data = tempdata;
            }
        }
    }
}

struct node * cancatenate(struct node *l1, struct node *l2)
{
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;

    struct node *temp = l1;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    
    temp->next = l2;
    
    return l1; 
}

struct node * reverselist(struct node *head)
{
    struct node *prev = NULL, *curr = head, *next = NULL;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev; 
}

int main()
{
    struct node *head1 = NULL;
    struct node *head2 = NULL;
    

    printf("Creating List 1:\n");
    createlist(&head1, 5);
    display(head1);
    
    printf("\nSorted List of List 1:");
    sortlist(&head1);
    display(head1);
    
    printf("\nReversed List of List 1:");
    head1 = reverselist(head1);
    display(head1);
    
    printf("\nCreating List 2:\n");
    createlist(&head2, 3);
    display(head2);

    printf("\nConcatenated List:");
    head1 = cancatenate(head1, head2);
    display(head1);

    return 0;
}