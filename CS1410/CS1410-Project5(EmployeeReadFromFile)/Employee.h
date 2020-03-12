//
//  employee.hpp
//  Project 5
//
//  Created by Riley Stahura on 10/8/18.
//  Copyright © 2018 Riley Stahura. All rights reserved.
//

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <fstream>
#include <string>
using namespace std;

class Employee {
    
public:
    
    Employee();
    Employee(int initNum , string initName , string initPhone ,string initAddress , double initHours , double initWage);

    int GetEmployeeNumber();
    string GetName();
    string GetAddress();
    string GetPhone();
    double GetWage();
    double GetHours();
    void setEmpNum(int employeeNum);
    void setName(string employeeName);
    void setAddress(string employeeAddress);
    void setPhone(string phoneNum);
    void setWage(double employeeWage);
    void setHours(double hours);
    void write(ofstream& file);
    static void read(ifstream& file);
    
    double CalcPay(double hoursWorked, double employeeWage);
    void PrintCheck(string name, double netPay, double hours, double wage, string phone, string address, int employeeNumber);
    
private:
    
    int employeeNumber;
    string name;
    string address;
    string phone;
    double hourlyWage;
    double hoursThisWeek;
    
};









#endif
