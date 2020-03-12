#Jeffrey Riley Stahura
#10617813
#CS 1400-001
#Due Feb 10


#*********** 2D Graphics and Mouse Clicks *******

#The user needs to be able to create a simple house by clicking

#Each click will do the following:
# 1: Bottom Left Corner of rectangle frame of house
# 2: Top Right corner of rectangle frame of house
# 3: Center top edge of door(will form a rectangle)
# 4: Center of the window (will form a square)
# 5: Peak of the roof, will extend to end of rectangle frame(Forms a triangle)

#House is a rectangle
#Door is 1/5 the width of the house
#Window is 1/2 the width of the door



import math
from graphics import *

def main():
    #Open Window
    #Set Graph
    
    win = GraphWin('Graphics',500,500)
    win.setCoords(0.0,0.0,10.0,10.0)

    # ****Get 2 Mouse Clicks for House base****


    p1 = win.getMouse()
    p1.draw(win)
     
    p2 = win.getMouse()
    p2.draw(win)

     # ****Create rectangle frame, draw house ****

    houseBase = Rectangle(p1,p2)
    houseBase.draw(win)
    houseBase.setFill('red')

    #x & y Coordinates for first 2 points, make new Point using x of p1 and y of p2, add house width. 
    #   "New Point TopLeft" is used for the 3rd point needed in the triangle roof at the end
    
    p1X = p1.getX()
    p1Y = p1.getY()
    p2X = p2.getX()
    p2Y = p2.getY()
    
    newPointTopLeft = Point(p1X,p2Y)
  
    houseWidth = p2X - p1X

    # ****Get door mouse click
    
    p3 = win.getMouse()
    p3.draw(win)

     # ****Rectangle Door****
    #Create 2 points to use for a new rectangle, specify width of door , draw door, color black,
    p3X = p3.getX()
    p3Y = p3.getY()
     
    
    doorWidth = 1/5 * houseWidth

    doorPointX1 = p3X - (doorWidth / 2)
    doorPointX2 = p3X + (doorWidth / 2)

    doorPoint1 = Point(doorPointX1, p3Y)
    doorPoint2 = Point(doorPointX2, p1Y)

    door = Rectangle(doorPoint1, doorPoint2)
    door.setFill('black')

    door.draw(win)

    # ****Window Mouse Click
    
    p4 = win.getMouse()
    p4.draw(win)

      # ****Window****

    p4X = p4.getX()
    p4Y = p4.getY()

    #Window is half the width of door, create 2 new points for square rectangle, color grey
    windowWidth = doorWidth / 2

    windowTopPointX = p4X - (windowWidth / 2)
    windowTopPointY = p4Y + (windowWidth / 2)
    windowBotPointX = p4X + (windowWidth / 2)
    windowBotPointY = p4Y - (windowWidth / 2)

    windowTopLeftPoint = Point(windowTopPointX, windowTopPointY)
    windowBotRightPoint = Point(windowBotPointX, windowBotPointY)

    window = Rectangle(windowTopLeftPoint, windowBotRightPoint)
    window.setFill('grey')
    window.draw(win)
    
    p5 = win.getMouse()
    p5.draw(win)
    
   #x & y Coordinates for first 2 points, make new Point using x of p1 and y of p2, add house width. 
    #   "New Point TopLeft" is used for the 3rd point needed in the triangle roof at the end
    
    p1X = p1.getX()
    p1Y = p1.getY()
    p2X = p2.getX()
    p2Y = p2.getY()
    
    newPointTopLeft = Point(p1X,p2Y)
  
    houseWidth = p2X - p1X
    

   
    
  

    # ****Triangle Roof****
    # Mouse Click 2 and 5 are used together with the New Point I created earlier to make the triangle
    roof = Polygon(p2,newPointTopLeft, p5)
    roof.setFill('brown')
    roof.draw(win)

    #undraw the points
    p1.undraw()
    p2.undraw()
    p3.undraw()
    p4.undraw()
    p5.undraw()
    

main()


#This was BY FAR the most challenging exercise for me.

#*Figuring out how to get the third point for the roof triangle was the first obstacle, which was resolved by making
#        a new Point using the X of click 1 and the Y of click 2

#*Figuring out how to make a rectangle with a center coordinate instead of a corner was hard too. Finding the width of
#        the house was KEY to helping me calculate 2 more Points for the rectangle

#*The window was actually easy. I divided the width of the door by 2, then subtracted that from the x value of mouse
#        click 4 and added that same value to the y value of mouse click 4, that gave me the top left Point for the
#        square. I did the same for the bottom right and it worked.
#
#
#
#
#
  

    
    

    

    
