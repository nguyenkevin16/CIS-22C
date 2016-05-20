/*
runningback.h
*/

#ifndef RUNNINGBACK_H
#define RUNNINGBACK_H
#include <string>

class rb {
	int ID;
	std::string name;
	double yards, TDs, ppg;
public:
	rb() : ID(0), name(""), yards(0), TDs(0), ppg(0) {}
	rb(int id, std::string name) : ID(id), name(name), yards(0), TDs(0), ppg(0) {}
	rb(int id, std::string name, double yards, double tds, double ppg) 
		: ID(id), name(name), yards(yards), TDs(tds), ppg(ppg) {}

	// ACCESSORS
	int get_ID() const { return ID; }
	std::string get_name() const { return name; }
	double get_yards() const { return yards; }
	double get_TDs() const { return TDs; }
	double get_ppg() const { return ppg; }

	// MUTATORS
	void set_ID(const int& i) { ID = i; }
	void set_name(const std::string& s) { name = s; }
	void set_yards(const double& d) { yards = d; }
	void set_TDs(const double& d) { TDs = d; }
	void set_ppg(const double& d) { ppg = d; }
};

#endif