#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

struct stack 
{
    int a[SIZE];
    int top; 
};

struct stack s;
void initstack()
{
    s.top = -1;
}

void push(int num)
{
    s.top++;
    s.a[s.top] = num;
}

int pop()
{
    int item;
    item = s.a[s.top];
    s.top--;
    return item;
}

int peak()
{
    return(s.a[s.top]);
}

void display()
{
    for(int i = s.top; i>=0; i--)
        printf("%d\t", s.a[i]);
}

void main()
{
    int ch, num;
   do
    {
    printf("\n\n1)Push:\n2)Pop:\n3)Peak:\n4)Display:\n5)Exit:");
    printf("\nEnter your choice: ");
    scanf("%d", &ch);
    switch(ch)
    {
        case 1: printf("\nEnter item: ");
                scanf("%d", &num);
                push(num);
                break;

        case 2: num = pop();
                printf("\nItem popped is: %d", num);
                break;

        case 3: num = peak();
               printf("\nTop element in the stack is: %d", num);
               break;

        case 4: printf("\nItems in stack are as follows: \n");
                display();
                break; 
    }
    }while(ch<5 && ch>=1);
}
