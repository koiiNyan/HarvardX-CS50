//A program that encrypts messages using Caesar’s cipher

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>


int main(int argc, string argv[])
{
    // check for 2 arguments only
    if (argc != 2)
    {
        printf("Usage: ./caesar k");
        return 1;
    }

    // from string to int
    int k = atoi(argv[1]);

    // check if the integer is non-negative
    if (k < 0)
    {
        printf("Usage: ./caesar k");
        return 1;
    }
    else
    {
        // prompt the user for a code
        string code = get_string("plaintext: ");
        {
            printf("ciphertext: ");
        }

        for (int i = 0, n = strlen(code); i < n; i++)
        {
            //check if the letter is uppercase or lowercase then convert
            if islower(code[i])

            {
                printf("%c", (((code[i] + k) - 97) % 26) + 97);
            }

            else if isupper(code[i])

            {
                printf("%c", (((code[i] + k) - 65) % 26) + 65);
            }

            //if its not a letter then print it without converting
            else

            {
                printf("%c", code[i]);
            }
        }

        printf("\n");
        return 0;
    }
}
