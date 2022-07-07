#include<stdio.h>
#include<stdlib.h>
#define SIZE 15

int a[SIZE];       //global declaration 
int top;

void initstack()
{
    top = -1;
}

void push(int num)
{
    top++;
    a[top] = num;
}

int pop()
{
    int item;
    item = a[top];
    top--;
    return item;    //instead of these fore lines we can use 'return(a[top--])'
}

int peak()
{
    int item;
    item = a[top];
    return item;
}

int isemptystack()
{
    if(top == -1)
        return 1;     //stack is empty
    else
        return 0;     //stack is full
}

int isstackfull()
{
    if(top == SIZE-1)
        return 1;
    else
        return 0;
}

void display()
{
    int i;
    for(i=top; i>=0; i--)
        printf("%d\t", a[i]);
}

int main()
{
    int ch, num;
    initstack();

    while(1)
    {
        printf("\n\n1)Push:\n2)Pop:\n3)Peak:\n4)Display:\n5)Exit:\n");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1: printf("\nEnter item: ");
                    scanf("%d", &num);
                    push(num);
                    break;
            case 2: num = pop();
                    printf("\nItem popped= %d\n", num);
                    break;
            case 3: num = peak();
                    printf("\n Top item is = %d\n", num);
                    break;
            case 4: printf("\nContent of stack: ");
                    display();
                    break;
            case 5: exit(0);
        }  //end of switch
    }   //end of while
    return 0;
}   //end of main