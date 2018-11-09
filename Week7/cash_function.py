from math import floor

dollars = input('Change owed: ')
while not dollars or dollars.isalpha() or float(dollars) <= 0:
    dollars = input('Change owed: ')
rounded_changed_owed_cents = round((float(dollars)) * 100)
number_of_coins = 0

quarter = 25
dime = 10
nickel = 5
penny = 1

def coins_counting(cents,modulus):
    global number_of_coins

    if modulus != 0:
        number_of_coins += floor(cents / modulus)
        new_cents = cents % modulus
        if new_cents >= dime:
            coins_counting(new_cents,dime)
        elif new_cents >= nickel:
            coins_counting(new_cents,nickel)
        elif new_cents >= penny:
            number_of_coins += 1

    return number_of_coins


print(coins_counting(rounded_changed_owed_cents,quarter))
