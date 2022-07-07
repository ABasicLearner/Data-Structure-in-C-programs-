#include<stdio.h>
#include<string.h>
#include "mystack.h"

int main()
{
    char a[20];
    printf("\nEnter a string: ");
    gets(a);

    for(int i=0; a[i]!='\0'; i++)
        push(a[i]);
    printf("\nReverse of string: ");
    while(isemptystack() != 1)
        printf("%c", pop());
}