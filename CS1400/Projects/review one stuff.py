from graphics import *
from math import *

def inches():
    
    length = float(input("Enter length: "))
    inches = length * 12
    feet = inches //12
    inches = inches % 12
    print("The length is", feet, "feet", inches, "inches.")

# CAR

def car():

    win = GraphWin("car", 400,400)
    body = Rectangle(Point(80,300), Point(310,200))
    body.draw(win)

    wheel1 = Circle(Point(110,300), 25)
    wheel2 = Circle(Point(275,300), 25)

    wheel1.draw(win)
    wheel2.draw(win)

    roof = Rectangle(Point(150,200), Point(310, 110))

    roof.draw(win)

print(pi)
