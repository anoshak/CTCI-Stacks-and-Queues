/*
 * Queue.h
 *
 *  Created on: Mar 5, 2015
 *      Author: Anoshak
 */

#ifndef QUEUE_H_
#define QUEUE_H_

#include <cstdio>
#include <map>
#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define MAX 100
typedef int qelement;

class Queue_a
{
	//Circular Queue array implementaion using count;
protected:
	qelement arr[MAX];
	int front, rear;
	int count;

public:
	Queue_a();
	bool empty();
	bool full();
	bool addq(qelement no);
	bool delq(qelement *noptr);
	void printq();
	int size();

};

class DQ_a
{
	//Double Ended Circular Queue Array Implementation using count
protected:
	qelement arr[MAX];
	int front, rear;
	int count;

public:
	DQ_a();
	bool full();
	bool empty();
	bool addleft(qelement no);
	bool addright(qelement no);
	bool delleft(qelement *noptr);
	bool delright(qelement *noptr);
	void printq();
	int size();

};

struct node
{
	qelement data;
	node* next;
};

class Queue_ll
{
	//queue linked list implementation
protected:
	node *front, *rear;

public:
	Queue_ll();
	bool empty();
	bool addq(qelement no);
	bool delq(qelement *noptr);
	void printq();
	int size();
};

class CQ_ll
{
	//Circular Queue Linked List Implementation
protected:
	node* last;
public:
	CQ_ll();
	bool empty();
	bool addq(qelement no);
	bool delq(qelement *noptr);
	void printq();
	int size();

};

class DQ_ll
{
	//Double ended queue linked list implementation
protected:
	node *left,*right;

public:
	DQ_ll();
	bool full();
	bool empty();
	bool addleft(qelement no);
	bool addright(qelement no);
	bool delleft(qelement *noptr);
	bool delright(qelement *noptr);
	void printq();
	int size();
};


#endif /* QUEUE_H_ */
