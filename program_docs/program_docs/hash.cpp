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
//insert the item with the given key in sorted order
void HashTable::addItem(int id, string name, double yards, double TDs, double ppg)
{
    Nodeptr N = new Node(id, name, yards, TDs, ppg);
    int hashIndex = hash(name);
    
    if (Table[hashIndex]->rbObject.get_name() == "")//check if it is taked
    {
        Table[hashIndex] = N;
    }
    else
    {
        Nodeptr temp = Table[hashIndex];
        Nodeptr prev= NULL;
        if (name< Table[hashIndex]->rbObject.get_name())
        {
            N->next = Table[hashIndex];
        }
        
        while(temp!= NULL && temp->rbObject.get_name() <= name)  //see if new node should be placed before or after then exited item(s)
        {
            prev = temp;
            temp = temp->next;
        }
        N->next = temp;
        prev->next =N;
    }
}

 
 
 //********************** removeItem function ********************
  //removes the item with the given key
void HashTable::removeItem(string key)
 {
     int hashIndex = hash(key);
     if (Table[hashIndex]->rbObject.get_name() == key)
    {
        delete Table[hashIndex];
    }
     else
     {
         Nodeptr temp = Table[hashIndex];
         Nodeptr prev = NULL;
         while(temp != NULL)
         {
             if (temp->rbObject.get_name()!=key)
             {
                 prev = temp;
                 temp = temp->next;
             }
             prev->next = temp->next;
             delete temp;
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
    if (Table[index]->rbObject.get_name() == "")
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
//prints the first item of each list
//includes the number of items stored at that list

{
    cout << "--------------------------------------------"<< endl;
    for (int i=0; i<TABLE_SIZE; i++)
    {
        cout << "Index " << i<< " :"<<endl;
        cout <<"ID: " << Table[i]->rbObject.get_ID() << endl;
        cout <<"Name: " << Table[i]->rbObject.get_name() <<endl;
        cout <<"yards: " << Table[i]->rbObject.get_yards() << endl;
        cout <<"TDs: " << Table[i]->rbObject.get_TDs() << endl;
        cout <<"ppg: " << Table[i]->rbObject.get_ppg() << endl;
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
        if (temp->rbObject.get_name() == name)
        {
            cout << temp->rbObject.get_yards();
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
    while (temp->next != NULL)
    {
        {
            cout <<"ID: " << temp->rbObject.get_ID() << endl;
            cout <<"Name: " << temp->rbObject.get_name() <<endl;
            cout <<"yards: " << temp->rbObject.get_yards() << endl;
            cout <<"TDs: " << temp->rbObject.get_TDs() << endl;
            cout <<"ppg: " << temp->rbObject.get_ppg() << endl;
        }
            temp = temp->next;
    }
}

