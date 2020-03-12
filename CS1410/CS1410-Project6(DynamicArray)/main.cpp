//
//  main.cpp
//  Project 6
//
//  Created by Riley Stahura on 11/3/18.
//  Copyright © 2018 Riley Stahura. All rights reserved.
//

#include <iostream>
#include <iostream>
#include "dynarray.hpp"
using namespace std;

int main() {
    
    // Create a default vector (cap = 2)
    DynArray sam;
    cout << "capacity = " << sam.capacity() << endl;
    
    // push some data into sam
    cout << "\nPushing three values into sam";
    sam.push_back(21);
    sam.push_back(31);
    sam.push_back(41);
    
    cout << "\nThe values in sam are: ";
    
    // test for out of bounds condition here
    for (int i = 0; i < sam.size() + 1; i++)
    {
        try
        {
            cout << sam.at(i) << " ";
        }
        catch(runtime_error& x)
        {
            cout << x.what() << endl;
        }
    }
    cout << "\n--------------\n";
    
    // clear sam and display its size and capacity
    sam.clear();
    cout << "\nsam has been cleared.";
    cout << "\nSam's size is now " << sam.size();
    cout << "\nSam's capacity is now " << sam.capacity() << endl;
    cout << "---------------\n";
    
    // Push 12 values into the vector - it should grow
    cout << "\nPush 12 values into sam.";
    for (int i = 0; i < 12; i++)
        sam.push_back(i);
    
    cout << "\nSam's size is now " << sam.size();
    cout << "\nSam's capacity is now " << sam.capacity() << endl;
    cout << "---------------\n";
    
    cout << "\nTest to see if contents are correct...";
    // display the values in the vector
    for (int i = 0; i < sam.size( ); i++)
    {
        cout << sam.at(i) << " ";
    }
    cout << "\n--------------\n";
    
    cout << "\nTest pop_back...";
    // display the values in the vector
    sam.pop_back();
    for (int i = 0; i < sam.size( ); i++)
    {
        cout << sam.at(i) << " ";
    }
    cout << endl;
     
   /* DynArray test(5);
    test.push_back(10);
    cout << endl << test.size() << endl;
    test.push_back(20);
    cout << endl << test.size() << endl;
    test.push_back(30);
    cout << endl << test.size() << endl;
    test.push_back(40);
    cout << endl << test.size() << endl;
    test.push_back(50);
    cout << endl << test.size() << endl;
    test.push_back(60);
    
    cout << endl << ".at points to" << test.at(3);
    */
}
