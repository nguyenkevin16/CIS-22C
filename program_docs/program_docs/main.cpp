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
using namespace std;

const char FILE_INPUT[] = "RB_stats_2015.txt";

// Function Prototypes
void checkFileOpen(ifstream&, const char[]);

int main() {

	ifstream fin(FILE_INPUT);
	checkFileOpen(fin, FILE_INPUT);

	string buffer, name;
	int ID, count = 0;
	double yards, TDs, ppg, temp;

	rb* rb_arr[40];
	getline(fin, buffer);

	// Start line-by-line loop
		fin >> ID;

		cout << ID << endl;

		fin >> buffer >> name >> buffer;
		name += " " + buffer;

		cout << name << endl;

		fin >> buffer >> buffer >> buffer;

		fin >> yards >> buffer >> buffer;

		cout << yards << endl;
		cout << buffer << endl;

		/*
		fin >> buffer >> buffer;

		fin >> temp;
		yards += temp;

		fin >> temp;
		TDs += temp;

		fin >> buffer >> ppg;
		*/

		//rb_arr[count] = new rb(ID, name, yards, TDs, ppg);
		//count++;
	// End line-by-line loop

	//rb_arr[0]->print();
	//cout << endl << endl;

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