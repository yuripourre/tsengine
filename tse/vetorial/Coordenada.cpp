/*
 * Coordenada.cpp
 *
 *  Created on: 08/11/2009
 *      Author: Yuri
 */

#include "Coordenada.h"

Coordenada::Coordenada()
{

}

Coordenada::Coordenada(int x, int y)
{
	this->x = x;
	this->y = y;
}

void Coordenada::setX(int x)
{
	this->x = x;
}

void Coordenada::setY(int y)
{
	this->y = y;
}

void Coordenada::setCoordenadas(int x,int y)
{
	this->x = x;
	this->y = y;
}


int Coordenada::getX(void) const
{
	return x;
}

int Coordenada::getY(void) const
{
	return y;
}

Coordenada::~Coordenada()
{

}
