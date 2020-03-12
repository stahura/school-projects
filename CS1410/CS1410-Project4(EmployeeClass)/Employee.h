//
//  employee.hpp
//  Project 4
//
//  Created by Riley Stahura on 10/8/18.
//  Copyright © 2018 Riley Stahura. All rights reserved.
//

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
using namespace std;

class Employee {
    
public:
    
    //Employee(int initNum = 0, string initName = "NoName", string initAddress = "a", string initPhone = "1", double initWage = 0.0, double initHours = 0.0);
    
    int GetEmployeeNumber();
    string GetName();
    string GetAddress();
    string GetPhone();
    double GetWage();
    double GetHours();
    void setName(string employeeName);
    void setAddress(string employeeAddress);
    void setPhone(string phoneNum);
    void setWage(double employeeWage);
    void setHours(double hours);
    
    
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
