#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP
/*************************************************************************
** Program  Filename: barbarian.hpp
** Author: Danielle Goodman
** Date: 5/22/2016
** Description: Header file for the class, Barbarian
** Input: n/a
** Output: n/a
*************************************************************************/
#include "creature.hpp"

class Barbarian :public Creature
{
private:
	int attackp;
	int defense;
	int armor;
	int strengthPoints;
	std::string name = "Barbarian";
	char ID[80];
	int team;
	

public:
	Barbarian() : Creature(){
		armor = 0;
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
