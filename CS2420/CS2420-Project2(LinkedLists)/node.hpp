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
 
 */

#ifndef node_hpp
#define node_hpp


#include <stdio.h>

using namespace std;
typedef int node_entry;

struct Node
{
    //CONSTRUCTORS
    Node();
    Node(node_entry item, Node *next = NULL);
    //MEMBERS
    node_entry data;
    Node * next;
    
};

Node::Node()
{
    next = NULL;
    
};

Node::Node(node_entry initData, Node *add_on) {
    data = initData;
    next = add_on;
};




#endif /* node_hpp */
