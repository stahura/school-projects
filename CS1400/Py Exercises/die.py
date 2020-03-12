from random import randrange

class Die:
    """Models a die"""

    def __init__(self):
        self.Roll() 
        

    def Roll(self):
        self.value = randrange(1,7)
        

    def GetValue(self):
        return self.value

class Yahtzee:
    """5 of a kind"""

    def __init__(self):
        self.die0 = Die()
        self.die1 = Die()
        self.die2 = Die()
        self.die3 = Die()
        self.die4 = Die()

    def Roll(self):
        self.die0.Roll()
        self.die1.Roll()
        self.die2.Roll()
        self.die3.Roll()
        self.die4.Roll()

    def AreEqual(self):
        if (self.die0.GetValue() == self.die1.GetValue() == self.die2.GetValue() == self.die3.GetValue() == self.die4.GetValue()):
            return True
        else:
            return False
            
def GetPositiveNumber():
    
    while True:
        number = int(input("Enter positive number: "))
        if number > 0:
            return number
        print("error on input")

def main():
    game = Yahtzee()


    
    numberOYahtzees = 0

    
    for i in range(100000):
        game.Roll()
        if game.AreEqual():
            numberOYahtzees = numberOYahtzees + 1

    print(numberOYahtzees)


    
main()
