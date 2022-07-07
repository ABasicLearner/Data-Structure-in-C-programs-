#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

#define NODEALLOC (struct node *)malloc(sizeof(struct node))
struct node *start = NULL;

void createlist(int n)
{
    struct node *t, *last;
    int i, num;
    printf("\nEnter data:  ");
    for(i=0; i<n; i++)
    {
        printf("\nEnter data for node%d\n", i+1);
        scanf("%d", &num);
        t = NODEALLOC;
        t->data = num;
        t->prev = NULL;
        t->next = NULL;

        if(start == NULL)
        {
            start = t;
            last = t;
        }
        else
        {
            last->next = t;
            t->prev = last;
            last = t;
        }   //end of else
    }    //end of for
}    //end of createlist function

void display()
{
    struct node *t;
    for(t= start; t != NULL; t = t->next)
        printf("%d\t", t->data);
}

void addbegin(int num)
{
    struct node *t, *last;
    t = NODEALLOC;
    t->data = num;
    t->prev = NULL;
    t->next = NULL;

    if(start == NULL)
    {
        start = t;
        last = t;
    }
    else
    {
        start->prev = t;
        t->next = start;
        start = t;
    }   //end of else
}   //end of addbegin function

void addend(int num)
{
    struct node *t, *p;
    int i;
    p = NODEALLOC;
    p->data = num;
    p->prev = NULL;
    p->next = NULL;

    if(start == NULL)
    {
        start = p;
    }
    else
    {
        t= start;
        while(t->next != NULL)
            t = t->next;
        p->prev = t;
        t->next = p;
    }   //end of else
}   //end of function

int main()
{
    int n, num, item;
    printf("\nHow many nodes: ");
    scanf("%d", &n);

    createlist(n);
    printf("\nLinked list is as follows: ");
    display();
    printf("\nEnter data to add at beginning: ");
    scanf("%d", &num);
    addbegin(num);
    display();
    printf("\nEnter data to add at the end of link list: ");
    scanf("%d", &item);
    addend(item);
    display();

    return 0;
}
