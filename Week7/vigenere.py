# A program that encrypts messages using Vigenère’s cipher

import sys

# Check for correct number of command line arguments
if len(sys.argv) != 2 or not sys.argv[1].isalpha():
    print('Usage: python vigenere.py key (key is a character(s)')
    sys.exit(1)

# get the key
key = sys.argv[1].lower()
key_length = len(key)
ascii_key = []
for char in key:
    ascii_key.append(ord(char) - 97)

# get the plaintext
plaintext = input('plaintext: ')
# encipher
ciphertext = ''

counter = 0
for character in plaintext:

    if character.isalpha():
        if character.islower():
            new_character = chr((ord(character) + ascii_key[counter] - 97) % 26 + 97)
            counter += 1
        else:
            new_character = chr((ord(character) + ascii_key[counter] - 65) % 26 + 65)
            counter += 1
        ciphertext += new_character
    else:
        ciphertext += character
    if counter >= key_length:
        counter = 0

# print ciphertext

print('ciphertext:', ciphertext)
