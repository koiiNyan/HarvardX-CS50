//A program that prints out each 3rd letter of the input, if it is a digit, there goes a smiley(s), if there's a blank -
//the program understands that there goes a new word and starts
//counting the 3rd letter, counting from the next character.

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    string s = get_string("");

    for (int i = 0, n = strlen(s); i < n; i++)

        {
            if isalpha(s[i])
            {
                i = i + 2;
            printf("%c", s[i]);
            }

            else if isdigit(s[i])
            {
                printf (":c ");
            }

            else
            {
                printf ("%c", s[i]);
            }
        }

}
