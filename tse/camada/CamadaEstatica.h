/*
 * CamadaEstatica.h
 *
 *  Created on: 26/10/2009
 *      Author: Yuri
 */

#ifndef CAMADAESTATICA_H_
#define CAMADAESTATICA_H_

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

//==============================================================================
class CamadaEstatica {


protected:

	int xLimite;
	int yLimite;

	SDL_Surface *imagem;

public:
	CamadaEstatica();
	CamadaEstatica(const char* arquivo);
	CamadaEstatica(const char* arquivo, bool fundoRosa);

	virtual ~CamadaEstatica();

	//void liberaImagem();

	//int getAlpha(void);
	//void setAlpha(int valor);

	int getXLimite() const;
	int getYLimite() const;
	void setXLimite(int xLimite);
	void setYLimite(int yLimite);
	void setCoordLimite(int xLimite, int yLimite);

	SDL_Surface* getImagem();

	bool carregaImagem( const char* arquivo);

	void carregaImagemMemo( const char* arquivo);

	void carregaImagem( const char* arquivo, bool fundoRosa);


	void igualaImagem( SDL_Surface* imagem );
	void igualaImagem( CamadaEstatica* cam );
	//void iguala( SDL_Surface* imagem );

	bool retiraFundo(void);
	bool retiraFundoRGB(int r, int g, int b);

	SDL_Color getPixel(int x, int y);
	void gira(double angle);
	void giraSuave(double angle);

	void estica(int novaLargura, int novaAltura);
	void esticaSuave(int novaLargura, int novaAltura);

};

#endif /* CAMADAESTATICA_H_ */
