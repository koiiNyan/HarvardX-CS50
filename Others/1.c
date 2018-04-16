//* A program that inputs for a string of characters
//* and outputs every character +2
//* (Exmp: 123 -> 345; 567 -> 789; 163 -> 385; abc -> cde etc.)

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    string s = get_string("");


 for (int i = 0, n = strlen(s); i < n; i++)
        {
                int j = s[i] + 2;
                printf("%c ", j);
            }

        {
            printf ("\n");
        }

}
