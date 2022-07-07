#include<stdio.h>

int foo(int n)
{
    if(n > 0)
        return foo(n/8);
    printf("%d", n);
}

void main()
{
    foo(1234);
}
