/*
 * Q3.cpp
 *
 *  Created on: Feb 26, 2015
 *      Author: Anoshak
 */
#include "Stacks.h"
#include <stack>
#include <vector>


class SetofStacks
{
private:
	static const int threshold=2;
	int nos;
	vector<Stackl> stacklist;

public:
	SetofStacks()
{
		nos=0;
		Stackl mystack;
		stacklist.push_back(mystack);
}

	void push(int ch)
	{
		if(stacklist[nos].size()==threshold)
		{
			//last stack is full; time to create new stack
			Stackl mystack;
			stacklist.push_back(mystack);
			nos++;
		}
		//push item onto the last stack
		stacklist[nos].push(ch);
	}

	int pop()
	{
		int ch;
		stacklist[nos].pop(&ch);
		if(stacklist[nos].size()==0 && nos!=0)
		{
			//last element, delete stack except if it is first stack;
			stacklist.pop_back();
			nos--;

		}
		return ch;
	}

	int popAt(int index)
	{
		int ch;
		stacklist[index].pop(&ch);
		while(index<nos)
		{
			//start shifting
			int no;
			stacklist[index+1].removeBottom(&no);
			if(stacklist[nos].size()==0)
			{
				//last element, delete stack
				stacklist.pop_back();
				nos--;

			}
			stacklist[index].push(no);
			index++;
		}
		return ch;
	}



};

/*
int main()
{
	SetofStacks myset;
	myset.push(11);
	myset.push(20);
	myset.push(33);
	myset.push(40);
	myset.push(50);
	myset.push(60);
	myset.push(70);
	myset.push(80);
	cout<<myset.popAt(1)<<endl;
	cout<<myset.popAt(1)<<endl;
	cout<<myset.pop()<<endl;
	cout<<myset.popAt(1)<<endl;

	cout<<myset.popAt(0)<<endl;
    cout<<myset.popAt(0)<<endl;
    cout<<myset.popAt(0)<<endl;
	myset.push(11);
	cout<<myset.pop()<<endl;
	//cout<<myset.pop()<<endl;

	return 0;
}
*/

