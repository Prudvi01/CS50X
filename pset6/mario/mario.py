from cs50 import get_int


# TO VALIDATE THE USER INPUT
while True:
    # TO GET AND STORE A VALUE FROM THE USER
    size = get_int("Enter : ")
    if size >= 0 and size <= 23:
        break

# TO PRINT THE PYRAMIDS
for i in range(size):
    print(" " * (size - i - 1), end="")
    print("#" * (i + 1), end="")
    print("  ", end="")
    print("#" * (i + 1), end="")
    print()