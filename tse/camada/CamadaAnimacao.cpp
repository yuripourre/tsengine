/*
 * CamadaAnimacao.cpp
 *
 *
 *      Author: Yuri
 */

#include "CamadaAnimacao.h"

CamadaAnimacao::CamadaAnimacao()
{

	ativaAnima = true;

	fatorAnima  = 0;
	modAnima    = 2;
	positivoAnima = true;
	animaEmX = true;

	oscilarAnima     = false;
	once = false;

	tymerAnima = new Tymer(500);

}
CamadaAnimacao::~CamadaAnimacao()
{
	delete tymerAnima;
}

void CamadaAnimacao::acionaAnimacao()
{

	if (ativaAnima)
	{
		if(tymerAnima->acionaTymer())
		{

			if (oscilarAnima)
			{
				if (positivoAnima)
				{

					if(fatorAnima==modAnima)
					{
						positivoAnima = false;
						if(animaEmX)
						{
							setXImagem(getXLimite()*fatorAnima);
						}
						else
						{
							setYImagem(getYLimite()*fatorAnima);
						}

						if(once){
							ativaAnima = false;
						}
						return;
					}
					else
					{
						fatorAnima++;
					}
				}
				else
				{
					if(fatorAnima==1)
					{
						fatorAnima++;

						positivoAnima = true;

						if(animaEmX)
						{
							setXImagem(getXLimite()*fatorAnima);
						}
						else
						{
							setYImagem(getYLimite()*fatorAnima);
						}

						return;
					}
					else
					{
						fatorAnima--;
					}
				}

			}
			else
			{
				fatorAnima++;
			}

			fatorAnima%=modAnima;

			if(animaEmX)
			{
				setXImagem(getXLimite()*fatorAnima);
			}
			else
			{
				setYImagem(getYLimite()*fatorAnima);
			}
		}
	}
}


void CamadaAnimacao::setNumeroFrames(int mod)
{
	modAnima = mod;
}

void CamadaAnimacao::setFrequenciaAnima(int frequencia)
{
	tymerAnima->setFreq(frequencia);
}

void CamadaAnimacao::setFatorAnima(int fator)
{
	fatorAnima = fator%modAnima;
}

void CamadaAnimacao::setAtivaAnima(bool aciona)
{
	ativaAnima = aciona;
}


void CamadaAnimacao::setOscilarAnima(bool aciona)
{
	oscilarAnima = aciona;
}

int CamadaAnimacao::getFatorAnima()
{
	return fatorAnima;
}

void CamadaAnimacao::setAnimaEmX()
{
	animaEmX = true;
}
void CamadaAnimacao::setAnimaEmY()
{
	animaEmX = false;
}
