/*
 * Util.cpp
 *
 *  Created on: 07/01/2010
 *      Author: Yuri
 */

#include "Util.h"


int stoi(string buffer)
{
	unsigned int i = 0,aux = 0;

	for(i=0;i<buffer.length();i++)
	{
		aux += (buffer.at(i)-'0')*(expInt(10,(buffer.length()-i+1)));
	}

	return aux;

}

string itos(int valor)
{

	std::ostringstream auxStream;

	auxStream << valor;

	string aux = auxStream.str();

	return aux;

}

int expInt(int base, int expoente)
{

	int i;

	if((base>0)&&(expoente>0))
	{
		for(i=1;i<expoente;i++)
		{
			base*=base;
		}
		return base;
	}
	else if(expoente==0)
	{
		return 1;
	}

	return 0;
}
