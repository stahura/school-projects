//
//  Employee.cpp
//  Project 7
//
//  Created by Riley Stahura on 11/8/18.
//  Copyright © 2018 Riley Stahura. All rights reserved.
//

#include "Employee.hpp"
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

// ************************************************
//*************** Generic Employee *****************
// ************************************************

Employee::Employee() {
    empNum = 0;
    name = "John Doe";
    address = "123";
    phone = "321";
    
}
Employee::Employee(int initNum, string initName, string initAddr, string initPhone) {
    empNum = initNum;
    name = initName;
    address = initAddr;
    phone = initPhone;
}
Employee::~Employee() {
    
}

//GETTERS
int Employee::GetEmpNum() {
    return empNum;
}
string Employee::GetName() {
    return name;
}
string Employee::GetAddress() {
    return address;
}
string Employee::GetPhone(){
    return phone;
}

//SETTERS
void Employee::setName(string employeeName) {
    name = employeeName;
}
void Employee::setAddress(string employeeAddress){
    address = employeeAddress;
}
void Employee::setPhone (string employeePhone) {
    phone = employeePhone;
}
void Employee::setNum(int employeeNumber) {
    empNum = employeeNumber;
    //FIXME: Assignment doesn't say to create this function..
}

void Employee::write(ofstream& file) {
    file << empNum << endl;
    file << name << endl;
    file << address << endl;
    file << phone << endl;
    
    
}

//FUNCTIONS
double Employee::CalcPay() {
    double total;
    
    return 100.0;
}
void Employee::PrintCheck() {
    cout<< endl << "Employee Class Print Check";
}
void Employee::readData(ifstream& file) {
    int tempNum;
    double tempWage, tempHours;
    file >> tempNum;
    file.ignore(1024, '\n');
    
    string tempName;
    getline(file, tempName);
    
    string tempAddress;
    getline(file, tempAddress);
    
    string tempPhone;
    getline(file, tempPhone);
    
    file >> tempHours;
    file.ignore(1024, '\n');
    
    file >> tempWage;
    file.ignore(1024, '\n');
    //FIXME: This returns an Hourly Employee Pointer
    // This will call ReadData();
    
    
    
    cout << "Setting name"<< endl;
    setName(tempName);
    setAddress(tempAddress);
    setPhone(tempPhone);
    setNum(tempNum);
   
    
    //this->calcPay();
    if(file.eof() == false) {
        this->PrintCheck();
        
    }
    
}
// ************************************************
//*************** Hourly Employee *****************
// ************************************************
HourlyEmployee::HourlyEmployee(int initNum, string initName, string initAddr, string initPhone, double initHoursWorked, double initWage) {
    
    setName(initName);
    setAddress(initAddr);
    setPhone(initPhone);
    setNum(initNum);
    hoursWorked = initHoursWorked;
    hourlyWage = initWage;
    
    
    //FIXME: How to define num/name/addr/phone if they are private members of base class?
}
double HourlyEmployee::getHoursWorked() {
    return hoursWorked;;
}
double HourlyEmployee::getHourlyWage() {
    return hourlyWage;
}
void HourlyEmployee::setHoursWorked(double hoursWorked) {
    
}
void HourlyEmployee::setHourlyWage(double hourlyWage) {
    
}
void HourlyEmployee::write(ofstream& file) {
    file << GetEmpNum() << endl;
    file << GetName() << endl;
    file << GetAddress() << endl;
    file << GetPhone() << endl;
    file << hoursWorked << endl;
    file << hourlyWage << endl;
}
double HourlyEmployee::calcPay() {
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
    total = hoursWorked * hourlyWage;
    
    
    fedTax = total * .2;
    incomeTax = total * .075;
    totalTax = fedTax + incomeTax;
    
    total = total - totalTax;
    
    
    return total;

}
void HourlyEmployee::PrintCheck() {
    cout << endl << endl;
    cout << "....................UVU Computer Science Dept................................." << endl;
    cout << endl << endl;
    cout << "Pay to the order of " << this->GetName() << "....................................$" << this->calcPay() << endl;
    cout << endl << endl;
    cout << "United Community Credit Union" << endl;
    cout << ".............................................................................." << endl;
    cout << endl;
    cout << "Hours worked: " << hoursWorked << endl;
    cout << "Hourly Wage: " << hourlyWage << endl;
    cout << endl << endl << endl << endl;
}
void HourlyEmployee::readData(ifstream& file) {
    int tempNum;
    double tempWage, tempHours;
    file >> tempNum;
    file.ignore(1024, '\n');
    
    string tempName;
    getline(file, tempName);
    
    string tempAddress;
    getline(file, tempAddress);
    
    string tempPhone;
    getline(file, tempPhone);
    
    file >> tempHours;
    file.ignore(1024, '\n');
    
    file >> tempWage;
    file.ignore(1024, '\n');
    //FIXME: This returns an Hourly Employee Pointer
    // This will call ReadData();
    
    
    
    
    setName(tempName);
    setAddress(tempAddress);
    setPhone(tempPhone);
    setNum(tempNum);
    hoursWorked = tempHours;
    hourlyWage = tempWage;
    
    
    //this->calcPay();
    if(file.eof() == false) {
        this->PrintCheck();
        
    }
    
}
HourlyEmployee* HourlyEmployee::read(ifstream& file) {
    HourlyEmployee* tmp = nullptr;
    tmp = new HourlyEmployee();
    
    tmp->readData(file);
    
    delete tmp;
    tmp = nullptr;
    
    return tmp;
    //HOW TO CALL HourlyEmployee::read(inFS);
    
    
}


