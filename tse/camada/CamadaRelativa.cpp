/*
 * CamadaRelativa.cpp
 *
 *  Created on: 20/01/2010
 *      Author: Yuri Pourre
 */

#include "CamadaRelativa.h"
#include "../TSe.h"
//using namespace peste;

CamadaRelativa::CamadaRelativa()
{
	xOffset = 0;
	yOffset = 0;
}
CamadaRelativa::CamadaRelativa(Camada* cam)
{

	refCam = cam;
	xOffset = 0;
	yOffset = 0;
}

CamadaRelativa::~CamadaRelativa()
{
	// TODO Auto-generated destructor stub
}

void CamadaRelativa::setXOffset(int xOffset)
{
	this->xOffset = xOffset;
}
void CamadaRelativa::setYOffset(int yOffset)
{
	this->yOffset = yOffset;
}

void CamadaRelativa::setCoordOffset(int xOffset, int yOffset)
{
	this->xOffset = xOffset;
	this->yOffset = yOffset;
}

void CamadaRelativa::desenha()
{
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
