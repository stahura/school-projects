from random import *

def main():

    total = 0
    attempts = 0
    

    while total != 12:
        rand1 = randrange(1,7)
        rand2 = randrange(1,7)
        total = rand1 + rand2
        attempts = attempts + 1
        print(total)

    print("Attempts:", attempts)
    
        
    

def abc():

    a = random()
    if a >= 0:
        a = a + randrange(-10,10)
    else:
        a = a - randrange(-10,10)

    print(a)

def die():
    
    die1 = randrange(1,7)
    die2 = randrange(1,7)
    die3 = randrange(1,7)
    die4 = randrange(1,7)
    die5 = randrange(1,7)

    fiveofakind = False

    attempts = 0

    
    while fiveofakind == False:
        die1 = randrange(1,7)
        die2 = randrange(1,7)
        die3 = randrange(1,7)
        die4 = randrange(1,7)
        die5 = randrange(1,7)
        attempts = attempts + 1
        
        
        if die1 == die2:
            if die2 == die3:
                if die3 == die4:
                    if die4 == die5:
                        print("success")
                        fiveofakind = True
        
                    

        print(die1, die2, die3, die4, die5)
    print("success")
    print(attempts)

def chance():
    
    chanceValue = 1
    remainingDice = int(input("How many dice are there?: "))
    diceInt = int(remainingDice)
    
    for i in range(1, diceInt):
        chanceValue = chanceValue * 1/6
        

    print(chanceValue)
        


        
    
    
    
