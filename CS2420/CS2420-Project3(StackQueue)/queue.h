#pragma once
#include "node.h"
#include "dynarray.h"
#include "stack.h"
#include <string>
#include <iostream>

using namespace std;

typedef int queue_entry;
class Queue
{
public:
	Queue();

	Error_code append(const queue_entry &item);
	Error_code serve();
	void traversePrint(void(*visit)(Node *)); //FIXME, don't know if it works yet. 

	Node *front;
	Node *rear;

};

Queue::Queue()
{
	front = nullptr;
	rear = nullptr;
}

Error_code Queue::append(const queue_entry &item)
{
	
	if (front == nullptr)
	{
		front = rear = new Node(item);
		cout << "     success" << endl;
		return success;
	}

	else
	{
		rear = rear->next = new Node(item);
		cout << "     success" << endl;
		return success;
	}

}

Error_code Queue::serve()
{
	
	if (front == nullptr)
	{ 
		cout << "     underflow" << endl;
		return underflow;
	}
	else
	{
		Node *p = front;
		front = front->next;
		if (front == nullptr)
			rear = nullptr;
		cout << "     success" << endl;
		return success;
	}
}

void Queue::traversePrint(void(*visit)(Node *))
{

	Node *p;
	p = front;
	DynArray<int> dynamicArray;

	while (p != nullptr)
	{
		dynamicArray.push_back(p->data);
		// cout << "i is: " << i << endl;
		 //(*visit)(p);
		p = p->next;
	}
	p = front;
	//cout << endl;
	for (int i = dynamicArray.size() - 1; i >= 0; i--)
	{
		//cout << dynamicArray.at(i) << endl;
		p->data = dynamicArray.at(i);
		(*visit)(p);
		p = p->next;
	}


}//END