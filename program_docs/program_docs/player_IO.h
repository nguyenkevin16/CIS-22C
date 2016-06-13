/* player_IO */

#ifndef PLAYER_IO
#define PLAYER_IO
#include"player.h"

class rb_list {
	rb* rb_arr[50];
public:
	rb_list();
	~rb_list();

	rb* get_item(const int& idx) const { return rb_arr[idx]; }
	void read_file(std::string fname);
	void checkFileOpen(std::ifstream& fin, std::string fname);
};

rb_list::rb_list() { 
	for (int i = 0; i < 50; i++) {
		rb_arr[i] = nullptr;
	}
}

rb_list::~rb_list() { 
	for (int i = 0; i < 50; i++) {
		if (rb_arr[i] != nullptr) {
			// delete rb_arr[i];
			// rb_arr[i] = nullptr;
		}
	} 
}

void rb_list::read_file(std::string fname) {

	std::ifstream fin(fname);
	checkFileOpen(fin, fname);

	std::string buffer, name, team;
	int gp, ruA, ruTD, rcTD, tar, rec;
	double pts, ppg, ruY, rcY;

	getline(fin, buffer);
	
	// Start line-by-line loop
	for (int i = 0; i < 50; i++) {
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
	}

	fin.close();
}

void rb_list::checkFileOpen(std::ifstream& fin, std::string fname){
	if (fin.fail()) {
		std::cerr << "The input file " << fname << " could not be found. This program will now terminate." << std::endl;
		system("pause");
		exit(1);
	}
}


#endif