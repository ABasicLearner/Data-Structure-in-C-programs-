//Addition, subtraction, multiplication and division of two complex numbers
#include<stdio.h>

struct complex
{
    float real;
    float img;
};

struct complex c1, c2;

struct complex addComplex(struct complex c1, struct complex c2)
{
    struct complex sum;
    sum.real = c1.real + c2.real;
    sum.img = c1.img + c2.img;
    return sum;
}

struct complex subComplex(struct complex c1, struct complex c2)
{
    struct complex sub;
    sub.real = c1.real - c2.real;
    sub.img = c1.img - c2.img;
    return sub;
}

struct complex mulComplex(struct complex c1, struct complex c2)
{
    struct complex mul;
    mul.real = c1.real * c2.real - c1.img * c2.img;
    mul.img = c1.real * c2.img + c2.real * c1.img;
    return mul;
}

struct complex divComplex(struct complex c1, struct complex c2)
{
    struct complex div;
    if(c2.real*c2.real - c2.img*c2.img != 0)
    {
        div.real = (c1.real*c2.real + c1.img*c2.img)/ (c2.real*c2.real - c2.img*c2.img);
        div.img = (c1.img*c2.real - c1.real*c2.img) / (c2.real*c2.real - c2.img*c2.img);
        return div;
    }
}

void main()
{
    struct complex add, sub, mul, div;
    printf("\nEnter first complex number, real part separted by a space from imaginary part: ");
    scanf("%f%f", &c1.real, &c1.img);
    printf("\nEnter second complex number, real part separted by a space from imaginary part: ");
    scanf("%f%f", &c2.real, &c2.img);
    add = addComplex(c1,c2);
    sub = subComplex(c1,c2);
    mul = mulComplex(c1,c2);
    div = divComplex(c1,c2);
    printf("\nSum of complex numbers is: (%f) + (%f)i", add.real, add.img);
    printf("\nSubtraction of complex numbers is: (%f) + (%f)i", sub.real, sub.img);
    printf("\nMultiplication of complex numbers is: (%f) + (%f)i", mul.real, mul.img);
    printf("\nDivision of complex numbers is: (%f) + (%f)i", div.real, div.img);
}