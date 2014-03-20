/*
 * AreaUtil.cpp
 *
 *  Created on: 08/11/2009
 *      Author: Yuri
 */

#include "AreaUtil.h"

AreaUtil::AreaUtil()
{
	vetor = new AreaColisao;
}

AreaUtil::AreaUtil(int areas)
{
	this->areas = areas;
	vetor = new AreaColisao[areas];
}

AreaUtil::~AreaUtil()
{
	delete vetor;
}

void AreaUtil::setArea(int indice, int x1, int y1, int x2,int y2)
{
	if(areas>=indice)
	{
		vetor[indice].setArea(x1,y1,x2,y2);
	}
}

AreaColisao AreaUtil::getArea(int indice)
{
	if(areas>=indice)
	{
		return vetor[indice];
	}
	return vetor[indice];
}

void AreaUtil::setNumeroAreas(int areas)
{
	int i;
	AreaColisao* aux = new AreaColisao[areas];

	for(i=0;i<this->areas;i++)
	{
		aux[i] = vetor[i];
	}

	vetor = aux;
	delete aux;

}
