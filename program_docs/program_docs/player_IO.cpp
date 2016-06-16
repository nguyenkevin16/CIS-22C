//		
//		player_IO.cpp
//		
//		Team 4
//
//		Kevin Nguyen
//		Ka U Ieong
//		Bret Farley
//		Minting Ye
//
//		Implementation of player_IO.h
//

#include "player_IO.h"
#include <iostream>
#include <fstream>
#include <string>

//--------------------------------------------------------------
//						Constructor								
//--------------------------------------------------------------
//	Sets the contents of the array to nullptr
rb_list::rb_list() {
	for (int i = 0; i < 100; i++) {
		rb_arr[i] = nullptr;
	}
}

//--------------------------------------------------------------
//						Destructor								
//--------------------------------------------------------------
//	Calls the empty_list() function
rb_list::~rb_list() {
	empty_list();
}

//--------------------------------------------------------------
//						add								
//--------------------------------------------------------------
//	in:		name and stats of a new player to add
//	out:	a rb* from the first available position in the array
rb* rb_list::add(std::string name, std::string team, int gp, double pts, double ppg, int ru_a, int ru_td, int rc_td, int tar, int rec, double ru_y, double rc_y) {
	int end = find_end();

	rb_arr[end] = new rb(name, team, gp, pts, ppg, ru_a, ru_td, rc_td, tar, rec, ru_y, rc_y);

	return rb_arr[end];
}

//--------------------------------------------------------------
//						find_end								
//--------------------------------------------------------------
//	in:		n/a
//	out:	first available position in the array
int rb_list::find_end() {
	int idx;

	for (int i = 0; i < 100; i++) {
		if (rb_arr[i] == nullptr) {
			idx = i;
			break;
		}
	}

	return idx;
}

//--------------------------------------------------------------
//						empty_list								
//--------------------------------------------------------------
//	in:		n/a
//	out:	erases the contents of the array (deallocates the memory)
void rb_list::empty_list() {
	for (int i = 0; i < 100; i++) {
		if (rb_arr[i] != nullptr) {
			delete rb_arr[i];
			rb_arr[i] = nullptr;
		}
	}
}

//--------------------------------------------------------------
//						read_file								
//--------------------------------------------------------------
//	in:		string of the file name to read
//	out:	int of the number of items read
int rb_list::read_file(std::string fname) {
	empty_list();

	std::ifstream fin(fname);
	checkFileOpen(fin, fname);

	std::string buffer, name, team;
	int gp, ruA, ruTD, rcTD, tar, rec;
	double pts, ppg, ruY, rcY;

	int i = 0;

	getline(fin, buffer);

	// Start line-by-line loop
	while (!fin.eof()) {
		fin >> buffer;						// Get rid of ranking

		if (fin.eof() || buffer.length() < 1) break;

		fin >> name >> buffer;				// Get names
		name += " " + buffer;

		fin >> team >> gp >> ruA;			// Get team, games played, and rushing attempts

		fin >> buffer;						// Get rushing yards
		if (buffer.find(",") != -1) buffer.replace(buffer.find(","), 1, "");
		ruY = stoi(buffer);

		// Get rushing TDs, targets, receptions, receiving yds, receiving TDs, points, points per game
		fin >> ruTD >> tar >> rec >> rcY >> rcTD >> pts >> ppg;

		// Dynamically allocate a new RB object and assign it to the RB_list array of pointers
		rb_arr[i] = new rb(name, team, gp, pts, ppg, ruA, ruTD, rcTD, tar, rec, ruY, rcY);
		i++;
	}

	fin.close();
	return i;
}

//--------------------------------------------------------------
//						checkFileOpen								
//--------------------------------------------------------------
//	in:		input file stream, file name
//	out:	n/a
//
//	Exits the program if the file could not be opened.
void rb_list::checkFileOpen(std::ifstream& fin, std::string fname){
	if (fin.fail()) {
		std::cerr << "The input file " << fname << " could not be found. This program will now terminate." << std::endl;
		system("pause");
		exit(1);
	}
}