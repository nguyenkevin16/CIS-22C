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
#include "bst_player.h"
#include "AVL.h"

using namespace std;

// Function Prototypes
void enableDebug(bool bvalue);
void menuController();
void menuSwitch(const int& choice);

int main() {

	enableDebug(true);

	string filename = "RB_stats_2015.txt";
	
	rb_list obj_list;
	obj_list.read_file(filename);

	HashTable hash;
	for (int i = 0; i < 50; i++) hash.addItem(obj_list.get_item(i));
	// hash.removeItem("Devonta Freeman");
	// hash.printList(12);	
	// hash.printTable();			// PROBLEM WITH INDEXING

	bst_player<rb> bst_obj;
	for (int i = 0; i < 50; i++) bst_obj.add_ptr(obj_list.get_item(i));

	// menuController();

	AVL<rb> avl;

	for (int i = 0; i < 20; i++) avl.add_ptr(obj_list.get_item(i));
	avl.display(avl.get_root(), 1);

	cout << endl << endl;

	avl.printBreadthFirst(avl.get_root());
	
	
	
	// bst_obj.add_ptr(obj_list.get_item(0));
	// bst_obj.add_ptr(obj_list.get_item(1));
	// bst_obj.add_ptr(obj_list.get_item(2));

	// bst_obj.printBreadthFirst(bst_obj.get_root());

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


void menuController() {
	system("pause");
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

	menuSwitch(stoi(choice));
}

void menuSwitch(const int& choice) {
	system("pause");
	system("CLS");

	switch (choice) {
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		case 8:
			break;
		case 9:
			cout << "Now exiting..." << endl;
			break;
		default:
			break;
	}
}