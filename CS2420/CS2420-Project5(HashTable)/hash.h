#pragma once
#include <iostream>
using namespace std;

const int MAX = 20;

struct Hash {

	Hash(); //Constructor

	//Member Functions
	int getValue(int value); //Gets the value entered
	bool insertValue(int value, int index); //Insert value into given location
	bool resolveCollision(int value, int original_index); //resolve collision introduced in InserValue
	void show();

	//Data Members
	int HashTable[MAX]; // MAX is a constant of 20
};

//Member function Definitions

Hash::Hash()
{
	for (int i = 0; i < MAX; i++)
	{
		HashTable[i] = -999;
	}
}

int Hash::getValue(int value)
{
	/*
	Returns the location in the array in which the passed integer value should be placed (the hash value).  
	Pass the function the value from the file to be inserted. 
	Remember the hash function is dependent upon the value to be stored in the hash table.   
	Implement your hash function using the mod (%) operator.
	*/
	value = value % (MAX);

	return value;
}

bool Hash::insertValue(int value, int index)
{
	//Inserts the value at given index
	bool keyExists;
	if (HashTable[index] == -999)
	{
		HashTable[index] = value;
		return keyExists = false;
	} 
	else
	{
		
		cout << "\nCollision detected at location " << index << " for value " << value << endl;
		resolveCollision(value, index);
		return keyExists = true;
	}
}

bool Hash::resolveCollision(int value, int original_index)
{
	//Resolves collision introduced by insertValue
	bool resolution_complete;
	int temp_num = original_index + 1;
	for (temp_num; temp_num <= 20; temp_num++) //FIXME: might need to adjust to temp_num < 20
	{
		if (HashTable[temp_num] == -999)
		{
			HashTable[temp_num] = value;
			return resolution_complete = true;
		}
	}
	for (int i = 0; i < original_index + 1; i++)
	{
		if (HashTable[temp_num] == -999)
		{
			HashTable[temp_num] = value;
			return resolution_complete = true;
		}
	}
	return resolution_complete = false;
}

void Hash::show()
{
	cout << "\nHASH TABLE contents" << endl;
	cout << "Element    Value" << endl;
	for (int i = 0; i < MAX; i++)
	{
		cout << "   " << i << "       " << HashTable[i] << endl;
	}
}