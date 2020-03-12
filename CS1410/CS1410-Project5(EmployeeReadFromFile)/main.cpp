//
//  main.cpp
//  Project 5
//
//  Created by Riley Stahura on 10/8/18.
//  Copyright © 2018 Riley Stahura. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
using namespace std;

using std::ios;


#include "Employee.h"
void intro();
void testfunc(ofstream& infile);



int main() {
    
    string name;
    string file;
    string address;
    string phone;
    int userEntry = 0;
    
    intro();
    
    
    while (userEntry == 0) {
        cin.clear();
        cin >> userEntry;
    }
    
    if (userEntry == 1) {
        
        cout << "Please enter a file name: " << endl << endl;
        cin >> file;
        ofstream outFS;
        outFS.open(file);
        
        if (!outFS.is_open()) {
            cout << "Could not open file myoutfile.txt." << endl;
            return 1;
        }
        testfunc(outFS);
    }
    if (userEntry == 2) {
        try {
            cout << endl << "Please enter a file name: " << endl;
            cin >> file;
            ifstream inFS;
            inFS.open(file);

            if (!inFS.is_open()) {
                throw runtime_error("Couldn't open file for input");
            }
            while (inFS.eof() == false) {
                inFS.peek();
                Employee::read(inFS);
            }
        }
        

        catch(runtime_error& excpt) {
            cout << excpt.what() << endl;
            
            
        }
    }
    

    
    

    return 0;
}

void intro() {
    
    cout << "This program has two options:" << endl;
    cout << "1 - Create a data file, or" << endl;
    cout << "2 - Read data from a file and print paychecks." << endl;
    cout << "Please enter (1) to create a file or (2) to print checks:" << endl;
}
void testfunc(ofstream& infile) {
    
    Employee joe(37, "Joe Brown", "123 Main St.", "123-6788", 45.00, 10.00);
    joe.write(infile);
    Employee sam(21, "Sam Jones", "45 East State", "661-9000", 30.00, 12.00);
    sam.write(infile);
    Employee mary(15, "Mary Smith", "12 High Street", "401-8900", 40.00, 15.00);
    mary.write(infile);
    
    infile.close();
    cout << "Data file created ... you can now run option 2." << endl;
}

