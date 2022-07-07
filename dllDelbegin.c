#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node *next;
    struct node *prev;

};

#define NODEALLOC (struct node *)malloc(sizeof(struct node))
struct node *start = NULL;

void createlist(int n)
{
    struct node *t, *last;
    int i, num;
    for(i=0; i<n; i++)
    {
    printf("Enter data for node%d\n", i+1);
    scanf("%d", &num);
    t = NODEALLOC;
    t->data = num;
    t->prev = NULL;
    t->next = NULL;

    if(start == NULL)
    {
        start = t;
        last = t;
    }  //end of if
    else
    {
        last->next = t;
        t->prev = last;
        last = t;
    }  //end of else
    }  //end of for
}   //end of create function

void display()
{
    struct node *t;
    if(start == NULL)
        printf("\nLinked list is empty!");
    else
    {
        for(t=start; t != NULL; t=t->next)
            printf("%d\t", t->data);
    }
}

void delbegin()
{
    struct node *t;
    if(start == NULL)
    {
        printf("\nLinked list is empty!");
        return;
    }
    t = start;
    start = t->next;
    free(t);
}

void main()
{
    int n, num;
    printf("\nHow many nodes?: ");
    scanf("%d", &n);
    createlist(n);
    display();
    delbegin();
    printf("\n");
    display();
}