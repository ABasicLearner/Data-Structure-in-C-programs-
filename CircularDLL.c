#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int data;
    struct node *next, *prev;
};

#define NODEALLOC (struct node *)malloc(sizeof(struct node))

struct node *start;

void createCirDLLlist(int n)
{   
    int i, num;
    struct node *t, *last;
    printf("\nEnter data: ");
    for(i = 0; i < n; i++)
    {
        printf("\nEnter data for node%d:  ", i+1);
        scanf("%d", &num);
        t = NODEALLOC;
        t->data = num;
        t->next = NULL;
        t->prev = NULL;
        if(start->next == NULL)
        {
            start->next = t;
            last = t;
        }
        else
        {
            last->next = t;
            last = t;
        }
    }   //end of for
    last->next = start;  
}   //end of function

void display()
{
    struct node *t = start->next;
    while(t != start)
    {
        printf("%d\t", t->data);
        t = t->next;
    } //end of while
}   //end of display

void addAtBegin(int num)
{
    int i;
    struct node *t;
    t = NODEALLOC;
    t->data = num;
    t->next = NULL;
    t->prev = NULL;
    if(start->next == NULL)
        start->next= t;
    else
    {
        start->next->prev = t;
        t->next = start->next;
        start->next = t;
    }
}

void addAtEnd(int num)
{
    int i;
    struct node *t, *p;
    t = NODEALLOC;
    t->data = num;
    t->next = NULL;
    t->prev = NULL;
    if(start->next == NULL)
        start->next= t;
    else
    {
        p = start->next;
        while(p->next != start)
            p = p->next;
        t->prev = p;
        p->next = t;
        t->next = start;
        start->prev = t;
    }
}

void addAfterPos(int num, int pos)
{
    int i, position=1;
    struct node *t, *p;
    t = NODEALLOC;
    t->data = num;
    t->next = NULL;
    t->prev = NULL;
    
    for(p = start; (p->next != start)&&(position <= pos); position++)
        p = p->next;

    if(position == pos+1)
    {
        t->next = p->next;
        t->prev = p;
        p->next->prev = t;
        p->next = t;
        
    }
    else
        printf("\nSorry! Position is out of range.");
    
}


void main()
{
    int n, pos, num1, num2, num3;
    printf("\nHow many nodes? : ");
    scanf("%d", &n);
    start = NODEALLOC;
    start->next = NULL;

    createCirDLLlist(n);
    printf("\nLinked list is as follows: ");
    display();

    printf("\nEnter element to add at the beginning of the linked list: ");
    scanf("%d", &num1);
    addAtBegin(num1);
    display();

    printf("\nEnter element to add at the end of the linked list: ");
    scanf("%d", &num2);
    addAtEnd(num2);
    display();

    printf("\nEnter the position at which you want to insert the node: ");
    scanf("%d", &pos);
    printf("\nEnter the elementto add at position %d: ", pos);
    scanf("%d", &num3);
    addAtPos(num3, pos);
    display();
}
