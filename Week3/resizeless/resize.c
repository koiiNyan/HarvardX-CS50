// Copies a BMP file

#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: ./resize n infile outfile\n");
        return 1;
    }

    // remember filenames
    int n = atoi(argv [1]);
    char *infile = argv[2];
    char *outfile = argv[3];

    // Check if n is a positive int <=100

    if ((n > 100) || (n < 0))
    {
        fprintf(stderr, "n should be a positive number, equal or less than 100\n");
    }

    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf, newbf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);
    newbf = bf;

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi, newbi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);
    newbi = bi;

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }


    //Changing width and height of the img by n

    newbi.biWidth = bi.biWidth * n;
    newbi.biHeight = bi.biHeight * n;


    // determine padding for scanlines
    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    int newpadding = (4 - (newbi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    //Changing size of img and size of file
    newbi.biSizeImage = ((sizeof(RGBTRIPLE) * newbi.biWidth) + newpadding) * abs(newbi.biHeight);
    newbf.bfSize = newbi.biSizeImage + 54;

    // write outfile's BITMAPFILEHEADER
    fwrite(&newbf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&newbi, sizeof(BITMAPINFOHEADER), 1, outptr);



// iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        // each row is written n times
        int rows = 0;

        while (rows < n)
        {

            // iterate over pixels in scanline
            for (int j = 0; j < bi.biWidth; j++)
            {
                // temporary storage
                RGBTRIPLE triple;

                // each pixel is written n times
                int px = 0;

                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

                // write RGB triple to outfile
                while (px < n)
                {
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                    px++;
                }
            }

            // add new padding
            for (int k = 0; k < newpadding; k++)

            {
                fputc(0x00, outptr);
            }
            // moving to the beginning

            if (rows < (n - 1))
            {
                fseek(inptr, -(bi.biWidth * sizeof(RGBTRIPLE)), SEEK_CUR);
            }
            rows++; //starting the new line
        }

        // skip over padding, if any
        fseek(inptr, padding, SEEK_CUR);
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    return 0;
}
