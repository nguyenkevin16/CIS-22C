//
//  HashTable.h
//  HashTable
//
//  Created by Minting Ye on 5/17/16.
//  Copyright © 2016 Minting Ye. All rights reserved.
//

#ifndef HashTable_h
#define HashTable_h

#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;

class HashTable {
    
public:
    HashTable();
    
    ~HashTable();

    int hash(string key);
    //returns the hash value for the given key
    //the hash value is the sum of
    //the ASCII values of each character % the table size
    
    void addItem(int id, string name, double yards, double TDs, double ppg);
    //inserts a new item into the table
    // calls the hash function on the key title to determine the correct bucket
    
    void removeItem(string key);
    //removes the item with the given key
    
    int numItemsAtIndex(int index);
    //Helper function to printTable
    //Counts the number of items in each bucket
    
    void printTable();
    //prints the first item of each bucket
    //includes the number of items stored at that bucket
    
    void printBucket(int index);
    //Prints all items stored at a particular bucket
    
    int findYards(string name);
    //Searches for Yards in the table using the key
    //returns the index under which the name is stored
    //returns -1 if the name is not found
    
private:
    
    struct Node
    {
        int id;
        string name;
        double yards;
        double TDs;
        double ppg;
        Node* next;
        Node(): id(0), name(""), yards(0), TDs(0), ppg(0), next(NULL){}
        Node(int nid, string nname, double nyards, double nTDs, double nppg): id(nid), name(nname), yards(nyards), TDs(nTDs), ppg(nppg), next(NULL) {}
    };
    
    typedef struct Node* Nodeptr;
    
    static const int TABLE_SIZE = 13;
    Nodeptr Table[TABLE_SIZE];
    
};

#endif /* HashTable_h */
