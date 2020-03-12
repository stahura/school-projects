def numvalue():

    name = input("Enter a single name: ")
    value = 0
    
    for letter in name:
                #To account for the spaces in between names
        if letter == " ":
            letterValue = ord(letter)-32
            
                #To account for the letter that may be uppercase
        elif letter == letter.upper():
            
            letterValue = ord(letter)-64
            value = value + letterValue
                #All other characters
        else:
            letterValue = ord(letter.lower())-96
            value = value + letterValue

    print(value)
