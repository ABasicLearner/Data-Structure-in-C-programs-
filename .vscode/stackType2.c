#include<stdio.h>
#include<stdlib.h>
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
    s.top++;
    s.a[s.top] = num;
}

int pop()
{
    return(s.a[s.top--]);
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

void display()
{
    int i;
    for(i=s.top; i>=0; i--)
        printf("%d\t", s.a[i]);
}

int main()
{
    int ch, num;
    initstack();

    while(1)
    {
        printf("\n1)Push:\n2)Pop:\n3)Peak:\n4)Display:\n5)Exit:\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1: printf("\nEnter item: ");
                    scanf("%d", &num);
                    push(num);
                    break;
            case 2: num = pop();
                    printf("\nItem popped: %d\n", num);
                    break;
            case 3: num = peak();
                    printf("\nTop item= %d\n", num);
                    break;
            case 4: printf("\nContent of stack: ");
                    display();
                    break;
            case 5: exit(0);
        }   //end of switch
    }   //end of while
    return 0;
}   //end of main