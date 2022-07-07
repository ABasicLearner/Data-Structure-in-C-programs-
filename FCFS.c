#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

struct queue 
{
    int a[SIZE];
    int front, rear;  
};

struct queue q;

void initqueue()
{
    q.front = q.rear = -1;
}

int isqueueempty()
{
    if(q.front == q.rear)
        return 1;
    else 
        return 0;
}

int isqueuefull()
{
    if(q.rear == SIZE-1)
        return 1;
    else
        return 0;
}

void insert(int item)
{
    if(isqueuefull() != 1)
    {
        q.rear++;
        q.a[q.rear] = item;
    }
    else
        printf("\nSorry! Can't take more then 10 processes entry!");
}

float dequeue()
{  
    if(isqueueempty() != 1)
    { 
        int item;
        q.front++;
        item = q.a[q.front];
        return item;
    }
    else
        return -1;
}

void display()
{
    for(int i = q.front+1; i <= q.rear; i++)
        printf("%d\t", q.a[i]);
}

void main()
{
    int n, item;
    printf("\nHow many processes?:  ");
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        printf("\nEnter burst time of process%d:  ", i+1);
        scanf("%d", &item);
        insert(item);     
    }
    printf("\nThe processes will get CPU in order as foloows: \n");
    display();
}
