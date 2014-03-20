/*
 * Tela.cpp
 *
 *  Created on: 21/12/2009
 *      Author: Yuri Pourre
 */

#include "Tela.h"
//Controle de FPS na Barra de Título
#include "../util/Util.h"

Tela::Tela()
{
	largura = 800;
	altura = 600;

	bitsdeCor = 32;

	//SDL_WM_SetIcon(SDL_LoadBMP("icon.bmp"), NULL);
	//icon = new CamadaEstatica("gui/icone.bmp");
	//SDL_WM_SetIcon(icon->getImagem(), NULL);

	Inicializa();
}

Tela::Tela(int width, int height)
{
	largura = width;
	altura = height;
	bitsdeCor = 32;

	Inicializa();
}

void Tela::Inicializa()
{
	posX = 200;
	posY = 100;

	center = true;
	fullscreen = false;

	titulo = new Frase();

	criaJanela();
	//SDL_Surface *icone=IMG_Load("gui/icone.bmp");
	//SDL_WM_SetIcon(icone, 0);

	//	icon = new CamadaEstatica("gui/icone.bmp");
	//SDL_WM_SetIcon(icon->getImagem(), NULL);

	//SDL_Surface *icone=IMG_Load("gui/icone.bmp");
	//SDL_WM_SetIcon(icone, 0);

	titulo = new Frase("Aplicativo SDL");
	SDL_WM_SetCaption( titulo->getConteudo().c_str() , NULL );

	//SDL_Surface *icone=IMG_Load("icone.bmp");
	//SDL_WM_SetIcon(icone, 0);
	//SDL_WM_SetCaption("Meu Titulo", 0);
}

void Tela::atualiza()
{
	SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
	SDL_Flip(screen);
}

SDL_Surface* Tela::getScreen()
{
	return screen;
}

int Tela::getAltura()
{
	return altura;
}
int Tela::getLargura()
{
	return largura;
}

void Tela::setTamanho(int largura, int altura)
{
	this->largura = largura;
	this->altura = altura;

	criaJanela();
}

void Tela::criaJanela()
{
	if(fullscreen!=true)
	{
		screen = SDL_SetVideoMode( largura, altura, bitsdeCor, SDL_SWSURFACE );

		/*
		if(center)
		{
			SDL_putenv("SDL_VIDEO_CENTERED=1");
		}
		else
		{
			string video = "SDL_VIDEO_WINDOW_POS=";
			video+=itos(posX);
			video+=",";
			video+=itos(posY);

			SDL_putenv(video.c_str());
		}
		*/
	}
	else
	{
		screen = SDL_SetVideoMode( largura, altura, bitsdeCor, SDL_FULLSCREEN );
	}

	if( screen == NULL )
	{
		//LOG
	}
}

Frase* Tela::getTitulo()
{
	return titulo;
}

void Tela::setFullScreen(bool fullscreen){
	this->fullscreen = fullscreen;
	criaJanela();
}


void Tela::setTitulo(const char* novoTitulo)
{
	titulo->setConteudo(novoTitulo);
	SDL_WM_SetCaption( titulo->getConteudo().data() , NULL );
}

Tela::~Tela()
{

	if (screen!=NULL)
	{
		SDL_FreeSurface(screen);
	}

	delete icon;
	delete titulo;
}
