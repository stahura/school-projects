// Author:         Jeffrey Riley Stahura
// Project:        2
// File:           main.cpp
// Instructor:     Dr. Reza Senati
// Class:          CS2420
// Date Written:   1-20-19
/*
// Description:
1)    Create single linked list class and double linked list class.
2)    Do not use facilities from standard template library.
3)    Instantiate lists in main();
4)    Open file input by user and read contents(Integers), while traversing, add integer to new node and add node to end of single linked list by calling insert();
5)    Once all integers are read and stored in single linked list, get data from single linked list, add data to double linked node and insert double nod into double linked list in ascending order.
6)    Each list needs a traverse(); function which visits every node form head sequentially until end of list. Pass name (or address) of a print function to the traverse function that prints the
        integer value in the node EX: ??? traverse(printMethod) ???
7)    Print contents of single linked list using it's ??? traverse(printMethod) ??? While traversing single linked list, printed integers must be in order in w hich they were read in from file, but may be unsorted
8)    Print contents of double linked list using ??? traverse(printMethod) ??? Print content of double linked list, printed integers must be in asceending order. Do not use any sorting routine to MY LIST
 
// Order of Operations:
1.    Print your name, class (i.e. CS 2420), section number, and program number (i.e. program 1 – Linked Lists)
2.    Prompt the user for the file name and open the file, if the file cannot be open, handle the error appropriately
3.    Read an integer from the file
4.    Insert the integer into a new node and add it at the end of a single linked list
5.    Read all of the integers and insert them into the single linked list until end of file is reached
6.    Traverse the single linked list node by node, for each node in the single linked list
7.    Insert the integer from the node of the single linked list into the double linked list in ascending order
8.    Do steps 6 and 7 for all of the nodes of single linked list.
9.    Print each integer from the single linked list using the traverse function passing the print function as a parameter.
10.   Print each integer from the double linked list using the traverse function passing the print function as a parameter.

 
 
                THINGS I WAS CONSCIOUS OF
 
    1. THE SINGLE LINKED LIST ITSELF WAS NOT SORTED
    2. I DID NOT USE THE C++ STL EXCEPT FOR #include <string>, I figured that was an exception?
    3. I DID NOT CREATE THE DOUBLE LINKED LIST WITHIN THE SAME WHILE LOOP AS THE SINGLE LIST,
        I INSTEAD ADDED THE NODES TO THE DOUBLE LINKED DURING THE single_list.traverse() PROCESS
        , FOLLOWING THE EXACT INSTRUCTIONS OF THE WORD DOCUMENT
    4. IN ORDER TO PRINT THE SINGLE_LIST IN THE ORDER THE NUMBERS WERE READ, I HAD TO USE MY OWN
        DYNAMIC ARRAY THAT I CREATED TO PRINT IN REVERSE. THE PROPER "traversePrint(void(*visit))
        WAS STILL USED TO PRINT THE INTEGERS.
    5. I'm absolutely certain this could have been waaaaay more simple, but i got stuck and resorted
        to a solution I knew would work.
    6. *************This final version of the program failed once during testing, but I haven't been able to replicate the issue since**************
 */

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "node.hpp"
#include "singleList.hpp" //FIXME: CHANGE BACK TO SINGLELIST>HPP
#include "doubleList.hpp"

using namespace std;

void printProjectInfo(); // PRINTS NAME, CLASS, SECTION , PROGRAM NUMBER
string getFileName(); // GETS FILE NAME FROM USER
ifstream openFile(string& file); ////OPENS FILE, CHECKS IF FILE IS OPEN UNTIL getCorrectFile() RETURNS A VALID FILE
void getCorrectFile(ifstream& inFS, string& myFile); //FUNCTION SERVES TO GIVE USER ABILITY TO RE-ENTER FILE NAME AFTER INVALID ENTRY
void singlePrint(Node *p) {cout << p->data << endl; } //PRINT FUNCTION FOR TRAVERSEPRINT(print) TO USE (DECLARED AND DEFINED HERE)
void doublePrint(doubleNode *p) {cout << "\n" << p->data;}

//*****************************
//Start of Main Func
//*****************************

int main()
{
    string filename;
    ifstream ifs;
    int num;
    SingleList single_list;
    DoubleList double_list;
    
    
    printProjectInfo();
    filename = getFileName(); // Get user input for file name >
    ifs = openFile(filename); // Open file > Get correct file if file invalid, while loop will repeatedly call until valid name is entered by user
    
    cout << "\nInserting the following integers into a Node and adding to a Single Linked List....:" << endl;
    while (ifs >> num)
    {
        cout << "\n" << num;
        single_list.add(num);
    }
    cout << "\n\nTraversing single_list and adding nodes to double_list" << "\n------------------------------------------------------";
    single_list.traverse(double_list);
    cout << "\n" << "Printing Content of Single_List via traversePrint(print)" << "\n--------------------------------------------------------"<< endl;
    single_list.traversePrint(singlePrint);
    cout << "\n" << "Content of Double_List via traversePrint(print)" << "\n-----------------------------------------------"<< endl;
    double_list.traversePrint(doublePrint);
    
    ifs.close(); // Close file
    cout << endl;
    
	char c;
	cin >> c;
	
    return 0;
}

//*****************************
//Function Definitions
//*****************************


void printProjectInfo()
{
    cout << "--------------------------------";
    cout << endl << "Name:      Jeffrey Riley Stahura" << "\nClass:     CS2420" << "\nSection:   601" << "\nProject:   2" << endl ;
    cout << "--------------------------------" << endl;
}

string getFileName()
{   //Function asks user for file name
    string tempFileName;
    cout << "Please enter a file name: "  << endl;
    cin >> tempFileName;
    return tempFileName;
}

ifstream openFile(string& file)
{   //Opens file, checks name repeatedly until valid
    ifstream inFS;
    inFS.open(file);
    while(!inFS.is_open())
        getCorrectFile(inFS, file);
    
    return inFS;
}

void getCorrectFile(ifstream& inFS, string& myFile)
{   //Function serves to give user ability to re-enter file name after invalid entry
    cout << endl << "File '" <<  myFile << "' not found." << endl;
    myFile = getFileName();
    inFS.open(myFile);
    
}
