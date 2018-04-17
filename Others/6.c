//A program that capitalizes the 1rst letter in the word

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    string s = get_string("");

    for (int i = 0, n = strlen(s); i < n; i++)

        {
            if islower(s[0])
            {

                s[0] = toupper(s[0]);
            printf("%s", s);
            }

}
}
