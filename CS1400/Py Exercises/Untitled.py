#length = float(input("Enter length: "))
#inches = length * 12
#print(inches)
#feet = inches //12
#print(feet)
#inches = inches % 12
#print(inches)
#print("The length is", feet, "feet", inches, "inches.")

#feet = float(input("Enter"))
#inches = feet * 12
#feet = inches // 12
#inches = inches % 12
#print(feet, "feet and ",inches,"inches")
'''

def main() :
# months is used as a lookup table
    months = "JanFebMarAprMayJunJulAugSepOctNovDec"
    n = int(input("Enter a month n ber (1-12) : ")) # compute starting position of month n in months
    pos = (n-1) * 3
# Grab the appropriate slice from months
    monthAbbrev = months[pos:pos+3] # print the result
    print("The month abbreviation is" , monthAbbrev + ".")




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

'''

       
    
  
