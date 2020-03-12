#pragma once
typedef int node_entry;

struct Node
{
	
	node_entry data;
	Node *next;

	Node();
	Node(node_entry item, Node *add = nullptr);
};

Node::Node()
{
	next = nullptr;
}

Node::Node(node_entry item, Node *add)
{
	data = item;
	next = add;
}