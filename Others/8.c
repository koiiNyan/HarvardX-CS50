//Count number of characters in the string

#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main()
{
    string c = get_string ("Enter a phrase: ");
    int x = strlen (c);
    printf("The number of characters in %s = %i\n", c, x);
    return 0;
}
