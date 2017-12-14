/*************************************************************************
** Program  Filename: HarryPotter.hpp
** Author: Danielle Goodman
** Date: 5/22/2016
** Description: Header file for the class, HarryPotter
** Input: n/a
** Output: n/a
*************************************************************************/
#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP
#include "creature.hpp"

class HarryPotter :public Creature
{
private:
	int attackp;
	int defense;
	int armor;
	int strengthPoints;
	std::string name = "Harry Potter";
	char ID[80];
	bool hogwarts = false;
	int team;

public:
	HarryPotter() : Creature() {
		armor = 0;
		strengthPoints = 10;
	}
	int points = 100;
	int attack();
	void defend(int damage);
	int getStrengthPoints();
	int getDefense();
	int getAttack();
	void recover();
	std::string getName();
	std::string getID();
	void setID();
	void setTeam(int t);
	int getTeam();
};

#endif
