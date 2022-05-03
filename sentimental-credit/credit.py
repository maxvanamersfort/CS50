import sys
import re
from cs50 import get_string

amex = '^34|37[0-9]{13}$'
visa = '^4[0-9]{12}(?:[0-9]{3})?$'
mastercard = '^(5[1-5][0-9]{14}|2(22[1-9][0-9]{12}|2[3-9][0-9]{13}|[3-6][0-9]{14}|7[0-1][0-9]{13}|720[0-9]{12}))$'

cardnumber = get_string("Number: ")

length = len(str(cardnumber))

if length != 13 and length != 15 and length != 16:
    print("INVALID")
    sys.exit()


def checkLuhn(cardnumber):

    nDigits = len(str(cardnumber))
    nSum = 0
    isSecond = False

    for i in range(nDigits - 1, -1, -1):
        d = ord(cardnumber[i]) - ord('0')

        if (isSecond == True):
            d = d * 2

        nSum += d // 10
        nSum += d % 10

        isSecond = not isSecond

    if (nSum % 10 == 0):
        return True
    else:
        return False


if (checkLuhn(cardnumber) == False):
    print("INVALID")
    sys.exit()

result1 = re.match(amex, cardnumber)
if result1:
    print("AMEX")

result2 = re.match(visa, cardnumber)
if result2:
    print("VISA")

result3 = re.match(mastercard, cardnumber)
if result3:
    print("MASTERCARD")
