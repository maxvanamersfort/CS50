from cs50 import get_int

# loop for prompting the user for a height between 1 and 8
while True:
    height = get_int("height: ")
    # if the height is correct break out
    if height > 0 and height < 9:
        break

# building the pyramid
for line in range(1, (height + 1), 1):
    print(" " * (height - line), end="")
    print("#" * line, end="")
    print(" " * 2, end="")
    print("#" * line, end="")
    print()

