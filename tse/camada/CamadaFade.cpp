/*
 * CamadaFade.cpp
 *
 *  Created on: 21/02/2010
 *      Author: Yuri Pourre
 */

#include "CamadaFade.h"

CamadaFade::CamadaFade()
{
	ativaFade = false;

	fade = false;
	fadeIn = true;

	tymerFade = new Tymer(300);
}

CamadaFade::~CamadaFade()
{
	delete tymerFade;
}

void CamadaFade::setAtivaFade(bool aciona)
{
	ativaFade = aciona;
}

void CamadaFade::setFade(bool aciona)
{
	fade = aciona;
}

void CamadaFade::setFrequenciaFade(int frequencia)
{
	freqFade = frequencia;
}

void CamadaFade::acionaFade()
{
	if(ativaFade)
	{
		if(tymerFade->acionaTymer())
		{

			if(fadeIn)
			{
				fatorFade++;
			}
			else
			{
				fatorFade--;
			}

			fatorFade%=256;

			setAlpha(fatorFade);
		}
	}
}
