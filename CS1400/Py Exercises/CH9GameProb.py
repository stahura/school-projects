from math import *
from random import random

def main():
    printIntro()
    probA, probB, n = getInputs()
    winsA, winsB = simNGames(n, probA, probB)
    printSummary(winsA, winsB)

def printIntro():
    print("This program simulates a game of racquetball between two")
    print('players called "A" and "B". the ability of eac player is')
    print("indicated by a probability (a number between 0 and 1) that")
    print("the player wins the point when serving. Player A always")
    print("has the first serve.")
def getInputs():
    #Returns n, a, b the simulation parameters
    a = float(input("What is the probability player A wins the serve?"))
    b = float(input("What is the probability player B wins the serve?"))
    n = int(input("How many games to simulate?"))

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
        else:
            if random() < probB:
                scoreB = scoreB + 1
            else:
                serving = "A"
    return scoreA, scoreB

def gameOver(a,b):
    #Scores for racquetball game. it's over when one reaches 15.
    return a==15 or b==15
    

def printSummary(winsA, winsB):
    n = winsA + winsB
    print("\nGames simulated:", n)
    print("Wins for A: {0} ({1:0.1%})".format(winsA, winsA/n))
    print("Wins for B: {0} ({1:0.1%})".format(winsB, winsB/n))


if __name__ == '__main__': main()
