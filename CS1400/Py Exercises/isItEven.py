from math import *
from random import *

def even(x):
    if x % 2 == 0:
        print("It is even")
    else:
        print("It is odd")
def main():

    x = int(input("Enter: "))

    even(x)


def disc1():

    s1 = [2,1,4,3]
    s2 = ['c','a','b']

    print("a: ",s1 + s2)
    print("b: ",3 * s1 + 2 * s2)
    print("c: ",s1[1])
    print("d: ",s1[1:3])
    print(s2[-1] + s1)
    #print(s1 + s2[-1])

def shuffles():

    myList = [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15]

    myListRange = range(0, len(myList))

    for i in myListRange:

        randnum = randrange(myListRange[0], myListRange[-1])
        myList[i], myList[randnum] = myList[randnum], myList[i]
        
    print(myList)

def innerProd(x,y):

    a = x[0] * y[0]
    b = x[1] * y[1]
    sum = a + b
    return sum
print(innerProd([1,2],[3,4]))
    



