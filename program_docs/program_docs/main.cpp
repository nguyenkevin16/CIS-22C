/*
	Team 4
	Kevin Nguyen
	Ka U Ieong
	Bret Farley
	Minting Ye
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
void menu_controller(HashTable* hashPtr, AVL<rb>* avlPtr, rb_list obj_list);
void menu_add(HashTable* hashPtr, AVL<rb>* avlPtr, rb_list obj_list);
void menu_delete();
void menu_find();
void menu_printHash();
void menu_printSortedData();
void menu_printTree();
void menu_printEfficiency();

int main() {

	enableDebug(true);

	HashTable* hashPtr = new HashTable;
	AVL<rb>* avlPtr = new AVL<rb>;
	rb_list obj_list;

	menu_controller(hashPtr, avlPtr, obj_list);

	avlPtr->display(avlPtr->get_root(), 1);
	cout << endl << endl;
	// avlPtr->rprintInOrder(avlPtr->get_root());

	delete hashPtr;
	delete avlPtr;


	// cout << bst_obj.search_string(bst_obj.get_root(), "Jeremy Langford")->get_data() << endl;
	// cout << hash.find("Jeremy Langford") << endl;

	// bst_obj.remove_string(bst_obj.get_root(), "Jeremy Langford");

	// cout << bst_obj.search_string(bst_obj.get_root(), "Jeremy Langford") << endl;
	// cout << hash.find("Jeremy Langford") << endl;

	// hash.removeItem("Jeremy Langford");
	// cout << hash.find("Jeremy Langford") << endl;
	
	// cout << hash.find("Devonta Freeman") << endl;
	// cout << bst_obj.get_root()->get_data() << endl;
	// cout << obj_list.get_item(0) << endl;


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


void menu_controller(HashTable* hashPtr, AVL<rb>* avlPtr, rb_list obj_list) {
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

	string choice;

	do {
		cout << "Enter a choice: ";
		cin >> choice;

	} while (!isdigit(choice[0]));

	switch (stoi(choice)) {
		case 1:
			menu_add(hashPtr, avlPtr, obj_list); break;
		case 2:
			menu_delete(); break;
		case 3:
			menu_find(); break;
		case 4:
			menu_printHash(); break;
		case 5:
			menu_printSortedData(); break;
		case 6:
			menu_printTree(); break;
		case 7:
			menu_printEfficiency(); break;
		case 8:
			break;
		case 9:
			cout << "Now exiting..." << endl; break;
		default:
			break;
	}
}

void menu_add(HashTable* hashPtr, AVL<rb>* avlPtr, rb_list obj_list) {
	system("CLS");
	
	cout << "Would you like to add a player manually or read from file?" << endl;
	cout << "1. Manually" << endl;
	cout << "2. Read from file" << endl;

	string choice;
	do {
		cout << "Enter a choice: ";
		cin >> choice;
	} while (!isdigit(choice[0]));

	if (choice == "2") {
		string filename = "RB_stats_2015.txt";

		obj_list.read_file(filename);

		for (int i = 0; i < 50; i++) hashPtr->addItem(obj_list.get_item(i));
		for (int i = 0; i < 50; i++) avlPtr->add_ptr(obj_list.get_item(i));
		
		return;
	} else {
	
	} 

}

void menu_delete() {

}

void menu_find() {

}

void menu_printHash() {

}

void menu_printSortedData() {

}

void menu_printTree() {

}

void menu_printEfficiency() {

}

// Head-to-head comparison
void compare(string& str1, string& str2, ) {
	cout << hash.find(str1) << endl;
	cout << hash.find(str2) << endl;
}