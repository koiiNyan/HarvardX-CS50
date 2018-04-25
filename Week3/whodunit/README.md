# Questions

## What's `stdint.h`?

It's a a header file in the C standard library. It declares sets of integer types with fixed widths; typedefs and macros for them. It helps ensure code portability across the compilers.

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

The point is to take exactly 8 (16/32) bits of memory. The preffix u- is for 'unsigned'. Signed ints can be both pos and neg. Unsigned are only positive.

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

BYTE is uint8_t, unsigned 8 bits or 1 byte;
DWORD is uint32_t, unsigned 32 bits or 4 bytes;
LONG is int32_t, signed 32 bits or 4 bytes;
WORD is uint16_t, unsigned 16 bits or 2 bytes.

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

ASCII: BM
DECI: 66 77
HEXA: 0x42 0x4D

## What's the difference between `bfSize` and `biSize`?

bfSize is the size of the whole file. biSize is the size of the BITMAPINFOHEADER header file.

## What does it mean if `biHeight` is negative?

If biHeight is negative, the bitmap is a top-down DIB and its origin is the upper-left corner.

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

WORD biBitCount

## Why might `fopen` return `NULL` in lines 24 and 32 of `copy.c`?

If inptr file or outptr file don't exist

## Why is the third argument to `fread` always `1` in our code?

The 3rd argument refers to quantity (how many units of information we want to acquire).
fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr); - 1 structure BITMAPFILEHEADER;
fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr); - 1 structure BITMAPINFOHEADER;
fread(&triple, sizeof(RGBTRIPLE), 1, inptr); - 1 structure RGBTRIPLE.

## What value does line 63 of `copy.c` assign to `padding` if `bi.biWidth` is `3`?

int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
padding = ( 4 - (3 * 3) % 4) % 4 = (4 - 9 % 4) % 4 = (4 - 1) % 4 = 3 % 4 = 3.
(The size of RGBtriple is always 3 bytes)


## What does `fseek` do?

Fseek allows you to rewind or fastforward within a file.
Inside the file structure C creates an indicator of where you are in the file. You can use fseek to move that indicator forward or backward.

## What is `SEEK_CUR`?

Current position in the file.

SEEK_SET - Beginning of the file;
SEEK_CUR - Current position;
SEEK_END - EOF
