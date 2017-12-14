/*************************************************************************
** Program  Filename: stack.hpp
** Author: Danielle Goodman
** Date: 5/22/2016
** Description: Header file for the class, Stack
** Input: n/a
** Output: n/a
*************************************************************************/
#ifndef STACK_HPP
#define STACK_HPP

#include <cstdlib>
#include "creature.hpp"

class Stack
{

protected:
	struct Stacknode
	{
		Creature *value;
		Stacknode *next;
		Stacknode() { next = NULL; }
		Stacknode(Creature *val, Stacknode *nextstack = NULL)
		{
			value = val;
			next = nextstack;
		}
	};
	Stacknode *head;
	Stacknode *top;


public:
	Stack() { head = NULL; }
	void add(Creature *val);
	Creature* remove(); 

};


#endif
