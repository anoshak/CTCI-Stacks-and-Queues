/*
 * Q2.cpp
 *
 *  Created on: Feb 24, 2015
 *      Author: Anoshak
 */

#include "Stacks.h"

class StackwithMin : public Stackl
{
protected:
	Stackl minStack;

public:
	bool push(stackelement ch)
	{
		node* p = new node;
		if(p==NULL)
			return 0;
		else
		{
			p->data=ch;
			p->next=top;
			top=p;
			if(minStack.empty())
				minStack.push(ch);
			else if(ch<minStack.peek())
				minStack.push(ch);
			return 1;

		}
	}

	bool pop(stackelement *chptr)
	{
		if(empty())
			return 0;
		else
		{
			node* p = top;
			top=p->next;
			*chptr = p->data;
		    if(p->data==minStack.peek())
		    {
		    	stackelement ch;
		    	minStack.pop(&ch);
		    }
		    free(p);
		    return 1;

		}
	}

	stackelement min()
	{
		return minStack.peek();
	}
};

