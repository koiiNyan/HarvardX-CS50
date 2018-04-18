//A program that checks if the letter is a vowel or a consonant

#include <stdio.h>
#include <cs50.h>

int main()
{
    char c;
    int lowvow, upvow;

    c = get_char("Letter: ");


   lowvow = (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'); //Check if lower case is a vowel
    upvow = (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'); //Check if upper case is a vowel

    if (lowvow || upvow)
        {
            printf("%c is a vowel\n", c);
        }

    else
        {
            printf("%c is a consonant\n", c);
        }
}
