//		
//		main.cpp
//		
//		Team 4
//
//		Kevin Nguyen
//		Ka U Ieong
//		Bret Farley
//		Minting Ye
//
//		Main holds all menu functions
//		Purpose of this program is to provide an interactive ranking
//		database of various NFL players. Currently, only running backs
//		are implemented. Future expansion may see databases on other
//		positions and additional advanced statistics.
//

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <cstdlib>
#include "player_IO.h"
#include "HashTable.h"
#include "ConsoleColor.h"
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
void menu_save(HashTable* hashPtr);
void menu_compare(HashTable* hashPtr);
void print_title(ostream & out);
void print_title();
void value_intinput(int& i);
void value_douinput(double& d);
void colorchange(double d1, double d2);
void value_team(string &s);
//--------------------------------------------------------------
//								MAIN								
//--------------------------------------------------------------
int main() {

	enableDebug(true);		// Utilized to check for memory leaks

	HashTable* hashPtr = new HashTable;
	rb_list obj_list;

	menu_controller(hashPtr, obj_list);

	delete hashPtr;

	system("pause");
	return 0;
}

//--------------------------------------------------------------
//							enableDebug								
//--------------------------------------------------------------
//	in:		bool value
//	out:	n/a
//
//	Utilized to check for memory leaks. Commented out in the main()
void enableDebug(bool bvalue) {
	if (!bvalue) return;

	int tmpFlag = _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG);

	// Turn on leak-checking bit.
	tmpFlag |= _CRTDBG_LEAK_CHECK_DF;

	// Turn off CRT block checking bit.
	tmpFlag &= ~_CRTDBG_CHECK_CRT_DF;

	// Set flag to the new value.
	_CrtSetDbgFlag(tmpFlag);
}

//--------------------------------------------------------------
//							menu_conroller								
//--------------------------------------------------------------
//	in:		hashTable* to hashTable obj; reference to list of 100 rb*
//	out:	n/a
//
//	Main menu controller; Currently has 10 options
void menu_controller(HashTable* hashPtr, rb_list& obj_list) {
	string choice;

	while (choice != "10") {
		system("CLS");

		// Menu display
		cout << "-------Main Menu-------" << endl;
		cout << "1. Add new data        " << endl;
		cout << "2. Delete data         " << endl;
		cout << "3. Find data           " << endl;
		cout << "4. List hash sequence  " << endl;
		cout << "5. List sorted data    " << endl;
		cout << "6. Print indented tree " << endl;
		cout << "7. Print efficieny     " << endl;
		cout << "8. Team choice         " << endl;
		cout << "9. Save to file        " << endl;
		cout << "10. Exit               " << endl;
		cout << "-----------------------" << endl;

		// Get selection from user
		do {
			cout << "Enter a choice: ";
			cin >> choice;
		} while (!isdigit(choice[0]));

		// Based on selection, call various menu functions
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
				menu_compare(hashPtr); break;
			case 9:
				menu_save(hashPtr); break;
			case 10:
				cout << "Now exiting..." << endl; 
				menu_save(hashPtr); break;
			default:
				break;
		}
	}
}

