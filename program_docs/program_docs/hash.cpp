
//  HashTable
//
//  Created by Minting Ye on 5/17/16.
//  Copyright © 2016 Minting Ye. All rights reserved.
//

#include "hash.h"
#include <iostream>
#include <string>


using namespace std;


//********************** constructor ********************
HashTable::HashTable()
{
    for (int i=0; i < TABLE_SIZE; i++)
        Table[i] = new Node();
}


//********************** destructor ********************
HashTable::~HashTable()
{
    for (int i=0; i< TABLE_SIZE; i++)
        delete Table[i];
}

//********************** hash function ********************
int HashTable::hash(string key)
{
    int index = 0;
    int sum = 0;
    for(int i = 0; i < key.length(); i++)
        sum += (int) key[i]; //summing the ASCII values for each character in the string
    index = sum % TABLE_SIZE; //dividing the summed ASCII values by 35 && storing remainder as my index
    return index;

}
//the ASCII values of each character % the table size


//********************** addItem function ********************
void HashTable::addItem(int id, string name, double yards, double TDs, double ppg)
{
    Nodeptr N = new Node(id, name, yards, TDs, ppg);
    int hashIndex = hash(name);
    
    if (Table[hashIndex]->name == "")
    {
        Table[hashIndex] = N;
    }
    else
    {
        Nodeptr temp = Table[hashIndex];
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = N;
     }
   
}

//********************** numItemsAtIndex function ********************
int HashTable::numItemsAtIndex(int index)
//Helper function to printTable
//Counts the number of items in each bucket

{
    Nodeptr temp = Table[index];
    int i=0;
    if (Table[index]->name == "")
        return i;
    else
    {
        while (temp->next != NULL)
        {
            i++;
            temp = temp->next;
        }
    return i;
    }
    
    
}

//********************** printTable function ********************
void HashTable::printTable()
//prints the first item of each bucket
//includes the number of items stored at that bucket

{
    cout << "--------------------------------------------"<< endl;
    for (int i=0; i<TABLE_SIZE; i++)
    {
        cout << "Index " << i<< " :"<<endl;
        cout <<"ID: " << Table[i]->id << endl;
        cout <<"Name: " << Table[i]->name <<endl;
        cout <<"yards: " << Table[i]->yards << endl;
        cout <<"TDs: " << Table[i]->TDs << endl;
        cout <<"ppg: " << Table[i]->ppg << endl;
        cout << "Number of Values at this Index: " << numItemsAtIndex(i);
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
        if (temp->name == name)
        {
            cout << temp->yards;
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


//********************** printBucket function ********************
void HashTable::printBucket(int index)
//Prints all items stored at a particular bucket
{
    Nodeptr temp = Table[index];
    while (temp->next != NULL)
    {
        {
            cout <<"ID: " << temp->id << endl;
            cout <<"Name: " << temp->name <<endl;
            cout <<"yards: " << temp->yards << endl;
            cout <<"TDs: " << temp->TDs << endl;
            cout <<"ppg: " << temp->ppg << endl;
        }
            temp = temp->next;
    }
}

