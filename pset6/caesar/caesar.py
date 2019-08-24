from cs50 import get_string
import sys

# TO ENSURE CORRECT USAGE
if(len(sys.argv) != 2):
    print('Usage: python caesar.py key')
    exit(1)

print("plaintext: ", end="")
plaintext = get_string()

# TO CONVERT THE USER INPUTED KEY INTO INT
key = int(sys.argv[1])

ciphertext = ""
ckey = 0

# TO ITERATE OVER EACH CHARACTER IN plaintext
for c in (plaintext):
    ckey = ord(c) + (key)
    # IN THE CASE OF LOWER CASE LETTERS
    if c.islower():
        if ckey > 122:
            ciphertext += chr(97 + ((ckey - 97) % 26))
        else:
            ciphertext += chr(ckey)
    # IN THE CASE OF UPPER CASE LETTERS
    elif c.isupper():
        if ckey > 90:
            ciphertext += chr(65 + ((ckey - 65) % 26))
        else:
            ciphertext += chr(ckey)
    # IN THE CASE OF NEITHER LOWER CASE NOR UPPER CASE LETTERS
    else:
        ciphertext += c

print("ciphertext: ", ciphertext)