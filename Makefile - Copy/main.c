#include <stdio.h>

int add(int,int);
int mul(int,int);

#define pi 3.14
int main()
{
    int sum, area;
    sum = add(12,14);
    printf("Addition is %d\n",sum);
    int mu = mul(5,5);
    printf("Multiplication is %d\n",mu);
    area = mu;           // area of rectangle l*b
    printf("Area of rectangle is %d\n",area);
    area = 0.5* mu;      // area of triangle 1/2* b* h
    printf("Area of triangle is %d\n", area);
    area = pi* mu;         // area of circle  3.14*r*r
    printf("Area of Circle is %d\n", area);
    return 0;
}