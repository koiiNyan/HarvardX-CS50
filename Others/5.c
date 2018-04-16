//A simple +/- calculator, that asks for 2 ints and then asks either you want to do a plus or a minus calculation.

#include <cs50.h>
#include <stdio.h>

int main (void)
{
    int x = get_int ("x: ");
    int y = get_int ("y: ");
    char z;

    do
    {
       z = get_char ("+/-: ");
    }
    while (z != '+' && z != '-');


    if (z == '+')
    {
        printf ("%i + %i = %i", x, y, x+y);
    }
    else if (z == '-')
    {
        printf ("%i - %i = %i", x, y, x-y);
    }
    {
        printf ("\n");
    }
}
