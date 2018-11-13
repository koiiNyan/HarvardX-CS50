# A program that cracks passwords

from sys import argv, exit
from crypt import crypt
import string

# Check for correct number of command line arguments
if len(argv) != 2:
    print('Usage: python crack.py hash')
    exit(1)
hash_pass = argv[1]
salt = hash_pass[0:2]
letters = string.ascii_letters
plaintext = ''

# Bruteforce

# 1 char pass

for first in range(0, len(letters)):
    plaintext = letters[first]
    crypted_pass = crypt(plaintext, salt)
    if hash_pass == crypted_pass:
        print(plaintext)
        exit(1)

# 2 char pass
for first in range(0, len(letters)):
    for second in range(0, len(letters)):
        plaintext = letters[first] + letters[second]
        crypted_pass = crypt(plaintext, salt)
        if hash_pass == crypted_pass:
            print(plaintext)
            exit(1)

# 3 char pass
for first in range(0, len(letters)):
    for second in range(0, len(letters)):
        for third in range(0, len(letters)):
            plaintext = letters[first] + letters[second] + letters[third]
            crypted_pass = crypt(plaintext, salt)
            if hash_pass == crypted_pass:
                print(plaintext)
                exit(1)

# 4 char pass
for first in range(0, len(letters)):
    for second in range(0, len(letters)):
        for third in range(0, len(letters)):
            for forth in range(0, len(letters)):
                plaintext = letters[first] + letters[second] + letters[third] + letters[forth]
                crypted_pass = crypt(plaintext, salt)
                if hash_pass == crypted_pass:
                    print(plaintext)
                    exit(1)

# 5 char pass
for first in range(0, len(letters)):
    for second in range(0, len(letters)):
        for third in range(0, len(letters)):
            for forth in range(0, len(letters)):
                for fifth in range(0, len(letters)):
                    plaintext = letters[first] + letters[second] + letters[third] + letters[forth] + letters[fifth]
                    crypted_pass = crypt(plaintext, salt)
                    if hash_pass == crypted_pass:
                        print(plaintext)
                        exit(1)
