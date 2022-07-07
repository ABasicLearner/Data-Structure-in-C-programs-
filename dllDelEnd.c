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

void delend()
{
    struct node *t;
    if(start == NULL)
    {
        printf("\nLinked list is empty!");
        return;
    }
    t=start;
    while(t->next->next != NULL)
        t = t->next;
    t->next = NULL;
    free(t->next);
}

void createlist(int n)
{
    struct node *t, *last;
    int i, num;
    for(i=0; i<n; i++)
    {
    printf("\nEnter data for node%d: ", i+1);
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
    }
    }
}

void display()
{
    struct node *t;
    if(start==NULL)
        printf("\nLinked list is empty!");
    else
        for(t=start; t!=NULL; t=t->next)
            printf("%d\t", t->data);
}

void main()
{
    int n;
    printf("\nHow many nodes?: ");
    scanf("%d", &n);
    createlist(n);
    display();
    printf("\n\n");
    delend();
    display();

}