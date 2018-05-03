#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv [])
{
    //ensure that the program accepts exactly one command-line argument, the name of a forensic image from which to recover JPEGs.

    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover card.raw\n");
        return 1;
    }

    //Filename
    char *file = argv [1]; //ptr to char

    //Open file
    FILE *fileptr = fopen(file, "r");  //ptr to file, new variable

    if (fileptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", file);
        return 2;
    }

    //Buffer for reading
    typedef uint8_t BYTE; // A uint8_t is an unsigned 1 byte data type, or a BYTE,      typedef => makes uint8_t and BYTE synonyms

    BYTE buffer[512]; // declaring a buffer of 512 bytes. The size of each element in the array of 512 elements is 1 byte.

    int img_count = 0; //Keeping track of the numbers of imgs, initializing their counter
    FILE *img = NULL; //new jpg file


    //reading until EOF
    while (fread(buffer, 512, 1, fileptr) == 1)  // data, size, number, inptr

    {

        //checking first pixels to find out if JPG
        if (buffer [0] == 0xff &&
            buffer [1] == 0xd8 &&
            buffer [2] == 0xff &&
            (buffer [3] & 0xf0) == 0xe0)


        {
            //Is the first jpg?
            if (img == NULL)
            {
                //Creating new file
                char filename [8]; //creating an array to store 8 characters (###.jpg + \0)
                sprintf(filename, "%03i.jpg", img_count);
                img = fopen(filename, "w");
                img_count ++;

                {
                    if (img != NULL)
                    {

                        //write jpeg to the created img
                        fwrite(buffer, 512, 1, img);
                    }
                }
            }

            //Not the first jpg

            else
            {
                //close last jpg
                fclose(img);

                //Creating new file
                char filename [8]; //creating an array to store 8 characters (###.jpg + \0)
                sprintf(filename, "%03i.jpg", img_count);
                img = fopen(filename, "w");
                img_count ++;


                //write jpeg to the created img
                {
                    fwrite(buffer, 512, 1, img);
                }
            }


        }

        else
        {
            if (img != NULL) //found a jpg
            {
                fwrite(buffer, 512, 1, img);
            }
        }
    }


    //closing files
    fclose(fileptr);
    fclose(img);

    return 0;
}

