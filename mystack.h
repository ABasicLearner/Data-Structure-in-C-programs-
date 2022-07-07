#include<stdio.h>
#define SIZE 15

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
    s.a[s.top++] = num;
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
   int item;
   item = s.a[s.top];
   return item;
}

int isemptystack()
{
    if(s.top == -1)
         return 1;
    else
        return 0;
}

int isstackfull()
{
    if(s.top == SIZE-1)
         return 1;
    else
        return 0;
}