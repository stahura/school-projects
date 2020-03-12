from math import *
from graphics import *
from animation2 import *
from random import *

class ShotTracker():
    """ Keep track of and animate a cannonball """

    def __init__(self, win, height, angle, velocity):
        self.proj = Projectile(height, angle, velocity)
        self.marker = Circle(Point(0, height), 3)
        self.marker.setFill('red')
        self.marker.setOutline('red')
        self.marker.draw(win)

    def update(self, time):
        self.proj.update(time)
        center = self.marker.getCenter()
        dx = self.proj.getX() - center.getX()
        dy = self.proj.getY() - center.getY()
        self.marker.move(dx,dy)

    def getX(self):
        return self.proj.getX()

    def getY(self):
        return self.proj.getY()

    def undraw(self):
        self.marker.undraw()


class Launcher():

    def adjAngle(self, amt):
        """Change Launch agnle by amt degrees"""

        self.angle = self.angle + radians(amt)
        self.redraw()

    def adjVel(self, amt):
        """Change launch velocity by amt"""

        self.vel = self.vel + amt
        self.redraw()

    def redraw(self):
        """redraw the arrow to show current angle and velocity"""

        self.arrow.undraw()
        pt2 = Point(self.vel*cos(self.angle),
                    self.vel*sin(self.angle))
        self.arrow = Line(Point(0,0), pt2).draw(self.win)
        self.arrow.setArrow("last")
        self.arrow.setWidth(3)

    def fire(self):
        return ShotTracker(self.win, degrees(self.angle), self.vel, 0.0)

    def __init__(self, win):
        #Draw base shot of launcher
        base = Circle(Point(0,0), 3)
        base.setFill("red")
        base.setOutline("red")
        base.draw(win)

        #save the window and create initial angle and velocity
        self.win = win
        self.angle = radians(45.0)
        self.vel = 40.0

        #Create initial "dummy" arrow(needed by redraw)
        self.arrow = Line(Point(0,0), Point(0,0)).draw(win)
        #replace it with correct arrow
        self.redraw()

class ProjectileApp:

    def __init__(self):
        #create graphics window
        self.win = GraphWin("Projectile Animation", 640, 480)
        self.win.setCoords(-10, -10, 210, 155)
        Line(Point(-10,0), Point(210,0)).draw(self.win)
        for x in range(0,210,50):
            Text(Point(x,-7),str(x)).draw(self.win)
            Line(Point(x,0), Point(x,2)).draw(self.win)

        #add the launcher to the window
        self.launcher = Launcher(self.win)

        #start with empty list of "live" shots
        self.shots = []
    def run(self):
        a = Target(self.win)
        

        #main event/animation loop
        while True:
            self.updateShots(1/30)
            
            key = self.win.checkKey()
            if key in ["q", "Q"]:
                break

            if key == "Up":
                self.launcher.adjAngle(5)
            elif key == "Down":
                self.launcher.adjAngle(-5)
            elif key == "Right":
                self.launcher.adjVel(5)
            elif key == "Left":
                self.launcher.adjVel(-5)
            elif key in ["f", "F"]:
                self.shots.append(self.launcher.fire())

            update(30)
        win.close()

    def updateShots(self, dt):
        alive =[]

        for shot in self.shots:
            shot.update(dt)
            if shot.getY() >= 0 and -10 < shot.getX() < 210:
                alive.append(shot)
            else:
                shot.undraw()
        self.shots = alive

class Target:

    def __init__(self,win):
        p1 = Point(randrange(0,150),0)
        p1X = p1.getX()
        p1Y = p1.getY()
        p2 = Point(randrange(p1X, p1X + 100), randrange(p1Y, p1Y + 100))
        self.rect = Rectangle(p1,p2)
        self.rect.setFill('lightgray')
        self.rect.draw(win)
        

    

if __name__ == "__main__":
    ProjectileApp().run()

            
        
