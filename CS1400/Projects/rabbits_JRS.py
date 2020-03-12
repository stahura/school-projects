'''
Jeffrey Riley Stahura
CS1400
Project: Rabbits, Rabbits, Rabbits
Due March 10th 2018

Scientists are doing research that requires the breeding of rabbits.
They start with 2 rabbits, 1 male, 1 female.
Every pair reproduces one pair, male and female.
Offspring cannot reproduce until after a month.
Offspring cannot have babies until the following month.


Steps:
Everything must print in a formatted table.
1.Print the following.
    A. Months that have passed.
    B. Adult rabbit PAIRS(not individuals)(An adult is over 1 month old)
    C. Baby rabbit pairs produced in given month(Always a male and female)
    D. Total number of rabbit pairs(Adult pairs + baby pairs)
2. Calculate how many months it takes until there are too many rabbits for cages
    (There are 500 cages)
3. Don't print any more rows when rabbits exceed cages
4. Print how many months it will take to run out of cages.




* I was stumped on how to remove babies from the baby counter while still adding it to adults
*   The solution was creating another variable "lastmonthbabies" and adding that to adults while
*   subtracting latmonthbabies from adults to keep the babies variable at the number it should be.
*
*

'''


def main():
   
    print("-----------------------\nRabbits Rabbits Rabbits \n-----------------------")
    print("Month Adults Babies Total")

    #initialize variables for adults, babies, total, month and last monthbabies
    adults = 1
    babies = 0
    total = adults + babies
    month = 1
    lastmonthbabies = 0

    
    
    while total <= 500:

        #Print out rows
        #Go to next month
        #Lastmonth babies needs to be added to adults as part of the new month before babies 
        #    are added to again in the for loop
        print("%3d " % month,"  ", adults,"   ", babies,"    ", total, "\n")
        month = month + 1

        lastmonthbabies = babies
        adults = adults + lastmonthbabies
            
            
        
            
        #After the first month, add 1 more baby to babies PER Adult
        #Since a baby is no longer a baby after a a month, subtract last months babies
        #   from adults to get the correct number of babies after each month
        #Tally the total amount so that the while loop can stop once it reaches 500
            
        for each in range(1, adults +1):
            babies = babies +1
        babies = adults - lastmonthbabies

        total = adults + babies
        
    #Exited While Loop, print final row and tell user how many months they have.
    print("%3d " % month,"  ", adults,"   ", babies,"    ", total, "\n")
    print("\nYou will have more rabbits than cages in", month, "months")
            
               

            

        
        
main()
            
                



