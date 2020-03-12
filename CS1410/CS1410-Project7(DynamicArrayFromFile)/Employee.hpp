//
//  Employee.hpp
//  Project 7
//
//  Created by Riley Stahura on 11/8/18.
//  Copyright © 2018 Riley Stahura. All rights reserved.
//

#ifndef Employee_hpp
#define Employee_hpp

#include <stdio.h>
#include <string>
using namespace std;

class Employee {
    
public:
    virtual ~Employee();
    
    int GetEmpNum();
    string GetName();
    string GetAddress();
    string GetPhone();
    
    void setName(string employeeName);
    void setAddress(string employeeAddress);
    void setPhone(string employeePhone);
    void setNum(int employeeNum);
    
    virtual void write(ofstream& file);
    virtual double CalcPay();
    virtual void PrintCheck();

protected:
    Employee();
    Employee(int initNum, string initName, string initAddr, string initPhone);
    
    virtual void readData(ifstream& file);
    
private:
    int empNum;
    string name;
    string address;
    string phone;
    
};

class HourlyEmployee : public Employee {

public:
    
    HourlyEmployee(int initNum, string initName, string initAddr, string initPhone, double initHoursWorked, double initWage);
    double getHoursWorked();
    double getHourlyWage();
    void setHoursWorked(double hoursWorked);
    void setHourlyWage(double hourlyWage);
    void write(ofstream& file);
    double calcPay();
    void PrintCheck();
    static HourlyEmployee* read(ifstream& file);
    
protected:
    HourlyEmployee() = default;
    void readData(ifstream& file);
    
private:
    double hoursWorked;
    double hourlyWage;
    
    
};

class SalariedEmployee : public Employee {
    
public:
    SalariedEmployee(int initNum, string initName, string initAddr, string initPhone, double initSalary);
    double getSalary();
    void setSalary(double);
    void write(ofstream& file);
    double calcPay();
    void PrintCheck();
    static SalariedEmployee* read(ifstream& file);
    
    
protected:
    SalariedEmployee() = default;
    void readData(ifstream& file);
    
private:
    double salary;
    
};
#endif /* Employee_hpp */
