/*
 * Botao.cpp
 *
 *  Created on: 10/01/2010
 *      Author: Yuri
 *
 */

#include "Botao.h"
#include "../TSe.h"
using tse::gui;

Botao::Botao()
{
	inicializar();

	setCoordenadas(0,0);
	setCoordLimite(gui->getTamanho(),gui->getTamanho());

	rotulo = new CamadaTexto();
}
Botao::Botao(const char* conteudo)
{
	inicializar();

	setCoordenadas(300,300);

	rotulo = new CamadaTexto(conteudo);
	rotulo->setTamanhoFonte(gui->getTamanho()/2);
	rotulo->carregaFonte(gui->getDirFonte());
	rotulo->escreve();

	setCoordLimite(gui->getTamanho()+rotulo->getXLimite(),gui->getTamanho());

	rotulo->centralizaX(getX(),getX()+getXLimite());
	rotulo->centralizaY(getY(),getY()+getYLimite());

}
Botao::Botao(int x, int y, const char* conteudo)
{
	inicializar();

	setCoordenadas(x,y);

	rotulo = new CamadaTexto(conteudo);
	rotulo->setTamanhoFonte(gui->getTamanho()/2);
	rotulo->carregaFonte(gui->getDirFonte());
	rotulo->escreve();

	setCoordLimite(gui->getTamanho()+rotulo->getXLimite(),gui->getTamanho());

	rotulo->centralizaX(getX(),getX()+getXLimite());
	rotulo->centralizaY(getY(),getY()+getYLimite());

}


Botao::~Botao()
{
	// TODO Auto-generated destructor stub
}

void Botao::inicializar()
{
	Componente();

	setCoordImagem(0,0);
	pressionado = false;

	registra();
}

void Botao::setRotulo(const char* conteudo)
{
	rotulo = new CamadaTexto(conteudo);
	rotulo->setTamanhoFonte(gui->getTamanho()/2);
	rotulo->carregaFonte(gui->getDirFonte());
	rotulo->escreve();

	setCoordLimite(gui->getTamanho()+rotulo->getXLimite(),gui->getTamanho());

	rotulo->centralizaX(getX(),getX()+getXLimite());
	rotulo->centralizaY(getY(),getY()+getYLimite());
}

void Botao::desenha()
{
	using tse::tela;

	int i;
	int metadeGui = gui->getTamanho()/2;
	int metadeBotao = getXLimite()/2;

	//Início
	gui->getTema()->desenhaSimples(getX(),getY(),getXImagem(),getYImagem(),metadeGui-1,gui->getTamanho(),tela);

	//Meio
	for(i=0;i<(metadeBotao-metadeGui+1);i++)
	{
		gui->getTema()->desenhaSimples((getX()+metadeGui-1)+i,getY(),getXImagem()+metadeGui-1,getYImagem(),1,gui->getTamanho(),tela);
		gui->getTema()->desenhaSimples((getX()+metadeBotao)+i,getY(),getXImagem()+metadeGui,getYImagem(),1,gui->getTamanho(),tela);
	}
	//Se a fonte for ímpar
	if(getXLimite()%2)
	{
		gui->getTema()->desenhaSimples((getX()+metadeBotao)+i,getY(),getXImagem()+metadeGui,getYImagem(),1,gui->getTamanho(),tela);
	}

	//Fim
	gui->getTema()->desenhaSimples(getX()+getXLimite()-metadeGui+1,getY(),getXImagem()+metadeGui+1,getYImagem(),metadeGui-1,gui->getTamanho(),tela);

	rotulo->desenha();
}

void Botao::gerencia()
{
	//passa o valor do click sei lá.
}

void Botao::sobMouse()
{
	if(getXImagem()!=gui->getTamanho())
	{
		setXImagem(gui->getTamanho());
	}
	if(pressionado)
	{
		rotulo->centralizaX(getX(),getX()+getXLimite());
		rotulo->centralizaY(getY(),getY()+getYLimite());
		pressionado = false;
	}
}
void Botao::semMouse()
{
	if(pressionado)
	{
		rotulo->centralizaX(getX(),getX()+getXLimite());
		rotulo->centralizaY(getY(),getY()+getYLimite());
		pressionado = false;
	}

	if(getXImagem())
	{
		setXImagem(0);
	}

}

void Botao::clickSobre(int press)
{
	if(getXImagem()!=gui->getTamanho()*2)
	{
		setXImagem(gui->getTamanho()*2);
	}
	if(!pressionado)
	{
		rotulo->setX(rotulo->getX()+1);
		pressionado = true;
	}
}
void Botao::clickFora(int press)
{
	if(getXImagem())
	{
		setXImagem(0);
	}
}
bool Botao::getPressionado(void)
{
	return pressionado;
}
