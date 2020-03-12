from math import *
from graphics import *

def sphereArea(radius):
#Return surface area of sphere with given radius
    
    area = 4*pi*radius**2
    print("The area is: ",area)
    return area

def sphereVolume(radius):
#Return volume of sphere having the given radius
    
    volume = (4/3)*pi*radius**3
    print("The volume is: ",volume)
    return volume



sphereArea(3)
sphereVolume(4)

def square(x):
    return x**2
def distance(p1,p2):

    dist = sqrt(square(p2.getX() - p1.getX()) + square(p2.getY() - p1.getY()))
    return dist

def triArea(p1,p2,p3):

    len1 = distance(p1,p2)
    len2 = distance(p2,p3)
    len3 = distance(p3,p1)

    s = (len1 + len2 + len3) / 2
    area = sqrt(s*(s-len1)*(s-len2)*(s-len3)) 
    
    return(area)

def main():
    
    
    win = GraphWin("Draw a triangle")
    win.setCoords(0.0, 0.0, 10.0, 10.0)

    message = Text(Point(5, 1), "click")
    message.draw(win)
    message2 = Text(Point(5,1.6), "test")
    message2.draw(win)
   

    p1 = win.getMouse()
    p1.draw(win)
    p2 = win.getMouse()
    p2.draw(win)
    p3 = win.getMouse()
    p3.draw(win)

    triangle = Polygon(p1,p2,p3)
    triangle.setFill("blue")
    triangle.setOutline("cyan")
    triangle.draw(win)
        
    area = triArea(p1,p2,p3)       
    perim = distance(p1,p2) + distance(p2,p3) + distance(p3,p1)
    message.setText("The perimeter is: {0:02f}".format(perim))
    message2.setText("The area is : {0:02f}".format(area))
    
    win.getMouse()
    win.close()
    
main()
