/*
 * CamadaRelativa.h
 *
 *  Created on: 20/01/2010
 *      Author: Yuri Pourre
 */

#ifndef CAMADARELATIVA_H_
#define CAMADARELATIVA_H_

#include "Camada.h"

class CamadaRelativa : public Camada
{

private:

	int xOffset;
	int yOffset;
	Camada* refCam;

public:
	CamadaRelativa();
	CamadaRelativa(Camada* cam);

	virtual ~CamadaRelativa();

	void setXOffset(int xOffset);
	void setYOffset(int yOffset);
	void setCoordOffset(int xOffset, int yOffset);

	void desenha();

};

#endif /* CAMADASEGUIDORA_H_ */
