//A program that calculates the minimum number of coins required to give a user change.

#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{

    float x;
    int c = 0;

//Prompting user for a non-negative value
    do
    {
        x = get_float("Change owed: ");
    }
    while (x <= 0);

    int m = x * 100;
    m = round(x * 100);

//Quarters

    while (m >= 25)
    {
        c++;
        m = m - 25;
    }

//Dimes

    while (m >= 10)
    {
        c++;
        m = m - 10;
    }

//Nickels

    while (m >= 5)
    {
        c++;
        m = m - 5;
    }

//Penny

    while (m >= 1)
    {
        c++;
        m = m - 1;
    }

//Coins
    {
        printf("%i\n", c);
    }

}
