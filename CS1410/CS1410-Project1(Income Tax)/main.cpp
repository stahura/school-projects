//
//  main.cpp
//  C Playground
//
//  Created by Riley Stahura on 8/22/18.
//  Copyright © 2018 Riley Stahura. All rights reserved.
//
/*
 For this project, you should write a program that does the following:
 
 1.Prompt the user to enter in their taxable income.
 2.Get the input. Validate the input to insure that it is a positive value. You may assume that a numerical value is entered.
 3.Prompt the user to enter in "s" or "m" for filing single or jointly.
 4.Get the input and validate that it is either "s" or "m". Re-do this step if the input is not valid.
 5.Based on the user's input, calculate the user's tax using the appropriate tax table and display the amount of money that person owes. Present this data nicely formatted.
 6.Ask the user if they want to do another tax calculation.
 7.Accept either 'y', 'n', or 'q' as input. Validate the input and re-do this step if it is not correct.
 8.If the user selects 'y' start back at step one. If the user selects 'q', quit. For all other choices, tell the user that an invalid choice was made and ask them to input again.
 */
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    
    double income= 0.0;
    string status = "a";
    string restart = "a";
    int exitNum = 0;
    double rate = 0.00;
    double flat = 0;
    double sub = 0.0;
    double taxes = 0.0;
    int programExitCode = 0;
    int promptCode = 0;
    string returnType;
    
    std::cout << std::fixed;
    std::cout << std::setprecision(2);
   
    
    //double taxTotal = 0.0;
    
    while (programExitCode == 0) {
        cout << "Please enter your taxable income. " << endl;
        cout << "(This must be a positive number): ";
        
        while (exitNum == 0) {
            cin >> income;
            if (income > 0){
                exitNum = 1;
            }else {
                cout << "Please enter a positive number";
            }
        }
        exitNum = 0;
        cout << endl;
        while (exitNum == 0) {
            cout << "Please enter 'm' if married and filing joint return"<< endl;
            cout << "or 's' if filing a single return" << endl;
            cin >> status;
            cout << endl;
            if (status == "s") {
                //break;
                exitNum = 1;
            }
            if (status == "m") {
                //break;
                exitNum = 1;
            }
        }
        //cout << "status is:" << status << endl;
        
        //cout << income << endl << status;
        
        if (status == "m") {
            
            returnType = " joint return";
            
            if ((income >= 0) && (income <= 1726)) {
                rate = .023;
                flat = 0;
                sub = 0;
            }
            if ((income >= 1727) && (income <= 5176)) {
                rate = .033;
                flat = 40;
                sub = 1726;
                
            }
            if ((income >= 5177) && (income <= 8626)) {
                rate = .052;
                flat = 175;
                sub = 5176;
                
            }
            if (income > 8626) {
                rate = .075;
                flat = 390;
                sub = 8626;
                
            }
            
        }
        if (status == "s") {
            
            returnType = " single return";
            
            if ((income >= 0) && (income <= 863)) {
                rate = .023;
                flat = 0;
                sub = 0;
                
            }
            if ((income >= 864) && (income <= 2588)) {
                rate = .033;
                flat = 25;
                sub = 863;
                
            }
            if ((income >= 2589) && (income <= 4313)) {
                rate = .052;
                flat = 85;
                sub = 2588;
                
            }
            if (income > 4313) {
                rate = .075;
                flat = 181;
                sub = 4313;
                
            }
        }
        //taxTotal = (income * rate);
        taxes = (income - sub) * (rate) + (flat);
        cout << "Your taxable income is: $" << income << endl;
        cout << "and you are filing a" << returnType << endl;
        cout << "Your income tax will be $" << taxes << endl << endl;
        cout << "Would you like to do another tax calculation (y or n)?" << endl;
        
        
        while (promptCode == 0) {
            cin >> restart;
            cout << endl;
            if (restart == "y") {
                programExitCode = 0;
                promptCode = 1;
            }
                else if (restart == "n") {
                cout << "Thank you, have a good day" << endl;
                programExitCode = 1;
                promptCode = 1;
            }
                else if (restart == "q") {
                cout << "Thank you, have a good day" << endl;
                programExitCode = 1;
                promptCode = 1;
            }
                else {
                    cout << "Please Input Valid Option" << endl;
                }
        }
        income = 0.00;
        status = "a";
        restart = "a";
        exitNum = 0;
        rate = 0.00;
        flat = 0;
        sub = 0.0;
        taxes = 0.0;
        //programExitCode = 0;
        promptCode = 0;
        
        
    }
}
