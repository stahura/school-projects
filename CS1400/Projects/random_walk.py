from graphics import *
from math import *
from random import *
"""
Riley Stahura
CS1400
Due March 31 2018

                Project 5: Random Walk

Random walk is a probablistic simulation. DISPLAY ACTUAL DISTANCE AND STRAIGHT LINE
distance in console , round properly.

The program should take the number of steps as input. Assume the walker always
starts at 0,0 in a 100x100 unit grid. Create a graphical program that will draw
a line to trace the path of the walk as it progresses. At the end, print out the
straight-line distance and actual distance traveled to the console or GUI, rounded
to the nearest whole unit.

Equation 1 generates a random direction:
    (1)angle = random() * 2 * math.pi
Equation 2 and 3 generate new position for each time step.
    (2)x = x + cos(angle)
    (3)y = y + sin(angle)

----------------------------------------------------------------------------------
import random
import math


Class for Walking

    init method:
        x,y values

    def x method:
        calculate new x

    def y method:
        calculate new y

    def get new position method:
        record old position
        get x and y from methods
        make new position
        draw a line with old and new position

Main Function:

    draw window
    set coords
    start point is 0,0

    step object instance of Walking class

    Create while loop with
        while loop nested
            try except user input for number of steps that will be taken

            exit loop ONLY when they enter a positive integer.

    for loop for every step in number of steps
        step.getnewposition()

    calculate distance between beginning and end points
    print distance traveled in total.
            
    

"""
class Walk():

    def __init__(self, win):
        self.x = 0
        self.y = 0
        self.win = win


    def getX(self):

        angle = random() * 2 * pi
        self.x = self.x + cos(angle)
        

    def getY(self):
 
        angle = random() * 2 * pi
        self.y = self.y + sin(angle)
        

    def getNewPosition(self):
        oldPos = Point(self.x,self.y)
        self.getX()
        self.getY()
        newPos = Point(self.x,self.y)
        newLine = Line(oldPos,newPos)
        newLine.draw(self.win)
    def getPosition(self):
        return Point(self.x,self.y)
        
        
        
    
    
    

def main():
    '''Draw window'''
    win = GraphWin("Random Walk",700,700)
    win.setCoords(-100,-100,100,100)

    '''Give it 0,0 start point and draw the point'''
    startPoint = Point(0,0)
    startPoint.draw(win)
    step = Walk(win)
    '''initialize numSteps and attempts for the nested while loops to ensure
    numsteps is a positive number'''
    
    numSteps = 0
    attempts = 0
    stepsIsPositive = False
 
    while stepsIsPositive == False:
        if attempts > 0:
            print("Please enter a positive number")
        
        while True:
            try:
                numSteps = int(input("Enter the number of steps: "))
            except ValueError:
                print("Enter a valid integer")
            else:
                break
        if numSteps >= 0:
            stepsIsPositive = True 
        else:
            attempts = attempts + 1 
        
    print(numSteps, "steps")

    '''For loop, for each step entered by the user, a new step will occur
    until it's taken the number entered'''
    for i in range(1,numSteps+1):
        step.getNewPosition()

    endPos = step.getPosition()
    redline = Line(startPoint,endPos)
    redline.setFill('red')
    redline.draw(win)
    '''Get the final distance travelled, print it out'''
    dist = sqrt(endPos.getY()**2 + endPos.getX()**2)
    print(round(dist))

        

main()


        
        

