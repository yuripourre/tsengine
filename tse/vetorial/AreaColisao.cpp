/*
 * AreaBatedora.cpp
 *
 *  Created on: 08/11/2009
 *      Author: Yuri
 */

#include "AreaColisao.h"

AreaColisao::AreaColisao()
{

}

AreaColisao::~AreaColisao()
{
	// TODO Auto-generated destructor stub
}

void AreaColisao::setArea(int x1,int y1, int x2, int y2)
{
	esqCima.setCoordenadas(x1,y1);
	dirBaixo.setCoordenadas(x2,y2);
}


