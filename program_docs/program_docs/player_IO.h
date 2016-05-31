/* player_IO */

#ifndef PLAYER_IO
#define PLAYER_IO
#include"rb.h"

class rb_list {
	rb* rb_arr[50];
public:
	rb_list();
	~rb_list();

	rb* get_arr(const int& idx) const { return rb_arr[idx]; }
	void read_file(std::string fname);
	// void print_list2() const;
	void checkFileOpen(std::ifstream& fin, std::string fname);
};

rb_list::rb_list() 
{ 
	for (int i = 0; i < 50; i++) 
		rb_arr[i] = nullptr; 
}

rb_list::~rb_list() 
{ 
	for (int i = 0; i < 50; i++) 
	{
		if (rb_arr[i] != nullptr)
		{
			delete rb_arr[i];
			rb_arr[i] = nullptr;
		}
	} 
}

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

/*
void rb_list::print_list2() const {
	for (int i = 0; i < 50; i++) {
		// std::cout << rb_arr[i] << std::endl;			
		
		// rb_arr[i]->print();
		// std::cout << *rb_arr[i];
		// cout << rb_arr[i];
		// std::cout << std::endl;
	}
}
*/

void rb_list::checkFileOpen(std::ifstream& fin, std::string fname){
	if (fin.fail()) {
		std::cerr << "The input file " << fname << " could not be found. This program will now terminate." << std::endl;
		system("pause");
		exit(1);
	}
}


#endif