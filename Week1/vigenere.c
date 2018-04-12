// A program that encrypts messages using Vigenère’s cipher

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>


int main(int argc, string argv[])
{
    // check for 2 arguments only
    if (argc != 2)
    {
        printf("Usage: ./vigenere k\n");
        return 1;
    }

    // check if alphabetical
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (!isalpha(argv[1][i]))
        {
            printf("Usage: ./vigenere k\n");

            return 1;
        }
    }

    // from string to int
    string k = argv[1];
    int klen = strlen(k);


    // check if the integer is non-negative
    if (k < 0)
    {
        printf("Usage: ./vigenere k");
        return 1;
    }
    else
    {
        // prompt the user for a code
        string code = get_string("plaintext: ");
        {
            printf("ciphertext: ");
        }
        //key letter

        for (int i = 0, j = 0, n = strlen(code); i < n; i++)

        {
            int key = k [j % klen];

            //check if the letter is uppercase or lowercase then convert
            if islower(code[i])

            {
                printf("%c", ((code[i] - 'a') + (tolower(key) - 'a')) % 26 + 'a');
                j++;
            }

            else if isupper(code[i])

            {
                printf("%c", ((code[i] - 'A') + (toupper(key) - 'A')) % 26 + 'A');
                j++;
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
