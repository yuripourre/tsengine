/*
 * CamadaEstatica.cpp
 *
 *  Created on: 26/10/2009
 *      Author: Yuri
 */

#include "CamadaEstatica.h"
#include "../outros/SDL_Bilinear/SDL_bilinear.h"

CamadaEstatica::CamadaEstatica()
{
	imagem = NULL;
	xLimite = 0;
	yLimite = 0;
}

CamadaEstatica::CamadaEstatica(const char* arquivo)
{
	carregaImagem(arquivo);
}

CamadaEstatica::CamadaEstatica(const char* arquivo, bool fundoRosa)
{
	carregaImagem(arquivo);
	retiraFundo();
}

CamadaEstatica::~CamadaEstatica()
{
	if(imagem!=NULL)
	{
		SDL_FreeSurface(imagem);
	}
}
/*
void CamadaEstatica::liberaImagem()
{
	if(imagem!=NULL)
	{
		SDL_FreeSurface(imagem);
	}
}
 */
int CamadaEstatica::getXLimite() const
{
	return xLimite;
}
int CamadaEstatica::getYLimite() const
{
	return yLimite;
}
void CamadaEstatica::setXLimite(int xLimite)
{
	this->xLimite = xLimite;
}
void CamadaEstatica::setYLimite(int yLimite)
{
	this->yLimite = yLimite;
}

void CamadaEstatica::setCoordLimite(int xLimite, int yLimite)
{
	this->xLimite = xLimite;
	this->yLimite = yLimite;
}

SDL_Surface* CamadaEstatica::getImagem()
{
	return imagem;
}

bool CamadaEstatica::carregaImagem( const char* arquivo )
{
	//gerenciadorMemo->remove(arquivo);
	//igualaImagem(gerenciadorMemo->addImagem(arquivo));
	//imagem = gerenciadorMemo->addImagem(arquivo);

	if(arquivo=='\0')
			return false;

	SDL_Surface* imagemCarregada = NULL;
	SDL_Surface* imagemOtimizada = NULL;

		imagemCarregada = IMG_Load( arquivo );

		if( imagemCarregada != NULL )
		{
			//ImagemOtimizada = SDL_DisplayFormat( ImagemCarregada );

			imagemOtimizada = SDL_ConvertSurface( imagemCarregada , imagemCarregada->format, SDL_SWSURFACE);

			SDL_FreeSurface( imagemCarregada );
		}
		else
		{
			return false;
		}

		imagem = imagemOtimizada;

	if(xLimite==0)
		xLimite = imagem->w;
	if(yLimite==0)
		yLimite = imagem->h;

	return true;

}


void CamadaEstatica::carregaImagemMemo( const char* arquivo )
{
	//imagem = gerenciadorMemo->addImagem(arquivo);
}


void CamadaEstatica::carregaImagem( const char* arquivo , bool fundoRosa)
{
	carregaImagem(arquivo);
	retiraFundo();
}

void CamadaEstatica::igualaImagem( CamadaEstatica* cam )
{
	igualaImagem(cam->getImagem());
}

void CamadaEstatica::igualaImagem( SDL_Surface* imagem )
{
	this->imagem = imagem;

	if(xLimite==0)
	{
		xLimite = this->imagem->w;
	}

	if(yLimite==0)
	{
		yLimite = this->imagem->h;
	}

}


bool CamadaEstatica::retiraFundo(void)
{
	if(getImagem() != NULL)
	{

		SDL_SetColorKey(imagem, SDL_SRCCOLORKEY | SDL_RLEACCEL, SDL_MapRGB(imagem->format, 0xFF, 0x00, 0xFF));

		return true;

	}
	return false;
}

bool CamadaEstatica::retiraFundoRGB(int r, int g, int b)
{
	if(imagem != NULL)
	{

		SDL_SetColorKey(imagem, SDL_SRCCOLORKEY | SDL_RLEACCEL, SDL_MapRGB(imagem->format, r, g, b));

		return true;
	}
	return false;
}

SDL_Color CamadaEstatica::getPixel(int x, int y)
{
    int bpp = imagem->format->BytesPerPixel;
    SDL_Color color;
    Uint32 tmp;

    Uint8 *p = (Uint8 *)imagem->pixels + y * imagem->pitch + x * bpp;

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

    SDL_GetRGB(tmp, imagem->format, &color.r, &color.g, &color.b);

    return color;
}


void CamadaEstatica::gira(double angle){
	imagem = SDL_Rotate(imagem, angle);
	xLimite = imagem->w;
	yLimite = imagem->h;
}
void CamadaEstatica::giraSuave(double angle){
	imagem = SDL_RotateSmooth(imagem, angle);
	xLimite = imagem->w;
	yLimite = imagem->h;
}
void CamadaEstatica::estica(int novaLargura, int novaAltura){
	imagem = SDL_Resize(imagem, novaLargura, novaAltura);
	xLimite = imagem->w;
	yLimite = imagem->h;
}
void CamadaEstatica::esticaSuave(int novaLargura, int novaAltura){
	imagem = SDL_ResizeSmooth(imagem, novaLargura, novaAltura);
	xLimite = imagem->w;
	yLimite = imagem->h;
}
