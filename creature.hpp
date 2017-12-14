/*************************************************************************
** Program  Filename: creature.hpp
** Author: Danielle Goodman
** Date: 5/22/2016
** Description: Header file for the pure virtual class, Creature
** Input: n/a
** Output: n/a
*************************************************************************/
#ifndef CREATURE_HPP
#define CREATURE_HPP

#include "ctime"
#include "cstdlib"
#include "string"
#include <iostream>

class Creature
{
private:
	int attackp;
	int defense;
	int armor;
	int strengthPoints;
	int team;

public:
	Creature();
	/******************************************************************
	** Function: attack()
	** Description: virtual function that returns the creature's 
		attack. Value is based on a die roll.
	** Parameters: none
	*******************************************************************/
	virtual int attack() = 0; //pure virtual
	
							  
	/******************************************************************
	** Function: defend(int)
	** Description: virtual function that calculates the creature's
		change in strength points based on their defense roll, armor,
		and the opposing creature's attack
	** Parameters: int that represents the opposing creature's attack
	*******************************************************************/
	virtual void defend(int damage) = 0; //pure virtual
	virtual int getStrengthPoints();
	virtual int getDefense();
	virtual int getAttack();
	virtual void recover() = 0;
	std::string name = "Creature";
	char ID[80];
	virtual std::string getName();
	virtual std::string getID();
	virtual void setID();
	virtual void setTeam(int t);
	virtual int getTeam();
	int points = 100;

};

#endif
