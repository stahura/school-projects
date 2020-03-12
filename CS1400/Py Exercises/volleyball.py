from math import *
from random import random

def main():
    printIntro()
    probA, probB, n = getInputs()
    winsA, winsB = simNGames(n, probA, probB)
    printSummary(winsA, winsB)

def printIntro():
    print("This program simulates a game of volleyball between two")
    print('teams called "A" and "B". the ability of each team is')
    print("indicated by a probability (a number between 0 and 1)")
    print("the team wins the point whether or not they serve. Team A always")
    print("has the first serve.")
def getInputs():
    #Returns n, a, b the simulation parameters
    a = float(input("What is the probability team A wins the rally" ))
    b = float(input("What is the probability team B wins the rally?" ))
    n = int(input("How many games to simulate?" ))

    return a, b, n

def simNGames(n, probA, probB):
    #Simulates n games, returns number of wins for A and B
    winsA = 0
    winsB = 0
    for i in range(n):
        scoreA, scoreB = simOneGame(probA, probB)
        if scoreA > scoreB:
            winsA = winsA +1
        else:
            winsB = winsB +1
    return winsA, winsB

def simOneGame(probA, probB):
    #simulates one game.Returns final scores for A and B
    scoreA = 0
    scoreB = 0
    serving = "A"
    while not gameOver(scoreA, scoreB):
        if serving == "A":
            if random() < probA:
                scoreA = scoreA + 1
            else:
                serving = "B"
                scoreB = scoreB +1
        else:
            if random() < probB:
                scoreB = scoreB + 1
            else:
                serving = "A"
                scoreA = scoreA +1
                
            

    return scoreA, scoreB

def gameOver(a,b):
    #Scores for volleyball game. it's over when one reaches 25.
    return a==25 or b==25
    

def printSummary(winsA, winsB):
    n = winsA + winsB
    print("\nGames simulated:", n)
    print("Wins for A: {0} ({1:0.1%})".format(winsA, winsA/n))
    print("Wins for B: {0} ({1:0.1%})".format(winsB, winsB/n))


if __name__ == '__main__': main()

#It's almost identical. Function simOneGame was altered to add 1 to scoreB
#   in the case that random() > probA, even if A was serving and vice versa.
#Changed the intro to be Volleyball instead of racquetball

#ALSO changed gameOver to be over once either a or b is equal to 25 instead of 15.