// ************************************************
//*************** Salaried Employee *****************
// ************************************************

SalariedEmployee::SalariedEmployee(int initNum, string initName, string initAddr, string initPhone, double initSalary) {
    setName(initName);
    setAddress(initAddr);
    setPhone(initPhone);
    setNum(initNum);
    salary = initSalary;
}
double SalariedEmployee::getSalary(){
    return salary;
}
void SalariedEmployee::setSalary(double n) {
    salary = n;
}
void SalariedEmployee::write(ofstream& file) {
    file << GetEmpNum() << endl;
    file << GetName() << endl;
    file << GetAddress() << endl;
    file << GetPhone() << endl;
    file << salary << endl;
    
}
double SalariedEmployee::calcPay() {
    double total = 0.0;
    double fedTax = 0.0;
    double incomeTax = 0.0;
    double totalTax = 0.0;
    double benefitsTax = 0.0;
    
    total = salary;
    fedTax = total * .2;
    incomeTax = total * .075;
    benefitsTax = total * .0524;
    totalTax = fedTax + incomeTax + benefitsTax;
    total = total - totalTax;

    return total;
}
void SalariedEmployee::PrintCheck() {
    cout << endl << endl;
    cout << "....................UVU Computer Science Dept................................." << endl;
    cout << endl << endl;
    cout << "Pay to the order of " << this->GetName() << "....................................$" << this->calcPay() << endl;
    cout << endl << endl;
    cout << "United Community Credit Union" << endl;
    cout << ".............................................................................." << endl;
    cout << endl;
    
    cout << endl << endl  << endl << "Salary: " << salary << endl;
}
SalariedEmployee* SalariedEmployee::read(ifstream& file) {
    SalariedEmployee* tmp = nullptr;
    tmp = new SalariedEmployee();
    
    tmp->readData(file);
    
    
    delete tmp;
    tmp = nullptr;
    
    return tmp;
    //HOW TO CALL HourlyEmployee::read(inFS);
    
    
}
void SalariedEmployee::readData(ifstream& file) {
    int tempNum;
    double tempSalary;
    
    file >> tempNum;
    file.ignore(1024, '\n');
    
    string tempName;
    getline(file, tempName);
    
    string tempAddress;
    getline(file, tempAddress);
    
    string tempPhone;
    getline(file, tempPhone);
    
    file >> tempSalary;
    file.ignore(1024, '\n');
    
    
    
    setName(tempName);
    setAddress(tempAddress);
    setPhone(tempPhone);
    setNum(tempNum);
    setSalary(tempSalary);
    
    
    if(file.eof() == false) {
        this->PrintCheck();
        
    }
    
}
