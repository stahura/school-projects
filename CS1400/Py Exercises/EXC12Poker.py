from random import *
from textpoker import TextInterface


class Dice:
    def __init__(self):
        self.dice = [0]*5
        self.rollAll()

    def roll(self, which):
        for pos in which:
            self.dice[pos] = randrange(1,7)

    def rollAll(self):
        self.roll(range(5))

    def values(self):
        return self.dice[:]

    def score(self):
        counts = [0] * 7
        for value in self.dice:
            counts[value] = counts[value] + 1

        if 5 in counts:
            return "Five of a Kind", 30
        elif 4 in counts:
            return "Four of a Kind", 15
        elif (3 in counts) and (2 in counts):
            return "Full House", 12
        elif 3 in counts:
            return "Three of a Kind", 8
        elif not (2 in counts) and (counts[1]==0 or counts[6] == 0):
            return "Straight", 20
        elif counts.count(2) == 2:
            return "Two Pairs", 5
        else:
            return "Garbage", 0

class PokerApp:
    def __init__(self, interface):
        self.dice = Dice()
        self.money = 100
        self.interface = interface

    def run(self):
        while self.money >= 10 and self.interface.wantToPlay():
            self.playRound()
        self.interface.close()

    def playRound(self):
        self.money = self.money -10
        self.interface.setMoney(self.money)
        self.doRolls()
        result, score = self.dice.score()
        self.interface.showResult(result, score)
        self.money = self.money + score
        self.interface.setMoney(self.money)

    def doRolls(self):
        #Roll all of the dice that exist
        self.dice.rollAll()
        #initialize roll to 1 in order to use While loop
        roll = 1
        #This calls a method within the chosen interface which prints dice values
        self.interface.setDice(self.dice.values())
        #Again, calls method within interface class, which will change the chosen die, assigns it
        #     to toRoll
        toRoll = self.interface.chooseDice()
        #do as long as roll is less than 3 and toRoll is not empty
        while roll < 3 and toRoll != []:
            #Rolls dice using roll method from Dice class, toRoll determines the die to roll
            self.dice.roll(toRoll)
            #accumulate 1 to roll
            roll = roll + 1
            #Repeats what was done before, prints dice values
            self.interface.setDice(self.dice.values())
            #As long as roll is less than 3 this will change the chosen die and assign it to toRoll
            if roll < 3:
                toRoll = self.interface.chooseDice()



