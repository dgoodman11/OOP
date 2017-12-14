/*************************************************************************
** Program  Filename: main.cpp
** Author: Danielle Goodman
** Date: 5/22/2016
** Description: Program that conducts a tournament using creatures
	of the type Barbarian, Medusa, Baba Yaga, Blue Men, and Harry Potter.
	The user enters how many creatures each player will battle, then 
	each player enters their lineup. The program conducts a battle
	between the 2 creatures first in their lineup, displays the winner,
	and moves the winner and loser appropriately. Battles continue until
	one team has been defeated.
** Input: An int that represents the number of creatures each player 
	will battle, ints that represent the menu selection of the creatures
	chosen, characters that represent the creature IDs
** Output: The winner of each round, the team that wins, the first,
	second, and third place finishers, and the loser pile
*************************************************************************/
#include "iostream"
#include "tournament.hpp"

using namespace std;



int main()
{
	srand(time(0));
	Tournament tournament;

	tournament.battleTournament();
	tournament.declarePlaceFinishers();
	cout << "The loser pile: " << endl;
	while (tournament.keepDisplayingLosers())
	{
		tournament.displayLosers();
	}

	return 0;
}

