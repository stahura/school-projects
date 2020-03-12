//
//  main.cpp
//  Project 8 V2
//
//  Created by Riley Stahura on 12/4/18.
//  Copyright © 2018 Riley Stahura. All rights reserved.
//

#include <iostream>
#include "dynarray.hpp"
using namespace std;

int main() {
    /* BEGIN MY TEST DRIVER
    cout << endl << "Program Started" << endl << endl;
    DynArray<int> intVector;
    DynArray<string> stringVector;
    
    cout << "capacity of intVector = " << intVector.capacity() << endl;
    cout << "capacity of stringVector = " << stringVector.capacity() << endl << endl;
    
    intVector.push_back(8);
    stringVector.push_back("Hello");
    
    for(int i = 0; i < intVector.size(); i++){
        cout << "intVector.at(" << i << "): is " << intVector.at(i) << endl;
        cout << "stringVector.at(" << i << "): is "  << stringVector.at(i) << endl << endl;
    }
    
    cout << endl;
    intVector.push_back(10);
    stringVector.push_back("My");
    cout << "capacity of intVector = " << intVector.capacity() << endl;
    cout << "capacity of stringVector = " << stringVector.capacity() << endl << endl;
    
    for(int i = 0; i < intVector.size(); i++){
        cout << "intVector.at(" << i << "): is " << intVector.at(i) << endl;
        cout << "stringVector.at(" << i << "): is "  << stringVector.at(i) << endl << endl;
    }
 
     END MY TEST DRIVER*/
    
    const char START = 'A';
    const int MAX = 12;
    
    // create a vector of chars
    DynArray<char> vectD;
    
    // push some values into the vector
    for (int i = 0; i < MAX; i++)
    {
        vectD.push_back(START + i);
    }
    
    // remove the last element
    vectD.pop_back();
    
    // add another value
    vectD.push_back('Z');
    
    // test memory management
    DynArray<char> vectD2 = vectD;
    // display the contents
    cout << "\n[";
    for (int i = 0; i < vectD2.size() - 1; i++)
    {
        cout << vectD2[i] << ", ";
    }
    
    cout << "..., " << vectD2.back() << "]\n";
    
    DynArray<char> vectD3;
    vectD3 = vectD2;
    cout << "\n[";
    for (int i = 0; i < vectD3.size() - 1; i++)
    {
        cout << vectD3[i] << ", ";
    }
    cout << "..., " << vectD3.back() << "]\n";
    
    vectD3.front() = '{';
    vectD3.back() = '}';
    cout << vectD3.front();
    for (int i = 1; i < vectD3.size() - 2; i++)
    {
        cout << vectD3[i] << ", ";
    }
    cout << vectD3[vectD3.size()-2] << vectD3.back() << endl;
    
    return 0;
}
