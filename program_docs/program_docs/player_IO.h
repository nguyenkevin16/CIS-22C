/* player_IO */

#ifndef PLAYER_IO
#define PLAYER_IO
#include <string>
#include <fstream>
#include <iostream>
#include"rb.h"

class rb_list {
	rb* rb_arr[50];
public:
	rb_list() { for (int i = 0; i < 50; i++) rb_arr[i] = nullptr; }

	void read_file(std::string fname);
	void print() const;
	void checkFileOpen(std::ifstream& fin, std::string fname);
};

void rb_list::read_file(std::string fname) {

	std::ifstream fin(fname);
	checkFileOpen(fin, fname);

	std::string buffer, name;
	int ID, count = 0;
	double yards, TDs, ppg, temp;

	getline(fin, buffer);
	
	// Start line-by-line loop
	for (int i = 0; i < 50; i++) {
		fin >> ID;

		fin >> buffer;
		fin >> name >> buffer;
		name += " " + buffer;

		fin >> buffer >> buffer >> buffer;

		fin >> buffer;
		if (buffer.find(",") != -1) buffer.replace(buffer.find(","), 1, "");
		yards = stoi(buffer);

		fin >> TDs;
		fin >> buffer >> buffer;

		fin >> temp;
		yards += temp;

		fin >> temp;
		TDs += temp;

		fin >> buffer >> ppg;

		rb_arr[i] = new rb(ID, name, yards, TDs, ppg);
	}
	fin.close();
}

void rb_list::print() const {
	for (int i = 0; i < 50; i++) {
		//std::cout << rb_arr[i] << std::endl;			
		
		//rb_arr[i]->print();
		std::cout << *rb_arr[i];
		// cout << rb_arr[i];
		// std::cout << std::endl;
	}
}

void rb_list::checkFileOpen(std::ifstream& fin, std::string fname){
	if (fin.fail()) {
		std::cerr << "The input file " << fname << " could not be found. This program will now terminate." << std::endl;
		system("pause");
		exit(1);
	}
}


#endif