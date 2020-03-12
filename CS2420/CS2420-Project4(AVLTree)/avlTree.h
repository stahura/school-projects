#pragma once
#ifndef AVLTREE_H
#define AVLTREE_H

#include <string>
#include <iostream>
//*****************************************
//			  NODE DEFINITION
//		    Version 2 of program
//*****************************************
typedef int node_entry;

struct BinaryNode
{
	BinaryNode(); //Construct node
	BinaryNode(node_entry num); //Construct node with data 
	BinaryNode *lchild;
	BinaryNode *rchild;

	node_entry data;

};

 BinaryNode::BinaryNode()
{
	 lchild = nullptr;
	 rchild = nullptr;
}

BinaryNode::BinaryNode(node_entry num)
{
	lchild = nullptr;
	rchild = nullptr;
	data = num;
}
//*****************************************
//		  AVL TREE DEFINITION
//*****************************************
class AVLTree {

public:

	AVLTree();

	BinaryNode* preInsert(node_entry num);
	BinaryNode* insertNode(BinaryNode *subroot, node_entry num);
	BinaryNode* balanceTree(BinaryNode *subroot);
	node_entry getBalance(BinaryNode *subroot);
	node_entry height(BinaryNode *subroot);
	BinaryNode* balanceLL(BinaryNode *ptr);
	BinaryNode* balanceRR(BinaryNode *ptr);
	BinaryNode* balanceLR(BinaryNode *ptr);
	BinaryNode* balanceRL(BinaryNode *ptr);

	BinaryNode *root;

};

AVLTree::AVLTree()
{ //Constructor for Tree
	root = nullptr;
}

BinaryNode * AVLTree::preInsert(node_entry num)
{ //Uses num from file to create a node before inserting into tree
	root = insertNode(root, num);
	return root;
}
BinaryNode* AVLTree::insertNode(BinaryNode * subroot, node_entry num)
{ //Insert Node into Tree, determine proper location, balance tree if necessary
	if (subroot == nullptr)
	{
		subroot = new BinaryNode(num);
		return subroot;
	}
	else
	{
		if (num > subroot->data)
		{
			subroot->rchild = insertNode(subroot->rchild, num);
			subroot = balanceTree(subroot);
			return subroot;
		}
		else if (num < subroot->data)
		{
			subroot->lchild = insertNode(subroot->lchild, num);
			subroot = balanceTree(subroot);
			return subroot;
		}
		return subroot;
	}

}

 BinaryNode * AVLTree::balanceTree(BinaryNode * subroot)
{
	node_entry balanceFactor = getBalance(subroot); 
	if (balanceFactor < -1)
	{
		if (getBalance(subroot->rchild) < 0)
		{
			return balanceRR(subroot);
		}
		else 
		{
			return balanceRL(subroot);
		}
	}
	else if (balanceFactor > 1)
	{
		if (getBalance(subroot->lchild) > 0)
		{
			return balanceLL(subroot);
		}
		else 
		{
			return balanceLR(subroot);
		}
	}
	return subroot;
}

node_entry AVLTree::getBalance(BinaryNode * subroot)
{
	node_entry balance = height(subroot->lchild) - height(subroot->rchild);
	return balance;
}

node_entry AVLTree::height(BinaryNode * subroot)
{
	using namespace std;


	if (subroot == nullptr)
	{
		//cout << "\nSubroot is null" << endl;
		return 0;
	}
	else 
	{
		if (height(subroot->lchild) > height(subroot->rchild))
		{
			//return height(subroot->lchild) + 1;
			return height(subroot->lchild) ;
		}
		else
		{
			//return height(subroot->rchild) + 1;
			return height(subroot->rchild) ;
		}
	}
	
}


BinaryNode * AVLTree::balanceLL(BinaryNode * ptr)
{
	BinaryNode *rightTree = ptr->lchild;
	ptr->lchild = rightTree->rchild;
	rightTree->rchild = ptr;
	return rightTree;

}

BinaryNode * AVLTree::balanceRR(BinaryNode * ptr)
{
	BinaryNode *rightTree = ptr->rchild;
	ptr->rchild = rightTree->lchild;
	rightTree->lchild = ptr;
	return rightTree;
}

BinaryNode * AVLTree::balanceLR(BinaryNode * ptr)
{
	BinaryNode* rightTree = ptr->lchild;
	ptr->lchild = balanceRR(ptr);
	return balanceLL(ptr);
}
BinaryNode * AVLTree::balanceRL(BinaryNode * ptr)
{
	BinaryNode *rightTree = ptr->rchild;
	ptr->rchild = balanceLL(ptr);
	return balanceRR(ptr);
}
#endif