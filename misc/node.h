#pragma once
//CIS 22C
//Lab2b
//Bret Farley, Minting Ye

//This is the node ADT

#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <cstdlib>

using namespace std;

template <typename Type> class node
{
protected:
	typedef node<Type>* nodeptr;
	Type data;
	node<Type>* next;
public:
	node()
	{
		next = 0;
	}
	node(Type obj)
	{
		next = 0;
		data = obj;
	}

	~node()
	{

	}
	void setData(Type obj)
	{
		//system("pause");
		data = obj;
	}

	void setNext(Type obj)
	{
		//next = new node;
		//system("pause");
		next->setData(obj);
	}

	

	Type getData()
	{
		return data;
	}

	node* getPointer()
	{
		return next;
	}

	//Simple link function. Attaches one node object to another in a one-way format
	void link(node<Type> obj)
	{
		next = &obj;
	}


	node* last()
	{
		node* temp1 = next;
		node* temp2 = 0;
		while (temp1 != 0)
		{
			temp2 = temp1;
			temp1 = temp1->next;
		}
		return temp2;
	}

	//Basic print function. Prints the node and any other data attached to it
	void printFrom()
	{
		node* temp1 = next;
		node* temp2 = 0;
		cout << endl << data;
		while (temp1 != 0)
		{
			cout << temp1->data << endl;
			temp2 = temp1->next;
			temp1 = temp2;
		}
		cout << endl;

	}

	template <typename T> friend class linkedList;
	template <typename T> friend class Stack;
	template <typename T> friend class Queue;
	template <typename T> friend class bst;
};
#endif // NODE_H
