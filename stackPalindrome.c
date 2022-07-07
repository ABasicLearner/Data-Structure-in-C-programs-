//logical error is there somewhere
#include<stdio.h>
#include<string.h>
#include "mystack.h"
int main()
{
    int i, flag = 0;
    char ch, str[10];
    printf("Enter a string: ");
    gets(str);

    for(i=0; str[i]!='\0'; i++)
        push(str[i]);

    i=0;
    while(isemptystack() != 1)
    {
        ch = pop();
        if(str[i++] != ch)
        {
                flag = 1;
                break;
        }
    }
    if(flag == 0)
        printf("Palindrome!");
    else
        printf("Not a palindrome");
    return 0;
}