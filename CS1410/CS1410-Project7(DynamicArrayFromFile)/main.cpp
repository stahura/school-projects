//
//  main.cpp
//  Project 7
//
//  Created by Riley Stahura on 11/8/18.
//  Copyright © 2018 Riley Stahura. All rights reserved.
//

#include <iostream>
#include <string>
#include "Employee.hpp"
#include <vector>
#include <fstream>

using namespace std;
void intro();


int main() {
    int userEntry = 0;
    string file;
    ofstream outFS;
    ifstream inFS;
    vector<Employee*> employeeList;
    
    intro();
    
    while (userEntry == 0) {
        cin.clear();
        cin >> userEntry;
    }
    if(userEntry == 1) {
    
       
        employeeList.push_back(new HourlyEmployee(1, "H. Potter", "Privet Drive", "201-9090", 40, 12.00));
        employeeList.push_back(new SalariedEmployee(2, "A. Dumbledore", "Hogwarts", "803-1230", 1200));
        employeeList.push_back(new HourlyEmployee(3, "R. Weasley", "The Burrow", "892-2000", 40, 10.00));
        employeeList.push_back(new SalariedEmployee(4, "R. Hagrid", "Hogwarts", "910-8765", 1000));
        cout << "Please enter a file name: " << endl;
        cin >> file;
        cout << endl;
        outFS.open(file); //REMEMBER TO CLOSE FILE
        
        
        for (int i = 0; i < employeeList.size(); i++) {
            employeeList.at(i)->write(outFS); //REMEMBER TO CLOSE FILE
        }
        outFS.close();
        cout << "Data file created ... you can now run option 2.";
        
    } else if (userEntry == 2) {
        cout << "Please enter a file name: " << endl;
        cin >> file;
        cout << endl;
        inFS.open(file);
        
        HourlyEmployee::read(inFS);
        SalariedEmployee::read(inFS);
        HourlyEmployee::read(inFS);
        SalariedEmployee::read(inFS);
        
    }
    inFS.close();

    
    return 0;
}

void intro() {
    
    cout << "This program has two options:" << endl;
    cout << "1 - Create a data file, or" << endl;
    cout << "2 - Read data from a file and print paychecks." << endl;
    cout << "Please enter (1) to create a file or (2) to print checks:" << endl << endl;
}


