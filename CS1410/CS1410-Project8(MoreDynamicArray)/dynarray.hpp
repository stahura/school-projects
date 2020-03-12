//
//  dynarray.hpp
//  Project 8
//
//  Created by Riley Stahura on 12/3/18.
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
    
    int back();
    int front();
    DynArray(const DynArray&);
    DynArray& operator=(const DynArray&);
    DynArray& operator[ ](int n);
    
    
    
private:
    
    int objSize;
    int objCapacity;
    int* objArray;
    int* arrayPtr = nullptr;
    int tempArray;
    
};
#endif /* dynarray_hpp */
