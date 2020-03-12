//
//  doubleList.hpp
//  CS2420-Project2
//
//  Created by Riley Stahura on 1/28/19.
//  Copyright © 2019 Riley Stahura. All rights reserved.
//

#ifndef doubleList_hpp
#define doubleList_hpp

#include <string>
#include "singleList.hpp"
#include "doubleNode.hpp" //FIXME: Change back to node.hpp after testing


#include <stdio.h>

class DoubleList
{
    
public:
    
    //Constructor
    DoubleList();
    
    //Member functions
    void add(int& num);
    void addOrder(int& num);
    void traverse();
    void traversePrint(void(*visit)(doubleNode *p));
    
    

    
protected:
    
    doubleNode *head;
    doubleNode *tail;
    int count;
    
    
}; //End Class Definition

DoubleList::DoubleList()
{
    head = NULL;
    count = 0;
};



void DoubleList::add(int& num)
{
    doubleNode *p = new doubleNode(num); //FIXME: Probably won't work like this (NULL as parameters)
    if(head == NULL)
    {
        head = p;
    }
    else
    {
        p->next = head;
        head->llink = p;
        head = p;
    }
    count++;
    
};

void DoubleList::addOrder(int& num)
{
    doubleNode* newNode = new doubleNode(num);
    if(head == NULL) //IF LIST IS EMPTY
    {
        head = newNode;
    }
    else
    {
        doubleNode *p,*q;
        p = head;
        q = NULL;
        while((p != NULL) && (num > p->data))
        {
            q = p;
            p = p->next;
        }
        if(q == NULL) // INSERT AT BEGINNING
        {
            newNode->next = p;
            p->llink = newNode;
            head = newNode;
        }
        else
        {
            if(p == NULL) //INSERT AT END
            {
                q->next = newNode;
                newNode->llink = q;
            }
            else //INSERT SOMEWHERE BETWEEN BEGINNING AND END
            {
                newNode->next = p;
                newNode->llink = q;
                p->llink = newNode;
                q->next = newNode;
            }//End Else3
        }//End Else2
        
    }//End Else1
    count++;
};

void DoubleList::traverse()
{
    if(head == NULL)
    {
        cout << "List is empty";
    }
    else
    {
        doubleNode *p;
        p = head;
        while(p != NULL)
        {
            //cout << "\n" << p->data;
            p = p->next;
        }
    }
};

void DoubleList::traversePrint(void(*visit)(doubleNode *p))
{
    doubleNode *p;
    p = head;
    while(p != NULL)
    {
        (*visit)(p);
        p = p->next;
    }
}



#endif /* doubleList_hpp */
