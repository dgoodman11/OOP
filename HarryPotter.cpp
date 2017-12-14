/*************************************************************************
** Program  Filename: HarryPotter.cpp
** Author: Danielle Goodman
** Date: 5/22/2016
** Description: Contains function definitions for the class HarryPotter
** Input: n/a
** Output: n/a
*************************************************************************/
#include "HarryPotter.hpp"

/******************************************************************
** Function: attack()
** Description: virtual function that returns the creature's
attack. Value is based on a die roll.
** Parameters: none
*******************************************************************/
int HarryPotter::attack()
{
	int die1 = rand() % (6) + 1;
	int die2 = rand() % (6) + 1;
	attackp = die1 + die2; 
	return die1 + die2;
}

/******************************************************************
** Function: defend(int)
** Description: virtual function that calculates the creature's
change in strength points based on their defense roll, armor,
and the opposing creature's attack. The first time Harry Potter's
strength points goes to 0, his health is regained
** Parameters: int that represents the opposing creature's attack
*******************************************************************/
void HarryPotter::defend(int attack)
{
	int damage;
	int die1 = rand() % (6) + 1;
	int die2 = rand() % (6) + 1;
	defense = (die1 + die2); 
	damage = attack - defense;
	if (damage > 0)
		strengthPoints -= damage;
	if (strengthPoints < 1 && hogwarts == false)
	{
		hogwarts = true;
		strengthPoints = 10;
	}
}

/******************************************************************
** Function: getStrengthPoints()
** Description: virtual function that returns the creature's
strength points
** Parameters: none
*******************************************************************/
int HarryPotter::getStrengthPoints()
{
	return strengthPoints;
}

/******************************************************************
** Function: getDefense()
** Description: virtual function that returns the creature's
defense
** Parameters: none
*******************************************************************/
int HarryPotter::getDefense()
{
	return defense;
}

/******************************************************************
** Function: getAttack()
** Description: virtual function that returns the creature's
attack points
** Parameters: none
*******************************************************************/
int HarryPotter::getAttack()
{
	return attackp;
}

/******************************************************************
** Function: getName()
** Description: virtual function that returns the creature's
name;
** Parameters: none
*******************************************************************/
std::string HarryPotter::getName()
{
	return name;
}

/******************************************************************
** Function: recover()
** Description: replenishes the creature's health
** Parameters: none
*******************************************************************/
void HarryPotter::recover()
{
	strengthPoints = 10;
	hogwarts = false;
}

/******************************************************************
** Function: getId()
** Description: returns ID
** Parameters: none
*******************************************************************/
std::string HarryPotter::getID()
{
	return ID;
}

/******************************************************************
** Function: setID()
** Description: asks user to enter a name for their creature,
sets ID to input
** Parameters: none
*******************************************************************/
void HarryPotter::setID()
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
void HarryPotter::setTeam(int t)
{
	team = t;
}

/******************************************************************
** Function: getTeam()
** Description: returns the team number
** Parameters: none
*******************************************************************/
int HarryPotter::getTeam()
{
	return team;
}