/*
rb.h
*/


#ifndef RB_H
#define RB_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include "player.h"

class rb : public player 
{
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

	// METHODS
	//void print_rb();
	// friend std::ostream& operator<<(std::ostream& out, const rb& p);


};

/*
void rb::print_rb()
{
	//std::cout << std::left << std::setw(2) << get_ID() << "\t" << std::setw(20) << get_name() << "\t" << std::setw(7) << get_yards() << "\t" << std::setw(7) << get_TDs() << "\t" << std::setw(7) << get_ppg() << std::endl;
}


ostream& operator<<(ostream& out, const rb& p)
{

	out << std::left << std::setw(2) << p.get_ID() << "\t" << std::setw(20) << p.get_name() << "\t" << std::setw(7) << p.get_yards() << "\t" << std::setw(7) << p.get_TDs() << "\t" << std::setw(7) << p.get_ppg() << std::endl;

	return out;
}
*/





#endif