//
//  main.cpp
//  Project 4
//
//  Created by Riley Stahura on 10/8/18.
//  Copyright © 2018 Riley Stahura. All rights reserved.
//

#include <iostream>
using namespace std;

#include "Employee.h"

int main() {
    string name;
    double wage;
    double hours;
    double netPay;
    string address;
    string phone;
    int employeeNum;
    int userEntry = 0;
    
    Employee employee1;
    Employee employee2;
    
    employee1.setName("Joe Brown");
    employee1.setWage(10.0);
    employee1.setHours(45.0);
    employee1.setPhone("123-6788");
    employee1.setAddress("123 Main St.");
    
    employee2.setName("Sam Jones");
    employee2.setWage(12.50);
    employee2.setHours(30.0);
    employee2.setPhone("661-9000");
    employee2.setAddress("45 East State");
    
    //Intitial questions
    cout << "This program has two options:" << endl;
    cout << "1 - Create a data file, or" << endl;
    cout << "2 - Read data from a file and print paychecks." << endl;
    cout << "Please enter <1> to create a file or <2> to print checks:" << endl;
    //End intitial questions
    while (userEntry == 0) {
        cin.clear();
        cin >> userEntry;
    }
    
    
        name = employee1.GetName();
        wage = employee1.GetWage();
        hours = employee1.GetHours();
        phone = employee1.GetPhone();
        address = employee1.GetAddress();
        netPay = employee1.CalcPay(hours, wage);
        employeeNum = 37;
        
        
        
        employee1.PrintCheck(name, netPay, hours, wage, phone, address, employeeNum);
        
        name = employee2.GetName();
        wage = employee2.GetWage();
        hours = employee2.GetHours();
        phone = employee2.GetPhone();
        address = employee2.GetAddress();
        netPay = employee2.CalcPay(hours, wage);
        employeeNum = 37;
        
        employee2.PrintCheck(name, netPay, hours, wage, phone, address, employeeNum);
        
        
    
    
    
    
    
    cout << endl;
    
    
    
    
    
    
    
    return 0;
}
