/*
 * Coordenada.h
 *
 *  Created on: 08/11/2009
 *      Author: Yuri
 */

#ifndef COORDENADA_H_
#define COORDENADA_H_

class Coordenada
{

private:
	int x;
	int y;

public:
	Coordenada();
	Coordenada(int x, int y);
	virtual ~Coordenada();

	void setX(int x);
	void setY(int y);
	int getX(void) const;
	int getY(void) const;
	void setCoordenadas(int x,int y);
};

#endif
