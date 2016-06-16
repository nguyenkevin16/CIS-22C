//		
//		player_IO.h
//		
//		Team 4
//
//		Kevin Nguyen
//		Ka U Ieong
//		Bret Farley
//		Minting Ye
//
//		Used to dynamically allocate memory for rb objects using an array of rb*
//		This array is used to create the hashTable and AVLs for quick search/sort
//

#ifndef PLAYER_IO
#define PLAYER_IO
#include "player.h"

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

#endif