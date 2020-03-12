//
//  dynarray.cpp
//  Project 8
//
//  Created by Riley Stahura on 12/3/18.
//  Copyright © 2018 Riley Stahura. All rights reserved.
//

#include "dynarray.hpp"
#include <iostream>
using namespace std;

DynArray::DynArray() {
    objSize = 0;
    
    objCapacity = 2;
    
    objArray = new int[2];
    
}
DynArray::DynArray(int n) {
    objSize = 0;
    
    objCapacity = n;
    
    objArray = new int[n];
}
DynArray::~DynArray() {
    delete []objArray;
}
int DynArray::size() {
    return objSize;
}
int DynArray::capacity() {
    return objCapacity;
}
void DynArray::push_back(int n) {
    
    if (objSize == objCapacity) {
        createNewArray(n);
    } else {
        objArray[objSize] = n;
        objSize++;
        
    }
    
}

void DynArray::pop_back() {
    objSize = objSize - 1;
}

int DynArray::at(int n) {
    
    if (n >= objSize) {
        throw runtime_error("invalid index");
    }
    
    return objArray[n];
    
}
void DynArray::clear() {
    delete [] objArray;
    objArray = new int[2];
    objSize = 0;
    objCapacity = 2;
    
}
void DynArray::createNewArray(int n) {
    
    
    int* tempArray = new int[objCapacity * 2];
    for(int i = 0; i < objSize; i++) {
        tempArray[i] = objArray[i];
        
    }
    objCapacity = objCapacity * 2;
    delete [] objArray;
    objArray = tempArray;
    objArray[objSize] = n;
    objSize++;
    
    
}

int DynArray::back() {
    const int& backNum = objArray[objSize - 1];
    return backNum;
}
int DynArray::front() {
    const int& frontNum = objArray[0];
    return frontNum;
}
DynArray::DynArray(const DynArray& origClass){
    cout << endl << "Copy Constructor called" << endl;
    objArray = new int[objSize];
    *objArray = 0;
}
DynArray& DynArray::operator=(const DynArray& objToCopy){
    cout << "Assignment op called." << endl;
    
    objSize = objToCopy.objSize;
    for(int i = 0; i < objToCopy.objSize; i++ )
        objArray[i] = objToCopy.objArray[i];
    
    if (this != &objToCopy) {           // 1. Don't self-assign
        delete []objArray;                  // 2. Delete old dataObj
        objArray = new int[objSize];               // 3. Allocate new dataObj
        *objArray = *(objToCopy.objArray); // 4. Copy dataObj
        
    }
    return *this;
}

/*
 DynArray& operator[ ](int n);
 */

