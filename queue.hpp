/*************************************************************************
** Program  Filename: queue.hpp
** Author: Danielle Goodman
** Date: 5/22/2016
** Description: Header file for the class, Queue
** Input: n/a
** Output: n/a
*************************************************************************/
#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <cstdlib>
#include "creature.hpp"

class Queue
{

protected:
	struct Queuenode
	{
		Creature *value;
		Queuenode *next;
		Queuenode *previous;
		Queuenode() { next = NULL; }
		Queuenode(Creature *val, Queuenode *prev1, Queuenode *nextqueue = NULL)
		{
			value = val;
			previous = prev1;
			next = nextqueue;
		}
	};
	Queuenode *back;
	Queuenode *prev;
	Queuenode *head;


public:
	Queue() { head = back = prev = NULL;}
	void add(Creature *val);
	void removeLoser();
	void moveWinner();
	Creature* firstInLine();
	bool isEmpty();

};



#endif
