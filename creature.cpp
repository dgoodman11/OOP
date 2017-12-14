/*************************************************************************
** Program  Filename: creature.cpp
** Author: Danielle Goodman
** Date: 5/22/2016
** Description: Contains the function definitions for the class Creature
** Input: n/a
** Output: n/a
*************************************************************************/
#include "creature.hpp"

/******************************************************************
** Function: Critter default constructor
** Description: Initializes attack and defense points to 0
** Parameters: none
*******************************************************************/
Creature::Creature()
{
	attackp = 0;
	defense = 0;
}

/******************************************************************
** Function: getStrengthPoints()
** Description: virtual function that returns the creature's
	strength points
** Parameters: none
*******************************************************************/
int Creature::getStrengthPoints()
{
	return strengthPoints;
}

/******************************************************************
** Function: getDefense()
** Description: virtual function that returns the creature's
	defense
** Parameters: none
*******************************************************************/
int Creature::getDefense() 
{
	return defense;
}

/******************************************************************
** Function: getAttack()
** Description: virtual function that returns the creature's
	attack points
** Parameters: none
*******************************************************************/
int Creature::getAttack()
{
	return attackp;
}

/******************************************************************
** Function: getName()
** Description: virtual function that returns the creature's
	name;
** Parameters: none
*******************************************************************/
std::string Creature::getName()
{
	return name;
}

/******************************************************************
** Function: getId()
** Description: returns ID
** Parameters: none
*******************************************************************/
std::string Creature::getID()
{
	return ID;
}

/******************************************************************
** Function: setID()
** Description: asks user to enter a name for their creature,
sets ID to input
** Parameters: none
*******************************************************************/
void Creature::setID()
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
void Creature::setTeam(int t)
{
	team = t;
}

/******************************************************************
** Function: getTeam()
** Description: returns the team number
** Parameters: none
*******************************************************************/
int Creature::getTeam()
{
	return team;
}

