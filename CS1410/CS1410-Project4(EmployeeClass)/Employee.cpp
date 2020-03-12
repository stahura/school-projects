//
//  employee.cpp
//  Project 4
//
//  Created by Riley Stahura on 10/8/18.
//  Copyright © 2018 Riley Stahura. All rights reserved.
//
#include <iostream>
#include <iomanip>
using namespace std;

#include "Employee.h"

int Employee::GetEmployeeNumber() {
    return employeeNumber;
}
string Employee::GetName() {
    
    return name;
}
string Employee::GetAddress() {
    
    return address;
}
string Employee::GetPhone() {
    
    return phone;
}
double Employee::GetWage() {
    
    return hourlyWage;
}
double Employee::GetHours() {
    
    return hoursThisWeek;
}
void Employee::setName(string employeeName) {
    name = employeeName;
}
void Employee::setAddress(string employeeAddress) {
    address = employeeAddress;
}
void Employee::setPhone(string phoneNum) {
    phone = phoneNum;
}
void Employee::setWage(double employeeWage) {
    hourlyWage = employeeWage;
}
void Employee::setHours(double hours) {
    hoursThisWeek = hours;
}

double Employee::CalcPay(double hoursWorked, double employeeWage) {
    std::cout << std::fixed;
    std::cout << std::setprecision(2);
    
    double total = 0.0;
    double overtime = 0.0;
    double fedTax = 0.0;
    double incomeTax = 0.0;
    double totalTax = 0.0;
    
    if (hoursWorked > 40) {
        overtime = hoursWorked - 40;
        overtime = overtime * .5;
        hoursWorked = hoursWorked + overtime;
        
    }
    total = hoursWorked * employeeWage;
    
    
    fedTax = total * .2;
    incomeTax = total * .075;
    totalTax = fedTax + incomeTax;
    
    total = total - totalTax;
    
    return total;
    //*** REMEMBER TO ADJUST FOR TAXES AND OVERTIME
}
void Employee::PrintCheck(string name, double netPay, double hours, double wage, string phone, string address, int employeeNumber) {
    cout << "Employee Name: " << name << endl;
    cout << "Employee Number: " << employeeNumber << endl;
    cout << "Address: " << address << endl;
    cout << "Phone: " << phone << endl;
    cout << endl << endl;
    cout << "....................UVU Computer Science Dept................................." << endl;
    cout << endl << endl;
    cout << "Pay to the order of " << name << "....................................$" << netPay << endl;
    cout << endl << endl;
    cout << "United Community Credit Union" << endl;
    cout << ".............................................................................." << endl;
    cout << endl;
    cout << "Hours worked: " << hoursThisWeek << endl;
    cout << "Hourly Wage: " << hourlyWage << endl;
    cout << endl << endl << endl << endl;
    
    
    //*** REMEMBER ADJUST FOR PROPER PRINT
}
