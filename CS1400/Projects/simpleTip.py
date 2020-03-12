#Project 1: Simple Tip Calculator
#Jeffrey Riley Stahura - 10617813

    #Users have a difficult time calculating tips
        #A:Solution is to calculate each tip for them based on Meal Price.
        #B:Allow user to input Meal Price
        #C:Meal price will be multipled by .20,.15, and .10 based on quality of service.
        #D:Print out separate line for the price of each tip based on quality of service
        #E:Print out the sum of the tip + meal price

def main():

    #User Input

    print("We've made it easy to calculate your tip. Just enter the following: ")
    mealCost = float(input("How much did the meal cost?: "))

    #Variables for tip calculation and formatting
    excellent = mealCost * .20
    average = mealCost *.15
    poor = mealCost * .10

    tipExcellent = "would be: ${0:0.2f}".format(excellent,2)
    tipAverage = "would be: ${0:0.2f}".format(average,2)
    tipPoor = "would be: ${0:0.2f}".format(poor,2)

    #Print the tip and total amount for each service level
    
    print("The meal was: ${0:0.2f}".format(mealCost,2))
    
    print("A tip for excellent service",tipExcellent,"for a total of: ${0:0.2f}".format(excellent + mealCost,2 ))
    print("A tip for average service ",tipAverage,"for a total of: ${0:0.2f}".format(average + mealCost,2 ))
    print("A tip for poor service ",tipPoor,"for a total of: ${0:0.2f}".format(poor + mealCost))
    print("  *If you'd like, let us know how you felt about our service by filling out a survey*")
    

main()


#I had a difficult time figuring out how to force the total price to show 2 decimal places.
#      Chapter 5(5.8.2) is where I found the answer
