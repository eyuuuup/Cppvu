"""String that holds the credit card number."""
creditCard = "4775928289636315"

def process(creditCard):
    """Step 0: splitting the number into a a array of numbers.

    Function takes the credit card number and splits the digits into an array.
    Parameters:
        creditCard (str):The credit card number used to split.
    Returns:
        boolean from sumAndCheck.


    """
    if not(creditCard.isdigit()):
        return False

    stringArray = [x for x in creditCard]
    if (len(stringArray) < 13 or len(stringArray) > 16) :
        return False
    else :
        return getDoubleDigits(stringArray)
   

def getDoubleDigits(stringArray):
    """Step 1: doubling every other digit, starting from the right.

    Function takes the array and doubles every second digit from right to left.
    If doubling of a digit results in a two-digit number, add up the two digits to get a single-digit number.
    Afterwards stores every single-digit number in an array to be passed along.
    Parameters:
        stringArray (arr of str): The credit card number splitted up into an array.
    Returns:
        boolean from sumAndCheck.

    """
    numberArray = []

    for i in range(len(stringArray)-2, -1, -2):
        numberArray.append(stringArray[i])
    print(numberArray) 

    singleDigitArray = []

    for i in range(len(numberArray)):
        digit = int(numberArray[i]) * 2
        singleDigitArray.append(digit)
    print(singleDigitArray)
    
    singleDigitSplitted = []

    for i in range(len(singleDigitArray)):
        digit = singleDigitArray[i]
        if(digit > 9) :
            digits = [int(x) for x in str(digit)]
            number = 0
            for j in range(len(digits)):
                number = number + int(digits[j])
            singleDigitSplitted.append(number)
        else :
            singleDigitSplitted.append(digit)
    print(singleDigitSplitted)

    return singleDigitNumbers(singleDigitSplitted, stringArray)

def singleDigitNumbers(singleDigitSplitted, stringArray):
    """Step 2: adding all single-digit numbers from step 1.

    Function takes the array of single-digit numbers and adds them all up.
    Also passes along stringArray for use in other functions.
    Parameters:
        stringArray (arr of str): The credit card number splitted up into an array.
        singleDigitSplitted (arr of int): The array with single-digit numbers.
    Returns:
        boolean from sumAndCheck.

    """
    sumSingle = 0
    for i in range(len(singleDigitSplitted)):
        sumSingle = sumSingle + singleDigitSplitted[i]
    return digitsOddPlaces(stringArray, sumSingle)

def digitsOddPlaces(stringArray, sumSingle):
    """Step 3: Add all digits in the odd places from right to left.

    Function takes the array of split-up credit card numbers and adds all digits in odd places from right to left.
    Also passes along sumSingle for use in other functions.
    Parameters:
        stringArray (arr of str): The credit card number splitted up into an array.
        sumSingle (int): The total of all single-digit numbers from step 2.
    Returns:
        boolean from sumAndCheck.

    """
    oddPlaces = []
    sumOdd = 0
    for i in range(len(stringArray)-1, -1, -2):
        oddPlaces.append(stringArray[i])
        sumOdd = sumOdd + int(stringArray[i])
    print(oddPlaces)
    return sumAndCheck(sumSingle, sumOdd)
      
def sumAndCheck(sumSingle, sumOdd):
    """Step 4 & 5: Adds the result from step 2 and 3 and afterwards checks the validity of the credit card number.

    Function takes the results from step 2 and 3 and will use modulo 10 to check if it is valid.
    Parameters:
        sumSingle (int): The total of all single-digit numbers from step 2.
        sumOdd (int): The total of digits in odd places numbers from step 3.
    Returns:
        A boolean depending on the credit card validity

    """
    print(sumSingle)
    print(sumOdd)

    endResult = sumSingle + sumOdd
    if(endResult % 10 == 0) :
        print("valid number")
        return True
    else :
        print("invalid number")
        return False
    

result = process(creditCard)
print(result)