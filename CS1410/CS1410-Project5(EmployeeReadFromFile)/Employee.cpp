//
//  employee.cpp
//  Project 5
//
//  Created by Riley Stahura on 10/8/18.
//  Copyright © 2018 Riley Stahura. All rights reserved.
//
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

#include "Employee.h"


Employee::Employee() {
    employeeNumber= 0;
    name = "no_name";
    address = "no_address";
    phone = "no_phone";
    hourlyWage = 0.0;
    hoursThisWeek = 0.0;
    
}
Employee::Employee(int initNum, string initName, string initPhone,string initAddress, double initHours, double initWage) {
    employeeNumber= initNum;
    address = initAddress;
    name = initName;
    phone = initPhone;
    hoursThisWeek = initHours;
    hourlyWage = initWage;
    
}
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
void Employee::setEmpNum(int employeeNum) {
    employeeNumber = employeeNum;
}
void Employee::write(ofstream& file) {
    
    file << employeeNumber << endl;
    file << name << endl;
    file << address << endl;
    file << phone << endl;
    file << hoursThisWeek << endl;
    file << hourlyWage << endl << endl;
}

void Employee::read(ifstream& file) {
    
    double netpay = 0.0;
    
    
    int eNum, eWage, eHours;
    file >> eNum;
    file.ignore(1024, '\n');
    
    string eName;
    getline(file, eName);
    
    string eAddress;
    getline(file, eAddress);
    
    string ePhone;
    getline(file, ePhone);
    
    file >> eHours;
    file.ignore(1024, '\n');
    
    file >> eWage;
    file.ignore(1024, '\n');
        
    Employee tmp;
    
    tmp.setEmpNum(eNum);
    tmp.setName(eName);
    tmp.setAddress(eAddress);
    tmp.setPhone(ePhone);
    tmp.setHours(eHours);
    tmp.setWage(eWage);
    netpay = tmp.CalcPay(eHours, eWage);
    if(file.eof() == false) {
        tmp.PrintCheck(eName, netpay, eHours, eWage, ePhone, eAddress, eNum);
    }
    
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
    
}
void Employee::PrintCheck(string name, double netPay, double hours, double wage, string phone, string address, int employeeNumber) {

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
    
    
    
}

