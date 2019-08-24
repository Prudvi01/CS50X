from cs50 import get_int

# TO PROMPT USER INPUT
while True:
    card = input("Enter card number :")
    if(card.isnumeric()):
        break

checksum = 0
# CONVERTING card INTO LIST
card = list(card)
length = len(card)

# TO CHANGE ALL VALUES OF card INTO INT
for i in range(length):
    card[i] = int(card[i])

# CALCULATING CHECKSUM
for i in range(length - 2, -1, -2):
    scc = (card[i]) * 2

    if (scc > 9):
        checksum += scc % 10
        scc = scc // 10

    checksum += scc

for i in range(length - 1, -1, -2):
    checksum += (card[i])

# VALIDATING THE CARD
if checksum % 10 == 0:
    if length == 15 and card[0] == 3:
        if card[1] == 4 or card[1] == 7:
            print("AMEX")

    elif length == 16 and card[0] == 5:
        if card[1] == 1 or card[1] == 2 or card[1] == 3 or card[1] == 4 or card[1] == 5:
            print("MASTERCARD")

    elif (length == 13 or length == 16) and card[0] == 4:
        print("VISA")

    else:
        print("VALID\nCannot determine the company.")
else:
    print("INVALID")
# END OF PROGRAM