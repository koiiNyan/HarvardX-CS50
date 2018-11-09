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


if rounded_changed_owed_cents >= quarter:
    number_of_coins = floor(rounded_changed_owed_cents / quarter)
    module = rounded_changed_owed_cents % quarter
    if module >= dime:
        number_of_coins += floor(module / dime)
        dime_module = module % dime
        if dime_module >= nickel:
            number_of_coins += floor(dime_module / nickel)
            nickel_module = dime_module % nickel
            if nickel_module:
                number_of_coins += nickel_module



elif rounded_changed_owed_cents >= dime:
    number_of_coins = floor(rounded_changed_owed_cents / dime)
    dime_module = rounded_changed_owed_cents % dime
    if dime_module >= nickel:
        number_of_coins += floor(dime_module / nickel)
        nickel_module = dime_module % nickel
        if nickel_module:
            number_of_coins += nickel_module

elif rounded_changed_owed_cents >= nickel:
    number_of_coins = floor(rounded_changed_owed_cents / nickel)


print(number_of_coins)
