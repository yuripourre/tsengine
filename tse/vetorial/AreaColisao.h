/*
 * AreaBatedora.h
 *
 *  Created on: 08/11/2009
 *      Author: Yuri
 */

#ifndef AREABATEDORA_H_
#define AREABATEDORA_H_

#include "Coordenada.h"

class AreaColisao
{
	Coordenada esqCima;
	Coordenada dirBaixo;

public:

	AreaColisao();

	virtual ~AreaColisao();

	void setArea(int x1,int y1, int x2, int y2);

};

#endif /* AREABATEDORA_H_ */
