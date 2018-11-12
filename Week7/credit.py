# a program that determines whether a provided credit card number is valid according to Luhn’s algorithm

# Prompt for user input
user_credit_card = input('Number: ')
while not user_credit_card or user_credit_card.isalpha() or float(user_credit_card) <= 0:
    user_credit_card = input('Number: ')

# Validate number's length
credit_card_length = len(user_credit_card)

digits_to_sum = []
every_other_digit = []
# Multiply every other digit starting from the last digit
for i in range(0, credit_card_length):
    if credit_card_length % 2 ==0:
        if i < (credit_card_length / 2):
            number = (user_credit_card[-1 - (i*2 + 1)])
            every_other_digit.append(int(number)*2)
    else:
        if i < (credit_card_length / 2 -1):
            number = (user_credit_card[-1 - (i*2 + 1)])
            every_other_digit.append(int(number)*2)
# Sum those digits
okay_digits = []
for i in every_other_digit:
    if len(str(i)) == 2:
        okay_digits.append(int(str(i)[0]))
        okay_digits.append(int(str(i)[1]))
    else:
        okay_digits.append(i)

sum_of_every_other_digit = sum(okay_digits)

# Add to remaining digits
for i in range(0, credit_card_length):
    if i < (credit_card_length / 2):
        digits_to_sum.append(int(user_credit_card[-1 - (i*2)]))
total_sum = sum_of_every_other_digit + sum(digits_to_sum)


# Validate checksum
if total_sum % 10 == 0:
# Validate company's id
    if user_credit_card[0:2] == '34' or user_credit_card[0:2] == '37' and credit_card_length == 15:
        print('AMEX')
    elif user_credit_card[0:2] == '51' or user_credit_card[0:2] == '52' or user_credit_card[0:2] == '53' \
    or user_credit_card[0:2] == '54' or user_credit_card[0:2] == '55' and credit_card_length == 16:
         print('MASTERCARD')
    elif user_credit_card[0] == '4' and credit_card_length == 16 or credit_card_length == 13:
         print('VISA')
    else:
        print('INVALID')
else:
    print('INVALID')
