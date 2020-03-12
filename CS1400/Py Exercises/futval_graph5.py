"""
futval_graph5.py
Changes from futval_graph4:
1. add instructions function
2. add prompt function
3. use for loop to create labels in createLabeledWindow
4. added showGraph function to clean up main().
5. Added docstring comments to the code.
"""

from graphics import *

def instructions():
    """
    Put any instructions to user here.
    :return: None
    """
    print("This program plots the growth of a 10 year investment.")

def promptUser():
    """
    Prompt user for any input values: principal and apr
    :return: a tuple that includes principal and apr
    """
    principal = float(input("Enter the initial principal: "))
    apr = float(input("Enter the annualized interest rate: "))
    return principal, apr


def createLabeledWindow():
    """
    Creates and populates our investment bar graph
    :return: the graphics window used to display the graph
    """
    window = GraphWin("Investment Growth Chart", 320, 240)
    window.setBackground("white")
    window.setCoords(-1.75,-200, 11.5, 10400)

    for value in range(0, 12500, 2500):
        label = '{}K'.format(value/1000).rjust(5)
        Text(Point(-1, value), label).draw(window)

    return window

def drawBar(window, year, height):
    """
    Draw a bar for the graph in the specified window.
    Year and height determine position and laegth of the bar.
    :param window: graph window to draw in.
    :param year: one of a specified range of years
    :param height: how high the bar should be
    :return: None
    """
    bar = Rectangle(Point(year, 0), Point(year+1, height))
    bar.setFill("green")
    bar.setWidth(2)
    bar.draw(window)

def showGraph(principal, apr):
    """
    Draws a 10-year graph in a graphical window.
    We return the window to the caller in case other things might
    be going on in the program.
    :param principal: starting investment value.  Must be greater than 0.
    :param apr: annual interest rate.
    :return: the window to draw in.
    """
    win = createLabeledWindow()
    drawBar(win, 0, principal)
    for year in range(1, 11):
        principal = principal * (1 + apr)
        drawBar(win, year, principal)

    return win

def main():
    instructions()
    principal, apr = promptUser()
    win = showGraph(principal, apr)

    input("Press <Enter> to quit.")
    win.close()

main()
