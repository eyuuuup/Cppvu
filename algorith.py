creditCard = "4388576018402626"

# Step 0: splitting the number into a a array of numbers
def split(creditCard):
    stringArray = []

    for i in creditCard:
        stringArray.append(i)

    return stringArray

print(split(creditCard))

array = split(creditCard)


# Step 1: doubling every other digit, starting from the right
def getDoubleDigits(stringArray):
    numberArray = []

    for i in range(len(stringArray)-2, -1, -2):
        numberArray.append(stringArray[i])

    print(numberArray) 

    singleDigitArray = []
    print(int(numberArray[0]) * 2)
    for i in range(len(numberArray)):
        digit = int(numberArray[i]) * 2
        singleDigitArray.append(digit)
    print(singleDigitArray)


getDoubleDigits(array)
