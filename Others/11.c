//A program that calculates sigma and factorial of a number

#include <cs50.h>
#include <stdio.h>

int fact(int n)
{
    if (n==1)
    return 1;
    else
    return n * fact (n-1);
}
int sigma(int n)
{
    if (n==1)
    return 1;
    else
    return n + sigma (n-1);
}
int main (void)
{
    int n = get_int ("Integer: ");

    printf ("Sigma: %i\n", sigma(n));

    printf ("Factorial: %i\n", fact(n));
}
