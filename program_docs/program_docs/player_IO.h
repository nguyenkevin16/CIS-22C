/* player_IO */

#ifndef PLAYER_IO
#define PLAYER_IO
#include"player.h"

class rb_list {
	rb* rb_arr[100];
public:
	rb_list();
	~rb_list();

	rb* get_item(const int& idx) const { return rb_arr[idx]; }
	int read_file(std::string fname);
	void checkFileOpen(std::ifstream& fin, std::string fname);
	void empty_list();
	int find_end();
	rb* add(std::string name, std::string team, int gp, double pts, double ppg, int ru_a, int ru_td, int rc_td, int tar, int rec, double ru_y, double rc_y);
};

rb_list::rb_list() { 
	for (int i = 0; i < 100; i++) {
		rb_arr[i] = nullptr;
	}
}

rb_list::~rb_list() { 
	empty_list();
}

rb* rb_list::add(std::string name, std::string team, int gp, double pts, double ppg, int ru_a, int ru_td, int rc_td, int tar, int rec, double ru_y, double rc_y) {
	int end = find_end();

	rb_arr[end] = new rb(name, team, gp, pts, ppg, ru_a, ru_td, rc_td, tar, rec, ru_y, rc_y);

	return rb_arr[end];
}

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

void rb_list::empty_list() {
	for (int i = 0; i < 100; i++) {
		if (rb_arr[i] != nullptr) {
			delete rb_arr[i];
			rb_arr[i] = nullptr;
		}
	}
}

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
	// for (int i = 0; i < 50; i++) {
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

void rb_list::checkFileOpen(std::ifstream& fin, std::string fname){
	if (fin.fail()) {
		std::cerr << "The input file " << fname << " could not be found. This program will now terminate." << std::endl;
		system("pause");
		exit(1);
	}
}


#endif