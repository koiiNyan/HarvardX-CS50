//A program that checks if the user prints a positive or a negative number.

#include <stdio.h>
#include <cs50.h>
int main()
{
    int n = get_int ("Number: ");

    // true if number is less than 0
    if (n < 0)
        {
            printf("Your number is negative\n");
        }

    // true if number is greater than 0
    else if ( n > 0)
        {
            printf("Your number is positive\n");
        }

    // if both num<0 & num>0 are false
    else
        {
            printf("Your number is 0\n");
        }
    return 0;
}
