/*************************************************************************
** Program  Filename: tournament.cpp
** Author: Danielle Goodman
** Date: 5/22/2016
** Description: Function definitions for the class, tournament
** Input: n/a
** Output: n/a
*************************************************************************/
#include "tournament.hpp"

/******************************************************************
** Function: spawnCreature
** Description: presents a menu to the user with the option to 
	select a creature. Generates a new instance of the creature
	selected. Also asks user to enter a name for that creature
** Parameters: an int that represents the team number the Creature
	will be on
*******************************************************************/
Creature* Tournament::spawnCreature(int t)
{
	int input; //user selection from menu
	do {
		std::cout << "Select a fighter" << std::endl;
		std::cout << "1 Medusa" << std::endl;
		std::cout << "2 Barbarian" << std::endl;
		std::cout << "3 Baba Yaga" << std::endl;
		std::cout << "4 Blue Men" << std::endl;
		std::cout << "5 Harry Potter" << std::endl;
		std::cin >> input;
	} while (input < 1 || input > 5);

	if (input == 1)
	{
		Creature *temp = new Medusa;
		temp->setID();
		temp->setTeam(t);
		return temp;
	}

	else if (input == 2)
	{
		Creature *temp = new Barbarian;
		temp->setID();
		temp->setTeam(t);
		return temp;
	}

	else if (input == 3)
	{
		Creature *temp = new BabaYaga;
		temp->setID();
		temp->setTeam(t);
		return temp;
	}

	else if (input == 4)
	{
		Creature *temp = new BlueMen;
		temp->setID();
		temp->setTeam(t);
		return temp;
	}

	else if (input == 5)
	{
		Creature *temp = new HarryPotter;
		temp->setID();
		temp->setTeam(t);
		return temp;
	}

	else return NULL;
}

/******************************************************************
** Function: initializeLineUp()
** Description: Asks users how many fighters the teams will use, 
	generates two queues, fills the queues with the users' creature
	choices
** Parameters: none
*******************************************************************/
void Tournament::initializeLineUp()
{
	std::cout << "How many fighters will both players use?" << std::endl;
	std::cin >> creatures;
	totalCreatures = (creatures * 2);
	creatureArray = new Creature*[totalCreatures];

	std::cout << std::endl;
	std::cout << "Player 1, enter line up" << std::endl; 
	for (int i = 0; i < creatures; i++)
	{
		creatureArray[i] = spawnCreature(1);
		Team1.add(creatureArray[i]);
	}

	std::cout << std::endl;
	std::cout << "Player 2, enter line up" << std::endl;
	for (int i = creatures; i < (creatures * 2); i++)
	{
		creatureArray[i] = spawnCreature(2);
		Team2.add(creatureArray[i]);
	}
}

/******************************************************************
** Function: battle()
** Description: battles the two creatures at the top of the two
	queues, displays the winner of the battle, displays the number
	of wins for each team, and calculates a new point total for 
	the winner and loser
** Parameters: none
*******************************************************************/
void Tournament::battle()
{
	Creature *a = Team1.firstInLine();
	Creature *b = Team2.firstInLine();
	turns = 0;
	bool defeat = false;
	int coinflip = (rand() % 2); //determines which side will attack first

	std::cout << std::endl;
	std::cout << "Match " << match << std::endl;
	std::cout << a->getID() << " the " << a->getName() 
		<< " from Team " << a->getTeam() << " vs " 
		<< b->getID() << " the " << b->getName() << " from Team "
		<< b->getTeam() << "!" << std::endl;

	do {
		turns++;

		if (coinflip == 0)
		{
			b->defend(a->attack());
			if (b->getStrengthPoints() < 1)
				defeat = true;

			else {
				a->defend(b->attack());
			}
			if (a->getStrengthPoints() < 1)
				defeat = true;
		}
		else
		{
			a->defend(b->attack());
			if (a->getStrengthPoints() < 1)
				defeat = true;

			else {
				b->defend(a->attack());
			}
			if (b->getStrengthPoints() < 1)
				defeat = true;
		}
		if (turns == 25)
			defeat = true;

	} while (defeat == false);



	if (a->getStrengthPoints() > 0 && b->getStrengthPoints() <= 0)
	{
		std::cout << a->getID() << " the " << a->getName() 
			<< " from Team " << a->getTeam() << " won in " 
			<< turns << " turns!" << std::endl;
		winner = a;
		loser = b;
		team1Points++;
	}
	else if (b->getStrengthPoints() > 0 && a->getStrengthPoints() <= 0)
	{
		std::cout << b->getID() << " the " << b->getName() 
			<< " from Team " << b->getTeam() << " won in " 
			<< turns << " turns!" << std::endl;
		winner = b;
		loser = a;
		team2Points++;
	}
	else
	{
		int tiebreaker = rand();
		if (tiebreaker % 2 == 0)
		{
			winner = a;
			loser = b;
		}
		else
		{
			winner = b;
			loser = a;
		}
		std::cout << "Fighters are equally matched! "
			<< winner->getID() << " from Team " << winner->getTeam()
			<< " won in a coin flip!" << std::endl;

		if (winner->getTeam() == 1)
			team1Points++;
		else team2Points++;
	}
	std::cout << "Team 1 wins: " << team1Points << std::endl;
	std::cout << "Team 2 wins: " << team2Points << std::endl;
	match++;

	loser->points -= 10;
	loser->points = (loser->points - (25 / turns));
	winner->points += 10;
	winner->points = (winner->points + (25 / turns));
}

