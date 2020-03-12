//
//  main.cpp
//  Project 8
//
//  Created by Riley Stahura on 12/3/18.
//  Copyright © 2018 Riley Stahura. All rights reserved.
//

#include <iostream>
#include "dynarray.hpp"
using namespace std;

int main() {
    // Create a default vector (cap = 2)
    DynArray array1;
    DynArray array2;
    
    cout << "capacity = " << array1.capacity() << endl;
    
    // push some data into sam
    cout << "\nPushing three values into sam";
    array1.push_back(21);
    array1.push_back(31);
    array1.push_back(41);
    
    cout << endl << array1.back() << endl;
    cout << endl << array1.front() << endl;
    cout << "size : " << array1.size() << endl;
    int n = 0;
    for(int i = 0; i < array1.size(); i ++) {
        cout << "i is " << array1.at(i) << endl;
    }
    n = array1.size();
    
    array2 = array1;
    cout << endl << array2.back() << endl;
    cout << endl << array2.front() << endl;
    cout << "size of array 2 is : " << array2.size() << endl;
    
    for(int i = 0; i < array2.size(); i ++) {
        cout << "i is " << array2.at(i) << endl;
    }
   
    
    
    
    return 0;
}
