// Copies a BMP file

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: resize f infile outfile\n");
        return 1;
    }

    // remember size multiplier
    float f = atof(argv[1]);

    // remember filenames
    char *infile = argv[2];
    char *outfile = argv[3];

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
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

    // Define height and width
    int old_width = bi.biWidth;
    int old_height = bi.biHeight;
    int new_width = floor(old_width * f);
    int new_height = floor(old_height * f);


    // Old and new padding
    int padding = (4 - (old_width * sizeof(RGBTRIPLE)) % 4) % 4;
    int new_padding = (4 - (new_width * sizeof(RGBTRIPLE)) % 4) % 4;


    // New headers
    bi.biHeight = new_height;
    bi.biWidth = new_width;
    bi.biSizeImage = ((sizeof(RGBTRIPLE) * new_width) + new_padding) * abs(new_height);
    bf.bfSize = bi.biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);

    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // Old and new ratio
    double width = (double) old_width / (double) new_width;
    double height = (double) old_height / (double) new_height;

    // allocate a memory to store a scanline
    RGBTRIPLE scanline[old_width * sizeof(RGBTRIPLE)];
    int cached_sl = -1;

    // for all rows in the new image
    for (int i = 0, biHeight = abs(new_height); i < biHeight; i++)
    {
        int row = i * height;

        if (cached_sl != row)
        {
            fseek(inptr, sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + (((sizeof(RGBTRIPLE) * old_width) + padding) * row), SEEK_SET);
            fread(scanline, sizeof(RGBTRIPLE), old_width, inptr);
            cached_sl = row;
        }

        // for all columns in the new image
        for (int j = 0; j < new_width; j++)
        {
            // compute the X coordinate of the corresponding column in the old image
            int column = j * width;
            fwrite(&scanline[column], sizeof(RGBTRIPLE), 1, outptr);
        }

        // write new padding
        for (int j = 0; j < new_padding; j++)
        {
            fputc(0x00, outptr);
        }
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}