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

	// enableDebug(true);

	string filename = "RB_stats_2015.txt";
	rb_list obj_list;
	obj_list.read_file(filename);

	HashTable hash;
	for (int i = 0; i < 50; i++) hash.addItem(obj_list.get_arr(i));
	hash.removeItem("Devonta Freeman");
	hash.printList(12);

	system("pause");
	return 0;
}
