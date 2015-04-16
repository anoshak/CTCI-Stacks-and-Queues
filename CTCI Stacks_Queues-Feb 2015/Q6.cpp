/*
 * Q6.cpp
 *
 *  Created on: Feb 26, 2015
 *      Author: Anoshak
 */

#include "Stacks.h"

Stackl sort(Stackl &s)
{
	Stackl temp;
	while(s.size())
	{
		int no;
		s.pop(&no);
		while(temp.size()!=0 && no< temp.peek())
		{
			int no1;
			temp.pop(&no1);
			s.push(no1);

		}
		temp.push(no);
	}
	return temp;

}

/*
int main()
{
	Stackl s;
	s.push(7);
	s.push(5);
	s.push(4);
	s.push(6);
	s.printstack();
	cout<<endl;
	Stackl result = sort(s);
	result.printstack();
}
*/

