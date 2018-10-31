#define _XOPEN_SOURCE
#include <unistd.h>

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char* argv[])
{
    // check for 2 arguments only
    if (argc != 2)
    {
        printf("Usage: ./crack hash\n");
        return 1;
    }


    // Hash password
    char* hash_pass = argv[1];
    // Salt string
    char salt[3];
    salt[0] = hash_pass[0];
    salt[1] = hash_pass[1];
    salt[2] = '\0';

     // Empty string for storing max 5 characters.
    char plaintext[5] = "";



    char* alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int alpha_len = strlen(alphabet);

    // Variable for founded password
    int found = 0;


// Bruteforce

// 1 char pass

    for (int first = 0; first < alpha_len; first++)
    {
        plaintext[0] = alphabet[first];
        char* crypted_pass = crypt(plaintext, salt);
        if (strcmp(hash_pass, crypted_pass) == 0)
        {
            printf("%s\n", plaintext);
            found = 1;
        }

    }


// 2 char pass

    if (found == 0)
    {
        for (int first = 0; first < alpha_len; first++)
        {
            plaintext[0] = alphabet[first];

            for (int second = 0; second < alpha_len; second++)
                {
                    plaintext[1] = alphabet[second];
                    char* crypted_pass = crypt(plaintext, salt);

                    if (strcmp(hash_pass, crypted_pass) == 0)
                    {
                        printf("%s\n", plaintext);
                        found = 1;
                    }
                }
            }
        }


// 3 char pass
    if (found == 0)
    {
        for (int first = 0; first < alpha_len; first++)
        {
            plaintext[0] = alphabet[first];

            for (int second = 0; second < alpha_len; second++)
                {
                    plaintext[1] = alphabet[second];

                    for(int third = 0; third < alpha_len; third++)
                    {
                        plaintext[2] = alphabet[third];
                        char* crypted_pass = crypt(plaintext, salt);

                        if (strcmp(hash_pass, crypted_pass) == 0)
                        {
                            printf("%s\n", plaintext);
                            found = 1;
                        }
                    }
                }
        }
    }


// 4 char pass

    if (found == 0)
    {
        for (int first = 0; first < alpha_len; first++)
        {
            plaintext[0] = alphabet[first];

            for (int second = 0; second < alpha_len; second++)
                {
                    plaintext[1] = alphabet[second];

                    for(int third = 0; third < alpha_len; third++)
                    {
                        plaintext[2] = alphabet[third];

                        for(int forth = 0; forth < alpha_len; forth++)
                        {
                            plaintext[3] = alphabet[forth];
                            char* crypted_pass = crypt(plaintext, salt);

                            if (strcmp(hash_pass, crypted_pass) == 0)
                            {
                                printf("%s\n", plaintext);
                                found = 1;
                            }
                        }
                    }
                }
        }
    }



// 5 char pass
    if (found == 0)
    {
        for (int first = 0; first < alpha_len; first++)
        {
            plaintext[0] = alphabet[first];

            for (int second = 0; second < alpha_len; second++)
                {
                    plaintext[1] = alphabet[second];

                    for(int third = 0; third < alpha_len; third++)
                    {
                        plaintext[2] = alphabet[third];

                        for(int forth = 0; forth < alpha_len; forth++)
                        {
                            plaintext[3] = alphabet[forth];
                            for(int fifth = 0; fifth < alpha_len; fifth++)
                            {
                                plaintext[4] = alphabet[fifth];
                                char* crypted_pass = crypt(plaintext, salt);

                                if (strcmp(hash_pass, crypted_pass) == 0)
                                {
                                    printf("%s\n", plaintext);
                                    found = 1;
                                }
                            }
                        }
                    }
                }
        }
    }

    return 0;
}
