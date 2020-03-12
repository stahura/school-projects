//
//  dynarray.hpp
//  Project 6
//
//  Created by Riley Stahura on 11/3/18.
//  Copyright © 2018 Riley Stahura. All rights reserved.
//

#ifndef dynarray_hpp
#define dynarray_hpp

#include <stdio.h>

class DynArray {
    
public:
    DynArray();
    DynArray(int n);
    ~DynArray();
    
    int size();
    int capacity();
    void push_back(int n);
    void pop_back();
    int at(int n);
    void clear();
    void delArray();
    void createNewArray(int n);
    
    
private:
    
    int objSize;
    int objCapacity;
    int* objArray;
    int* arrayPtr = nullptr;
    int tempArray;
    
    
    
};

#endif /* dynarray_hpp */
