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

void enqueue(int item)
{
    q.rear++;
    q.a[q.rear] = item;
}

int dequeue()
{   
    int item;
    q.front++;
    item = q.a[q.front];
    return item;
}

int peak()
{
    int item;
    item = q.a[q.front];
    return item;
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

void display()
{
    for(int i = q.front+1; i <= q.rear; i++)
        printf("%d\t", q.a[i]);
}

void main()
{
    int n, data;
    initqueue();

    while(1)
    {
    printf("\n\n1)Insert:\n2)Delete:\n3)Peak:\n4)Display:\n5)Exit:\n");
    printf("\nEnter your choice: ");
    scanf("%d", &n);

    switch(n)
    {
        case 1: printf("\nEnter data: ");
                scanf("%d", &data);
                enqueue(data);
                break;

        case 2: data = dequeue();
                printf("\nDeleted item is: %d", data);
                break;

        case 3: data = peak();
                printf("\nFirst element is: %d", data);
                break;

        case 4: printf("\nQueue data is as follows: ");
                display();
                break;

        case 5: exit(0);

        default : printf("\nInvalid input!");
    }
    }
}