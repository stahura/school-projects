//
//  dynarray.cpp
//  Project 6
//
//  Created by Riley Stahura on 11/3/18.
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



