from graphics import *

def main():

    print("We've made it easy to calculate your tip. Just enter the following: ")
    mealCost = float(input("How much did the meal cost?: "))

    excellent = mealCost * .20
    average = mealCost *.15
    poor = mealCost * .10

    tipExcellent = "would be: ${0:0.2f}".format(excellent,2)
    tipAverage = "would be: ${0:0.2f}".format(average,2)
    tipPoor = "would be: ${0:0.2f}".format(poor,2)

    

    print("A tip for excellent service",tipExcellent,"for a total of: ${0:0.2f}".format(excellent + mealCost,2 ))
    print("A tip for average service ",tipAverage,"for a total of: ${0:0.2f}".format(average + mealCost,2 ))
    print("A tip for poor service ",tipPoor,"for a total of: ${0:0.2f}".format(poor + mealCost))
    print("  *If you'd like, let us know how you felt about our service by filling out a survey*")
    


'''
length = float(input("Enter length: "))

inches = length * 12
feet = inches //12
t = inches % 12

print("The length is", feet, "feet", inches, "inches.")
'''

def car():

    win = GraphWin("Hello", 400, 400)

    body = Rectangle(Point(50,300), Point(300,200))
    wheel1 = Circle(Point(100,300), 25)
    wheel2 = Circle(Point(250,300), 25)
    roof = Rectangle(Point(300,200), Point(100,170))

    body.draw(win)
    wheel1.draw(win)
    wheel2.draw(win)
    roof.draw(win)
