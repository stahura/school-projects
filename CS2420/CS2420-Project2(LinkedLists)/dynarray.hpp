//
//  dynarray.hpp
//  Project 8 V2
//
//  Created by Riley Stahura on 12/4/18.
//  Copyright © 2018 Riley Stahura. All rights reserved.
//
#include <iostream>
#include <string>
using namespace std;

#ifndef dynarray_hpp
#define dynarray_hpp

#include <stdio.h>
template<typename T>
class DynArray {
    
public:
    DynArray();
    DynArray(const int& n);
    ~DynArray();
    
    int size() const;
    int capacity() const;
    void push_back(const T& n);
    void pop_back();
    T& at(const int& n);
    void clear();
    void delArray();
    void createNewArray(const T& n);
    
    T& back() const;
    T& front() const;
    DynArray(const DynArray<T>&);
    DynArray<T>& operator=(const DynArray<T>&);
    
    T& operator[](int n);

    
    
private:
    
    int objSize;
    int objCapacity;
    T* objArray;
    T* arrayPtr = nullptr;  //FIXME MAYBE: Maybe these need to be const at the end?
    T tempArray;
    
};//END CLASS DEFINITIONS


template<typename T>
DynArray<T>::DynArray(){
    objSize = 0;
    
    objCapacity = 2;
    
    objArray = new T[2];
    
}//END


template<typename T>
DynArray<T>::DynArray(const int& n) {
    objSize = 0;
    
    objCapacity = n;
    
    objArray = new T[n];
}//END


template<typename T>
DynArray<T>::~DynArray() {
    delete []objArray;
}//END


template<typename T>
int DynArray<T>::size() const { //FIXME: is this correct?
    return objSize;
}//END


template<typename T>
int DynArray<T>::capacity() const {
    return objCapacity;
}//END


template<typename T>
void DynArray<T>::push_back(const T& n) {
    
    if (objSize == objCapacity) {
        createNewArray(n);
    } else {
        objArray[objSize] = n;
        objSize++;
        
    }
    
}//END


template<typename T>
void DynArray<T>::pop_back() {
    objSize = objSize - 1;
}//END


template<typename T>
T& DynArray<T>::at(const int& n) {
    
    if (n >= objSize) {
        throw runtime_error("invalid index");
    }
    return objArray[n];
}//END


template<typename T>
void DynArray<T>::clear() {
    delete [] objArray;
    objArray = new T[2];
    objSize = 0;
    objCapacity = 2;
    
}//END


template<typename T>
void DynArray<T>::createNewArray(const T& n) {
    //cout << "grow" << endl;
    
    T* tempArray = new T[objCapacity * 2];
    for(int i = 0; i < objSize; i++) {
        tempArray[i] = objArray[i];
    }
    
    objCapacity = objCapacity * 2;
    delete [] objArray;
    objArray = tempArray;
    objArray[objSize] = n;
    objSize++;
    
    
}//END


template<typename T>
T& DynArray<T>::back() const{
    if(objSize <= 0)
        throw runtime_error("ERROR");
   
    return objArray[objSize - 1];
}//END


template<typename T>
T& DynArray<T>::front() const {
    if(objSize <= 0)
        throw runtime_error("ERROR");
   
    return objArray[0];
}//END


template<typename T>
DynArray<T>::DynArray(const DynArray<T>& origClass){
    cout << "copy" << endl;
    objArray = new T[origClass.capacity()];
    objSize = origClass.size();
    objCapacity = origClass.capacity();
    
    for(int i=0; i < origClass.size(); i++)
        objArray[i] = origClass.objArray[i];
}//END


template<typename T>
DynArray<T>& DynArray<T>::operator=(const DynArray<T> &objToCopy){
    
    if(this != &objToCopy) {
        delete [] objArray;
        objArray = new T[objToCopy.capacity()];
        objCapacity = objToCopy.capacity();
        objSize = objToCopy.objSize;
        
        for (int i = 0; i < objToCopy.objSize; i++)
            objArray[i] = objToCopy.objArray[i];
    }
    cout << "assign" << endl;
    return *this;
    
}//END

template<typename T>
T& DynArray<T>::operator[](int n) {
    
    return at(n); //FIXME: This is giving me problems.
}//END





#endif /* dynarray_hpp */
