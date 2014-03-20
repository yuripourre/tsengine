/*
 * Camada.h
 *
 *
 *      Author: Yuri
 */

#ifndef CAMADA_H_
#define CAMADA_H_

#include "CamadaSimples.h"
#include "CamadaEstatica.h"

class Camada : public CamadaEstatica{

protected:

	int x;
	int y;

	int xImagem;
	int yImagem;

	bool aparecendo;

	int alpha;

public:

	Camada();

	Camada(int x, int y);
	Camada(int x, int y, int xLimite, int yLimite);
	Camada(int x, int y, int xLimite, int yLimite, int xImagem, int yImagem);

	~Camada();

	int getX() const;
	void setX(int x);

	int getY() const;
	void setY(int y);


	int getAlpha(void);
	void setAlpha(int valor);

	int getXImagem();
	int getYImagem();

	bool getAparecendo();
	int getAcionado();

	void setCoordenadas(int x, int y);

	void setXImagem(int dentroX);
	void setYImagem(int dentroY);

	void setCoordImagem(int dentroX, int dentroY);
	void setCamada(int x, int y, int xLimite, int yLimite, int xImagem, int yImagem);

	void setAparecendo(bool aparecendo);
	void mudaAparecendo();

	virtual void desenha(SDL_Surface *destino);
	virtual void desenha();
	void desenhaSimples(int x,int y,int xImagem,int yImagem,int xLimite,int yLimite,SDL_Surface *destino);

	//Funções úteis
	int centralizaX(int xInicial, int xFinal);
	int centralizaY(int yInicial, int yFinal);

	void centralizaX(Camada *b);
	void centralizaY(Camada *b);
	void centraliza(Camada *b);

	void setOffsetX(int offset){
		x += offset;
	}
	void setOffsetY(int offset){
		y += offset;
	}


	bool colideRetangular(Camada* b);
	bool colideCircular(Camada* b);

	bool colideIso(Camada *b){
		int m = b->getY()/2;
		if(b->getY()<m)
			b->setY(b->getY()-m);

		if(b->getX()>m+1+2*y)
			return false;
		else if(b->getX()<m-1-2*b->getY())
			return false;
		else
			return true;
	}

	void* operator new(size_t x) {

		void *aux = malloc( x );

		//gerenciador.adiciona(this);
		//if( aux == NULL )
			//throw bad_alloc;

		return aux;
	}

};


#endif



