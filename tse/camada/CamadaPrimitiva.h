/*
 * CamadaPrimitiva.h
 *
 *  Created on: 27/12/2009
 *      Author: Yuri
 */

#ifndef CAMADAPRIMITIVA_H_
#define CAMADAPRIMITIVA_H_

#include "Camada.h"
#include "../outros/SDL_gfxPrimitives/SDL_gfxPrimitives.h"

class CamadaPrimitiva: public Camada {
//Ele não será filho de Camada estática.
private:

	SDL_Color corDifusa;
	int expessura;

	int tipo;

	bool aparecendo;

	void inicializa();

public:

	CamadaPrimitiva();
	CamadaPrimitiva(int tipo);

	CamadaPrimitiva(int x, int y);
	CamadaPrimitiva(int x, int y, int xLimite, int yLimite);
	CamadaPrimitiva(int x, int y, int xLimite, int yLimite,int tipo);

	virtual ~CamadaPrimitiva();

	void setCor(int r, int g, int b);
	void setCor(int r, int g, int b, int a);
	void setCor(SDL_Color cor);

	Uint32 getCorRGB(SDL_Surface* destino);

	//void CamadaPrimitiva::setAparecendo(bool aparecendo);
	//void CamadaPrimitiva::mudaAparecendo();

	//void desenha(SDL_Surface *destino);
	void desenhaPrimitiva();
	void desenhaPrimitiva(SDL_Surface *destino);




	//Using SDL_gfxPrimitives maded by A. Schiffler
	//Usando SDL_gfxPrimitives feita por A. Schiffler

