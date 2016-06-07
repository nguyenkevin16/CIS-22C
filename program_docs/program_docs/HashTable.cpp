//
//  main.cpp
//  HashTable
//
//  Created by Minting Ye on 5/17/16.
//  Copyright © 2016 Minting Ye. All rights reserved.
//

#include "HashTable.h"
#include <iostream>
#include <string>

using namespace std;

//********************** constructor ********************
HashTable::HashTable()
{
	for (int i = 0; i < TABLE_SIZE; i++) {
		Table[i] = nullptr;
	}
}


//********************** destructor ********************
HashTable::~HashTable()
{
	for (int i = 0; i < TABLE_SIZE; i++)
	{
		empty_list(i);
	}
}

//********************** hash function ********************
int HashTable::hash(string key)
{
    int index = 0;
    int sum = 0;
    for(unsigned i = 0; i < key.length(); i++)
        sum += (int) key[i]; //summing the ASCII values for each character in the string
    index = sum % TABLE_SIZE; //dividing the summed ASCII values by 35 && storing remainder as my index
    return index;

}
//the ASCII values of each character % the table size


rb* HashTable::find(const string& str) {
	int hashIndex = hash(str);

	Table[hashIndex];

	if (Table[hashIndex] == nullptr) {
		return nullptr;
	}
	else {
		Nodeptr temp = Table[hashIndex];
		Nodeptr prev = nullptr;

		if (str == temp->rbObject->get_name()) {
			return temp->rbObject;
		}

		else {
			while (temp->next != nullptr) {
				prev = temp;
				temp = temp->next;
				
				if (str == temp->rbObject->get_name()) {
					return temp->rbObject;
				}
			}
		}

		return nullptr;
	}
}

//********************** addItem function ********************
//insert the item with the given key in sorted order
void HashTable::addItem(int id, string name, double yards, double TDs, double ppg)
{
	Nodeptr N = new Node(id, name, yards, TDs, ppg);
	int hashIndex = hash(name);

	if (Table[hashIndex] == nullptr) // Check if slot is empty, if yes, add to slot
	{
		Table[hashIndex] = N;
	}
	else
	{
		Nodeptr temp = Table[hashIndex];
		Nodeptr prev = nullptr;
		if (name < Table[hashIndex]->rbObject->get_name())
		{
			N->next = Table[hashIndex];
			Table[hashIndex] = N;
		}
		else
		{
			while (temp != nullptr && temp->rbObject->get_name() <= name)  //see if new node should be placed before or after then exited item(s)
			{
				prev = temp;
				temp = temp->next;
			}
			N->next = temp;
			prev->next = N;
		}
	}
}


//********************** addItem function ********************
//insert the item with the given key in sorted order
void HashTable::addItem(rb* rb_obj)
{
	Nodeptr N = new Node(rb_obj);
	int hashIndex = hash(rb_obj->get_name());

	if (Table[hashIndex] == nullptr) // Check if slot is empty, if yes, add to slot
	{
		Table[hashIndex] = N;
	}
	else
	{
		Nodeptr temp = Table[hashIndex];
		Nodeptr prev = nullptr;
		if (rb_obj->get_name() < Table[hashIndex]->rbObject->get_name())
		{
			N->next = Table[hashIndex];
			Table[hashIndex] = N;
		}
		else
		{
			while (temp != nullptr && temp->rbObject->get_name() <= rb_obj->get_name())  //see if new node should be placed before or after then exited item(s)
			{
				prev = temp;
				temp = temp->next;
			}
			N->next = temp;
			prev->next = N;
		}
	}
}

 
 
 //********************** removeItem function ********************
 //removes the item with the given name
void HashTable::removeItem(string name)
{
	int hashIndex = hash(name);
	Nodeptr temp = Table[hashIndex];
	Nodeptr prev = nullptr;

	if (Table[hashIndex] != nullptr) 
	{
		if (Table[hashIndex]->rbObject->get_name() == name)	
		{
			Table[hashIndex] = temp->next;
			delete temp;
		}
		else
		{
			while (temp != nullptr)
			{
				if (temp->rbObject->get_name() != name)
				{
					prev = temp;
					temp = temp->next;
				}
				else if (temp->rbObject->get_name() == name)
				{
					prev->next = temp->next;
					delete temp;
					return;
				}
			}

			cout << "The player " << name << " could not be found." << endl;
		}
	}
 }

 

//********************** numItemsAtIndex function ********************
int HashTable::numItemsAtIndex(int index)
//Helper function to printTable
//Counts the number of items in each index

{
    Nodeptr temp = Table[index];
    int i=0;
    if (Table[index]->rbObject == nullptr)
        return i;
    else
    {
		i++;

        do
        {
            i++;
            temp = temp->next;
		} while (temp->next != nullptr);
    return i;
    }
}

//********************** printTable function ********************
void HashTable::printTable()
//prints the first item of each list
//includes the number of items stored at that list

{
    cout << "--------------------------------------------"<< endl;
    for (int i=0; i<TABLE_SIZE; i++)
    {
		cout << "Index " << i << " : # of nodes: " << numItemsAtIndex(i) << endl;
	}
        
}


//********************** findYards function ********************
int HashTable::findYards(string name)
//Searches for yards in the table using the key
//returns the index under which the name is stored
//returns -1 if the name is not found

{
    int hashIndex = hash(name);
    Nodeptr temp = Table[hashIndex];
    while (temp->next != NULL)
    {
        if (temp->rbObject->get_name() == name)
        {
            cout << temp->rbObject->get_yards();
            return hashIndex;
        }
        else
        {
         temp =temp->next;
        }
    }
    cout << "The title was not stored in the table." <<endl;
    return -1;

}


//********************** printList function ********************
void HashTable::printList(int index)
//Prints all items stored at a particular list
{
    Nodeptr temp = Table[index];
    
	if (Table[index] != nullptr) {
		do
		{
			{
				cout << "ID: " << temp->rbObject->get_ID() << endl;
				cout << "Name: " << temp->rbObject->get_name() << endl;
				cout << "yards: " << temp->rbObject->get_yards() << endl;
				cout << "TDs: " << temp->rbObject->get_TDs() << endl;
				cout << "ppg: " << temp->rbObject->get_ppg() << endl;
			}
			temp = temp->next;
		} while (temp != nullptr);
	}
}


//********************** empty_list() ********************
void HashTable::empty_list(int index) {
	Nodeptr temp;

	while (Table[index] != nullptr) {
		temp = Table[index];
		Table[index] = temp->next;
		delete temp;
		temp = nullptr;
	}
}

