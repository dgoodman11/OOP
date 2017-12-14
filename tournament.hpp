/*************************************************************************
** Program  Filename: tournament.hpp
** Author: Danielle Goodman
** Date: 5/22/2016
** Description: Header file for the class, Tournament
** Input: n/a
** Output: n/a
*************************************************************************/

#ifndef TOURNAMENT_HPP
#define TOURNAMENT_HPP
#include "creature.hpp"
#include "stack.hpp"
#include "queue.hpp"
#include "barbarian.hpp"
#include "medusa.hpp"
#include "blueMen.hpp"
#include "BabaYaga.hpp"
#include "HarryPotter.hpp"

class Tournament
{
private:
	int creatures;
	int totalCreatures;
	int turns;
	int match = 1;
	int team1Points = 0;
	int team2Points = 0;
	int keepDisplaying = 0;
	Creature **creatureArray;
	Creature *winner;
	Creature *loser;
	Stack losers;
	Queue Team1;
	Queue Team2;
	Creature *FirstPlace;
	Creature *SecondPlace;
	Creature *ThirdPlace;

public:
	Creature* spawnCreature(int t);
	void initializeLineUp();
	void battle();
	void adjustStackAndQueues();
	void checkHead();
	void declarePlaceFinishers();
	void battleTournament();
	void displayLosers();
	bool keepDisplayingLosers();

};


#endif
