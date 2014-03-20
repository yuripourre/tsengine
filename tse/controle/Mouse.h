/*
 * Mouse.h
 *
 *
 *      Author: Yuri
 */

#ifndef _MOUSE_H_
#define _MOUSE_H_

#include "../camada/Camada.h"

class Mouse: public Camada{

private:

	int pressionado;

	bool rodinhaCima;
	bool rodinhaBaixo;

	char estado;

	int xCursor;
	int yCursor;

	CamadaEstatica* normal;
	CamadaEstatica* texto;
	CamadaEstatica* ocupado;
	CamadaEstatica* ajuda;
	CamadaEstatica* mover;

	CamadaEstatica* vertical;
	CamadaEstatica* horizontal;
	CamadaEstatica* diagonalP;
	CamadaEstatica* diagonalS;

	CamadaEstatica* extra;


public:

	Mouse();
	virtual ~Mouse();

	bool sobreBox(Camada* b);
	bool sobreIso(Camada* b);
	bool sobreCor(Camada* b, int red, int green, int blue);
	bool sobreArea(int xq , int yq, int limxq, int limyq);
	bool sobreCirculo(Camada *b);

	int getPressionado(void);
	void setPressionado(int e);

	bool getRodinhaCima(void);
	bool getRodinhaBaixo(void);

	void setRodinhaCima(bool press);
	void setRodinhaBaixo(bool press);

	void setEstado(int estado);
	void setCursor(CamadaEstatica* cursor);
	void normalCursor();


	bool sobPixel(Camada* cam, int r, int g, int b)
	{
		if(!sobreBox(cam)){
			return false;
		}

		//Teste
		//int bx = b->getX()+(x-b->getX())+b->getXImagem();
		int bx = cam->getX()+(x-cam->getX());
		int by = cam->getY()+(y-cam->getY());

		SDL_Color cor = getPixel( bx, by, cam->getImagem());

		if((cor.r==r)&&
		(cor.g==g)&&
		(cor.b==b)){
			return false;
		}
		else{
			return true;
		}

	}
	SDL_Color getPixel(int x, int y,SDL_Surface *TMPSurface)
	{
		int bpp = TMPSurface->format->BytesPerPixel;
		SDL_Color color;
		Uint32 tmp;

		/* Aqui p é o endereço para o pixel que queremos recuperar */
		Uint8 *p = (Uint8 *)TMPSurface->pixels + y * TMPSurface->pitch + x * bpp;

		switch(bpp) {
		case 1:
			tmp = *p;
			break;

		case 2:
			tmp = *(Uint16 *)p;
			break;
		case 3:
			if(SDL_BYTEORDER == SDL_BIG_ENDIAN)
			{
				tmp = p[0] << 16 | p[1] << 8 | p[2];
			}else{
				tmp = p[0] | p[1] << 8 | p[2] << 16;
			}

			break;
		case 4:
			tmp = *(Uint32 *)p;
			break;
		default:
			tmp = 0;
			break;
		}

		SDL_GetRGB(tmp, TMPSurface->format, &color.r, &color.g, &color.b);

		return color;
	}

};

#endif
