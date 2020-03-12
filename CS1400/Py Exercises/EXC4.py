from graphics import *
import math

def target():

    win = GraphWin('Target')

    outerOne = Point(100,100)
    circOne = Circle(outerOne,50)
    circOne.setFill('red')
    circOne.draw(win)

    outerTwo = Point(100,100)
    circTwo = Circle(outerTwo,40)
    circTwo.setFill('blue')
    circTwo.draw(win)

    outerThree = Point(100,100)
    circThree = Circle(outerThree,30)
    circThree.setFill('black')
    circThree.draw(win)

    outerFour = Point(100,100)
    circFour = Circle(outerFour,20)
    circFour .setFill('white')
    circFour .draw(win)

    center = Point(100,100)
    circCenter = Circle(center,10)
    circCenter.setFill('yellow')
    circCenter.draw(win)

def circles():

    win = GraphWin('User Circles',400,400)

    #User input for center and radius for both circles
    print("Enter the requested information. Circle one will be yellow, while circle two will be blue")
    userCenterOneX = int(input("What is the X point of the center of the first circle?: "))
    userCenterOneY = int(input("What is the Y point of the center of the first circle?: "))
    userRadiusOne = int(input("What is the Radius of the first circle?: "))

    userCenterTwoX = int(input("What is the X point of the center of the second circle?: "))
    userCenterTwoY = int(input("What is the Y point of the center of the second circle?: "))
    userRadiusTwo = int(input("What is the Radius of the second circle?: "))

    #Draw the circles

    centerOne = Point(userCenterOneX,userCenterOneY)
    circOne = Circle(centerOne,userRadiusOne)
    circOne.setFill('yellow')
    circOne.draw(win)

    centerTwo = Point(userCenterTwoX,userCenterTwoY)
    circTwo = Circle(centerTwo,userRadiusTwo)
    circTwo.setFill('blue')
    circTwo.draw(win)

    #********* Do they overlap? **********
    
    #a = (userCenterTwoX - userCenterOneX)**2
    #b = (userCenterOneY - userCenterTwoY)**2

    

    #distance = math.sqrt(a + b)

    
    

    #if userRadiusTwo >= distance - userRadiusOne:
    #      print("The circles will overlap")
    #else:
    #      print("The circles will not overlap")

    #If the radius of circle two is greater than or equal to the distance between-
    #-the center of both circles minus the radius of circle 1, they will overlap
