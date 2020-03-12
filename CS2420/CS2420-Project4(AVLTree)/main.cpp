#include "pch.h"
#include "main.h"
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
/*
#pragma once
using namespace std;
#include <iostream>
#include <string>
#include <fstream>
#include <vector>


//Main Function Declarations
void printProjectInfo(); // PRINTS NAME, CLASS, SECTION , PROGRAM NUMBER
string getFileName(); // GETS FILE NAME FROM USER
ifstream openFile(string& file); ////OPENS FILE, CHECKS IF FILE IS OPEN UNTIL getCorrectFile() RETURNS A VALID FILE
void getCorrectFile(ifstream& inFS, string& myFile); //FUNCTION SERVES TO GIVE USER ABILITY TO RE-ENTER FILE NAME AFTER INVALID ENTRY

*/
//void inOrder(BinaryNode* subroot);

int main()
{
	string filename;
	ifstream ifs;
	vector<int> list;
	int num;

	AVLTree tree;
	BinaryNode *node;

	printProjectInfo();
	filename = getFileName(); // Get user input for file name >
	ifs = openFile(filename); // Open file > Get correct file if file invalid, while loop will repeatedly call until valid name is entered by user
	cout << "\nPrinting numbers from file...." << endl;
	while (ifs >> num)
	{
		cout << "\n" << num;
		list.push_back(num);
		tree.preInsert(num);
	}
	ifs.close();
	cout << "\nTraversing tree (In Order)" << endl;
	traverseInOrder(tree.root);
	traversePreOrder(tree.root, tree);
}

