/*
 * Camada.cpp
 *
 *
 *      Author: Yuri
 */

#include "Camada.h"

#include "../TSe.h"

Camada::Camada()
{

	x = 0, y = 0;
	xLimite = 0, yLimite = 0;
	xImagem = 0,yImagem = 0;

	aparecendo  = true;
	alpha = 255;


}

Camada::Camada(int x, int y)
{

	this->x = x, this->y = y;
	xLimite = 0, yLimite = 0;
	xImagem = 0,yImagem = 0;

	aparecendo  = true;
	alpha = 255;
}

Camada::Camada(int x, int y,int xLimite, int yLimite)
{

	this->x = x, this->y = y;
	this->xLimite = xLimite, this->yLimite = yLimite;
	xImagem = 0,yImagem = 0;

	aparecendo  = true;
	alpha = 255;

}

Camada::Camada(int x, int y, int xLimite, int yLimite, int xImagem, int yImagem)
{

	this->x = x, this->y = y;
	this->xLimite = xLimite, this->yLimite = yLimite;

	this->xImagem = xImagem;
	this->yImagem = yImagem;

	aparecendo  = true;
	alpha = 255;

}

int Camada::getXImagem()
{
	return xImagem;
}
int Camada::getYImagem()
{
	return yImagem;
}
bool Camada::getAparecendo()
{
	return aparecendo;
}
//SETS
void Camada::setXImagem(int xImagem)
{
	this->xImagem = xImagem;
}
void Camada::setYImagem(int yImagem)
{
	this->yImagem = yImagem;
}

int Camada::getAlpha()
{
	return alpha;
}

void Camada::setAlpha(int valor)
{
	valor%=256;
	alpha = 255-valor;
	SDL_SetAlpha(getImagem(), SDL_SRCALPHA, alpha);
}

void Camada::setCoordImagem(int dentroX, int dentroY)
{
	xImagem = dentroX;
	yImagem = dentroY;
}

void Camada::setCamada(int x, int y, int xLimite, int yLimite, int xImagem, int yImagem)
{

	this->x = x, this->y = y;
	this->xLimite = xLimite, this->yLimite = yLimite;
	this->xImagem = xImagem, this->yImagem = yImagem;

}

int Camada::getX () const
{
	return x;
}
int Camada::getY () const
{
	return y;
}

void Camada::setX(int x)
{
	this->x = x;
}
void Camada::setY(int y)
{
	this->y = y;
}

void Camada::setCoordenadas(int x, int y)
{
	this->x = x;
	this->y = y;
}

void Camada::setAparecendo(bool aparecendo)
{
	this->aparecendo = aparecendo;
}

void Camada::mudaAparecendo()
{
	if(aparecendo)
	{
		aparecendo = false;
		return;
	}
	if(!aparecendo)
	{
		aparecendo = true;
	}
}

void Camada::desenha(SDL_Surface *destino)
{
	if(aparecendo)
	{
		SDL_Rect rect;

		rect.x = getX();
		rect.y = getY();

		SDL_Rect rect2;

		rect2.x = xImagem;
		rect2.y = yImagem;
		rect2.w = getXLimite();
		rect2.h = getYLimite();


		SDL_BlitSurface(getImagem(), &rect2, destino, &rect);
	}

}
void Camada::desenha()
{

	if(aparecendo)
	{
		SDL_Rect rect;

		rect.x = x;
		rect.y = y;

		SDL_Rect rect2;

		rect2.x = xImagem;
		rect2.y = yImagem;
		rect2.w = xLimite;
		rect2.h = yLimite;


		SDL_BlitSurface(getImagem(), &rect2, tse::tela, &rect);
	}

}

void Camada::desenhaSimples(int x,int y,int xImagem,int yImagem,int xLimite,int yLimite,SDL_Surface *destino)
{

	if(aparecendo)
	{
		SDL_Rect rect;

		rect.x = x;
		rect.y = y;

		SDL_Rect rect2;

		rect2.x = xImagem;
		rect2.y = yImagem;
		rect2.w = xLimite;
		rect2.h = yLimite;

		SDL_BlitSurface(getImagem(), &rect2, destino, &rect);
	}
}

Camada::~Camada()
{
	//liberaImagem();
	//O destrutor da Camada estática já é chamado.
}

int Camada::centralizaX(int xInicial, int xFinal)
{
	int x;
	x = (((xInicial+xFinal)/2)-(getXLimite()/2));
	setX(x);
	return x;
}

int Camada::centralizaY(int yInicial, int yFinal)
{
	int y;
	y = (((yInicial+yFinal)/2)-(getYLimite()/2));
	setY(y);
	return y;
}

void Camada::centralizaX(Camada *b)
{
	int x;
	x = (((b->getX()+b->getX()+b->getXLimite())/2)-(getXLimite()/2));
	setX(x);
}
void Camada::centralizaY(Camada *b)
{
	int y;
	y = (((b->getY()+b->getY()+b->getYLimite())/2)-(getYLimite()/2));
	setY(y);
}

void Camada::centraliza(Camada *b)
{
	int x,y;
	x = (((b->getX()+b->getX()+b->getXLimite())/2)-(getXLimite()/2));

	y = (((b->getY()+b->getY()+b->getYLimite())/2)-(getYLimite()/2));
	setCoordenadas(x,y);
}


//A little adaptation of
//int SDL_CollideBoundingBox(SDL_Rect a , SDL_Rect b)
//from SDL_Collide
bool Camada::colideRetangular(Camada* b)
{
	if(b->getX() + b->getXLimite() < getX())	return false;
	if(b->getX() > getX() + getXLimite())		return false;

	if(b->getY() + b->getYLimite() < getY())	return false;
	if(b->getY() > getY() + getYLimite())		return false;

	return true;
}


//A little adaptation of
//Uma pequena adaptação de
//int SDL_CollideBoundingCircle(int x1 , int y1 , int r1 , int x2 , int y2 , int r2 , int offset)
//from SDL_Collide
bool Camada::colideCircular(Camada* b)
{

	int xdiff = b->getX() - getX();
	int ydiff = b->getY() - getY();

	int dcentre_sq = (ydiff*ydiff) + (xdiff*xdiff);

	int r_sum_sq = b->getXLimite()/2 + getXLimite()/2;
	r_sum_sq *= r_sum_sq;

	if(dcentre_sq - r_sum_sq<=0)
	{
		return true;
	}

	return false;
}



//Functions of SDL_Bilinear
//Funções do SDL_Bilinear
/*
void Camada::girar(double angulo)
{
	igualaImagem(SDL_Rotate(getImagem(), angulo));
}

void Camada::girarSuave(double angulo)
{
	igualaImagem(SDL_RotateSmooth(getImagem(), angulo));
}

void Camada::redimensionar(int xLimiteNovo, int yLimiteNovo)
{
	igualaImagem(SDL_Resize(getImagem(), xLimiteNovo, yLimiteNovo));
	setCoordLimite(xLimiteNovo, yLimiteNovo);
}

void Camada::redimensionarSuave(int xLimiteNovo, int yLimiteNovo)
{
	igualaImagem(SDL_ResizeSmooth(getImagem(), xLimiteNovo, yLimiteNovo));
	setCoordLimite(xLimiteNovo, yLimiteNovo);
}
*/
