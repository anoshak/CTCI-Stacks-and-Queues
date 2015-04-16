/*
 * Stacks.cpp
 *
 *  Created on: Feb 24, 2015
 *      Author: Anoshak
 */

#include "Stacks.h"

Stacka::Stacka() {
	top = -1;
}

bool Stacka::full() {
	if (top == MAX - 1)
		return 1;
	else
		return 0;

}
bool Stacka::empty() {
	if (top == -1)
		return 1;
	else
		return 0;

}
bool Stacka::push(stackelement ch) {
	if (full())
		return 0;
	else {
		arr[++top] = ch;
		return 1;
	}

}
bool Stacka::pop(stackelement *chptr) {
	if (empty())
		return 0;
	else {
		*chptr = arr[top--];
		return 1;
	}

}
stackelement Stacka::peek() {
	return arr[top];

}
void Stacka::printstack() {
	if (empty())
		cout << "Stack is empty." << endl;
	else {
		cout << "Stack elements from top to bottom are: ";
		for (int i = top; i > -1; i--)
			cout << arr[i] << " ";
		cout << endl;
	}

}

Stackl::Stackl()
{
	top=NULL;
}

bool Stackl::empty()
{
	if(top==NULL)
		return 1;
	else return 0;
}

bool Stackl::push(stackelement ch)
{
	node* p = new node;
	if(p==NULL)
		return 0;
	else
	{
		p->data=ch;
		p->next=top;
		top=p;
		return 1;
	}
}

bool Stackl::pop(stackelement *chptr)
{
	if(empty())
		return 0;
	else
	{
		*chptr=top->data;
		node* p=top;
		top=top->next;
		free(p);
		return 1;

	}
}
stackelement Stackl::peek()
{
	return top->data;
}
void Stackl::printstack()
{
	if (empty())
		cout << "Stack is empty." << endl;
	else {
		cout << "Stack elements from top to bottom are: ";
		for (node* p = top; p; p=p->next)
			cout << p->data << " ";
		cout << endl;
	}

}

bool Stackl::removeBottom(stackelement* chptr)
{
	if(empty())
		return 0;
	else
	{
		node* p=top;
		node* prev=NULL;
		while(p->next!=NULL)
		{
			prev=p;
			p=p->next;
		}
		*chptr=p->data;
		if(prev==NULL)
		{
			//only one element
			top=NULL;

		}
		else
		{
			prev->next=NULL;
		}
		free(p);
		return 1;
	}
}

int Stackl::size()
{
	int count=0;
	node* p = top;
	while(p)
	{
		count++;
		p=p->next;
	}
	return count;
}
