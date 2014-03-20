/*
 * BotaoCustom.cpp
 *
 *  Created on: 24/01/2010
 *      Author: Yuri Pourre
 */

#include "BotaoCustom.h"
#include "../TSe.h"

//using namespace peste;


BotaoCustom::BotaoCustom(int x, int y,const char* normal,const char* sobMouse,const char* clicado, bool fundoRosa)
{

	Componente();

	setCoordenadas(x,y);
	//setCoordLimite(xLimite, yLimite);

	camNormal = new CamadaEstatica(normal);
	camSobMouse = new CamadaEstatica(sobMouse);
	camClicado = new CamadaEstatica(clicado);

	if(fundoRosa)
	{
		camNormal->retiraFundo();
		camSobMouse->retiraFundo();
		camClicado->retiraFundo();
	}

	igualaImagem(camNormal->getImagem());

	pressionado = false;

	registra();

}

void BotaoCustom::setBotao(int x, int y,int xLimite, int yLimite,const char* normal,const char* sobMouse,const char* clicado)
{

	setCoordenadas(x,y);
	//setCoordLimite(xLimite, yLimite);

	camNormal = new CamadaEstatica(normal);
	camSobMouse = new CamadaEstatica(sobMouse);
	camClicado = new CamadaEstatica(clicado);

	igualaImagem(camNormal->getImagem());

	pressionado = false;

}

BotaoCustom::BotaoCustom()
{
	Componente();

	setCoordenadas(0,0);
	setCoordLimite(0,0);

	//camNormal = new CamadaEstatica();
	//camSobMouse = new CamadaEstatica();
	//camClicado = new CamadaEstatica();

	pressionado = false;

	registra();
}

BotaoCustom::~BotaoCustom()
{
	// TODO Auto-generated destructor stub
}

/*
void BotaoCustom::setRotulo(const char* conteudo)
{
	rotulo = new CamadaTexto(conteudo);
	rotulo->setTamanhoFonte(gui->getTamanho()/2);
	rotulo->carregaFonte(gui->getDirFonte());
	rotulo->escreve();

	setCoordLimite(gui->getTamanho()+rotulo->getXLimite(),gui->getTamanho());

	rotulo->centralizaX(getX(),getX()+getXLimite());
	rotulo->centralizaY(getY(),getY()+getYLimite());
}
 */

void BotaoCustom::desenha()
{

	if(getAparecendo())
	{
		SDL_Rect rect;

		rect.x = getX();
		rect.y = getY();

		SDL_Rect rect2;

		rect2.x = 0;
		rect2.y = 0;
		rect2.w = getXLimite();
		rect2.h = getYLimite();


		SDL_BlitSurface(getImagem(), &rect2, tse::tela, &rect);
	}

}

void BotaoCustom::gerencia()
{
	//passa o valor do click sei lá.
}

void BotaoCustom::sobMouse()
{
	igualaSobMouse();

	pressionado = false;
}
void BotaoCustom::semMouse()
{
	igualaNormal();

	pressionado = false;
}

void BotaoCustom::clickSobre(int press)
{
	igualaClicado();

	pressionado = true;
}
void BotaoCustom::clickFora(int press)
{
	igualaNormal();

	pressionado = false;
}

bool BotaoCustom::getPressionado()
{
	return pressionado;
}
bool BotaoCustom::getTrava()
{
	return trava;
}

void BotaoCustom::setTrava(bool trava)
{
	this->trava = trava;
}
void BotaoCustom::setPressionado(bool press)
{
	pressionado = press;
}

void BotaoCustom::igualaNormal(void)
{
	if(getImagem()!=camNormal->getImagem())
	{
		igualaImagem(camNormal->getImagem());
	}
}
void BotaoCustom::igualaSobMouse(void)
{
	if(getImagem()!=camSobMouse->getImagem())
	{
		igualaImagem(camSobMouse->getImagem());
	}
}
void BotaoCustom::igualaClicado(void)
{
	if(getImagem()!=camClicado->getImagem())
	{
		igualaImagem(camClicado->getImagem());
	}
}
