//
//  HashTable.h
//  HashTable
//
//  Created by Minting Ye on 5/17/16.
//  Copyright © 2016 Minting Ye. All rights reserved.
//

#ifndef HashTable_h
#define HashTable_h

#include <iostream>
#include <string>
#include <cstdlib>
#include "player.h"

class HashTable {
private:

	struct Node
	{
		rb* rb_ptr;
		Node* next;
		Node() 
			: rb_ptr(nullptr), next(nullptr) {}
		Node(rb* rb_ptr) 
			: rb_ptr(rb_ptr), next(nullptr) {}
		Node(std::string name, std::string team, int gp, double pts, double ppg, int ru_a, int ru_td, int rc_td, int tar, int rec, double ru_y, double rc_y)
			: rb_ptr(new rb(name, team, gp, pts, ppg, ru_a, ru_td, rc_td, tar, rec, ru_y, rc_y)), next(nullptr) {}
	};

	typedef struct Node* Nodeptr;

	static const int TABLE_SIZE = 29;
	Nodeptr Table[TABLE_SIZE];
public:
    HashTable();
    ~HashTable();

	Nodeptr get_idx(const int& idx) const { return Table[idx]; }

	rb* find(const std::string& str);

    int hash(std::string key);
    //returns the hash value for the given key
    //the hash value is the sum of
    //the ASCII values of each character % the table size
    
	void addItem(std::string name, std::string team, int gp, double pts, double ppg, int ru_a, int ru_td, int rc_td, int tar, int rec, double ru_y, double rc_y);
    // inserts a new item into the table
    // calls the hash function on the key title to determine the correct bucket
    
	void addItem(rb* rb_new);
	// inserts a new item into the table
	// calls the hash function on the key title to determine the correct bucket

    void removeItem(std::string key);
    //removes the item with the given key
    
    int numItemsAtIndex(int index);
    //Helper function to printTable
    //Counts the number of items in each index
    
    void printTable();
    //prints the first item of each linked list
    //includes the number of items stored at that index
    
    void printList(int index);
    //Prints all items stored at a particular list
    
    int findPts(std::string name);
    //Searches for Yards in the table using the key
    //returns the index under which the name is stored
    //returns -1 if the name is not found

	void empty_list(int index);
    
};

#endif /* HashTable_h */
