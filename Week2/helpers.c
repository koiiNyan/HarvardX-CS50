// Helper functions for music

#include <cs50.h>

#include "helpers.h"

#include <string.h>

#include <math.h>

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)

// Take text-based representation of the duration of note and turn in into how many 8 notes long it should last
//Numerator and denominator are each one digit long; have a slash between them; 1st char of the string is a num, last - denom

{
    int res = 0;

    // ascii-char to int conversion ** 48=0; 0=num, 1=/, 2=den
    int num = (int)fraction[0] - 48;
    int den = (int)fraction[2] - 48;

    if (den == 8)
    {
        res = num;
    }
    else if (num == 1 && num < 8)
    {
        res = (8 / den) * num;
    }

    return res;
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    // Parse the string into a note and its octave, figure out where in the string is the note part & the octave part

    int stCount = 0;
    int octposit = 0;
    int oct = 0;
    //Finding the position of oct

    for (stCount = 0; note[stCount] != '\0'; stCount++);
    if (stCount == 3)
    {
        octposit = 2;
    }
    if (stCount == 2)
    {
        octposit = 1;
    }

    //Transfering oct-number from alph char to actual number from ascii
    oct = (int)note[octposit] - 48;

    //Freq of the note in the oct
    double freq = 0.0;

    // Determine note letter, shifting 2 as there're 2 keys between letters, keyboard goes like C-D-E-F-G-A-B, A=440 => the letters to the left of A are divided, the letter to the right is multiplied.

    switch (note[0])
    {
        case 'A' :
            freq = 440.0;
            break;

        case 'B' :
            freq = 440.0 * (pow(2.0, (2.0 / 12.0)));
            break;

        case 'C' :
            freq = 440.0 / (pow(2.0, (9.0 / 12.0)));
            break;

        case 'D' :
            freq = 440.0 / (pow(2.0, (7.0 / 12.0)));
            break;

        case 'E' :
            freq = 440.0 / (pow(2.0, (5.0 / 12.0)));
            break;
            //between E & F there's no other keyboard
        case 'F' :
            freq = 440.0 / (pow(2.0, (4.0 / 12.0)));
            break;

        case 'G' :
            freq = 440.0 / (pow(2.0, (2.0 / 12.0)));
            break;

        default :
            return 0;
    }

    // Shifting oct(oct is a full cycle, so 2^12/12 = 2^1 = 2
    if (oct > 4)
    {
        for (int i = 0; i < oct - 4; i++)
        {
            freq *= 2.0;
        }
    }
    else if (oct < 4)
    {
        for (int i = 0; i < 4 - oct; i++)
        {
            freq /= 2.0;
        }
    }

    // Finding out if sharp or flat (sharp is a semi-tone up and flat is a semi-tone down)
    if (note[1] == '#')
    {
        freq *= (pow(2.0, (1.0 / 12.0)));
    }
    else if (note[1] == 'b')
    {
        freq /= (pow(2.0, (1.0 / 12.0)));
    }


    // Round and return freq
    return round(freq);

}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    // if s represents a rest, returns true, otherwise false; rest = blank string

    if (strcmp(s, "") == 0)   //strcmp - compare two strings
    {
        return true;
    }
    else
    {
        return false;
    }
}