//--------------------------------------------------------------
//							menu_add								
//--------------------------------------------------------------
//	in:		hashTable* to hashTable obj; reference to list of 100 rb*
//	out:	n/a
//
//	Add functionality - currently 3 options
//	
//
void menu_add(HashTable* hashPtr, rb_list& obj_list) {
	system("CLS");
	
	cout << "Would you like to add a player manually or read from file?" << endl;
	cout << "1. Manually" << endl;
	cout << "2. Start new file" << endl;
	cout << "3. Use default file" << endl;

	string choice;
	do {
		cout << "Enter a choice: ";
		cin >> choice;
	} while (!isdigit(choice[0]));

	if (choice == "1") {
		string buffer, name, team;
		int gp = 0, ruA = 0, ruTD = 0, rcTD = 0, tar = 0, rec = 0;
		double pts = 0, ppg = 0, ruY = 0, rcY = 0;

		cout << "Enter the player's name: ";
		cin.ignore();
		getline(cin, name);

		cout << "Enter the 3-letter abbreviation for the player's team: ";
		cin >> team;
		value_team(team);

		cout << "Enter the number of games played last season: ";
		cin >> gp;
		value_intinput(gp);

		if (gp != 0){

			cout << "Enter the number of rushing attempts: ";
			cin >> ruA;
			value_intinput(ruA);

			cout << "Enter the number of rushing yards: ";
			cin >> ruY;
			value_douinput(ruY);

			cout << "Enter the number of rushing TDs: ";
			cin >> ruTD;
			value_intinput(ruTD);

			cout << "Enter the number of targets: ";
			cin >> tar;
			value_intinput(tar);

			cout << "Enter the number of receptions: ";
			cin >> rec;
			value_intinput(rec);

			cout << "Enter the number of receiving yards: ";
			cin >> rcY;
			value_douinput(rcY);

			cout << "Enter the number of receiving TDs: ";
			cin >> rcTD;
			value_intinput(rcTD);

			cout << "Enter the number of fantasy points: ";
			cin >> pts;
			value_douinput(pts);

			if (gp != 0) ppg = pts / gp;
			else ppg = 0;
		}
		
		hashPtr->addItem(obj_list.add(name, team, gp, pts, ppg, ruA, ruTD, rcTD, tar, rec, ruY, rcY));
	}

	else if (choice == "2") {
		//string filename = "RB_stats_2015.txt";
		string filename;
		
		cout << "Enter the name of the file you would like to work with: ";
		cin.ignore();
		getline(cin, filename);

		obj_list.read_file(filename);

		for (int i = 0; i < hashPtr->get_table_size(); i++) {
			hashPtr->empty_list(i);
		}

		for (int i = 0; i < 50; i++) hashPtr->addItem(obj_list.get_item(i));
	} 

	else if (choice == "3") {
		string filename = "RB_stats_2015.txt";

		obj_list.read_file(filename);

		for (int i = 0; i < hashPtr->get_table_size(); i++) {
			hashPtr->empty_list(i);
		}

		for (int i = 0; i < 50; i++) hashPtr->addItem(obj_list.get_item(i));
	}

	system("pause");
	return;
}

void menu_delete(HashTable* hashPtr) {
	string name;

	system("CLS");

	cout << "Enter the name of the player you wish to remove: ";
	cin.ignore();
	getline(cin, name);

	if (hashPtr->find(name) != nullptr) {
		hashPtr->removeItem(name);
		cout << "Removed " << name << endl;
	} else {
		cout << "Could not find the player." << endl;
	}

	system("pause");
	return;
}

void menu_find(HashTable* hashPtr) {
	string name;

	system("CLS");

	cout << "Please enter the name of the player: ";
	cin.ignore();
	getline(cin, name);

	if (hashPtr->find(name) == nullptr) {
		cout << "Could not find the player." << endl;
	} else {
		cout << hashPtr->find(name) << endl << endl;
	}

	system("pause");
	return;
}

void menu_printHash(HashTable* hashPtr) {
	system("CLS");

	hashPtr->print_all();

	system("pause");
	return;
}

void menu_printSortedData(HashTable* hashPtr) {
	rb** rbPtr = hashPtr->return_all();
	int total = hashPtr->total_items();
	AVL<rb, string>* avlPtr;
	
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

		avlPtr = new AVL<rb, string>("name");

		for (int i = 0; i < total; i++) avlPtr->add_ptr(rbPtr[i]);

		print_title();
		avlPtr->rprintInOrder(avlPtr->get_root());

		delete avlPtr;

	} if (choice == "2") {
		system("CLS");

		avlPtr = new AVL<rb, string>("pts");

		for (int i = 0; i < total; i++) avlPtr->add_ptr(rbPtr[i]);
		
		print_title();
		avlPtr->rprintInOrder(avlPtr->get_root());

		delete avlPtr;

	} if (choice == "3") {
		system("CLS");

		avlPtr = new AVL<rb, string>("ppg");

		for (int i = 0; i < total; i++) avlPtr->add_ptr(rbPtr[i]);

		print_title();
		avlPtr->rprintInOrder(avlPtr->get_root());

		delete avlPtr;
	}

	system("pause");
	return;
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

	int max_idx = 0;
	for (int i = 0; i < hash_slots; i++) {
		if (hashPtr->numItemsAtIndex(i)>hashPtr->numItemsAtIndex(max_idx)) max_idx = i;
	}
	
	cout << "Longest list: " << "Index " << max_idx + 1 << " in the hash table with " << hashPtr->numItemsAtIndex(max_idx) << " items" << endl;
	cout << "AVL Statistics: " << endl;

	system("pause");
}

