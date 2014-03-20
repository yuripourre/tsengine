/*
 * CamadaFade.h
 *
 *  Created on: 21/02/2010
 *      Author: Yuri Pourre
 */

#ifndef CAMADAFADE_H_
#define CAMADAFADE_H_

#include "Camada.h"
#include "../util/Tymer.h"

class CamadaFade : public Camada{

private:

		int freqFade;
		int	fatorFade;

		bool ativaFade;
		bool fade;
		bool fadeIn;
		bool oscilarFade;

	    Tymer* tymerFade;

public:
	CamadaFade();
	virtual ~CamadaFade();

	void acionaFade();

	void setAtivaFade(bool aciona);

	void setFrequenciaFade(int frequencia);

	void setFade(bool aciona);

};

#endif /* CAMADAFADE_H_ */
