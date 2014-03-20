/*
 * CamadaTextoRelativa.h
 *
 *  Created on: 23/02/2010
 *      Author: Yuri Pourre
 */

#ifndef CAMADATEXTORELATIVA_H_
#define CAMADATEXTORELATIVA_H_

#include "CamadaTexto.h"

class CamadaTextoRelativa : public CamadaTexto
{

private:

	int xOffset;
	int yOffset;
	Camada* refCam;

public:
	CamadaTextoRelativa();
	CamadaTextoRelativa(Camada* cam);

	void CamadaTextoRelativa::setXOffset(int xOffset);
	void CamadaTextoRelativa::setYOffset(int yOffset);
	void CamadaTextoRelativa::setCoordOffset(int xOffset, int yOffset);

	virtual ~CamadaTextoRelativa();

	void desenha();
};

#endif /* CAMADASEGUIDORA_H_ */
