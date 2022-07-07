#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node *next;
};

#define NODEALLOC (struct node *)malloc(sizeof(struct node))
struct node *start = NULL;

void createlist(int n)
{
    struct node *t, *last;
    int i, num;
    printf("\nEnter data: ");
    for(i = 0; i < n; i++)
    {
        printf("\nEnter data for node%d:  ", i+1);
        scanf("%d", &num);

        t = NODEALLOC;
        t -> data = num;
        t -> next = NULL;

        if(start == NULL)
        {
            start = t;
            last = t;
        } //end of if
        else
        {
            last -> next = t;
            last = t;
        }  //end of else
    }  //end of for
}  //end of function

void display()
{
    struct node *t;
    for(t = start; t != NULL; t = t->next)
    printf("%d\t", t->data);
}  //end of display function

void addbegin(int num)
{
    struct node *t;
    t = NODEALLOC;
    t->data = num;
    t->next = NULL;
    if(start == NULL)
        start = t;
    else
    {
        t->next = start;
        start = t;
    }  //end of else
}   //end of addbegin function

void addend(int num)
{
    struct node *t, *p;
    t = NODEALLOC;
    t->data = num;
    t->next = NULL;
    if(start == NULL)
        start = t;
    else
    {
        p = start;
        while(p->next != NULL)
        p = p->next;
    p->next = t; 
    }   //end of else
}   //end of addend function

void delbegin()
{
    struct node *t;
    if(start == NULL)
    {
        printf("\nList is empty!");
        return;
    }
    t = start;
    start = t->next;
    free(t);
}

void delend()
{
    struct node *t;
    if(start == NULL)
    {
        printf("\nList is empty!");
        return;
    }
    t = start;
    while(t->next->next != NULL) 
    t = t->next;
    t->next=NULL;
    free(t->next);
}

void delbet(int pos)
{   struct node *t, *p;
    int position=1;
    if(start == NULL)
    {
        printf("\nList is empty!");
        return;
    }
    t=start;
    while(position<pos)
    {
        t = t->next;
        if(position == pos-1)
        {
            t->next = t->next->next;
        }
        position++;
    }   
}

int main()
{
    int n, num, pos;
    struct node *p;
    printf("How many nodes?: ");
    scanf("%d", &n);

    createlist(n);
    printf("\nLinked list is as follows:\n");
    display();

    printf("\nAdd new node: ");
    printf("\nEnter data: ");
    scanf("%d", &num);
    addbegin(num);
    display();
    printf("\n\n");
    delbegin();
    display();
    printf("\n\n");
    delend();
    display();
    printf("\nDelete node from any position");
    printf("\nFrom which position: ");
    scanf("%d", &pos);
    delbet(pos);
    display();
    
    return 0;
}   //end of main

