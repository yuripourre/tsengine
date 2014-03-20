/*
 * CamadaPrimitiva.cpp
 *
 *  Created on: 27/12/2009
 *      Author: Yuri
 */

#include "CamadaPrimitiva.h"
#include "../TSe.h"
//using namespace peste;

CamadaPrimitiva::CamadaPrimitiva()
{
	inicializa();
}

CamadaPrimitiva::CamadaPrimitiva(int tipo)
{
	inicializa();

	this->tipo = tipo;
}

CamadaPrimitiva::CamadaPrimitiva(int x, int y)
{
	inicializa();

	setCoordenadas(x,y);
}
CamadaPrimitiva::CamadaPrimitiva(int x, int y, int xLimite, int yLimite)
{
	inicializa();

	setCoordenadas(x,y);
	setCoordLimite(xLimite,yLimite);
}

CamadaPrimitiva::CamadaPrimitiva(int x, int y, int xLimite, int yLimite,int tipo)
{
	inicializa();
	this->tipo = tipo;

	setCoordenadas(x,y);
	setCoordLimite(xLimite,yLimite);
}
void CamadaPrimitiva::inicializa(){
	using namespace tse::primitivas;
	this->tipo = PRIM_PIXEL;

	x = 0;
	y = 0;

	setCor(0,0,0,255);
	expessura = 1;
	aparecendo = true;
}

CamadaPrimitiva::~CamadaPrimitiva()
{
	// TODO Auto-generated destructor stub
}

void CamadaPrimitiva::setCor(int r, int g, int b)
{
	setCor(r,g,b,255);
}
void CamadaPrimitiva::setCor(int r, int g, int b, int a)
{
	corDifusa.r = r%256;
	corDifusa.g = g%256;
	corDifusa.b = b%256;
	corDifusa.unused = a%256;
}

void CamadaPrimitiva::setCor(SDL_Color cor)
{
	setCor(cor.r,cor.g,cor.b,255);
}

void CamadaPrimitiva::desenhaPrimitiva()
{
	desenhaPrimitiva(tse::tela);
}

void CamadaPrimitiva::desenhaPrimitiva(SDL_Surface* destino)
{
	using namespace tse::primitivas;

	if(aparecendo)
	{
		switch(tipo)
		{

		case PRIM_BOX:
			boxColorida(destino);
			break;

		case PRIM_RECT:
			retanguloColorido(destino);
			break;

		case PRIM_PIXEL:
			pixelColorido(destino);
			break;

		case PRIM_LINHAH:
			linhaHColorida(destino);
			break;
		case PRIM_LINHAV:
			linhaVColorida(destino);
			break;
		case PRIM_LINHA:
			linhaColorida(destino);
			break;

		case PRIM_CIRCULO:
			circuloColorido(destino);
			break;
		case PRIM_CIRCULO_AA:
			circuloAAColorido(destino);
			break;
		case PRIM_CIRCULO_PREENCHIDO:
			circuloPreenchidoColorido(destino);
			break;

		case PRIM_ELIPSE:
			elipseColorida(destino);
			break;
		case PRIM_ELIPSE_AA:
			elipseAAColorida(destino);
			break;
		case PRIM_ELIPSE_PREENCHIDA:
			elipsePreenchidaColorida(destino);
			break;




		}

	}
}
int CamadaPrimitiva::pixelColorido(SDL_Surface* destino)
{
	return pixelRGBA(destino,getX(),getY(),(Uint8)corDifusa.r,(Uint8)corDifusa.g,(Uint8)corDifusa.b,(Uint8)corDifusa.unused);
}

void CamadaPrimitiva::linhaHColorida(SDL_Surface* destino)
{
	hlineRGBA(destino, getX(),getXLimite(),getY(),(Uint8)corDifusa.r,(Uint8)corDifusa.g,(Uint8)corDifusa.b,(Uint8)corDifusa.unused);
}

void CamadaPrimitiva::linhaVColorida(SDL_Surface* destino)
{
	vlineRGBA(destino,getX(),getY(),getYLimite(),(Uint8)corDifusa.r,(Uint8)corDifusa.g,(Uint8)corDifusa.b,(Uint8)corDifusa.unused);
}

void CamadaPrimitiva::retanguloColorido(SDL_Surface* destino)
{
	rectangleRGBA(destino,getX(),getY(),getX()+getXLimite(),getY()+getYLimite(),(Uint8)corDifusa.r,(Uint8)corDifusa.g,(Uint8)corDifusa.b,(Uint8)corDifusa.unused);
}
void CamadaPrimitiva::boxColorida(SDL_Surface* destino)
{
	boxRGBA(destino,getX(),getY(),getX()+getXLimite(),getY()+getYLimite(),(Uint8)corDifusa.r,(Uint8)corDifusa.g,(Uint8)corDifusa.b,(Uint8)corDifusa.unused);
}


