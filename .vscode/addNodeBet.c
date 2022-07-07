#include<stdio.h>
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

void addbet(int num, int pos)
{
    int position = 1;
    struct node *t, *p;
    t = NODEALLOC;
    t->data = num;
    t->next = NULL;
    for(p = start; position < pos-1; p = p->next)
    {
        position++;
    }
    if(pos == position-1)
    {
        t->next = p->next;
        p->next = t; 
    }
    
}

void display()
{
    struct node *t;
    for(t = start; t != NULL; t = t->next)
    printf("%d\t", t->data);
}  //end of display function

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
    printf("\nAt which position?: ");
    scanf("%d", &pos);
    addbet(num, pos);
    display();

    return 0;
}
