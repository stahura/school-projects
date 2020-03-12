#Jeffrey Riley Stahura
#10617813
#CS1400-001
#Due Feb. 24th
#                               Programming Project #3: Farmer John's Field
#
#
#We need to determine the area of a shaded region that is left in the center after creating 4 circles
#   Steps
#       Draw the 4 circles that mirror each other across the X and Y axis
#       Get the center of each circle, 2 of those points will be used to create the square
#       Get the area of shaded area by getting 1/4 area of each circle. Since there are 4 1/4ths, we just subtract circle area from square area
#       User input will be the length of the square side. Half the user input is each circle's radius.
#       Ensure invalid user input does not crash the program
#       Print the area of the shaded shape in console
#       Close on last mouse click
#----------------------------------------------------------------------------------------------------------------------
#   Major Points
#I had a hard time figuring out how to "gracefully" accept invalid input. I found an answer on stackoverflow (https://goo.gl/R4iPbF) and realized
#   that I could use a while loop with a try-except. I'd rather not have the program close upon invalid input, so I found a better solution.
#I also had a hard time deciding how to color in the shaded area. I couldn't find a way to color a "custom" shape, so i made an underlying square
#   that would just be gray. The white filled circles on top would cover the rest of the square, creating the proper gray shape.

from math import *
from graphics import *


def distance(p1,p2):

    dist = sqrt(square(p2.getX() - p1.getX()) + square(p2.getY() - p1.getY()))
    return dist

def circleArea(radius):
#Return area of a circle using given radius
    
    area = pi*radius**2
    print("The area of each circle is:{0:10.2f}".format(area))
    return area

def squareArea(length):
#return area of square using given length

    area = length * length
    print("The area of the square is:{0:10.2f}".format(area))
    return area

def main():
    
    win = GraphWin('Graphics',550,550)
    win.setCoords(-10.0,-10.0,10.0,10.0)


    #Get 4 center points(p1,p2,p3,p4)
    
    
    p1 = Point(-5,5)
    p2 = Point(5,5)
    p3 = Point(-5,-5)
    p4 = Point(5,-5)
    #draw a square *under*/before the circles, allowing the shaded area to take proper shape.
    squareunder = Rectangle(p3,p2)
    squareunder.setFill('gray')
    squareunder.draw(win)
    #draw 4 circles, color them white so that the entire underlying square does not show, only the desired portion  
    circ1 = Circle(p1,5)
    circ1.setFill('white')
    circ1.draw(win)
    
    circ2 = Circle(p2,5)
    circ2.setFill('white')
    circ2.draw(win)
    
    circ3 = Circle(p3,5)
    circ3.setFill('white')
    circ3.draw(win)
    
    circ4 = Circle(p4,5)
    circ4.setFill('white')
    circ4.draw(win)
    

    #draw the square.
    square = Rectangle(p3,p2)
    square.draw(win)


    #USER INPUT via console
    #While loop to ensure program does not exit when input is invalid
    while True:
        try:
            length = float(input("Enter the length of a side of the square: "))
        except ValueError:
            print("Invalid entry, please enter a number")
        else:
            break



    #Now get the area of the square and the circles by calling the functions rectArea,circArea
    rectArea = squareArea(length)
    circArea = circleArea(length/2)

    #Shaded Area calculation
    shadedCalc = rectArea - circArea
    print("the area of the shadded area is: {0:2.2f}".format(shadedCalc))

    #close on last mouseclick

    close = win.getMouse()
    win.close()



main()

    
