// CS2420-Project3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "queue.h"
#include "stack.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//Function Declarations
void printIntro();
string getFileName(); // GETS FILE NAME FROM USER
ifstream openFile(string& file); ////OPENS FILE, CHECKS IF FILE IS OPEN UNTIL getCorrectFile() RETURNS A VALID FILE
void getCorrectFile(ifstream& inFS, string& myFile); //FUNCTION SERVES TO GIVE USER ABILITY TO RE-ENTER FILE NAME AFTER INVALID ENTRY
void print(Node *p) { cout << p->data << endl; } //PRINT FUNCTION FOR TRAVERSEPRINT(print) TO USE (DECLARED AND DEFINED HERE)

//BEGIN MAIN
int main()
{
	string filename;
	ifstream ifs;
	int num;
	string original_line;
	string word1;
	string word2;
	Stack stack1;
	Queue queue1;


	printIntro();
	filename = getFileName(); // Get user input for file name >
	ifs = openFile(filename); // Open file > Get correct file if file invalid, while loop will repeatedly call until valid name is entered by user

	while (getline(ifs, original_line)) {
		//cout << original_line << endl;
		int pos = original_line.find_first_of(' ');
		word1 = original_line.substr(0, pos);
		word2 = original_line.substr(pos + 1, original_line.back());
		cout << word1;

		if (word1 == "append")
		{
			num = stoi(word2); //stoi converts string to int
			
			cout << "         Queue       " << num;
			queue1.append(num);
		}
		else if(word1 == "serve")
		{
			cout << "          Queue       " << "--";
			queue1.serve();
		}
		else if (word1 == "push")
		{
			num = stoi(word2);
			cout << "           Stack       " << num;
			stack1.push(num);
		}
		else if (word1 == "pop")
		{
			cout << "            Stack       ";
			stack1.pop();
		}
	}
	cout << "\nQueue" << "\n-----" << endl;
	queue1.traversePrint(print); //This seems to work properly
	cout << "\nStack" << "\n-----" << endl;
	stack1.traversePrint(print); //FIXME: Indicates that stack is empty.. why? I think it has to do with .pop();
	ifs.close();
	char c;
	cin >> c;

}
//END MAIN

/* **********************
**************************
BEGIN FUNCTION DEFINITIONS

**************************
 * *********************/

void printIntro()
{
	cout << "--------------------------------";
	cout << endl << "Name:      Jeffrey Riley Stahura" << "\nClass:     CS2420" << "\nSection:   601" << "\nProject:   3" << endl;
	cout << "--------------------------------" << endl;
}

string getFileName()
{   //Function asks user for file name
	string tempFileName;
	cout << "Please enter a file name: " << endl;
	cin >> tempFileName;
	cout << "-------------------------------------------" << endl;
	cout << "Operation    Structure    Value    Result" << endl;
	return tempFileName;
}

ifstream openFile(string& file)
{   //Opens file, checks name repeatedly until valid
	ifstream inFS;
	inFS.open(file);
	while (!inFS.is_open())
		getCorrectFile(inFS, file);
	cout << "-------------------------------------------" << endl;
	return inFS;
}

void getCorrectFile(ifstream& inFS, string& myFile)
{   //Function serves to give user ability to re-enter file name after invalid entry
	cout << endl << "File '" << myFile << "' not found." << endl;
	myFile = getFileName();
	inFS.open(myFile);

}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
