/*
 * Q4.cpp
 *
 *  Created on: Feb 26, 2015
 *      Author: Anoshak
 */

#include"Stacks.h"

void towers(int n, char from, char to, char aux)
{
	if(n==1)
		cout<<"Move disk from "<<from<<" to "<<to<<endl;
	else
	{
		towers(n-1,from,aux,to);
		towers(1,from,to,aux);
		towers(n-1,aux,to,from);
	}
}


/*int main()
{
	towers(3,'A','C','B');
	return 0;
}*/
