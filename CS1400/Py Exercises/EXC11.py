from graphics import *
from button import Button
#Calculator
class Calculator:
    
    def __init__(self):
        win = GraphWin("Calculator")
        win.setCoords(0,0,6,7)
        win.setBackground("slategray")
        self.win = win
        #create widgets
        self.__createButtons()
        self.__createDisplay()


    #buttons list
    ##start with standard sized buttons
    #bspecs gives center coords and label of buttons
    def __createButtons(self):
            

        bSpecs = [(2,1,'0'), (3,1,'.'),
                  (1,2,'1'), (2,2,'2'), (3,2,'3'), (4,2,'+'),  (5,2,'-'),
                  (1,3,'4'), (2,3,'5'), (3,3,'6'), (4,3,'*'),  (5,3,'/'),
                  (1,4,'7'), (2,4,'8'), (3,4,'9'), (4,4,'<-'), (5,4,'C')]
        self.buttons = []

        for(cx,cy,label) in bSpecs:
            self.buttons.append(Button(self.win,Point(cx,cy),.75,.75,label))
        #create larger '=' button
        self.buttons.append(Button(self.win, Point(4.5,1), 1.75, .75, "="))
        #activate buttons
        for b in self.buttons:
            b.activate()

    def __createDisplay(self):
        bg = Rectangle(Point(.5,5.5), Point(5.5,6.5))
        bg.setFill('white')
        bg.draw(self.win)
        text = Text(Point(3,6), "")
        text.draw(self.win)
        text.setFace("courier")
        text.setStyle("bold")
        text.setSize(16)
        self.display = text



    def run(self):
        while True:
            key = self.getButton()
            self.processButton(key)

    def getButton(self):
        #wait for button click
        #return label of button that was clicked
        while True:
            #loop for each mouse click
            p = self.win.getMouse()
            for b in self.buttons:
                #loop for each button
                if b.clicked(p):
                    return b.getLabel()
    def processButton(self,key):
        #updates display of calculator for press of this key
        text = self.display.getText()
        if key == 'C':
            self.display.setText("")
        elif key == '<-':
            #backspace, slice last character
            self.display.setText(text[:-1])
        elif key == '=':
            #evaluate and display
            try:
                result = eval(text)
            except:
                result = 'ERROR'
            self.display.setText(str(result))
        else:
            #Normal key press, append to end of display
            self.display.setText(text+key)

if __name__ == '__main__':
    #Create calculator object
    theCalc = Calculator()
    #call calculator run method
    theCalc.run()

    
