class Bowler:

    def __init__(self, name, score):
        self.name = name
        self.score = score

    def GetName(self):
        return self.name

    def GetScore(self):
        return self.score

def PrintBowlers(listOfBowlers):
    for i in listOfBowlers:
        if i.GetScore() == 300:
            print("*", end="")

        print(i.GetName(), "\t", i.GetScore())
    print()
    
    
def main():
    bowlers = []
    bowlers.append(Bowler("Riley", 100))
    bowlers.append(Bowler("Olivia", 70))
    bowlers.append(Bowler("Maria", 80))
    bowlers.append(Bowler("Talon", 60))
    bowlers.append(Bowler("Seth", 50))

    outFile = open("game_results.txt", "w")

    for i in bowlers:
        print(i.GetName(), "\t", i.GetScore())
    print("")

    bowlers.sort(key=Bowler.GetName)
    for i in bowlers:
        print(i.GetName(), "\t", i.GetScore())
    print("")

    bowlers.sort(key=Bowler.GetScore)
    for i in bowlers:
        print(i.GetName(), "\t", i.GetScore())
    print("")

    print("hello", file=outFile)
    outFile.close()


    '''
    PrintBowlers(bowlers)

    bowlers.sort(key=Bowler.GetName)
    PrintBowlers(bowlers)

    bowlers.sort(key=Bowler.GetScore, reverse=True
    

    bowlers.sort(key=Bowler.GetScore, reverse=True)
    for i in bowlers:
       print(i.GetName(), "\t", i.GetScore())
           
    '''        


    
    

main()
