/*************************************************************************
** Program  Filename: queue.cpp
** Author: Danielle Goodman
** Date: 5/22/2016
** Description: Function definitions for the class, Queue
** Input: n/a
** Output: n/a
*************************************************************************/
#include "queue.hpp"

/******************************************************************
** Function: add
** Description: This function creates a new node, and modifies
	pointers appropriately.
** Parameters: a character that will be added to the queue
*******************************************************************/
void Queue::add(Creature *val)
{
	if (head == NULL)
	{
		head = new Queuenode(val, NULL);
		back = prev = head;
	}
	else
	{
		Queuenode *queueptr = head;
		while (queueptr->next != NULL)
			queueptr = queueptr->next;

		prev = queueptr;
		queueptr->next = new Queuenode(val, prev);
		back = queueptr->next;

	}
}

/******************************************************************
** Function: remove
** Description: This function deletes the value at head, and moves
	the head to the next value in the queue
** Parameters: none
*******************************************************************/
void Queue::removeLoser()
{
	if (head->next != NULL)
	{
		Queuenode *queueptr = head->next;
		delete queueptr->previous;
		queueptr->previous = NULL;
		head = queueptr;
	}
	else
	{
		delete head;
		head = NULL;
	}
}

/******************************************************************
** Function: moveWinner()
** Description: moves the value at the head to the back of the 
	queue and sets the head to the next in line
** Parameters: none
*******************************************************************/
void Queue::moveWinner()
{
	if (head->next != NULL)
	{
		Queuenode *queueptr = head->next;
		Queuenode *backtemp = back;
		back->next = head;
		back = back->next;
		back->next = NULL;
		back->previous = backtemp;

		head = queueptr;
		head->previous = NULL;
	}
	else head = back;
}

/******************************************************************
** Function: firstInLine()
** Description: returns the value at the head of the queue
** Parameters: none
*******************************************************************/
Creature* Queue::firstInLine()
{
	return head->value;
}

/******************************************************************
** Function: getTeam()
** Description: returns true if queue is empty (head = null)
** Parameters: none
*******************************************************************/
bool Queue::isEmpty()
{
	if (head == NULL)
		return true;
	else return false;
}