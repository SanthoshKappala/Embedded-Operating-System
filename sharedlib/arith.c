#include <stdio.h>
#include "header.h"

int main()
{
    printf("Addition is        %d\n", add(14,12));
    printf("Subtraction is     %d\n", sub(54,14));
    printf("Multiplication is  %d\n", mul(12, 4));
    printf("Division is        %d\n", div(36, 4));
    printf("Area of circle is  %f\n", area(5));
    return 0;
}