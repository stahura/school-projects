#pragma once
using namespace std;
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
//#include "binaryNode.h"
//#include "binaryTree.h" 



//Main Function Declarations
void printProjectInfo(); // PRINTS NAME, CLASS, SECTION , PROGRAM NUMBER
string getFileName(); // GETS FILE NAME FROM USER
ifstream openFile(string& file); ////OPENS FILE, CHECKS IF FILE IS OPEN UNTIL getCorrectFile() RETURNS A VALID FILE
void getCorrectFile(ifstream& inFS, string& myFile); //FUNCTION SERVES TO GIVE USER ABILITY TO RE-ENTER FILE NAME AFTER INVALID ENTRY
//void print(BinaryNode *p) { cout << p->data << endl; }
//Main Function Definitions
void printProjectInfo()
{
	cout << "--------------------------------";
	cout << endl << "Name:      Jeffrey Riley Stahura" << "\nClass:     CS2420" << "\nSection:   601" << "\nProject:   5" << endl;
	cout << "--------------------------------" << endl;
}

string getFileName()
{   //Function asks user for file name
	string tempFileName;
	cout << "Please enter a file name: " << endl;
	cin >> tempFileName;
	return tempFileName;
}

ifstream openFile(string& file)
{   //Opens file, checks name repeatedly until valid
	ifstream inFS;
	inFS.open(file);
	while (!inFS.is_open())
		getCorrectFile(inFS, file);

	return inFS;
}

void getCorrectFile(ifstream& inFS, string& myFile)
{   //Function serves to give user ability to re-enter file name after invalid entry
	cout << endl << "File '" << myFile << "' not found." << endl;
	myFile = getFileName();
	inFS.open(myFile);

}

