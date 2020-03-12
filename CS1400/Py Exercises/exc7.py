from graphics import *
from math import *

def disc3():
    a,b,c = eval(input('Enter three numbers: '))

    if a > b:
        if b > c:
            print("Spam Please!")
        else:
            print("It's a late parrot!")
    elif b > c:
        print("Cheese Shoppe")
        if a >= c:
             print("Cheddar")
        elif a < b:
            print("Gouda")
        elif c==b:
            print("Swiss")
    else:
        print("Trees")
        if a ==b:
             print("Chestnut")
        else:
             print("Larch")
    print("Done")

def speed():
    while True:
        try:
            clockedSpeed = int(input("Enter the clocked speed: "))
            speedLimit = int(input("Enter the speed limit: "))
        except ValueError:
            print("please enter a valid number")
        else:
            break
    
    fineAmount = 0

    if clockedSpeed > speedLimit:
    
        fineAmount = 50
    
        for number in range(clockedSpeed+1):
            if number > speedLimit:
                fineAmount = fineAmount + 5
                if clockedSpeed > 90:
                    fineAmount = fineAmount + 200
        print("The clocked speed is illegal and the penalty is a fine of: $",fineAmount)
    else:
        print("The clocked speed is legal")
        
def pol():

    while True:
        try:
            age = int(input("Enter your age: "))
            citizenTime = int(input("Enter the time that you've been a US citizen "))
        except ValueError:
            print("please enter a valid number")
        else:
            break
    
    if age >= 25 and citizenTime >= 7:
        if age >= 30 and citizenTime >= 9:
            print("You are eligible for both the House and Senate")
        else:
            print("You are eligible for the House, but not the Senate")
    else:
        print("You are not eligible for the House or the Senate")

def circInter():

    win = GraphWin("Intersection", 300,300)
    win.setCoords(-10.0,-10.0,10.0,10.0)

    yint = float(input("Enter the y-intercept: "))
    radius = float(input("Enter the radius: "))

    circCenter = Point(0,0)
    circ = Circle(circCenter,radius)
    circ.draw(win)
    #x value for both points
    x1 = -10
    x2 = 10
    #points that will be used for line
    p1 = Point(x1, yint)
    p2 = Point(x2, yint)

    line = Line(p1,p2)
    line.draw(win)
    
    #The math needed to determine the intersections
    #Intersection Points
    #Put everything within a try-except to prevent it from crashing if there is no intersection)
    try:
        intersection = sqrt((radius**2) - (yint**2))

        intP1 = Point(intersection,yint)
        intP1.setFill('red')
        intP1.draw(win)

        intP2 = Point((intersection * -1),yint)
        intP2.setFill('red')
        intP2.draw(win)

        intP1X = intP1.getX()
        intP2X = intP2.getX()
        print("The x values of the intersection points are: ", intP1X, "and", intP2X)
    except ValueError:
        print("There is no intersection")

def testing():
    print("This program find MPG\n")

    try:
        m = float(input("Enter Miles Driven: "))
        g = float(input("Enter Gallons used: "))

        mpg = m / g

        print("\nYour MPG is: {0.0.2f}".format(mpg))
    except ValueError as excObj:
        print("Invalid data given")
    except:
        print("\nCan't Divide by Zero")
def fah():
    fahrenheit = 86.0
    if fahrenheit > 90:
        print("It's really hot out there. Be careful!")
    if fahrenheit > 80:
        print("Beautiful day for a hike!")
    if fahrenheit > 70:
        print("Perfect day for a picnic.")
    if fahrenheit > 60:
        print("Go on a long walk.")

def fah2():
    fahrenheit = 63.5
    if fahrenheit > 90:
        print("Its hot")
    elif fahrenheit > 80:
        print("Beautiful day")
    elif fahrenheit > 70:
        print("Perfect day")
    else:
        print("Long walk")
fah2()

    
    
        

    
    
    

    
        

        
    
