/*************************************************************************
** Program  Filename: blueMen.hpp
** Author: Danielle Goodman
** Date: 5/22/2016
** Description: Header file for the class, BlueMen
** Input: n/a
** Output: n/a
*************************************************************************/
#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP
#include "creature.hpp"

class BlueMen :public Creature
{
private:
	int attackp;
	int defense;
	int armor;
	int strengthPoints;
	std::string name = "Blue Men";
	char ID[80];
	int team;

public:
	BlueMen() : Creature() {
		armor = 3;
		strengthPoints = 12;
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
