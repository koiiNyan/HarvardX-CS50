// Converting letter to ASCII number

#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    char s = get_char("Letter: ");
    {
        printf("The ASCII value of %c is %i\n", s, (int) s);
    }
}
