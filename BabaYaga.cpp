/*************************************************************************
** Program  Filename: BabaYaga.cpp
** Author: Danielle Goodman
** Date: 5/22/2016
** Description: Contains the function definitions for the class BabaYaga
** Input: n/a
** Output: n/a
*************************************************************************/
#include "BabaYaga.hpp"

/******************************************************************
** Function: attack()
** Description: virtual function that returns the creature's
attack. Value is based on a die roll. The value of attack / 3
is added to Baba Yaga's strength points
** Parameters: none
*******************************************************************/
int BabaYaga::attack()
{
	int soul;
	int die1 = rand() % (6) + 1;
	int die2 = rand() % (6) + 1;
	attackp = die1 + die2; 
	soul = attackp / 3;
	strengthPoints += soul;
	return die1 + die2;
}

/******************************************************************
** Function: defend(int)
** Description: virtual function that calculates the creature's
change in strength points based on their defense roll, armor,
and the opposing creature's attack
** Parameters: int that represents the opposing creature's attack
*******************************************************************/
void BabaYaga::defend(int attack)
{
	int damage;
	int die1 = rand() % (10) + 1;
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
int BabaYaga::getStrengthPoints()
{
	return strengthPoints;
}

/******************************************************************
** Function: getDefense()
** Description: virtual function that returns the creature's
defense
** Parameters: none
*******************************************************************/
int BabaYaga::getDefense()
{
	return defense;
}

/******************************************************************
** Function: getAttack()
** Description: virtual function that returns the creature's
attack points
** Parameters: none
*******************************************************************/
int BabaYaga::getAttack()
{
	return attackp;
}

/******************************************************************
** Function: getName()
** Description: virtual function that returns the creature's
name;
** Parameters: none
*******************************************************************/
std::string BabaYaga::getName()
{
	return name;
}

/******************************************************************
** Function: recover()
** Description: replenishes the creature's health
** Parameters: none
*******************************************************************/
void BabaYaga::recover()
{
	strengthPoints = 12;
}

/******************************************************************
** Function: getId()
** Description: returns ID
** Parameters: none
*******************************************************************/
std::string BabaYaga::getID()
{
	return ID;
}

/******************************************************************
** Function: setID()
** Description: asks user to enter a name for their creature,
sets ID to input
** Parameters: none
*******************************************************************/
void BabaYaga::setID()
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
void BabaYaga::setTeam(int t)
{
	team = t;
}

/******************************************************************
** Function: getTeam()
** Description: returns the team number
** Parameters: none
*******************************************************************/
int BabaYaga::getTeam()
{
	return team;
}