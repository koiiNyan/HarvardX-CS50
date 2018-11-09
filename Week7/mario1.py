# A program that prints out a half-pyramid of a specified height

height = input('Height: ')

while not height or height.isalpha() or int(height) < 0 or int(height) > 23:
    height = input('Height: ')


height = int(height)
for i in range(0, height):
    print((' ' * (height - i - 1)) + ('#' * (i+2)))
