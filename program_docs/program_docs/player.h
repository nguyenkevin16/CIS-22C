/*
player.h
*/

#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <iomanip>

class player {
protected:
	std::string name;
	std::string team;
	int games_played;
	double points, points_per_game;
public:
	// CONSTRUCTORS
	player() : name(""), team("Free Agent"), games_played(0), points(0), points_per_game(0) {}
	player(std::string name) : name(name), team("Free Agent"), games_played(0), points(0), points_per_game(0) {}
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
	
	rb(std::string name)
		: player(name), rush_att(0), rush_td(0), rec_td(0), targets(0), receptions(0), rush_yards(0), rec_yards(0) {}

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

	// METHODS
	/*
	std::ostream& operator<<(std::ostream& out, const rb& obj) {
		out << obj.name << " "
			<< obj.team << " "
			<< obj.games_played
			<< obj.rush_att << " "
			<< obj.rush_yards << " "
			<< obj.rush_td << " "
			<< obj.targets << " "
			<< obj.receptions << " "
			<< obj.rec_yards << " "
			<< obj.rec_td << " "
			<< obj.points << " "
			<< obj.points << " "
			<< obj.points_per_game;

		return out;
	}
	*/

	void save_player(std::ostream& out)
	{
		out << std::left << std::setw(20) << this->get_name() << std::setw(4) << this->get_team() << std::setw(4) << this->get_gp() << std::setw(4) << this->get_attempts() << std::setw(8) << this->get_RuY() << std::setw(4) << this->get_RuTD() << std::setw(4) << this->get_tar() << std::setw(4) << this->get_rec() << std::setw(5) << this->get_RcY() << std::setw(4) << this->get_RcTD() << std::setw(8) << this->get_pts() << std::setw(6) << this->get_ppg() << std::endl;
	}

	void print_rb(){
		std::cout << std::left << std::setw(20) << get_name() << std::setw(4) << get_team() << std::setw(4) << get_gp() << std::setw(4) << get_attempts() << std::setw(8) << get_RuY() << std::setw(4) << get_RuTD() << std::setw(4) << get_tar() << std::setw(4) << get_rec() << std::setw(5) << get_RcY() << std::setw(4) << get_RcTD() << std::setw(8) << get_pts() << std::setw(6) << get_ppg() << std::endl;
	};

	friend std::ostream& operator<<(std::ostream& out, const rb* p){

		out << std::left << std::setw(20) << p->get_name() << std::setw(4) << p->get_team() << std::setw(4) << p->get_gp() << std::setw(4) << p->get_attempts() << std::setw(8) << p->get_RuY() << std::setw(4) << p->get_RuTD() << std::setw(4) << p->get_tar() << std::setw(4) << p->get_rec() << std::setw(5) << p->get_RcY() << std::setw(4) << p->get_RcTD() << std::setw(8) << p->get_pts() << std::setw(6) << p->get_ppg();
		return out;
	};


};

#endif