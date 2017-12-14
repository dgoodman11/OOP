/*************************************************************************
** Program  Filename: BabaYaga.hpp
** Author: Danielle Goodman
** Date: 5/22/2016
** Description: Header file for the class, BabaYaga
** Input: n/a
** Output: n/a
*************************************************************************/
#ifndef BABAYAGA_HPP
#define BABAYAGA_HPP
#include "creature.hpp"

class BabaYaga :public Creature
{
private:
	int attackp;
	int defense;
	int armor;
	int strengthPoints;
	std::string name = "Baba Yaga";
	char ID[80];
	int team;
		
public:
	BabaYaga() : Creature() {
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
