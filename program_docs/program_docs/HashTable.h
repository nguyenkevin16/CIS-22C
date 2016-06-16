//
//		HashTable.h
//
//		Team 4
//
//		Kevin Nguyen
//		Ka U Ieong
//		Bret Farley
//		Minting Ye
//
//		Created by Minting Ye on 5/17/16.
//		Copyright © 2016 Minting Ye. All rights reserved.
//

#ifndef HashTable_h
#define HashTable_h

#include <iostream>
#include <string>
#include <cstdlib>
#include "player.h"

class HashTable {
private:
	struct Node {
		// Data Members
		rb* rb_ptr;
		Node* next;

		// Constructors
		Node() 
			: rb_ptr(nullptr), next(nullptr) {}
		Node(rb* rb_ptr) 
			: rb_ptr(rb_ptr), next(nullptr) {}
		Node(std::string name, std::string team, int gp, double pts, double ppg, int ru_a, int ru_td, int rc_td, int tar, int rec, double ru_y, double rc_y)
			: rb_ptr(new rb(name, team, gp, pts, ppg, ru_a, ru_td, rc_td, tar, rec, ru_y, rc_y)), next(nullptr) {}
	};

	typedef struct Node* Nodeptr;

	rb** return_ptrs;	// Used to return an array of all hash table elements (only for rb objects)

	static const int TABLE_SIZE = 29;
	Nodeptr Table[TABLE_SIZE];				// Table of hash node*
public:
	// Constructors
    HashTable();
    ~HashTable();

	int get_table_size() const { return TABLE_SIZE; }
	// returns the size of the hash table
	// i.e. number of slots in the hash table

	int total_items();
	// returns the total number of nodes in the hash table

	void print_all();
	// prints the contents of the hash table to standard output
	// each node is preceded by table index and linked list number (e.g. 1.1)

	rb** return_all(); 
	// returns a ptr to an array of rb* of all rb objects in the hash table

	Nodeptr get_idx(const int& idx) const { return Table[idx]; }
	// returns the first node* at the specified table index

	rb* find(const std::string& str);
	// returns the rb* to the located player in the hash table

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
    //Searches for points in the table using the key
    //returns the index under which the name is stored
    //returns -1 if the name is not found

	void empty_list(int index);
	// dynamically releases a list at a specified table index location
    
};

#endif /* HashTable_h */
