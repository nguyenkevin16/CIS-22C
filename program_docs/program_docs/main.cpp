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
#include "player_IO.h"
#include "HashTable.h"
#include "bst_player.h"
using namespace std;

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

int main() {

	enableDebug(true);

	string filename = "RB_stats_2015.txt";
	rb_list obj_list;
	obj_list.read_file(filename);

	HashTable hash;
	for (int i = 0; i < 50; i++) hash.addItem(obj_list.get_arr(i));
	// hash.removeItem("Devonta Freeman");
	// hash.printList(12);	
	// cout << endl << hash.get_table(12)->rbObject << endl;

	bst_player<rb> bst_obj;
	for (int i = 0; i < 50; i++) bst_obj.add_ptr(obj_list.get_arr(i));
	// bst_obj.add_ptr(obj_list.get_arr(0));
	// bst_obj.add_ptr(obj_list.get_arr(1));
	// bst_obj.add_ptr(obj_list.get_arr(2));

	// bst_obj.printBreadthFirst(bst_obj.get_root());

	cout << bst_obj.search_string(bst_obj.get_root(), "Jeremy Langford")->get_data() << endl;
	cout << hash.find("Jeremy Langford") << endl;

	bst_obj.remove_string(bst_obj.get_root(), "Jeremy Langford");

	cout << bst_obj.search_string(bst_obj.get_root(), "Jeremy Langford") << endl;
	cout << hash.find("Jeremy Langford") << endl;

	hash.removeItem("Jeremy Langford");
	cout << hash.find("Jeremy Langford") << endl;
	
	// cout << hash.find("Devonta Freeman") << endl;
	// cout << bst_obj.get_root()->get_data() << endl;
	// cout << obj_list.get_arr(0) << endl;


	system("pause");
	return 0;
}
