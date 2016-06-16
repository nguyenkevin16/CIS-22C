//
//  HashTable.cpp
//
//  Created by Minting Ye on 5/17/16.
//  Copyright © 2016 Minting Ye. All rights reserved.
//

#include "HashTable.h"
#include <iostream>
#include <string>

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

	delete[] return_ptrs;
}

//********************** hash function ********************
int HashTable::hash(std::string key)
{
    int index = 0;
    int sum = 0;
    for(unsigned i = 0; i < key.length(); i++)
        sum += (int) key[i]; //summing the ASCII values for each character in the string
    index = sum % TABLE_SIZE; //dividing the summed ASCII values by 35 && storing remainder as my index
    return index;

}
//the ASCII values of each character % the table size


rb* HashTable::find(const std::string& str) {
	int hashIndex = hash(str);

	Table[hashIndex];

	if (Table[hashIndex] == nullptr) {
		return nullptr;
	}
	else {
		Nodeptr temp = Table[hashIndex];
		Nodeptr prev = nullptr;

		if (str == temp->rb_ptr->get_name()) {
			return temp->rb_ptr;
		}

		else {
			while (temp->next != nullptr) {
				prev = temp;
				temp = temp->next;
				
				if (str == temp->rb_ptr->get_name()) {
					return temp->rb_ptr;
				}
			}
		}

		return nullptr;
	}
}

int HashTable::total_items() {
	int total_items = 0;
	for (int i = 0; i < TABLE_SIZE; i++) 
		total_items += numItemsAtIndex(i);

	return total_items;
}


rb** HashTable::return_all() {
	int total_items = this->total_items();
	
	delete [] return_ptrs;
	return_ptrs = new rb*[total_items];

	int list_size, rb_pos = 0;
	Nodeptr curr, prev;

	for (int table_idx = 0; table_idx < TABLE_SIZE; table_idx++) {
		list_size = numItemsAtIndex(table_idx);
		
		curr = Table[table_idx];
		prev = nullptr;
		

		for (int i = 0; i < list_size; i++) {
			return_ptrs[rb_pos] = curr->rb_ptr;

			prev = curr;
			curr = curr->next;

			rb_pos++;
		}
	}

	return return_ptrs;
}

void HashTable::print_all() {
	int list_size, rb_pos = 0;
	Nodeptr curr, prev;

	for (int table_idx = 0; table_idx < TABLE_SIZE; table_idx++) {
		list_size = numItemsAtIndex(table_idx);

		curr = Table[table_idx];
		prev = nullptr;

		if (curr != nullptr) {
			for (int i = 0; i < list_size; i++) {

				std::cout << table_idx + 1 << "." << i + 1 << ": ";
				curr->rb_ptr->print_simple();							// CHANGE TO SIMPLE OUTPUT - looks MESSY

				prev = curr;
				curr = curr->next;

				rb_pos++;
			}

			std::cout << std::endl;
		}
	}
}

//********************** addItem function ********************
//insert the item with the given key in sorted order
void HashTable::addItem(std::string name, std::string team, int gp, double pts, double ppg, int ru_a, int ru_td, int rc_td, int tar, int rec, double ru_y, double rc_y)
{
	Nodeptr N = new Node(name, team, gp, pts, ppg, ru_a, ru_td, rc_td, tar, rec, ru_y, rc_y);
	int hashIndex = hash(name);

	if (Table[hashIndex] == nullptr) // Check if slot is empty, if yes, add to slot
	{
		Table[hashIndex] = N;
	}
	else
	{
		Nodeptr temp = Table[hashIndex];
		Nodeptr prev = nullptr;
		if (name < Table[hashIndex]->rb_ptr->get_name())
		{
			N->next = Table[hashIndex];
			Table[hashIndex] = N;
		}
		else
		{
			while (temp != nullptr && temp->rb_ptr->get_name() <= name)  //see if new node should be placed before or after then exited item(s)
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
void HashTable::addItem(rb* rb_new)
{
	Nodeptr N = new Node(rb_new);
	int hashIndex = hash(rb_new->get_name());

	if (Table[hashIndex] == nullptr) // Check if slot is empty, if yes, add to slot
	{
		Table[hashIndex] = N;
	}
	else
	{
		Nodeptr temp = Table[hashIndex];
		Nodeptr prev = nullptr;
		if (rb_new->get_name() < Table[hashIndex]->rb_ptr->get_name())
		{
			N->next = Table[hashIndex];
			Table[hashIndex] = N;
		}
		else
		{
			while (temp != nullptr && temp->rb_ptr->get_name() <= rb_new->get_name())  //see if new node should be placed before or after then exited item(s)
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
void HashTable::removeItem(std::string name)
{
	int hashIndex = hash(name);
	Nodeptr temp = Table[hashIndex];
	Nodeptr prev = nullptr;

	if (Table[hashIndex] != nullptr) 
	{
		if (Table[hashIndex]->rb_ptr->get_name() == name)	
		{
			Table[hashIndex] = temp->next;
			delete temp;
		}
		else
		{
			while (temp != nullptr)
			{
				if (temp->rb_ptr->get_name() != name)
				{
					prev = temp;
					temp = temp->next;
				}
				else if (temp->rb_ptr->get_name() == name)
				{
					prev->next = temp->next;
					delete temp;
					return;
				}
			}

			std::cout << "The player " << name << " could not be found." << std::endl;
		}
	}
 }

 

//********************** numItemsAtIndex function ********************
int HashTable::numItemsAtIndex(int index)
//Helper function to printTable
//Counts the number of items in each index

{
	Nodeptr temp = Table[index];
	int i = 0;
	if (Table[index] == nullptr)
		return i;
	else
	{
		//i++;

		while (temp != nullptr)
		{
			i++;
			temp = temp->next;
		}
		return i;
	}
}


//********************** printTable function ********************
void HashTable::printTable()
//prints the first item of each list
//includes the number of items stored at that list

{
    std::cout << "--------------------------------------------"<< std::endl;
    for (int i=0; i<TABLE_SIZE; i++)
    {
		std::cout << "Index " << i << " : # of nodes: " << numItemsAtIndex(i) << std::endl;
	}
        
}


//********************** findPts function ********************
int HashTable::findPts(std::string name)
//Searches for yards in the table using the key
//returns the index under which the name is stored
//returns -1 if the name is not found

{
    int hashIndex = hash(name);
    Nodeptr temp = Table[hashIndex];
    while (temp->next != NULL)
    {
        if (temp->rb_ptr->get_name() == name)
        {
            std::cout << temp->rb_ptr->get_pts();
            return hashIndex;
        }
        else
        {
         temp =temp->next;
        }
    }
    std::cout << "The title was not stored in the table." <<std::endl;
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
				std::cout << "Name: " << temp->rb_ptr->get_name() << std::endl;
				std::cout << "yards: " << temp->rb_ptr->get_pts() << std::endl;
				std::cout << "ppg: " << temp->rb_ptr->get_ppg() << std::endl;
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