	//Original Prototypes
	//Protótipos Originais
	/*
	 *
	--Horizontal line--

	DLLINTERFACE int hlineColor (SDL_Surface *dst, Sint16 x1, Sint16 x2, Sint16 y, Uint32 color);
	DLLINTERFACE int hlineRGBA (SDL_Surface *dst, Sint16 x1, Sint16 x2, Sint16 y, Uint8 r, Uint8 g, Uint8 b, Uint8 a);

	-- Vertical line --

	DLLINTERFACE int vlineColor (SDL_Surface *dst, Sint16 x, Sint16 y1, Sint16 y2, Uint32 color);
	DLLINTERFACE int vlineRGBA (SDL_Surface *dst, Sint16 x, Sint16 y1, Sint16 y2, Uint8 r, Uint8 g, Uint8 b, Uint8 a);

	-- Rectangle --

	DLLINTERFACE int rectangleColor (SDL_Surface *dst, Sint16 x1, Sint16 y1, Sint16 x2, Sint16 y2, Uint32 color);
	DLLINTERFACE int rectangleRGBA (SDL_Surface *dst, Sint16 x1, Sint16 y1, Sint16 x2, Sint16 y2, Uint8 r, Uint8 g, Uint8 b, Uint8 a);

	-- Filled rectangle (Box) --

	DLLINTERFACE int boxColor (SDL_Surface *dst, Sint16 x1, Sint16 y1, Sint16 x2, Sint16 y2, Uint32 color);
	DLLINTERFACE int boxRGBA (SDL_Surface *dst, Sint16 x1, Sint16 y1, Sint16 x2, Sint16 y2, Uint8 r, Uint8 g, Uint8 b, Uint8 a);

	-- Line --

	DLLINTERFACE int lineColor(SDL_Surface *dst, Sint16 x1, Sint16 y1, Sint16 x2, Sint16 y2, Uint32 color);
	DLLINTERFACE int lineRGBA (SDL_Surface *dst, Sint16 x1, Sint16 y1, Sint16 x2, Sint16 y2, Uint8 r, Uint8 g, Uint8 b, Uint8 a);

	-- AA Line --
	DLLINTERFACE int aalineColor (SDL_Surface *dst, Sint16 x1, Sint16 y1, Sint16 x2, Sint16 y2, Uint32 color);
	DLLINTERFACE int aalineRGBA (SDL_Surface *dst, Sint16 x1, Sint16 y1, Sint16 x2, Sint16 y2, Uint8 r, Uint8 g, Uint8 b, Uint8 a);

	-- Circle --

	DLLINTERFACE int circleColor(SDL_Surface *dst, Sint16 x, Sint16 y, Sint16 r, Uint32 color);
	DLLINTERFACE int circleRGBA (SDL_Surface *dst, Sint16 x, Sint16 y, Sint16 rad, Uint8 r, Uint8 g, Uint8 b, Uint8 a);

	-- AA Circle --

	DLLINTERFACE int aacircleColor(SDL_Surface *dst, Sint16 x, Sint16 y, Sint16 r, Uint32 color);
	DLLINTERFACE int aacircleRGBA (SDL_Surface *dst, Sint16 x, Sint16 y, Sint16 rad, Uint8 r, Uint8 g, Uint8 b, Uint8 a);

	-- Filled Circle --

	DLLINTERFACE int filledCircleColor(SDL_Surface *dst, Sint16 x, Sint16 y, Sint16 r, Uint32 color);
	DLLINTERFACE int filledCircleRGBA (SDL_Surface *dst, Sint16 x, Sint16 y, Sint16 rad, Uint8 r, Uint8 g, Uint8 b, Uint8 a);

	-- Ellipse --

	DLLINTERFACE int ellipseColor (SDL_Surface *dst, Sint16 x, Sint16 y, Sint16 rx, Sint16 ry, Uint32 color);
	DLLINTERFACE int ellipseRGBA (SDL_Surface *dst, Sint16 x, Sint16 y, Sint16 rx, Sint16 ry, Uint8 r, Uint8 g, Uint8 b, Uint8 a);

	-- AA Ellipse --

	DLLINTERFACE int aaellipseColor (SDL_Surface *dst, Sint16 x, Sint16 y, Sint16 rx, Sint16 ry, Uint32 color);
	DLLINTERFACE int aaellipseRGBA (SDL_Surface *dst, Sint16 x, Sint16 y, Sint16 rx, Sint16 ry, Uint8 r, Uint8 g, Uint8 b, Uint8 a);

	-- Filled Ellipse --

	DLLINTERFACE int filledEllipseColor (SDL_Surface *dst, Sint16 x, Sint16 y, Sint16 rx, Sint16 ry, Uint32 color);
	DLLINTERFACE int filledEllipseRGBA (SDL_Surface *dst, Sint16 x, Sint16 y, Sint16 rx, Sint16 ry, Uint8 r, Uint8 g, Uint8 b, Uint8 a);

	-- Polygon --

	DLLINTERFACE int polygonColor (SDL_Surface *dst, Sint16 *vx, Sint16 *vy, int n, Uint32 color);
	DLLINTERFACE int polygonRGBA (SDL_Surface *dst, Sint16 *vx, Sint16 *vy, int n, Uint8 r, Uint8 g, Uint8 b, Uint8 a);

	-- Filled Polygon --

	DLLINTERFACE int filledPolygonColor (SDL_Surface *dst, Sint16 *vx, Sint16 *vy, int n, int color);
	DLLINTERFACE int filledPolygonRGBA (SDL_Surface *dst, Sint16 *vx, Sint16 *vy, int n, Uint8 r, Uint8 g, Uint8 b, Uint8 a);

	-- 8x8 Characters/Strings --

	DLLINTERFACE int characterColor (SDL_Surface *dst, Sint16 x, Sint16 y, char c, Uint32 color);
	DLLINTERFACE int characterRGBA (SDL_Surface *dst, Sint16 x, Sint16 y, char c, Uint8 r, Uint8 g, Uint8 b, Uint8 a);
	DLLINTERFACE int stringColor (SDL_Surface *dst, Sint16 x, Sint16 y, char *c, Uint32 color);
	DLLINTERFACE int stringRGBA (SDL_Surface *dst, Sint16 x, Sint16 y, char *c, Uint8 r, Uint8 g, Uint8 b, Uint8 a);

	 */

	//Subscribing Methods
	//Sobrescrevendo Métodos


	/* Pixel */
	int pixelColorido(SDL_Surface* destino);
	//int pixelColorido();

	//int pixelRGBA(SDL_Surface *dst, Sint16 x, Sint16 y, Uint8 r, Uint8 g, Uint8 b, Uint8 a);

	/* Linha Horizontal */

	void linhaHColorida(SDL_Surface* destino);
	void linhaHColorida();
	//int hlineRGBA (SDL_Surface *dst, Sint16 x1, Sint16 x2, Sint16 y, Uint8 r, Uint8 g, Uint8 b, Uint8 a);

	/* Linha Vertical */

	void linhaVColorida(SDL_Surface* destino);
	void linhaVColorida();
	//int vlineRGBA (SDL_Surface *dst, Sint16 x, Sint16 y1, Sint16 y2, Uint8 r, Uint8 g, Uint8 b, Uint8 a);

	/* Retângulo */

	void retanguloColorido(SDL_Surface* destino);
	void retanguloColorido();
	//int rectangleRGBA (SDL_Surface *dst, Sint16 x1, Sint16 y1, Sint16 x2, Sint16 y2, Uint8 r, Uint8 g, Uint8 b, Uint8 a);

