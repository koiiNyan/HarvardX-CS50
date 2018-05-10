//Simple calculations using functions

#include <stdio.h>
#include <cs50.h>

int sum (int a, int b)
{
    return a + b;
}

int subt (int a, int b)
{
    return a - b;
}

int mult (int a, int b)
{
    return a * b;
}

int divi (int a, int b)
{
    return a / b;
}

int main (void)
{
    int a = get_int ("a= ");
    int b = get_int ("b= ");
    printf ("Sum= %i \n", sum(a,b));
    printf ("Subt= %i \n", subt(a,b));
    printf ("Mult= %i \n", mult(a,b));
    printf ("Divide= %i \n", divi(a,b));
}
