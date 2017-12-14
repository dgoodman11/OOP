/*************************************************************************
** Program  Filename: blueMen.cpp
** Author: Danielle Goodman
** Date: 5/22/2016
** Description: Contains the function definitions for the class BlueMen
** Input: n/a
** Output: n/a
*************************************************************************/
#include "blueMen.hpp"

/******************************************************************
** Function: attack()
** Description: virtual function that returns the creature's
attack. Value is based on a die roll.
** Parameters: none
*******************************************************************/
int BlueMen::attack()
{
	int die1 = rand() % (10) + 1;
	int die2 = rand() % (10) + 1;
	attackp = die1 + die2; 
	return die1 + die2;
}

/******************************************************************
** Function: defend(int)
** Description: virtual function that calculates the creature's
change in strength points based on their defense roll, armor,
and the opposing creature's attack. The number of die rolled to 
determine defense depends on the strength points of the blue men
** Parameters: int that represents the opposing creature's attack
*******************************************************************/
void BlueMen::defend(int attack)
{
	int damage;
	int die1 = rand() % (6) + 1;
	int die2 = rand() % (6) + 1;
	int die3 = rand() % (6) + 1;
	if (strengthPoints > 8)
		defense = die1 + die2 + die3;
	else if (strengthPoints <= 8 && strengthPoints > 4)
		defense = die1 + die2;
	else if (strengthPoints <= 4)
		defense = die1;
	damage = attack - defense - armor;
	if (damage > 0)
		strengthPoints -= damage;
}

/******************************************************************
** Function: getStrengthPoints()
** Description: virtual function that returns the creature's
strength points
** Parameters: none
*******************************************************************/
int BlueMen::getStrengthPoints()
{
	return strengthPoints;
}

/******************************************************************
** Function: getDefense()
** Description: virtual function that returns the creature's
defense
** Parameters: none
*******************************************************************/
int BlueMen::getDefense()
{
	return defense;
}

/******************************************************************
** Function: getAttack()
** Description: virtual function that returns the creature's
attack points
** Parameters: none
*******************************************************************/
int BlueMen::getAttack()
{
	return attackp;
}

/******************************************************************
** Function: getName()
** Description: virtual function that returns the creature's
name;
** Parameters: none
*******************************************************************/
std::string BlueMen::getName()
{
	return name;
}

/******************************************************************
** Function: recover()
** Description: replenishes the creature's health
** Parameters: none
*******************************************************************/
void BlueMen::recover()
{
	strengthPoints = 12;
}

/******************************************************************
** Function: getId()
** Description: returns ID
** Parameters: none
*******************************************************************/
std::string BlueMen::getID()
{
	return ID;
}

/******************************************************************
** Function: setID()
** Description: asks user to enter a name for their creature,
sets ID to input
** Parameters: none
*******************************************************************/
void BlueMen::setID()
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
void BlueMen::setTeam(int t)
{
	team = t;
}

/******************************************************************
** Function: getTeam()
** Description: returns the team number
** Parameters: none
*******************************************************************/
int BlueMen::getTeam()
{
	return team;
}
