#include "pch.h"
// Author:         Jeffrey Riley Stahura
// Project:        4
// File:           main.cpp
// Instructor:     Dr. Reza Senati
// Class:          CS2420
// Date Written:   3/9/2019
//		INSTRUCTIONS
//
// A: Define Node and Class to implement a binary search tree. Each node needs int data entry and lchild,rchild
// B: Read and Print from p4data.txt(Allow user to enter file name) insert them into an empty balanced binary search tree. No duplicated data allowed
// C: Traverse(print node entry) the tree recursively, using inorder traversal
// D: Traverse(print node entry) the tree non-recursively, u sing predorder traversal
//
//			THESE MUST BE DONE IN ORDER
//
#pragma once
using namespace std;
#include "avlTree.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stack>
//#include "binaryNode.h"
//#include "binaryTree.h" 



//Main Function Declarations
void printProjectInfo(); // PRINTS NAME, CLASS, SECTION , PROGRAM NUMBER
string getFileName(); // GETS FILE NAME FROM USER
ifstream openFile(string& file); ////OPENS FILE, CHECKS IF FILE IS OPEN UNTIL getCorrectFile() RETURNS A VALID FILE
void getCorrectFile(ifstream& inFS, string& myFile); //FUNCTION SERVES TO GIVE USER ABILITY TO RE-ENTER FILE NAME AFTER INVALID ENTRY
void traverseInOrder(BinaryNode* subroot); //TRAVERSE AND PRINT NODE VALUES IN ORDER RECURSIVELY
void traversePreOrder(BinaryNode* subroot, AVLTree tree); //TRAVERSE AND PRINT NODE VALUES PREORDER NON-RECURSIVELY
//void print(BinaryNode *p) { cout << p->data << endl; }
//Main Function Definitions
void printProjectInfo()
{
	cout << "--------------------------------";
	cout << endl << "Name:      Jeffrey Riley Stahura" << "\nClass:     CS2420" << "\nSection:   601" << "\nProject:   4" << endl;
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

void traverseInOrder(BinaryNode* subroot) //FIXME: Visit each node to print it instead of current implementation
{ //Recursively print nodes in order
	
	if (subroot != nullptr)
	{
		traverseInOrder(subroot->lchild);
		cout << subroot->data << endl;
		traverseInOrder(subroot->rchild);
	}
}

void traversePreOrder(BinaryNode* subroot, AVLTree tree) 
{ //Non recursively print nodes in preorder
	cout << "\nTraversing tree (Pre Order)" << endl;
	stack<BinaryNode*> stack;
	BinaryNode* ptr = subroot;

	if (ptr != nullptr)
		stack.push(ptr);
	while (!stack.empty())
	{
		ptr = stack.top();
		stack.pop();
		cout << ptr->data << endl;
		if (ptr->rchild != nullptr)
			stack.push(ptr->rchild);
		if (ptr->lchild != nullptr)
			stack.push(ptr->lchild);
	}

}