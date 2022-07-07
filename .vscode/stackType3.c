#include<stdio.h>
#include<stdlib.h>
#define SIZE 15

struct stack
{
    int a[SIZE];
    int top;
};

void initstack(struct stack *sp)
{
    sp->top = -1;
}

int isemptystack(struct stack *sp)
{
    if(sp->top == -1)
        return 1;
    else
        return 0;
}

int isstackfull(struct stack *sp)
{
    if(sp->top == SIZE-1)
        return 1;
    else
        return 0;
}

void push(struct stack *sp, int num)
{
    sp->top++;
    sp->a[sp->top]=num;
}

int pop(struct stack *sp)
{
    int item;
    item = sp->a[sp->top];
    sp->top--;
    return item;
}

int peak(struct stack *sp)
{
    int item;
    item = sp->a[sp->top];
    return item;
}

void display(struct stack *sp)
{
    int i;
    for(i=sp->top; i>=0; i--)
        printf("%d\t", sp->a[i]);
}

void main()
{
    struct stack s;
    int ch, num;
    initstack(&s);

    while(1)
    {
        printf("\n1)Push:\n2)Pop:\n3)Peak:\n4)Display:\n5)Exit:\n");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1: printf("\nEnter item: ");
                    scanf("%d", &num);
                    push(&s, num);
                    break;
            case 2: num = pop(&s);
                    printf("\nItem popped: %d\n", num);
                    break;
            case 3: num = peak(&s);
                    printf("\nTop item= %d\n", num);
                    break;
            case 4: printf("\nContent of stack: ");
                    display(&s);
                    break;
            case 5: exit(0);
        }   //end of switch
    }   //end of while
}  //end of main
