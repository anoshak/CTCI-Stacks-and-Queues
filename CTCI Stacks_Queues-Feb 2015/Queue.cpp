/*
 * Queue.cpp
 *
 *  Created on: Mar 5, 2015
 *      Author: Anoshak
 */

#include "Queue.h"

Queue_a::Queue_a()
{
	front = rear = -1;
	count = 0;
}

bool Queue_a::empty()
{
	if(count==0)
		return 1;
	else return 0;
}

bool Queue_a::full()
{
	if(count==MAX)
		return 1;
	else return 0;
}

bool Queue_a::addq(qelement no)
{
	if(full())
		return 0;
	else
	{
		rear = (rear+1)%MAX;
		arr[rear]=no;
		count++;
		return 1;
	}
}

bool Queue_a::delq(qelement *noptr)
{
	if(empty())
		return 0;
	else
	{
		front = (front +1 )%MAX;
		*noptr = arr[front];
		count--;
		return 1;
	}
}

void Queue_a::printq()
{
	if(!empty())
	{
		for(unsigned i=(front+1)%MAX, j=count; j!=0; i=(i+1)%MAX,j--)
			cout<<arr[i]<<" ";
		cout<<endl;
	}
}

int Queue_a::size()
{
	return count;
}

DQ_a::DQ_a()
{
	front = rear = 0;
	count = 0;
}

bool DQ_a::full()
{
	if(count==MAX)
		return 1;
	else return 0;
}
bool DQ_a::empty()
{
	if(count==0)
		return 1;
	else return 0;
}
bool DQ_a::addleft(qelement no)
{
	if(full())
		return 0;
	else
	{
		arr[front]=no;
		if(front==0)
			front = MAX - 1;
		else front--;
		count++;
		return 1;
	}
}
bool DQ_a::addright(qelement no)
{
	if(full())
		return 0;
	else
	{
		rear=(rear+1)%MAX;
		arr[rear]=no;
		count++;
		return 1;
	}
}
bool DQ_a::delleft(qelement *noptr)
{
	if(empty())
		return 0;
	else
	{
		front = (front+1)%MAX;
		*noptr = arr[front];
		count--;
		return 1;
	}
}
bool DQ_a::delright(qelement *noptr)
{
	if(empty())
		return 0;
	else
	{
		*noptr = arr[rear];
		if(rear==0)
			rear=MAX-1;
		else rear--;
		count--;
		return 1;

	}
}
void DQ_a::printq()
{
	if(!empty())
	{
		for(unsigned i=(front+1)%MAX, j=count; j!=0; i=(i+1)%MAX,j--)
			cout<<arr[i]<<" ";
		cout<<endl;
	}
}
int DQ_a::size()
{
	return count;
}


Queue_ll::Queue_ll()
{
	front = rear = NULL;
}
bool Queue_ll::empty()
{
	if(front==NULL)
		return 1;
	else return 0;
}

bool Queue_ll::addq(qelement no)
{
	node* p = new node;
	if(p==NULL)
		return 0;
	else
	{
		p->data = no;
		p->next = NULL;
		if(front==NULL)
			front = rear = p;
		else
		{
			rear->next=p;
			rear=p;
		}
		return 1;
	}
}
bool Queue_ll::delq(qelement *noptr)
{
	if(empty())
		return 0;
	else
	{
		node* p = front;
		*noptr = p->data;
		front = p->next;
		free(p);
		return 1;
	}
}
void Queue_ll::printq()
{
	node* p = front;
	while(p)
	{
		cout<<p->data<<" ";
		p=p->next;
	}
	cout<<endl;
}
int Queue_ll::size()
{
	int count = 0;
	node* p = front;
	while(p)
	{
		count++;
		p=p->next;
	}
	return count;
}

CQ_ll::CQ_ll()
{
	last = NULL;
}
bool CQ_ll::empty()
{
	if(last==NULL)
		return 1;
	else return 0;
}
bool CQ_ll::addq(qelement no)
{
	node* p = new node;
	if(p==NULL)
		return 0;
	else
	{
		p->data = no;
		if(last==NULL)
		{
			p->next = p;
			last = p;
		}
		else
		{
			p->next = last->next;
			last->next = p;
			last = p;
		}
		return 1;
	}
}
bool CQ_ll::delq(qelement *noptr)
{
	if(empty())
		return 0;
	else
	{
		node* p = last->next;
		*noptr = p->data;
		if(p==last)
			last=NULL;
		else last->next = p->next;
		free(p);
		return 1;

	}
}
void CQ_ll::printq()
{
	if(last!=NULL)
	{
		node* p = last->next;
		while(p!=last)
		{
			cout<<p->data<<" ";
			p=p->next;
		}
		cout<<p->data;
		cout<<endl;
	}
}
int CQ_ll::size()
{
	if(last==NULL)
		return 0;
	else
	{
		int count = 0;
		node* p = last;
		do
		{
			count++;
			p=p->next;
		}
		while(p!=last);
		return count;
	}
}


DQ_ll::DQ_ll()
{
	left = right = NULL;
}

bool DQ_ll::empty()
{
	if(left==NULL)
		return 1;
	else return 0;
}
bool DQ_ll::addleft(qelement no)
{
	node *p = new node;
	if(p==NULL)
		return 0;
	else
	{
		p->data = no;
		p->next = left;
		if(left == NULL)
			left = right = p;
		else left = p;
		return 1;
	}
}
bool DQ_ll::addright(qelement no)
{
	node *p = new node;
	if(p==NULL)
		return 0;
	else
	{
		p->data = no;
		p->next = NULL;
		if(left==NULL)
			left = right = p;
		else
		{
			right->next = p;
			right = p;
		}
		return 1;

	}
}

bool DQ_ll::delleft(qelement *noptr)
{
	if(empty())
		return 0;
	else
	{
		*noptr = left->data;
		node* p = left;
		left = left->next;
		if(left==NULL)
			right=NULL;
		delete p;
		return 1;
	}
}
bool DQ_ll::delright(qelement *noptr)
{
	if(empty())
		return 0;
	else
	{
		*noptr=right->data;
		if(left==right)
		{
			delete right;
			left =right = NULL;
		}
		else
		{
			node* p =left;
			while(p->next!=right)
				p=p->next;
			p->next=NULL;
			delete right;
			right = p;
		}
		return 1;
	}
}
void DQ_ll::printq()
{
	node* p = left;
	while(p)
	{
		cout<<p->data<<" ";
		p=p->next;
	}
	cout<<endl;
}
int DQ_ll::size()
{
	int count = 0;
	node* p = left;
	while(p)
	{
		count++;
		p=p->next;
	}
	return count;
}

int main()
{
	Queue_a myq;
	int no;
	cout<<myq.delq(&no)<<endl;
	myq.addq(10);
	myq.addq(20);
	cout<<myq.delq(&no)<<endl;
	cout<<no<<endl;
	myq.addq(30);
	myq.printq();
	return 0;
}

