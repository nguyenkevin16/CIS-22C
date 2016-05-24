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
#include "player.h"
#include "player_IO.h"
using namespace std;

int main() {

	string filename = "RB_stats_2015.txt";

	rb_list obj_list;
	obj_list.read_file(filename);
	obj_list.print();

	cout << obj_list.get_arr(0) << endl;
	cout << obj_list.get_arr(1) << endl;
	cout << obj_list.get_arr(2) << endl;
	

	system("pause");
	return 0;
}