void menu_compare(HashTable* hashPtr) {
	rb* player1;
	rb* player2;

	string name;

	cout << "Please enter the name of the first player: ";
	cin.ignore();
	getline(cin, name);

	if (hashPtr->find(name) == nullptr) {
		cout << "Could not find the player. Back to the menu now." << endl;
		system("pause");
		return;
	} else {
		player1 = hashPtr->find(name);
	}

	cout << "Please enter the name of the second player: ";
	getline(cin, name);

	if (hashPtr->find(name) == nullptr) {
		cout << "Could not find the player. Back to the menu now." << endl;
		system("pause");
		return;
	} else {
		player2 = hashPtr->find(name);
	}
	print_title();
	player1->print_compare();
	std::cout  << std::setw(8); colorchange(player1->get_pts(), player2->get_pts());
	std::cout << std::setw(6); colorchange(player1->get_ppg(), player2->get_ppg());
	std::cout << white << std::endl;


	player2->print_compare();
	std::cout << std::setw(8); colorchange(player2->get_pts(), player1->get_pts());
	std::cout << std::setw(6); colorchange(player2->get_ppg(), player1->get_ppg());
	std::cout << white << std::endl;


	system("pause");
}


void menu_save(HashTable* hashPtr) {
	rb** rbPtr = hashPtr->return_all();
	int total = hashPtr->total_items();

	ofstream out("outputtest.txt");
	int count = 1;

	//system("CLS");

	AVL<rb, string>* avlPtr = new AVL<rb, string>("pts");

	for (int i = 0; i < total; i++) avlPtr->add_ptr(rbPtr[i]);

	print_title(out);
	avlPtr->rsaveInOrder(avlPtr->get_root(), out, count);

	delete avlPtr;
	// system("pause");
	return;
}



void print_title() {

	std::cout << std::left << std::setw(20) << "Name" << std::setw(4) << "tm" << std::setw(4) << "GP" << std::setw(4) << "RuA" << std::setw(7) << "RuY" << std::setw(5) << "Rutd" << std::setw(4) << "tar" << std::setw(4) << "Rc" << std::setw(4) << "RcY" << std::setw(5) << "RcTD" << std::setw(8) << "pts" << std::setw(6) << "p/g" << std::endl;

}


void print_title(ostream & out) {

	out << std::left << std::setw(4) << "No " << std::setw(20) << "Name" << std::setw(4) << "tm" << std::setw(4) << "GP" << std::setw(4) << "RuA" << std::setw(7) << "RuY" << std::setw(5) << "Rutd" << std::setw(4) << "tar" << std::setw(4) << "Rc" << std::setw(4) << "RcY" << std::setw(5) << "RcTD" << std::setw(8) << "pts" << std::setw(6) << "p/g" << std::endl;

}

void colorchange(double d1, double d2)
{
	if (d1 >= d2)cout << red << d1;
	else cout << white << d1;
}

void value_intinput(int &i){
	while (i < 0){
		cout << "invalue inpput, the value will not be less then zero." << endl << " Please input the correct value :";
		cin >> i;
	}
}
void value_douinput(double &d){

	while (d < 0){
		cout << "invalue inpput, the value will not be less then zero."<<endl<<" Please input the correct value :";
		cin >> d;
	}

}
void value_team(string &s){

	while (s.length() != 3){

		cout << "your team name doesn't match the formet" << endl << "please input 3-letter abbreviation for the player's team: ";
		cin >> s;

	}
	return;



}