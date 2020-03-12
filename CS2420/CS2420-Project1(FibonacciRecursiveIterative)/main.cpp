// Author:         Jeffrey Riley Stahura
// Project:        1
// File:           main.cpp
// Instructor:     Dr. Reza Senati
// Class:          CS2420
// Date Written:   1-09-19
// Description:    Read a series of integers from file and use:
//                 1)A Recursive Function to print number and the fibonacci number of that number
//                 2)A Non-Recursive Function to print number and the fibonacci number of that number

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;


string getFileName();//FUNCTION ASKS USER TO ENTER FILE NAME
void getCorrectFile(ifstream& inFS, string& myFile); //FUNCTION SERVES TO GIVE USER ABILITY TO RE-ENTER FILE NAME AFTER INVALID ENTRY
void getFib(vector<int>& fibList); //NON RECURSIVE FIBONACCI FUNCTION
int getFib(int n); //RECURSIVE FIBONACCI FUNCTION
void readProcessData(ifstream& inFS, int& fibNum, vector<int>& fibNums, int& num); // FUNCTION READS DATA FROM FILE, THEN RUNS GETFIB(PROCESSES DATA)
ifstream openFile(string& file); //OPENS FILE, CHECKS IF FILE IS OPEN UNTIL getCorrectFile() RETURNS A VALID FILE

int main()
{
    
    int num;
    int fibNum;
    string file;    //Declare Variables
    ifstream inFS;
    vector<int> fibNums;
    
    file = getFileName();//Get user input for file name > Open file > Get correct file if file invalid, while loop will repeatedly call until valid name is entered by user
    inFS = openFile(file);//Opens file, checks valid name
    readProcessData(inFS,fibNum, fibNums,num); //Reads data from file, runs RECURSIVE AND NON-RECURSIVE fib functions(See functions for details) FIXME: Still need to define non-recursive function
    
    inFS.close(); //Close file
    
	cout << endl << "Type any letter and press enter to close" << endl;
	cin >> file;
   
    return 0;
}

//********************
//Function Definitions
//********************


string getFileName()
{
    //Function asks user for file name
    
    string tempFile;
    cout << "Please enter a file name: " << endl << endl;
    cin >> tempFile;
    return tempFile;
    
}


void getCorrectFile(ifstream& inFS, string& myFile )
{
    //Function serves to give user ability to re-enter file name after invalid entry
    cout << "File '" <<  myFile << "' not found." << endl;
    myFile = getFileName();
    inFS.open(myFile);
    
}


int getFib(int n)
{
    //RECURSIVE FIBONACCI FUNCTION
    if(n == 0)
    {
        return n;
    }
    else if(n == 1)
    {
        return n;
    }
    else
    {
        return getFib(n-1) + getFib(n-2);
    }
}


void getFib(vector<int>& fibList)
{
    //NON-RECURSIVE FIBONACCI FUNCTION
    int num1 = 0;
    int num2 = 1;
    int nextNum = 0;
    
    //For every Num in list -> calculate up to Nth fibonacci number - > Print Number(.at(i)) -> Print Fibonacci Number(j)
    for(int i = 0; i < fibList.size(); i++)
    {
        for(int j = 0; j < fibList.at(i); j++)
        {
            nextNum = num1 + num2;
            num1 = num2;
            num2 = nextNum;
        }
        cout << endl << fibList.at(i) << "    " << num1;
        num1 = 0;
        num2 = 1;
        nextNum = 0;
    }
}



void readProcessData(ifstream& inFS, int& fibNum, vector<int>& fibNums, int& num)
{
    //Function reads data from file, then runs getFib(processes data)
    //Repeatedly read line into int variable 'num' until last line has been read.
    //int fibNum is equal to RECURSIVE call with parameter 'num'
    //Print num and fibnum result.
    cout << "Recursive" << endl; //Output a simple header for an organized table for N and Fib(N)
    cout << "---------\n" << "N" << "  Fib(N)" << "\n---------";
    
    while (inFS >> num)
    {
        fibNums.push_back(num);
        fibNum = getFib(num);
        cout << endl << num << "    " << fibNum;
    }
    cout << endl << "-------------\n";
    cout << "Non-Recursive" << endl; //Output a simple header for an organized table for N and Fib(N)
    cout << "-------------\n" << "N" << "  Fib(N)" << "\n-------------";
    getFib(fibNums);
    cout << endl;
}

ifstream openFile(string& file)
{
    //Opens file, checks name repeatedly until valid
    ifstream inFS;
    inFS.open(file);
    while(!inFS.is_open())
    {
        getCorrectFile(inFS, file);
    }
    return inFS;
}


