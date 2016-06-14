/*
	Team 4
	Kevin Nguyen
	Ka U Ieong
	Bret Farley
	Minting Ye

	To-Do:
	MENU_ADD
	COMPARE
	EFFICIENCY - clean up
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <cstdlib>
#include "player_IO.h"
#include "HashTable.h"
#include "AVL.h"

using namespace std;

// Function Prototypes
void enableDebug(bool bvalue);
void menu_controller(HashTable* hashPtr, rb_list& obj_list);
void menu_add(HashTable* hashPtr, rb_list& obj_list);
void menu_delete(HashTable* hashPtr);
void menu_find(HashTable* hashPtr);
void menu_printHash(HashTable* hashPtr);
void menu_printSortedData(HashTable* hashPtr);
void menu_printTree(HashTable* hashPtr);
void menu_printEfficiency(HashTable* hashPtr);

int main() {

	enableDebug(true);

	HashTable* hashPtr = new HashTable;
	rb_list obj_list;

	obj_list.read_file("RB_stats_2015.txt");
	for (int i = 0; i < 50; i++) hashPtr->addItem(obj_list.get_item(i));

	menu_controller(hashPtr, obj_list);

	delete hashPtr;

	system("pause");
	return 0;
}

void enableDebug(bool bvalue)
{
	if (!bvalue) return;

	int tmpFlag = _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG);

	// Turn on leak-checking bit.
	tmpFlag |= _CRTDBG_LEAK_CHECK_DF;

	// Turn off CRT block checking bit.
	tmpFlag &= ~_CRTDBG_CHECK_CRT_DF;

	// Set flag to the new value.
	_CrtSetDbgFlag(tmpFlag);
}


void menu_controller(HashTable* hashPtr, rb_list& obj_list) {
	string choice;

	while (choice != "9") {
		system("CLS");

		cout << "-------Main Menu-------" << endl;
		cout << "1. Add new data        " << endl;
		cout << "2. Delete data         " << endl;
		cout << "3. Find data           " << endl;
		cout << "4. List hash sequence  " << endl;
		cout << "5. List sorted data    " << endl;
		cout << "6. Print indented tree " << endl;
		cout << "7. Print efficieny     " << endl;
		cout << "8. Team choice         " << endl;
		cout << "9. Exit                " << endl;
		cout << "-----------------------" << endl;

		do {
			cout << "Enter a choice: ";
			cin >> choice;

		} while (!isdigit(choice[0]));

		switch (stoi(choice)) {
		case 1:
			menu_add(hashPtr, obj_list); break;
		case 2:
			menu_delete(hashPtr); break;
		case 3:
			menu_find(hashPtr); break;
		case 4:
			menu_printHash(hashPtr); break;
		case 5:
			menu_printSortedData(hashPtr); break;
		case 6:
			menu_printTree(hashPtr); break;
		case 7:
			menu_printEfficiency(hashPtr); break;
		case 8:
			break;
		case 9:
			cout << "Now exiting..." << endl; break;
		default:
			break;
		}
	}
}

void menu_add(HashTable* hashPtr, rb_list& obj_list) {
	system("CLS");
	
	cout << "Would you like to add a player manually or read from file?" << endl;
	cout << "1. Manually" << endl;
	cout << "2. Read from file" << endl;

	string choice;
	do {
		cout << "Enter a choice: ";
		cin >> choice;
	} while (!isdigit(choice[0]));

	if (choice == "1") {



	}


	else if (choice == "2") {
		string filename = "RB_stats_2015.txt";

		obj_list.read_file(filename);

		for (int i = 0; i < 50; i++) hashPtr->addItem(obj_list.get_item(i));
		
		return;
	} 
}

void menu_delete(HashTable* hashPtr) {
	string buffer, name;

	cout << "Enter the name of the player you wish to remove: ";
	cin >> name >> buffer;
	name += " " + buffer;

	if (hashPtr->find(name) != nullptr) {
		hashPtr->removeItem(name);
	} else {
		cout << "Could not find the player." << endl;
	}

	system("pause");
}

void menu_find(HashTable* hashPtr) {
	string buffer, name;

	cout << "Please enter the name of the player: ";
	cin >> name >> buffer;
	name += " " + buffer;

	if (hashPtr->find(name) == nullptr) {
		cout << "Could not find the player." << endl;
	} else {
		cout << hashPtr->find(name) << endl << endl;
	}

	system("pause");
}

void menu_printHash(HashTable* hashPtr) {
	system("CLS");

	hashPtr->print_all();
	system("pause");
}

void menu_printSortedData(HashTable* hashPtr) {
	rb** rbPtr = hashPtr->return_all();
	int total = hashPtr->total_items();
	
	system("CLS");

	cout << "-------Sorted Data-------" << endl;
	cout << "1. Name                  " << endl;
	cout << "2. Pts                   " << endl;
	cout << "3. Pts per game          " << endl;

	string choice;

	do {
		cout << "Enter a choice: ";
		cin >> choice;

	} while (!isdigit(choice[0]));

	if (choice == "1") {
		system("CLS");

		AVL<rb, string>* avlPtr = new AVL<rb, string>("name");

		for (int i = 0; i < total; i++) avlPtr->add_ptr(rbPtr[i]);

		cout << "Name           tm  GP  RuA RuY   Rutd  Tar Rc  RcY RcTD pts   p/g" << endl;
		avlPtr->rprintInOrder(avlPtr->get_root());

		delete avlPtr;
		system("pause");
		return;
	} if (choice == "2") {
		system("CLS");

		AVL<rb, string>* avlPtr = new AVL<rb, string>("pts");

		for (int i = 0; i < total; i++) avlPtr->add_ptr(rbPtr[i]);
		
		cout << "Name           tm  GP  RuA RuY   Rutd  Tar Rc  RcY RcTD pts   p/g" << endl;
		avlPtr->rprintInOrder(avlPtr->get_root());

		delete avlPtr;
		system("pause");
		return;
	} if (choice == "3") {
		system("CLS");

		AVL<rb, string>* avlPtr = new AVL<rb, string>("ppg");

		for (int i = 0; i < total; i++) avlPtr->add_ptr(rbPtr[i]);

		cout << "Name           tm  GP  RuA RuY   Rutd  Tar Rc  RcY RcTD pts   p/g" << endl;
		avlPtr->rprintInOrder(avlPtr->get_root());

		delete avlPtr;
		system("pause");
		return;
	}
}

void menu_printTree(HashTable* hashPtr) {
	rb** rbPtr = hashPtr->return_all();
	int total = hashPtr->total_items();

	system("CLS");

	cout << "-------Print Tree--------" << endl;
	cout << "1. Name                  " << endl;
	cout << "2. Pts                   " << endl;
	cout << "3. Pts per game          " << endl;

	string choice;

	do {
		cout << "Enter a choice: ";
		cin >> choice;

	} while (!isdigit(choice[0]));

	if (choice == "1") {
		system("CLS");

		AVL<rb, string>* avlPtr = new AVL<rb, string>("name");

		for (int i = 0; i < total; i++) avlPtr->add_ptr(rbPtr[i]);

		avlPtr->display(avlPtr->get_root(), 1);
		cout << endl;

		delete avlPtr;
		system("pause");
		return;
	} if (choice == "2") {
		system("CLS");

		AVL<rb, string>* avlPtr = new AVL<rb, string>("pts");

		for (int i = 0; i < total; i++) avlPtr->add_ptr(rbPtr[i]);

		avlPtr->display(avlPtr->get_root(), 1);
		cout << endl;

		delete avlPtr;
		system("pause");
		return;
	} if (choice == "3") {
		system("CLS");

		AVL<rb, string>* avlPtr = new AVL<rb, string>("ppg");

		for (int i = 0; i < total; i++) avlPtr->add_ptr(rbPtr[i]);

		avlPtr->display(avlPtr->get_root(), 1);
		cout << endl;

		delete avlPtr;
		system("pause");
		return;
	}
}

void menu_printEfficiency(HashTable* hashPtr) {
	cout << "Hash Statistics: " << endl;

	int hash_total = hashPtr->total_items();
	int hash_slots = hashPtr->get_table_size();
	double load_factor = static_cast<double>(hash_total) / hash_slots;

	cout << "Load Factor: " << load_factor << endl;


	cout << "AVL Statistics: " << endl;

	system("pause");
}