/******************************************************************
** Function: initializeLineUp()
** Description: Sends the winner to the back of its queue,
	sends the loser to the loser pile and deletes it from its 
	queue
** Parameters: none
*******************************************************************/
void Tournament::adjustStackAndQueues()
{
	if (winner->getTeam() == 1)
	{
		Team1.moveWinner();
		losers.add(loser);
		Team2.removeLoser();
	}
	else if (winner->getTeam() == 2)
	{
		Team2.moveWinner();
		losers.add(loser);
		Team1.removeLoser();
	}
}

void Tournament::checkHead()
{
	std::cout << "Team 1 head: " << Team1.firstInLine()->getID() << std::endl;
	std::cout << "Team 2 head: " << Team2.firstInLine()->getID() << std::endl;
}

/******************************************************************
** Function: battleTournament()
** Description: calls the initializeLineUp funtion, then calls
	battle and adjustStackandQueues until one of the queues is
	empty. Then displays the winning team.
** Parameters: none
*******************************************************************/
void Tournament::battleTournament()
{
	this->initializeLineUp();
	do {
		this->battle();
		this->adjustStackAndQueues();
	} while (!Team1.isEmpty() && !Team2.isEmpty());

	if (Team1.isEmpty())
	{
		std::cout << "\nTeam 2 won! \n" << std::endl;
	}
	else if (Team2.isEmpty())
	{
		std::cout << "\nTeam 1 won! \n" << std::endl;
	}
}

/******************************************************************
** Function: declarePlaceFinishers()
** Description: Searches the array of all creatures in the 
	tournament to find the one with the 1st, 2nd, and 3rd most
	points. Then displays the creatures who took these titles
** Parameters: none
*******************************************************************/
void Tournament::declarePlaceFinishers()
{
	FirstPlace = creatureArray[0];
	for (int i = 1; i < totalCreatures; i++)
	{
		if (creatureArray[i]->points > FirstPlace->points)
			FirstPlace = creatureArray[i];
	}

	for (int i = 0; i < totalCreatures; i++)
	{
		if (creatureArray[i]->points < FirstPlace->points)
			SecondPlace = creatureArray[i];
	}

	for (int i = 0; i < totalCreatures; i++)
	{
		if (creatureArray[i]->points > SecondPlace->points
			&& creatureArray[i]->points < FirstPlace->points)
			SecondPlace = creatureArray[i];
	}

	if (totalCreatures > 2)
	{
		for (int i = 0; i < totalCreatures; i++)
		{
			if ((creatureArray[i]->points < SecondPlace->points)
				|| ((creatureArray[i]->points == SecondPlace->points) 
				&& creatureArray[i]->getID() != SecondPlace->getID()))
				ThirdPlace = creatureArray[i];
		}
		for (int i = 0; i < totalCreatures; i++)
		{
			if (creatureArray[i]->points > ThirdPlace->points
				&& creatureArray[i]->points < SecondPlace->points)
				ThirdPlace = creatureArray[i];
		}
	}

	std::cout << "First Place: " << FirstPlace->getID() <<
		" the " << FirstPlace->getName() << " from Team " <<
		FirstPlace->getTeam() << std::endl;

	std::cout << "Second Place: " << SecondPlace->getID() <<
		" the " << SecondPlace->getName() << " from Team " <<
		SecondPlace->getTeam() << std::endl;

	if (totalCreatures > 2)
	{
		std::cout << "Third Place: " << ThirdPlace->getID() <<
			" the " << ThirdPlace->getName() << " from Team " <<
			ThirdPlace->getTeam() << std::endl;
	}
	std::cout << std::endl;
}

/******************************************************************
** Function: displayLosers()
** Description: calls the remove function on the losers stack.
	Displays the creature at the end of the stack
** Parameters: none
*******************************************************************/
void Tournament::displayLosers()
{
	Creature *temp = losers.remove();
	std::cout << temp->getID() << " the " << temp->getName() <<
		" from Team " << temp->getTeam() << std::endl;
}

/******************************************************************
** Function: keepDisplayingLosers()
** Description: returns true as long as there are still losers in
	the loser pile
** Parameters: none
*******************************************************************/
bool Tournament::keepDisplayingLosers()
{
	keepDisplaying++;
	if (keepDisplaying < match)
		return true;
	else return false;
}

