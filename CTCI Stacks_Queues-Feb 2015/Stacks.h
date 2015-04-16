/*
 * Stacks.h
 *
 *  Created on: Feb 24, 2015
 *      Author: Anoshak
 */

#ifndef STACKS_H_
#define STACKS_H_

#include <cstdio>
#include <map>
#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <cstring>
#define MAX 100

using namespace std;

typedef int stackelement;

class Stacka
{
protected:
	int top;
	stackelement arr[MAX];

public:
	Stacka();
	bool full();
	bool empty();
	bool push(stackelement ch);
	bool pop(stackelement *chptr);
	stackelement peek();
	void printstack();
};

struct node
{
	stackelement data;
	node* next;
};
class Stackl
{
protected:
	node* top;

public:

	Stackl();
	bool full();
	bool empty();
	bool push(stackelement ch);
	bool pop(stackelement *chptr);
	stackelement peek();
	void printstack();
	bool removeBottom(stackelement* chptr);
	int size();

};


#endif /* STACKS_H_ */
