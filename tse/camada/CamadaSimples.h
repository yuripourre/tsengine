/*
 * CamadaSimples.h
 *
 *  Created on: 27/12/2009
 *      Author: Yuri
 */

#ifndef CAMADASIMPLES_H_
#define CAMADASIMPLES_H_

//#include "CamadaEstatica.h"
#include "../outros/SDL_Collide/SDL_collide.h"

class CamadaSimples{

protected:

	int x;
	int y;

public:
	CamadaSimples();
	CamadaSimples(int x, int y);
	CamadaSimples(int x, int y, int xLimite,int yLimite);
	virtual ~CamadaSimples();


	int getX() const;
	void setX(int x);

	int getY() const;
	void setY(int y);

	//int getXLimite() const;
	//void setXLimite(int xLimite);

	//int getYLimite() const;
	//void setYLimite(int yLimite);

	void setCoordenadas(int x, int y);
	//void setCoordLimite(int xLimite, int yLimite);

	//void desenhaSimples(int x,int y,int xImagem,int yImagem,int xLimite,int yLimite,SDL_Surface *destino);

};

#endif /* CAMADASIMPLES_H_ */
