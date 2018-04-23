//A simple calculator without using cs50 C library

#include <stdio.h>

int main(void)
{
    int x=0;
    printf("Enter the 1st number: \n");
    scanf("%i", &x);

    int y=0;
    printf("Enter the 2nd number: \n");
    scanf("%i", &y);

    printf ("%i + %i = %i\n", x, y, x+y);
    printf ("%i - %i = %i\n", x, y, x-y);
    printf ("%i * %i = %i\n", x, y, x*y);
    printf ("%i / %i = %i\n", x, y, x/y);
}
