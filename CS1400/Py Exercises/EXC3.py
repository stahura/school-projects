import math
#Chapter 3 Discussion 2 pg 78

pi = math.pi

def first():
    answer = (3+4)*5
    print(answer)

def second():
    n = int(input("Enter value for 'n': "))
    answer = (n*n - n*1) /2
    print(answer)
    

def third():

    radius = int(input("Enter the radius: "))
    answer = pi * 4 * (radius**2)
    print(answer)

def fourth():

    radius = float(input("Enter the radius: "))
    a = eval(input("Enter 'a' measured in radians: "))
    b = eval(input("Enter 'b' measured in radians: (Ex. math.pi/6) "))

    c = math.cos(a)**2
    d = math.sin(b)**2
    
    answer = math.sqrt((radius * c) + (radius * d))
    print(answer)

def fifth():

    yy = int(input("Enter 'y2': "))
    y = int(input("Enter 'y1': "))
    xx = int(input("Enter 'x2': "))
    x = int(input("Enter 'x1': "))

    answer = (yy-y)/(xx-x)
    print(answer)

#Chapter 3 Discussion 4 pg. 78

def sixth():
    for i in range(1,11):
        print(i*i)

def seventh():
    for i in [1,3,5,7,9]:
        print(i,":", i**3)

def eighth():
    x = 2
    y = 10

    for j in range(0,y,x):
        print(j,end="")
        print(x+y)
    print("done")
    
def ninth():
    ans = 0
    for i in range(1,11):
            ans = ans + i*i
            print(i)
    print(ans)

#Programming Exercises 2


def pizza():
    
    diameter = float(input("Enter the pizza size in inches: "))
    radius = diameter / 2
    pizzaSize = pi * (radius**2)
    print("The size in square inches is: ",round(pizzaSize,2))
    
    price = float(input("Enter the pizza price: "))

    costper = price / pizzaSize
    print("The price per square inch is: ", round(costper,2), "cents")
    
    
#Factorial functions
def factorialEx():
    n = int(input("Please enter a whole number: "))
    fact =1
    for factor in range(n,1,-1):
        fact = fact * factor
    print("The factorial of", n, "is", fact)

def factorial():
    n = int(input("Please enter a whole number: "))
    fact =1
    for factor in range(1,n+1):
        fact = fact * factor
    print("The factorial of", n, "is", fact)
    
