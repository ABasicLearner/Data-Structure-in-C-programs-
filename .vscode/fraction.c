//Addition, subtraction, multiplication and division of two fractional numbers
#include<stdio.h>

struct fraction
{
    float num;
    float deno;
};

struct fraction n1, n2;

struct fraction addFraction(struct fraction n1, struct fraction n2)
{
    struct fraction sum;
    sum.num = n1.num*n2.deno + n1.deno*n2.num;
    sum.deno = n1.deno * n2.deno;
    return sum;
}

struct fraction subFraction(struct fraction c1, struct fraction c2)
{
    struct fraction sub;
    sub.num = n1.num*n2.deno + n1.deno*n2.num;
    sub.deno = c1.deno * c2.deno;
    return sub;
}

struct fraction mulFraction(struct fraction c1, struct fraction c2)
{
    struct fraction mul;
    mul.num = c1.num * n2.num;
    mul.deno = c1.deno * c2.deno;
    return mul;
}

struct fraction divFraction(struct fraction c1, struct fraction c2)
{
    struct fraction div;
    if(c2.num*c2.num - c2.deno*c2.deno != 0)
    {
        div.num = c1.num * c2.deno;
        div.deno = c1.deno * c2.num;
        return div;
    }
}

void main()
{
    struct fraction add, sub, mul, div;
    printf("\nEnter first fraction number, numerator part separted by a space from denominator part: ");
    scanf("%f%f", &n1.num, &n1.deno);
    printf("\nEnter second fraction number, numerator part separted by a space from denominator part: ");
    scanf("%f%f", &n2.num, &n2.deno);
    add = addFraction(n1,n2);
    sub = subFraction(n1,n2);
    mul = mulFraction(n1,n2);
    div = divFraction(n1,n2);
    printf("\nSum of fraction numbers is: (%f) / (%f)", add.num, add.deno);
    printf("\nSubtraction of fraction numbers is: (%f) / (%f)", sub.num, sub.deno);
    printf("\nMultiplication of fraction numbers is: (%f) / (%f)", mul.num, mul.deno);
    printf("\nDivision of fraction numbers is: (%f) / (%f)", div.num, div.deno);
}