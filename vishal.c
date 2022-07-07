/*stack implementation using array*/
#include<stdio.h>
#include<stdlib.h>
#define SIZE 10      // pre-processor macro

int stack[SIZE],top=-1;

void push(int);
int pop(void);
int isfull(void);
int isempty(void);
void peek(void);
void display(void);

void main()
{
	int ch, item;
	while(1)
	{
		printf("\n1.push:\n2.pop\n3.peak\n4.display\n5.exit\n");
	
		printf("\nEnter your choice : ");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1 :	printf("\nEnter element: ");
						scanf("%d", &item);
						push(item);
						break;

			case 2 :	item = pop();
						if (item ==0)
							printf("\nStack is underflow \n");
						else
							printf("\nPopped item : %d\n", item);
						break;

			case 3 : 	peek();
						break;

			case 4 : 	display();
						break;
		
			case 5 : 	exit(0);
			
			default :	printf("\nInvalid input \n\n");
		}
	}
}

void push(int ele)
{
	if(isfull()==1)
	{
		printf("\nStack is overflow \n");
	}
	else
	{
		top++;
		stack[top] = ele;
		printf("\n%d pushed \n", ele);
	}	
}


int isfull()
{
	if(top==SIZE-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


int pop()
{
	if(isempty()==1)
	{
		return 0;
	}
	else
	{
		return(stack[top--]);
	}
}

int isempty()
{
	if(top==-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


void peek()
{
	if(isempty()==1)
	{
		printf("\nStack is empty \n");
	}
	else
	{
		printf("\nPeek element : %d \n", stack[top]);
	}
}

void display()
{
	if(isempty()==1)
	{
		printf("\nStack is empty \n");
	}
	else
	{
		int i;
		printf("\nStack element: ");
		for(i=top ; i>=0 ; i--)
		{
			printf("%d\t", stack[i]);
		}
		
	}
}