/*
player.h
*/

#ifndef PLAYER_H
#define PLAYER_H
#include <string>

class player 
{
private:
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

#endif