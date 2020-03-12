#pragma once
#include "node.h"
#include "dynarray.h"
enum Error_code { overflow, underflow, success };
typedef int stack_entry;

class Stack
{
public:
	Stack();

	Error_code push(const stack_entry &item);//FIXME: ERROR_CODE, return OVERFLOW. Ask Professor?
	Error_code pop();						//FIXME: ERROR_CODE, return UNDERFLOW. Ask Professor?
	void traversePrint(void(*visit)(Node *)); //FIXME, don't know if it works yet. 
	
	
	Node *top_node;
protected:
	
private:
};

Stack::Stack()
{
	top_node = nullptr;
}

Error_code Stack::push(const stack_entry &item)
{
	Node *new_top = new Node(item, top_node);
	if (new_top == nullptr)
		return overflow;
	top_node = new_top;
	cout << "     success" << endl;
	return success;
}

Error_code Stack::pop() 
{
	
	Node *old_top = top_node;

	//if (old_top != nullptr) //FIXME. Crashes when ->next is NULL
	if (top_node == nullptr)
	{
		cout << "     underflow" << endl;
		return underflow;
	}
	top_node = old_top->next;
	delete old_top;
	cout << "       success" << endl;
	return success;
}
void Stack::traversePrint(void(*visit)(Node *))
{

	Node *p;
	p = top_node;
	DynArray<int> dynamicArray;

	while (p != nullptr)
	{
		dynamicArray.push_back(p->data);
		// cout << "i is: " << i << endl;
		 //(*visit)(p);
		p = p->next;
	}
	p = top_node;
	//cout << endl;
	for (int i = dynamicArray.size() - 1; i >= 0; i--)
	{
		//cout << dynamicArray.at(i) << endl;
		p->data = dynamicArray.at(i);
		(*visit)(p);
		p = p->next;
	}


}//END




