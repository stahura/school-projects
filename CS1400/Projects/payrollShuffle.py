'''
Jeffrey Riley Stahura
CS1400
Due April 14 2018

                                Payroll Shuffle

An Employee has the following attributes:

employee number
name
street address
hourly wage
hours worked this week

An employee object will need the following methods:

A constructor for the employee class that takes arguments to initialize all of the above mentioned attributes.
A method, calc_salary(), that calculates and returns an employee's net pay as a double. 
An employee's gross pay is calculated by multiplying the hours worked by their hourly wage. Be sure to give time-and-a-half for overtime (anything over 40 hours). 
To compute the net pay, deduct 20% for Federal income tax, and 7.5% for state income tax.


Create Employee class
     def init   
        id
        name
        address
        wage
        hours
    def salary

        overtime pay
        if hours are more than 40
            gross pay includes overtime pay
        else
            gross pay is hours * wage

        calculate taxes
        subtract taxes from gross, that is net

        

        return net pay
        
def getinfo
    open file
    read file

    for every line in file
        remove \n from line
        add to list

    take items from list and make 5 different lists to be used for each employee

    return 5 lists

def main

    draw Graph

    draw labels

    draw button

    draw text to be changed based on input

    create employee objects

    while loop

        get mouse click
        if mouse is clicked
            populate employee information
        #REPEAT THE ABOVE 5 times ^^^^^

----------------------------------------------------------------------------------------
                                LESSONS LEARNED


I had a really hard time figuring out how to make the button actually work. I realized I just had to
    create a while loop and wait for a mouse click.
I finally figured out how to get the information from the data.txt file into the Employee parameters
    but my solution seems sloppy. I imported it as 1 big list, broke it into 5 lists and returned the lists.
    When that is returned, it is returned as a LIST of 5 LISTS. Each index of that list was made into a list.
    I then could take the index of the 5 lists and use each index as a paramenter for Employee Class.
I could not figure out how to keep the Grpahics information in a separate function. For example, the button, labels
    text field for employee information. To save time  I put it all in main.
TKINTER gave me issues. When I opened the file and read it, it had issues converting certain strings to Integers. I
    need to be able to do that, otherwise I won't be able to calculate wage * hours later on. I eventually realized
    i had to tweak the syntax and read every line of "f" instead of every line of "inFile"
    
'''






from button import *
from projectile import *
from math import *
from random import *
from tkinter.filedialog import askopenfilename

class Employee:
    '''Creates Employee objects with the information that it is input
       It asks for id, name, address, wage and hours.

       It also includes a calc_salary method to calculate their salary
       with the hour and wage given.
    '''

    def __init__(self, id_num, name, address, wage, hours):
        self.id_num = id_num
        self.name = name
        self.address = address
        self.wage = wage
        self.hours = hours

    def calc_salary(self, wage, hours):

        overtime_pay = self.wage/2 + self.wage

        
        if hours > 40:
            gross_pay = self.hours * overtime_pay
        else:
            gross_pay = self.hours * self.wage

        federal_tax = gross_pay * .20
        state_tax = gross_pay * .075

        net_pay = gross_pay - (federal_tax + state_tax)


        
        return net_pay

    



def getInfo():
    '''This function opens the file, reads the information and places it into a list
        Once it's in a list, it converts wage and hour into floats in order to be able
        to be multiplied in Employee.calc_salary
    '''

    testList = []
    inFile = askopenfilename()
    f = open(inFile)

    for line in f:
        line = line.strip("\n")
        testList.append(line)
    
    '''Takes every 5 items in list to create it's own list'''
    info0 = testList[0:5]
    info0[3], info0[4] = float(info0[3]), float(info0[4])
    info1 = testList[5:10]
    info1[3], info1[4] = float(info1[3]), float(info1[4])
    info2 = testList[10:15]
    info2[3], info2[4] = float(info2[3]), float(info2[4])
    info3 = testList[15:20]
    info3[3], info3[4] = float(info3[3]), float(info3[4])
    info4 = testList[20:25]
    info4[3], info4[4] = float(info4[3]), float(info4[4])
    '''close file'''    
    f.close()
    return info0, info1, info2, info3, info4
    

    
