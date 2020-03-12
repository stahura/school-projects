from math import *
from graphics import *
'''
def windChill(t,w):

    windchill = 35.74+(0.6215*t)-35.75*(w**0.16)+(0.4275*t)*(w**0.16)

    return windchill


windspeeds = [0,5,10,15,20,25,30,35,40,45,50]
temperatures = [-20,-10,0,10,20,30,40,50,60]


print("     |-----------------Wind Speed----------------")
print("Temp |", end="")
for y in windspeeds:
    print("%3d " % y, end="")                
print()
print("     |-------------------------------------------")
                                               
for t in temperatures:                          
    print("%3d " % t,"|", end="",)                   
    for w in windspeeds:                        
        print("%3d " % windChill(t,w), end="") 
    print()
print("-----|-------------------------------------------")
'''
#def gcd():

#    m = float(input("Enter number one: "))
#    n = float(input("Enter number two: "))
    

#    while m != 0:
#        n, m = m, n%m
#    print(n)


'''
for each row in the image:
    for each column in the image:
        r,g,b = get pixel info for current row and column
        brightness = int(round(0.299r + 0.587g + 0.114b))
        set pixel to color_rgb(brightness, brightness, brightness)
    update image to # to see progress row by row
    '''
def pic():
    
    win = GraphWin("Grayscale", 300,290)
    win.setCoords(-10.0,-10.0,10.0,10.0)

    imgName = input("Enter the name of the image: ")

    img = Image(Point(0,0), imgName)
    img.draw(win)
    row = 0
    column = 0

    

    for row in range(299):
        for column in range(300):
            r, g, b = img.getPixel(row, column)
            brightness = int(round(0.299*r + 0.587*g + 0.114*b))
            img.setPixel(row, column, color_rgb(brightness, brightness, brightness))

pic()


