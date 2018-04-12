//A program that prints out a half-pyramid of a specified height

#include <cs50.h>
#include <stdio.h>

int main(void)


{
//Prompt user for height
    int height;
    int sp;
    int hsh;
    int i;

    do
    {
        height = get_int("Height: ");
    }
    while (height > 23 || height < 0);

//Row=i

    for (i = 0; i < height; i++)
//Spaces=sp

    {
        for (sp = 0; sp < height - i - 1; sp++)


        {
            printf(" ");
        }


//Hashes=hsh

        for (hsh = 0; hsh < i + 2; hsh++)


        {
            printf("#");
        }



//New line

        printf("\n");
    }

}
