/*************************************************************************
** Program  Filename: medusa.cpp
** Author: Danielle Goodman
** Date: 5/22/2016
** Description: Contains the function definitions for the class Medusa
** Input: n/a
** Output: n/a
*************************************************************************/
#include "medusa.hpp"

/******************************************************************
** Function: attack()
** Description: virtual function that returns the creature's
attack. Value is based on a die roll. If medusa rolls a 12,
attack is set to 200, a very high amount that will destroy any
opponent
** Parameters: none
*******************************************************************/
int Medusa::attack()
{
	int die1 = rand() % (6) + 1;
	int die2 = rand() % (6) + 1;
	if (die1 + die2 == 12)
	{
		attackp = 200; 
		return 200;
	}
	else {
		attackp = die1 + die2; 
		return die1 + die2;
	}
}

/******************************************************************
** Function: defend(int)
** Description: virtual function that calculates the creature's
change in strength points based on their defense roll, armor,
and the opposing creature's attack
** Parameters: int that represents the opposing creature's attack
*******************************************************************/
void Medusa::defend(int attack)
{
	int damage;
	int die1 = rand() % (6) + 1;
	defense = die1; 
	damage = attack - die1 - armor;
	if (damage > 0)
		strengthPoints -= damage;
}

/******************************************************************
** Function: getStrengthPoints()
** Description: virtual function that returns the creature's
strength points
** Parameters: none
*******************************************************************/
int Medusa::getStrengthPoints()
{
	return strengthPoints;
}

/******************************************************************
** Function: getDefense()
** Description: virtual function that returns the creature's
defense
** Parameters: none
*******************************************************************/
int Medusa::getDefense()
{
	return defense;
}

/******************************************************************
** Function: getAttack()
** Description: virtual function that returns the creature's
attack points
** Parameters: none
*******************************************************************/
int Medusa::getAttack()
{
	return attackp;
}

/******************************************************************
** Function: getName()
** Description: virtual function that returns the creature's
name;
** Parameters: none
*******************************************************************/
std::string Medusa::getName()
{
	return name;
}

/******************************************************************
** Function: recover()
** Description: replenishes the creature's health
** Parameters: none
*******************************************************************/
void Medusa::recover()
{
	strengthPoints = 8;
}

/******************************************************************
** Function: getId()
** Description: returns ID
** Parameters: none
*******************************************************************/
std::string Medusa::getID()
{
	return ID;
}

/******************************************************************
** Function: setID()
** Description: asks user to enter a name for their creature,
	sets ID to input
** Parameters: none
*******************************************************************/
void Medusa::setID()
{
	std::string s;
	std::cout << "Please enter a name for this " << name << std::endl;
	std::cin.ignore();
	std::cin.getline(ID, 80);
}

/******************************************************************
** Function: setTeam()
** Description: sets the team number to the argument provided
** Parameters: int that represents the team number
*******************************************************************/
void Medusa::setTeam(int t)
{
	team = t;
}

/******************************************************************
** Function: getTeam()
** Description: returns the team number
** Parameters: none
*******************************************************************/
int Medusa::getTeam()
{
	return team;
}
