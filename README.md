# HarvardX CS50 2018
### [CS50 Library for C](https://github.com/cs50/libcs50)
Here's the list of the tasks I've made for the course.


## WEEK 0: Scratch
[Link to my project in Scratch](https://scratch.mit.edu/projects/210970429/)


## WEEK 1:
### Hello
**Task:** Implement a program that prints out a simple greeting to the user, per the below.
```
$ ./hello
hello, world
```
[hello.c](/Week1/hello.c)

### Mario
**Task:** Implement a program that prints out a half-pyramid of a specified height, per the below.
```
$ ./mario
Height: 5
    ##
   ###
  ####
 #####
######
```
[mario1.c](/Week1/mario1.c)

### Mario2
**Task:** Implement a program that prints out a double half-pyramid of a specified height, per the below.
```
$ ./mario
Height: 4
   #  #
  ##  ##
 ###  ###
####  ####
```
[mario2.c](/Week1/mario2.c)

### Cash
**Task:** Implement a program that calculates the minimum number of coins required to give a user change.
```
$ ./cash
Change owed: 0.41
4
```
[cash.c](/Week1/cash.c)

### Credit
**Task:** Implement a program that determines whether a provided credit card number is valid according to Luhn’s algorithm.
```
$ ./credit
Number: 378282246310005
AMEX
```
[credit.c](/Week1/credit.c)

## WEEK 1 (continued):
### Caesar
**Task:** Implement a program that encrypts messages using Caesar’s cipher, per the below.
```
$ ./caesar 13
plaintext:  HELLO
ciphertext: URYYB
```
[caesar.c](/Week1/caesar.c)

### Vigenère
**Task:** Implement a program that encrypts messages using Vigenère cipher, per the below.
```
$ ./vigenere ABC
plaintext:  HELLO
ciphertext: HFNLP
```
[vigenere.c](/Week1/vigenere.c)

### Crack
**Task:** Implement a program that cracks passwords, per the below.
```
$ ./crack 50fkUxYHbnXGw
rofl
```
[crack.c](/Week1/crack.c)

## WEEK 2:
### Music
**Task:** 
- Learn to read sheet music.
- Learn to read code.
- Convert musical notes to frequencies.
- Synthesize songs.

[Music](/Week2/)

## WEEK 3:
### Whodunit
**Task:** Answer some questions and then implement a program that reveals a hidden message in a BMP, per the below.
```
$ ./whodunit clue.bmp verdict.bmp
```
[Whodunit](/Week3/whodunit)

### Resize (Less)
**Task:** Implement a program that resizes BMPs, per the below.
```
$ ./resize 4 small.bmp large.bmp
```
[Resize(Less)](/Week3/resizeless)

### Resize (More)
**Task:** Implement a program that resizes BMPs, per the below.
```
$ ./resize .25 large.bmp small.bmp
$ ./resize 4 small.bmp large.bmp
```
[Resize(More)](/Week3/more/resize)

### Recover
**Task:** Implement a program that recovers JPEGs from a forensic image, per the below.
```
$ ./recover
Usage: ./recover image
$ echo $?
1
```
```
$ ./recover card.raw
$ echo $?
0
```
[Recover](/Week3/recover)

## WEEK 4:
### Speller
**Task:** Implement a program that spell-checks a file, per the below.
```
$ ./speller texts/lalaland.txt
MISSPELLED WORDS

[...]
AHHHHHHHHHHHHHHHHHHHHHHHHHHHT
[...]
Shangri
[...]
fianc
[...]
Sebastian's
[...]

WORDS MISSPELLED:
WORDS IN DICTIONARY:
WORDS IN TEXT:
TIME IN load:
TIME IN check:
TIME IN size:
TIME IN unload:
TIME IN TOTAL:
```
[Speller](/Week4)

## WEEK 7: Déjà vu
### Sentimental
**Task:** Implement the below exactly as specified but in Python
- [hello.py](/Week7/hello.py)
- [mario1.py](/Week7/mario1.py)
- [mario2.py](/Week7/mario2.py)
- [cash.py](/Week7/cash.py)
- [cash_function.py](/Week7/cash_function.py)
- [credit.py](/Week7/credit.py)
- [caesar.py](/Week7/caesar.py)
- [vigenere.py](/Week7/vigenere.py)
- [crack.py](/Week7/crack.py)

### Similarities (Less)
**Task:** 
1.Implement a program that compares two files for similarities.
2.Implement a website that highlights similarities across files, a la the below.

[Similarities(Less)](/Week7/less)

### Similarities (More)
**Task:** 
1.Implement a program that measures the edit distance between two strings.
2.Implement a web app that depicts the costs of transforming one string into another.

[Similarities(More)](/Week7/similarities-more)
