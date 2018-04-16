//A program that outputs every 2nd character of the string.

#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string s = get_string("symbols: ");
    printf("every 2nd symbol????:  \n");
    for (int i=1; i<strlen(s); i+=2)
    printf("%c\n",s[i]);
    }


