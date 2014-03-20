/*
 * CamadaTextoRelativa.cpp
 *
 *  Created on: 23/02/2010
 *      Author: Yuri Pourre
 */

#include "CamadaTextoRelativa.h"
#include "../TSe.h"
//using namespace tse;

CamadaTextoRelativa::CamadaTextoRelativa()
{
	xOffset = 0;
	yOffset = 0;
}
CamadaTextoRelativa::CamadaTextoRelativa(Camada* cam)
{

	refCam = cam;
	xOffset = 0;
	yOffset = 0;
}

CamadaTextoRelativa::~CamadaTextoRelativa()
{
	// TODO Auto-generated destructor stub
}

void CamadaTextoRelativa::setXOffset(int xOffset)
{
	this->xOffset = xOffset;
}
void CamadaTextoRelativa::setYOffset(int yOffset)
{
	this->yOffset = yOffset;
}

void CamadaTextoRelativa::setCoordOffset(int xOffset, int yOffset)
{
	this->xOffset = xOffset;
	this->yOffset = yOffset;
}

void CamadaTextoRelativa::desenha()
{
	if(getFrase()->getConteudo().empty())
	{
		return;
	}

	if(getAparecendo())
	{
		SDL_Rect rect;

		rect.x = refCam->getX()+xOffset;
		rect.y = refCam->getY()+yOffset;

		SDL_Rect rect2;

		rect2.x = getXImagem();
		rect2.y = getYImagem();
		rect2.w = getXLimite();
		rect2.h = getYLimite();


		SDL_BlitSurface(getImagem(), &rect2, tse::tela, &rect);
	}
}
