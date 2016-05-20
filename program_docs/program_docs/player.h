/*
player.h
*/

#ifndef PLAYER_H
#define PLAYER_H
#include <string>

class player {
	int ID;
	std::string name;
public:
	player() : ID(0), name("") {}
	player(int id, std::string name) : ID(id), name(name) {}

	// ACCESSORS
	int get_ID() const { return ID; }
	std::string get_name() const { return name; }

	// MUTATORS
	void set_ID(const int& i) { ID = i; }
	void set_name(const std::string& s) { name = s; }
};

class rb : public player {
	double yards, TDs, ppg;
public:
	rb() : player(0, ""), yards(0), TDs(0), ppg(0) {}
	rb(int id, std::string name) : player(id, name), yards(0), TDs(0), ppg(0) {}
	rb(int id, std::string name, double yards, double tds, double ppg) 
		: player(id, name), yards(yards), TDs(tds), ppg(ppg) {}

	// ACCESSORS
	double get_yards() const { return yards; }
	double get_TDs() const { return TDs; }
	double get_ppg() const { return ppg; }

	// MUTATORS
	void set_yards(const double& d) { yards = d; }
	void set_TDs(const double& d) { TDs = d; }
	void set_ppg(const double& d) { ppg = d; }
};

#endif