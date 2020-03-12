from graphics import *

from random import randrange, random

import math

def run():

    width = 640

    height = 480

    win = GraphWin("Cannon Ball", width, height)

    radius = 3


    # 1

    # add code here to generate a random height greater than or equal to 0 and less than 100
    height = randrange(0, 100)
    print(height)
    x, y = 0, height

    ball = Circle(Point(x,y), radius)
    ball.setFill("red")
    ball.draw(win)

    # 2

    # add code here to generate a random angle greater than 0 and less than 90
    angle = randrange(1,90)
    # 3

    # add code here to generate a random velocity greater than 0 and less than 100
    velocity = randrange(1,100)
    # to use in setting xvel and yvel

    xvel = velocity*math.cos(angle)
    
    yvel = velocity*math.sin(angle)

 

    keyString = win.checkKey()
s
    # 4

    # replace XXX's below with expressions or statements that will make the loop repeat until

    # the cannonball reaches the ground

    while ball.p1.getY() < 480:
        
        time.sleep(.001)
        
        
        # 5
        # add code here to make the ball travel from the initial position at the given angle and velocity
        dx = x+ .001 * xvel
        yvel1 = yvel - .001 * 9.8
        dy = y +.001 * (yvel + yvel1) / 2.0
        yvel = yvel1
        ball.move(dx,dy)
        
        # until it hits the ground. Be sure to adjust yvel for the effect of gravity.

        #XXX

    #win.close()

run()
