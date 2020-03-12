'''
Jeffrey Riley Stahura
CS1400
Due April 26 2018
                        Programming Project 7: Bowling Team


Create a scoring program for a bowling league, it will work as follows:

------  ------  ------  ------  ------  ------  ------  ------  ------  ------  ------                    
*At the end of each game, the program asks you to record the scores for each team member.
    You type in their first name and that person's score for the game on a single line.
    
*When there are no more players to input, enter an empty line.

#Your program should now print the following lists in columns:
    1:the names and scores of each bowler in the order entered
    2:the names and scores in descending order with high scorer at the top
    3:the names and scores in alphabetical order
    
*If anyone scores a perfect game, put an asterisk in front of their name.
*Next, your program should display the following summary information:
    1:Display a congratulatory message showing the high score and who got it.
    2:Display a sympathetic message showing the low score and who got it.
    3:The team average score, rounded down to the nearest pin.
*Last, your program should write each of the lists and the summary information
    to a text file called game_results.txt in the same format it is displayed on the screen.

------  ------  ------  ------  ------  ------  ------  ------  ------  ------  ------  
                                       Pseudocode

class Bowler:

    def init(name, score):

    def get score

    def get name

def calcAverage:
    calculate average score

def getInput:

 while true: #until they enter a blank string
 
    name = string input
    score = int input
    
    append to list of bowlers

 return list

    

def printBowlers:
    for every bowler in list
        get the score and name print it
        write to file
def getSummary:
    print summary
    write summary to file

main:

    start game

    printBowlers(list) #print out in order entered?
    
    bowlers.sort(key=Bowler.GetName)
    printBowlers(list)

    bowlers.sort(key=Bowler.GetName)
    printBowlers(list)
-------------------------------------------------------------------
                            Lessons learned
                            
*I had a hard time with writing to the file. I eventually realized I could open
    it and close it within the printBowlers function and getSummary function.
    I thought it wouldn't work to open and close multiple times
*Calling classes and functions makes much more sense after this project. Getting
    information from the classes is so SIMPLE!
    
'''


class Bowler:
    '''
    Create Bowler with Score and Name
    '''
    def __init__(self, name, score):
        self.name = name
        self.score = score
    def GetScore(self):
        return self.score
    def GetName(self):
        return self.name

def getInput():
    
    '''This function handles the bulk of the responsibilities. After taking the input
            it breaks it up into a string an int. It then calls printBowlers to print 3 times
            each one will be in a different order. It then calls getSummary.
    '''

    '''
        create empty list, give name and score as parameters to create Bowler, append
            new bowler to list of players.
    '''
    players = []
    while players == []:
        while True:
            info = input("Enter the name and score: ").split()
            print("")
            if (len(info)) == 0:
                break
            try:
                print(info[0], info[1])
                name = info[0]
                score = int(info[1])
                bowler = Bowler(name, score)
                players.append(bowler)
                #print(name, score)
            except:
                print("Please Enter Valid Input.(Enter a blank value if there are no more entries)")

    '''
    print list, reorder it in numerical order and print it, reorder it by name and print it
    '''
    printBowlers(players)
    
    players.sort(key=Bowler.GetScore, reverse=True)
    printBowlers(players)
        
    players.sort(key=Bowler.GetName)
    printBowlers(players)


    getSummary(players)


    

    
    return players
       
def calcAverage(playerList):
    '''
    This calculates the total scores of all bowlers, and divides it by the number of bowlers
        to get an average score
    '''
    outFile = open("game_results.txt", "a")
    total = 0
    count = 0
    for i in playerList:
        a = i.GetScore()
        total = total + a
        count = count + 1
    average = total/count
    average = int(average)
    print("The average score is", average)
    print("\nThe average score is", average, file=outFile)
    outFile.close()
    return average
        
        
def printBowlers(playerList):
    '''
    prints scores both to shell and writes it to the console, then closes file
    '''
    outFile = open("game_results.txt", "a")
    
    for i in playerList:
        if i.GetScore() == 300:
            print("*", end="")
        print(i.GetName(), "\t", i.GetScore())
        print(i.GetName(), "\t", i.GetScore(), file=outFile)
    print("", file=outFile)      
    print("")
    outFile.close()
   

def getSummary(playerList):
    '''
    prints summary both to console and writes to file, then closes file.
    Last step is to calculate the average, print to console and write to shell
    '''
    outFile = open("game_results.txt", "a")

    
    playerList.sort(key=Bowler.GetScore, reverse=True)
    
    winner = playerList[0]
    winnerName = winner.GetName()
    highScore = winner.GetScore()

    loser = playerList[-1]
    loserName = loser.GetName()
    loserScore = loser.GetScore()
    print("The winner is", winnerName,"! Congrats!", winnerName, "won with a score of", highScore)
    print(loserName, "did the worst, with a score of", loserScore, ". You are bad at this game.")
    print("\nThe winner is", winnerName,"! Congrats!", winnerName, "won with a score of", highScore,"\n", file=outFile)
    print(loserName, "did the worst, with a score of", loserScore, ". You are bad at this game.", file=outFile)
    outFile.close()
    outFile = open("game_results.txt", "a")    
    calcAverage(playerList)
    outFile.close()
 
    
    
def main():

    start = getInput()
    
main()

    






















            
