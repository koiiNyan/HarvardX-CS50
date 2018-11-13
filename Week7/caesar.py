# a program that encrypts messages using Caesar’s cipher

import sys

if len(sys.argv) != 2 or sys.argv[1].isalpha():
    print('Usage: python caesar.py key (key is a number)')
    sys.exit(1)
# get the key
key = int(sys.argv[1])
if key < 0:
    print('Usage: python caesar.py key (key is a number)')
    sys.exit(1)
# get the plaintext
plaintext = input('plaintext: ')
# encipher
ciphertext = ''
for character in plaintext:
    if character.isalpha():
        if character.islower():
            new_character = chr((ord(character) + key - 97) % 26 + 97)
        else:
            new_character = chr((ord(character) + key - 65) % 26 + 65)
        ciphertext += new_character
    else:
        ciphertext += character
# print ciphertext

print('ciphertext:', ciphertext)
