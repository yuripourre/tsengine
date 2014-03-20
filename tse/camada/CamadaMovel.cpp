/*
 * CamadaMovel.cpp
 *
 *
 *      Author: Yuri
 */
#include "CamadaMovel.h"

CamadaMovel::CamadaMovel()
{
	moveEmX = false;
	moveEmY = false;

	oscilarX = false;
	oscilarY = false;

	tymerX = new Tymer(300);
	tymerY = new Tymer(300);

}

CamadaMovel::~CamadaMovel()
{
	delete tymerX;
	delete tymerY;
}

void CamadaMovel::setMaxX(int max)
{
	maxX = max;
}

void CamadaMovel::setMaxY(int max)
{
	maxY = max;
}

void CamadaMovel::setMinX(int min)
{
	minX = min;
}

void CamadaMovel::setMinY(int min)
{
	minY = min;
}

void CamadaMovel::setFreqX(int frequencia)
{
	tymerX->setFreq(frequencia);
}

void CamadaMovel::setFreqY(int frequencia)
{
	tymerY->setFreq(frequencia);
}
//Gets
int CamadaMovel::getMaxX(void)
{
	return maxX;
}

int CamadaMovel::getMaxY(void)
{
	return maxY;
}

int CamadaMovel::getMinX(void)
{
	return minX;
}

int CamadaMovel::getMinY(void)
{
	return minY;
}

int CamadaMovel::getFreqX(void)
{
	return tymerX->getFreq();

}

int CamadaMovel::getFreqY(void)
{
	return tymerY->getFreq();
}

bool CamadaMovel::getOscilarX(void)
{
	return oscilarX;
}

bool CamadaMovel::getOscilarY(void)
{
	return oscilarY;
}

bool CamadaMovel::getPositivoEmX(void)
{
	return positivoEmX;
}

bool CamadaMovel::getPositivoEmY(void)
{
	return positivoEmY;
}

//Movimentos
void CamadaMovel::setOscilarX(bool aciona)
{
	oscilarX = aciona;
}
void CamadaMovel::setOscilarY(bool aciona)
{
	oscilarY = aciona;
}

void CamadaMovel::setMoveEmX(bool aciona)
{
	moveEmX = aciona;
}
void CamadaMovel::setMoveEmY(bool aciona)
{
	moveEmY = aciona;
}

bool CamadaMovel::getMoveEmX(void)
{
	return moveEmX;
}

bool CamadaMovel::getMoveEmY(void)
{
	return moveEmY;
}

void CamadaMovel::acionaMovimentoX()
{

	if(tymerX->acionaTymer())
	{

		if (oscilarX)
		{
			if (positivoEmX)
			{
				fatorX=1;

				if(getX()==maxX)
				{
					positivoEmX = false;
				}
			}
			else
			{
				fatorX=-1;

				if(getX()==minX)
				{
					positivoEmX = true;
				}
			}

		}

		else
		{
			if(minX>maxX)
			{
				positivoEmX = false;
			}
			else
			{
				positivoEmX = true;
			}

			if(positivoEmX)
			{
				if((getX()>=minX)&&(getX()<maxX))
				{
					fatorX=1;
				}
			}
			else
			{
				if((getX()<=minX)&&(getX()>maxX))
				{
					fatorX=-1;
				}
			}

		}

		if(moveEmX)
		{
			setX(getX()+fatorX);
		}
	}

}

void CamadaMovel::acionaMovimentoY()
{

	if(tymerY->acionaTymer())
	{

		if (oscilarY)
		{
			if (positivoEmY)
			{
				fatorY=1;

				if(getY()==maxY)
				{
					positivoEmY = false;
				}
			}
			else
			{
				fatorY=-1;

				if(getX()==minY)
				{
					positivoEmY = true;
				}
			}

		}

		else
		{
			if(minY>maxY)
			{
				positivoEmY = false;
			}
			else
			{
				positivoEmY = true;
			}

			if(positivoEmY)
			{
				if((getY()>=minY)&&(getY()<maxY))
				{
					fatorY=1;
				}
			}
			else
			{
				if((getY()<=minY)&&(getY()>maxY))
				{
					fatorY=-1;
				}
			}

		}

		if(moveEmY)
		{
			setY(getY()+fatorY);
		}
	}
}