	/* Retângule Preenchido(Box) */

	void boxColorida(SDL_Surface* destino);
	void boxColorida();
	//int boxRGBA (SDL_Surface *dst, Sint16 x1, Sint16 y1, Sint16 x2, Sint16 y2, Uint8 r, Uint8 g, Uint8 b, Uint8 a);

	/* Linha */

	int linhaColorida(SDL_Surface* destino);
	//int lineRGBA (SDL_Surface *dst, Sint16 x1, Sint16 y1, Sint16 x2, Sint16 y2, Uint8 r, Uint8 g, Uint8 b, Uint8 a);

	/* Linha AA */
	int linhaAAColorida(SDL_Surface* destino);
	//int aalineRGBA (SDL_Surface *dst, Sint16 x1, Sint16 y1, Sint16 x2, Sint16 y2, Uint8 r, Uint8 g, Uint8 b, Uint8 a);

	/* Círculo */

	int circuloColorido(SDL_Surface* destino);
	//int circleRGBA (SDL_Surface *dst, Sint16 x, Sint16 y, Sint16 rad, Uint8 r, Uint8 g, Uint8 b, Uint8 a);

	/* Círculo AA */

	int circuloAAColorido(SDL_Surface* destino);
	//int aacircleRGBA (SDL_Surface *dst, Sint16 x, Sint16 y, Sint16 rad, Uint8 r, Uint8 g, Uint8 b, Uint8 a);

	/* Filled Circle */
	int circuloPreenchidoColorido(SDL_Surface* destino);
	//int filledCircleRGBA (SDL_Surface *dst, Sint16 x, Sint16 y, Sint16 rad, Uint8 r, Uint8 g, Uint8 b, Uint8 a);

	/* Ellipse */
	int elipseColorida(SDL_Surface* destino);
	//int ellipseRGBA (SDL_Surface *dst, Sint16 x, Sint16 y, Sint16 rx, Sint16 ry, Uint8 r, Uint8 g, Uint8 b, Uint8 a);

	/* AA Ellipse */
	int elipseAAColorida(SDL_Surface* destino);
	//int aaellipseColor (SDL_Surface *dst, Sint16 x, Sint16 y, Sint16 rx, Sint16 ry, Uint32 color);
	//int aaellipseRGBA (SDL_Surface *dst, Sint16 x, Sint16 y, Sint16 rx, Sint16 ry, Uint8 r, Uint8 g, Uint8 b, Uint8 a);

	/* Filled Ellipse */
	int elipsePreenchidaColorida(SDL_Surface* destino);
	//int filledEllipseColor (SDL_Surface *dst, Sint16 x, Sint16 y, Sint16 rx, Sint16 ry, Uint32 color);
	//int filledEllipseRGBA (SDL_Surface *dst, Sint16 x, Sint16 y, Sint16 rx, Sint16 ry, Uint8 r, Uint8 g, Uint8 b, Uint8 a);

	/* Polygon */
	int poligonoColorido (Sint16 *vx, Sint16 *vy, int n);
	//int polygonColor (SDL_Surface *dst, Sint16 *vx, Sint16 *vy, int n, Uint32 color);
	//int polygonRGBA (SDL_Surface *dst, Sint16 *vx, Sint16 *vy, int n, Uint8 r, Uint8 g, Uint8 b, Uint8 a);

	/* Filled Polygon */
	int poligonoPreenchidoColorido (Sint16 *vx, Sint16 *vy, int n);
	//int filledPolygonColor (SDL_Surface *dst, Sint16 *vx, Sint16 *vy, int n, int color);
	//int filledPolygonRGBA (SDL_Surface *dst, Sint16 *vx, Sint16 *vy, int n, Uint8 r, Uint8 g, Uint8 b, Uint8 a);

	/* 8x8 Characters/Strings */
	int caracterColorido (SDL_Surface* destino,char c);
	int stringColorida (SDL_Surface* destino,char *c);

	//int characterColor (SDL_Surface *dst, Sint16 x, Sint16 y, char c, Uint32 color);
	//int characterRGBA (SDL_Surface *dst, Sint16 x, Sint16 y, char c, Uint8 r, Uint8 g, Uint8 b, Uint8 a);
	//int stringColor (SDL_Surface *dst, Sint16 x, Sint16 y, char *c, Uint32 color);
	//int stringRGBA (SDL_Surface *dst, Sint16 x, Sint16 y, char *c, Uint8 r, Uint8 g, Uint8 b, Uint8 a);

};

#endif /* CAMADAPRIMITIVA_H_ */
