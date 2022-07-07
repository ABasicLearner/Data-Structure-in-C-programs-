#include <stdio.h>
//#include "mystack.h"

void main()
{
    int num, rem;
    printf("\nEnter decimal number: ");
    scanf("%d", &num);

    initstack();
    while(1)
    {
        rem = num%2;
        push(rem);
        num = num/2;
    }
    printf("Binary equivalent= ");
    while(isemptystack()==0)
        printf("%d", pop());
}