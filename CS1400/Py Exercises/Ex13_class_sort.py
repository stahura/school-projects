from random import *

class Bowler:

    def __init__(self, name, score):
        self.name = name
        self.score = score
        

def main():
    randList = []
    seed(1)

    for i in range(10):
        randList.append(randrange(0,101))
    

    # sort this list

    for i in range(len(randList)):
        swapped = False
        for j in range(len(randList) - 1):
            
            if (randList[j] < randList[j+1]):
                #swap
                swapped = True
                randList[j], randList[j+1] = randList[j+1], randList[j]
        if swapped == False:
            break
    print(randList)
    
    bowlers = []
    
    while True:
        data = input("Enter name and score: ").split()
        if(len(data)) == 0:
            break
        try:
            print(data[0], data[1])
            name = data[0]
            score = int(data[1])
            bowlers.append(Bowler(name, score))
            print(name, score)
        except:
            print("Bad Entry")


        print(bowlers)
main()
        

