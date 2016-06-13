/*
player.h
*/

#ifndef PLAYER_H
#define PLAYER_H
#include <string>

class player {
protected:
	std::string name;
	std::string team;
	int games_played;
	double points, points_per_game;
public:
	// CONSTRUCTORS
	player() : name(""), team("Free Agent"), games_played(0), points(0), points_per_game(0) {}
	player(std::string name, std::string team, int gp, double pts, double ppg)
		: name(name), team(team), games_played(gp), points(pts), points_per_game(ppg) {}

	// ACCESSORS
	std::string get_name() const { return name; }
	std::string get_team() const { return team; }
	int get_gp() const { return games_played; }
	double get_pts() const { return points; }
	double get_ppg() const { return points_per_game; }

	// MUTATORS
	void set_name(const std::string& s) { name = s; }
	void set_team(const std::string& s) { team = s; }
	void set_gp(const int& i) { games_played = i; }
	void set_pts(const int& d) { points = d; }
	void set_ppg(const int& d) { points_per_game = d; }

};



class rb : public player {
protected:
	int rush_att, rush_td, rec_td, targets, receptions;
	double rush_yards, rec_yards;
public:
	// CONSTRUCTORS
	rb() 
		:	player(), 
			rush_att(0), rush_td(0), rec_td(0), targets(0), receptions(0), rush_yards(0), rec_yards(0) {}

	rb(std::string name, std::string team, int gp, double pts, double ppg)
		:	player(name, team, gp, pts, ppg), 
			rush_att(0), rush_td(0), rec_td(0), targets(0), receptions(0), rush_yards(0), rec_yards(0) {}

	rb(std::string name, std::string team, int gp, double pts, double ppg, int ru_a, int ru_td, int rc_td, int tar, int rec, double ru_y, double rc_y)
		:	player(name, team, gp, pts, ppg), 
			rush_att(ru_a), rush_td(ru_td), rec_td(rc_td), targets(tar), receptions(rec), rush_yards(ru_y), rec_yards(rc_y) {}

	// ACCESSORS
	int get_attempts() const { return rush_att; }
	int get_RuTD() const { return rush_td; }
	int get_RcTD() const { return rec_td; }
	int get_tar() const { return targets; }
	int get_rec() const { return receptions; }
	double get_RuY() const { return rush_yards; }
	double get_RcY() const { return rec_yards; }

	// MUTATORS
	void set_attempts(const int& i) { rush_att = i; }
	void set_RuTD(const int& i) { rush_td = i; }
	void set_RcTD(const int& i) { rec_td = i; }
	void set_tar(const int& i) { targets = i; }
	void set_rec(const int& i) { receptions = i; }
	void set_RuY(const double& d) { rush_yards = d; }
	void set_RcY(const double& d) { rec_yards = d; }

};

#endif