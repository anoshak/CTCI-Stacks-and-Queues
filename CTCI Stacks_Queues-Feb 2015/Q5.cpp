/*
 * Q5.cpp
 *
 *  Created on: Feb 26, 2015
 *      Author: Anoshak
 */

#include "Stacks.h"
#include<stack>

class MyQueue
{
private:
	stack<int> Stacks[2];
	int cur;
	bool popped;
public:
	MyQueue()
{
		cur=0;
		popped = 0;
}
	void add(int ch)
	{
		if(popped)
		{
			popped=0;
			shiftStacks();
		}
		Stacks[cur].push(ch);

	}

	bool del(int* chptr)
	{
		if(Stacks[cur].size()==0)
			return 0;
		if(!popped)
		{
			popped = 1;
			shiftStacks();

		}
		*chptr=Stacks[cur].top();
		Stacks[cur].pop();
		return 1;
	}

	void shiftStacks()
	{
		while(Stacks[cur].size())
		{
			int ch = Stacks[cur].top();
			Stacks[cur].pop();
			int other = (cur+1)%2;
			Stacks[other].push(ch);
		}
		cur=(cur+1)%2;
	}
};

class MyQueue2{
private:
	stack<int> oldest,newest;
public:
	void add(int ch)
	{
		newest.push(ch);
	}

	void shiftStacks()
	{
		if(oldest.size()==0)
		{
			while(newest.size())
			{
				int ch = newest.top();
				oldest.push(ch);
				newest.pop();
			}
		}
	}

	bool del(int* chptr)
	{
		shiftStacks();
		if(oldest.size()==0)
			return 0;
		*chptr = oldest.top();
		oldest.pop();
		return 1;
	}
};
/*
int main()
{
	MyQueue2 test;
	test.add(10);
	test.add(20);
	test.add(30);
	test.add(40);
	test.add(50);
	int ch;
	test.del(&ch);
	cout<<ch<<endl;
	test.del(&ch);
	cout<<ch<<endl;
	test.add(60);
	test.del(&ch);
	cout<<ch<<endl;
	test.del(&ch);
	cout<<ch<<endl;
	test.del(&ch);
	cout<<ch<<endl;
	test.del(&ch);
	cout<<ch<<endl;


	return 0;



}
*/

