//A program that asks for your name, prints it out, then gets your next answer, if it is one of 2 possible answers,
//you get a motivation sentence, if not, you get a smiley.

#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)

{
    string s = get_string ("What is your name?: ");
    printf ("Hello, %s\n", s);



    string t = get_string ("How are you?: ");
    if (strcmp(t, "Good")==0)
    {
        printf ("Have a nice day!\n");
    }
    else if (strcmp(t, "Bad")==0)
    {
        printf ("Dont worry!\n");
    }
    else
    {
        printf ("C:\n");
    }
}
