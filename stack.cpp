/*************************************************************************
** Program  Filename: stack.cpp
** Author: Danielle Goodman
** Date: 5/22/2016
** Description: Function definitions for the class, Stack
** Input: n/a
** Output: n/a
*************************************************************************/
#include "stack.hpp"

/******************************************************************
** Function: add
** Description: This function creates a new node, and modifies
pointers appropriately.
** Parameters: a character that will be added to the stack
*******************************************************************/
void Stack::add(Creature *val)
{
	if (head == NULL)
	{
		head = new Stacknode(val);
		top = head;
	}
	else
	{
		Stacknode *stackptr = head;
		while (stackptr->next != NULL)
			stackptr = stackptr->next;

		stackptr->next = new Stacknode(val);
		top = stackptr->next;
	}
}

/******************************************************************
** Function: remove
** Description: Returns the value of the last node, and deletes
	that node
** Parameters: none
*******************************************************************/
Creature* Stack::remove()
{
	if (head->next != NULL)
	{
		Creature *temp = top->value;
		// Assign top as new end of the list
		Stacknode *stackptr = head;
		Stacknode *prevptr = head;
		while (stackptr->next != NULL)
		{
			prevptr = stackptr;
			stackptr = stackptr->next;
		}
		delete stackptr;
		stackptr = NULL;
		prevptr->next = NULL;
		top = prevptr;

		return temp;
	}
	else
	{
		return head->value;
		delete head;
		head = NULL;
	}
	
}

