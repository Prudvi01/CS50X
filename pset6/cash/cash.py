from cs50 import get_float

# PROMPTING THE USER TO ENTER A VAILD INPUT
while True:
    cash = get_float("change owed : ")
    if cash >= 0:
        break

# CONVERTING THE CASH INTO CENTS
cents = round(cash * 100)

quarter = 25
dime = 10
nickel = 5
penny = 1
coins = 0

# NUMBER OF QUARTERS NEEDED
coins += round(cents // quarter)
cents = cents % 25

# NUMBER OF DIMES NEEDED
coins += round(cents // dime)
cents = cents % 10

# NUMBER OF NICKELS NEEDED
coins += round(cents // nickel)
cents = cents % 5

# NUMBER OF PENNIES NEEDED
coins += round(cents // penny)
cents = cents % 1

print(coins)