/*
 * CamadaSimples.cpp
 *
 *  Created on: 27/12/2009
 *      Author: Yuri
 */

#include "CamadaSimples.h"

CamadaSimples::CamadaSimples()
{
	// TODO Auto-generated constructor stub
}
CamadaSimples::CamadaSimples(int x, int y)
{
	this->x = x;
	this->y = y;
}

CamadaSimples::~CamadaSimples()
{
	// TODO Auto-generated destructor stub
}

int CamadaSimples::getX () const
{
	return x;
}
int CamadaSimples::getY () const
{
	return y;
}

void CamadaSimples::setX(int x)
{
	this->x = x;
}
void CamadaSimples::setY(int y)
{
	this->y = y;
}

void CamadaSimples::setCoordenadas(int x, int y)
{
	this->x = x;
	this->y = y;
}
