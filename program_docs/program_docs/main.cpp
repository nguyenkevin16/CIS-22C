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
void checkFileOpen(ifstream&, const char[]);

int main() {

	ifstream fin(FILE_INPUT);
	checkFileOpen(fin, FILE_INPUT);

	rb_list obj_list;
	obj_list.read_file(fin);
	obj_list.print();

	fin.close();

	system("pause");
	return 0;
}

void checkFileOpen(ifstream& fin, const char name[]) {
	if (fin.fail()) {
		cerr << "The input file " << name << " could not be found. This program will now terminate." << endl;
		exit(1);
	}
}