void CamadaPrimitiva::boxColorida()
{
	boxColorida(tse::tela);
}


int CamadaPrimitiva::linhaColorida(SDL_Surface* destino)
{
	return lineRGBA(destino,getX(),getY(),getXLimite(),getYLimite(),(Uint8)corDifusa.r,(Uint8)corDifusa.g,(Uint8)corDifusa.b,(Uint8)corDifusa.unused);
}
int CamadaPrimitiva::linhaAAColorida(SDL_Surface* destino)
{
	return aalineRGBA(destino,getX(),getY(),getXLimite(),getYLimite(),(Uint8)corDifusa.r,(Uint8)corDifusa.g,(Uint8)corDifusa.b,(Uint8)corDifusa.unused);
}
int CamadaPrimitiva::circuloColorido(SDL_Surface* destino)
{
	return circleRGBA(destino,(getX()+getXLimite())/2,(getY()+getYLimite())/2,getXLimite()/2,(Uint8)corDifusa.r,(Uint8)corDifusa.g,(Uint8)corDifusa.b,(Uint8)corDifusa.unused);

}
int CamadaPrimitiva::circuloAAColorido(SDL_Surface* destino)
{
	return aacircleRGBA(destino,(getX()+getXLimite())/2,(getY()+getYLimite())/2,getXLimite()/2,(Uint8)corDifusa.r,(Uint8)corDifusa.g,(Uint8)corDifusa.b,(Uint8)corDifusa.unused);
}

int CamadaPrimitiva::circuloPreenchidoColorido(SDL_Surface* destino)
{
	return filledCircleRGBA(destino,(getX()+getXLimite())/2,(getY()+getYLimite())/2,getXLimite()/2,(Uint8)corDifusa.r,(Uint8)corDifusa.g,(Uint8)corDifusa.b,(Uint8)corDifusa.unused);
}

int CamadaPrimitiva::elipseColorida(SDL_Surface* destino)
{
	return ellipseRGBA(destino,(getX()+getXLimite())/2,(getY()+getYLimite())/2,getXLimite()/2,getYLimite()/2,(Uint8)corDifusa.r,(Uint8)corDifusa.g,(Uint8)corDifusa.b,(Uint8)corDifusa.unused);
}
int CamadaPrimitiva::elipseAAColorida(SDL_Surface* destino)
{
	//return aaellipseColor(destino,(getX()+getXLimite())/2,(getY()+getYLimite())/2,getXLimite()/2,getYLimite()/2,getCorRGB(destino));
	return aaellipseRGBA(destino,(getX()+getXLimite())/2,(getY()+getYLimite())/2,getXLimite()/2,getYLimite()/2,(Uint8)corDifusa.r,(Uint8)corDifusa.g,(Uint8)corDifusa.b,(Uint8)corDifusa.unused);
}
int CamadaPrimitiva::elipsePreenchidaColorida(SDL_Surface* destino)
{
	return filledEllipseRGBA(destino,getX(),getY(),getXLimite(),getYLimite(),(Uint8)corDifusa.r,(Uint8)corDifusa.g,(Uint8)corDifusa.b,(Uint8)corDifusa.unused);
}

/* Polygon */
int poligonoColorido (Sint16 *vx, Sint16 *vy, int n);
//int polygonColor (SDL_Surface *dst, Sint16 *vx, Sint16 *vy, int n, Uint32 color);
//int polygonRGBA (SDL_Surface *dst, Sint16 *vx, Sint16 *vy, int n, Uint8 r, Uint8 g, Uint8 b, Uint8 a);

/* Filled Polygon */
int poligonoPreenchidoColorido (Sint16 *vx, Sint16 *vy, int n);
//int filledPolygonColor (SDL_Surface *dst, Sint16 *vx, Sint16 *vy, int n, int color);
//int filledPolygonRGBA (SDL_Surface *dst, Sint16 *vx, Sint16 *vy, int n, Uint8 r, Uint8 g, Uint8 b, Uint8 a);

/* 8x8 Characters/Strings */
int CamadaPrimitiva::caracterColorido (SDL_Surface* destino, char c)
{
	return characterColor(destino,getX(),getY(),c,getCorRGB(destino));
}
int CamadaPrimitiva::stringColorida (SDL_Surface* destino, char *c)
{
	return stringColor(destino,getX(),getY(),c,getCorRGB(destino));
}

Uint32 CamadaPrimitiva::getCorRGB(SDL_Surface* destino)
{
	return SDL_MapRGBA(destino->format,(Uint8)corDifusa.r,(Uint8)corDifusa.g,(Uint8)corDifusa.b,255);
}
