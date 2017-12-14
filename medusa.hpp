/*************************************************************************
** Program  Filename: medusa.hpp
** Author: Danielle Goodman
** Date: 5/22/2016
** Description: Header file for the class, Medusa
** Input: n/a
** Output: n/a
*************************************************************************/
#ifndef MEDUSA_HPP
#define MEDUSA_HPP
#include "creature.hpp"

class Medusa :public Creature
{
private:
	int attackp;
	int defense;
	int armor;
	int strengthPoints;
	char ID[80];
	std::string name = "Medusa";
	int team;

public:
	Medusa() : Creature() {
		armor = 3;
		strengthPoints = 8;
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