def main():

    '''Main will draw the graph, draw all labels and buttons, create new employees
    '''

    win = GraphWin("Fluff Shuffle Electronics", 500,500)
    win.setBackground('light gray')
    win.setCoords(-10.0,-10.0, 10.0, 10.0)

    '''Points to use for the Labels'''
    p1 = Point(-2,7)
    p2 = Point(-2,5)
    p3 = Point(-2,3)
    p4 = Point(-2,1)
    p5 = Point(-2,-1)
    p6 = Point(-2,-3)

    '''Create and Draw Labels'''
    id_label = Text(p1,"  ID Number:")
    id_label.setSize(20)
    id_label.setStyle('bold')
    id_label.draw(win)
    name_label = Text(p2,"       Name:")
    name_label.setSize(20)
    name_label.setStyle('bold')
    name_label.draw(win)
    address_label = Text(p3," Address:")
    address_label.setSize(20)
    address_label.setStyle('bold')
    address_label.draw(win)
    wage_label = Text(p4,"Hourly Wage:")
    wage_label.setSize(20)
    wage_label.setStyle('bold')
    wage_label.draw(win)
    hours_label = Text(p5,"Hours Worked:")
    hours_label.setSize(20)
    hours_label.setStyle('bold')
    hours_label.draw(win)
    net_label = Text(p6,"    Net Pay:")
    net_label.setSize(20)
    net_label.setStyle('bold')
    net_label.draw(win)

    '''Create points to be used as the first parameter for Text Objects below'''
    pnt1 = Point(3,7)
    pnt2 = Point(3,5)
    pnt3 = Point(3,3)
    pnt4 = Point(3,1)
    pnt5 = Point(3,-1)
    pnt6 = Point(3,-3)

    '''Create Text for employee info to populate, next to labels'''
    id_info = Text(pnt1, "")
    id_info.setSize(15)
    id_info.draw(win)
    name_info = Text(pnt2, "")
    name_info.setSize(15)
    name_info.draw(win)    
    address_info = Text(pnt3, "")
    address_info.setSize(15)
    address_info.draw(win)
    wage_info = Text(pnt4, "")
    wage_info.setSize(15)
    wage_info.draw(win)
    hours_info = Text(pnt5, "")
    hours_info.setSize(15)
    hours_info.draw(win)
    net_info = Text(pnt6, "")
    net_info.setSize(15)
    net_info.draw(win)
    '''Create NEXT Button'''
    nextButton = Button(win, Point(0, -6), 6, 2, "Next Employee")
    nextButton.activate()

    '''file grabs info from getInfo function. That information will be returned in the form of a list
       of lists.
    '''
    file = getInfo()
    
    '''the following creates 5 lists, each index of "file" is a list, each list will be used
       and inputted into the Employee parameters for each employee.
    '''
    info0 = file[0]
    info1 = file[1]
    info2 = file[2]
    info3 = file[3]
    info4 = file[4]

    '''Create employees. Each index of each list are the required parameters for Employee Class
    '''
    employee0 = Employee(info0[0],info0[1],info0[2],info0[3],info0[4])
    employee1 = Employee(info1[0],info1[1],info1[2],info1[3],info1[4])
    employee2 = Employee(info2[0],info2[1],info2[2],info2[3],info2[4])
    employee3 = Employee(info3[0],info3[1],info3[2],info3[3],info3[4])
    employee4 = Employee(info4[0],info4[1],info4[2],info4[3],info4[4])
    

    '''Initialize a, this will ensure the WHILE loop never ends so that you can
       always click next employee
    '''
            
    a = 2
   
    
    while a != 1:
        '''While Loop loops forever. When you click Next Employee after the 5th empoloyee it starts over.
           Before each IF statement it waits until you click on the Next Employee Button 
        '''

        pt0 = win.getMouse()
        if nextButton.clicked(pt0):
            id_info.setText(employee0.id_num)
            name_info.setText(employee0.name)
            address_info.setText(employee0.address)
            wage_info.setText(employee0.wage)
            hours_info.setText(employee0.hours)
            net_info.setText(employee0.calc_salary(employee0.wage, employee0.hours))
        
        pt1 = win.getMouse()
        if nextButton.clicked(pt1):
            id_info.setText(employee1.id_num)
            name_info.setText(employee1.name)
            address_info.setText(employee1.address)
            wage_info.setText(employee1.wage)
            hours_info.setText(employee1.hours)
            net_info.setText(employee1.calc_salary(employee1.wage, employee1.hours))
            
            
        pt2 = win.getMouse()
        if nextButton.clicked(pt2):
            id_info.setText(employee2.id_num)
            name_info.setText(employee2.name)
            address_info.setText(employee2.address)
            wage_info.setText(employee2.wage)
            hours_info.setText(employee2.hours)
            net_info.setText(employee2.calc_salary(employee2.wage, employee2.hours))

        pt3 = win.getMouse()
        if nextButton.clicked(pt3):
            id_info.setText(employee3.id_num)
            name_info.setText(employee3.name)
            address_info.setText(employee3.address)
            wage_info.setText(employee3.wage)
            hours_info.setText(employee3.hours)
            net_info.setText(employee3.calc_salary(employee3.wage, employee3.hours))
            

        pt4 = win.getMouse()
        if nextButton.clicked(pt4):
            id_info.setText(employee4.id_num)
            name_info.setText(employee4.name)
            address_info.setText(employee4.address)
            wage_info.setText(employee4.wage)
            hours_info.setText(employee4.hours)
            net_info.setText(employee4.calc_salary(employee4.wage, employee4.hours))  


    
    
main()
    

        

    

        
