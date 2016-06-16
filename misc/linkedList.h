#pragma once
//CIS 22C
//Lab2b
//Bret Farley, Minting Ye

//This is the linkedList ADT

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <cstdlib>
#include "node.h"


using namespace std;

template <typename Type> class linkedList
{
protected:
	typedef node<Type>* nodeptr;
	node<Type>* head;
	node<Type>* tail;
	int length;
	//cursor functions will be implemented if time permits
	node<Type>* cursor;
public:
	/*------------Constructors and destructor-----------*/
	linkedList()
	{
		head = 0;
		tail = 0;
		length = 0;
	}

	/*------------Basic utility functions.--------------*/
	bool is_null()
	{
		return(length == 0);
	}

	Type head_item()
	{
		return head->data;
	}

	node<Type>* get_head()
	{
		return head;
	}
	void set_tail(Type obj)
	{
		tail->setNext(obj);
		tail = tail->next;
	}
	Type tail_item()
	{
		return tail->data;
	}

	int get_length()
	{
		return length;
	}

	/*-----------Editing functions---------------------*/

	//initialize member function takes in user input to create
	//a list of a set amount of items
	void initialize()
	{
		if (head == 0)
		{
			cout << "how many items? ";
			int items;
			node<Type>* temp = head;
			node<Type>* last;
			cin >> items;
			head = new node<Type>;
			temp = head;
			Type dataIn;

			cout << "Enter " << items << " items of datatype \n";
			for (int i = 0; i < items; i++)
			{
				cin >> dataIn;
				temp->data = dataIn;
				temp->next = new node<Type>;
				last = temp;
				temp = temp->next;
				length++;
			}
			temp = 0;
			tail = last;
		}
		else
			cout << "Cannot initialize, list already exists.\n";
	}

	//I changed the names of these functions to their conventional
	//programming names. Originally insert head, tail remove head,
	//tail functions


	void push(Type item)       //previously insert tail
	{
		if (length == 0)
		{
			tail = new node<Type>(item);
			cout << "\n adding headnode\n";
			head = tail;
		}
		else
		{
			cout << "\n Pushing node\n";
			system("pause");
			node<Type>* N = new node<Type>(item);// create the new node by calling the node constructor
			cout << tail->getData();
			system("pause");
			(tail->next)->data = item;
			tail = tail->next;
			//tail->next = N;
			//tail = N; //make the original tail point to the new node

		}
		length++;
	}

	void front_push(Type item) //previously insert head
	{
		if (length == 0)
		{
			head = new node<Type>(item);
			tail = head;
		}
		else
		{
			node<Type>* N = new node<Type>(item);//create the new node by calling the node constructor
			N->next = head;//set the new node's next field to point to the head
			head = N;//make the head be the new node
		}
		length++;
	}

	void shift(Type item)      //previously delete head
	{
		if (length == 0) //or make a call to the is_empty() function
		{
			cout << "delete_head(): List is empty. Cannot remove first element." << endl;
		}
		else if (length == 1)
		{
			delete head;
			head = 0;
			tail = 0;
			cursor = NULL;
			length = 0;
		}
		else
		{
			if (cursor == head)
				cursor = 0;
			node<Type>* temp = head; //store original head node in a temporary variable
			head = head->next; //make the head pointer point to the second node in the List
			delete temp; //delete the original head
			length--;
		}
	}

	//inserts an item after the position indicated
	//preconditions: pos cannot be longer than length or equal to 0

	void insert_item(int pos, Type item)
	{
		if (pos >= length)
		{
			cout << "Position longer than length.\n";
		}
		else if (pos == 0)
		{
			cout << "Position precedes length.\n";
		}
		else
		{
			node<Type>* temp = head;
			node<Type>* temp2;
			for (int i = 0; i < pos; i++)
			{
				temp2 = temp;
				temp = temp->next;
			}
			node<Type>* holder = new node<Type>(item);
			holder->next = temp;
			temp2->next = holder;
			length++;
		}
	}

	void remove_item(int pos, Type item)
	{
		if (pos >= length)
		{
			cout << "Improper position.\n";
		}
		else if (pos == 0)
		{
			shift(item);
		}
		else
		{
			node<Type>* temp = head;
			node<Type>* temp2;
			for (int i = 0; i < pos; i++)
			{
				temp2 = temp;
				temp = temp->next;
			}
			node<Type>* holder = temp->next;
			holder->next = temp;
			temp2->next = holder;
			delete temp;
			length--;
		}
	}

	//utilizes the node::printFrom() function to compact code
	//prints from the head node
	void print()
	{
		head->printFrom();
	}

	ostream& operator<<(ostream& os)
	{
		nodeptr cur = head;
		bool cont = true;
		while (cont)
		{
			os << cur->data << " ";
			if (cur->next == 0)
				cont = false;
		}
		return os;
	}
};

#endif // LINKEDLIST_H
