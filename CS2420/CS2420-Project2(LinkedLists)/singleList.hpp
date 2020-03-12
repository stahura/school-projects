//
//  singleList.hpp
//  CS2420-Project2
//
//  Created by Riley Stahura on 1/26/19.
//  Copyright © 2019 Riley Stahura. All rights reserved.
//

#ifndef singleList_hpp
#define singleList_hpp

using namespace std;

#include <string>
#include "node.hpp"
#include "doubleNode.hpp"

#include "dynarray.hpp"
#include "doubleList.hpp"

#include <stdio.h>


class SingleList
{
    
public:
    
    SingleList(); //Constructor
    
    void traverse(DoubleList& list);
    void traversePrint(void(*visit)(Node *));  //Member functions
    void add(int& num);
    
protected:
    
    Node * head;
    
    int count = 0;
    
    
}; //End Class Definition


/*
 BEGIN MEMBER FUNCTION DEFINITIONS
 */
SingleList::SingleList() {}

void SingleList::traverse(DoubleList& list)
{

    Node *p; //FIXME: DOES THIS NEED TO BE DEFINED AS A "new Node()" ??
    p = head;
	while (count <= 10)
	{
		list.addOrder(p->data);
		p = p->next; 
		count++;
    }

    
    cout << endl;
	count = 0;
    
}//END

void SingleList::traversePrint(void(*visit)(Node *))
{
    
    Node *p;
    p = head;
    DynArray<int> dynamicArray;
    
    while(count <= 10)
    {
        dynamicArray.push_back(p->data);
        p = p->next;
		count++;
    }
    p = head;
    cout << endl;
    for(int i = dynamicArray.size() - 1; i >= 0; i--)
    {
        p->data = dynamicArray.at(i);
        (*visit)(p);
        p = p->next;
    }
	count = 0;
    
}//END

void SingleList::add(int& num)
{
    if(head == NULL)
    {
        head = new Node(num);
        head->next = NULL;
    }
    else
    {
        Node *q;
        Node *p;
        
        q = NULL;
        p = head;

        if(q == NULL)
        {
          
            p = new Node(num, head);
            head = p;
        }
        else
        {
            
            p = new Node(num, q->next);
            q->next = p;
        }
    }
    // count++ FIXME: why count?
}//END


#endif /* singleList_hpp */
