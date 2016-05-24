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

const char FILE_INPUT[] = "RB_stats_2015.txt";

// Function Prototypes


int main() {

	
	

	std::string filename = "RB_stats_2015.txt";


	rb_list obj_list;
	obj_list.read_file(filename);
	obj_list.print();

	

	system("pause");
	return 0;
}

