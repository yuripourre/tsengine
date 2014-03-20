/*
 * PrincipalGui.cpp
 *
 *  Created on: 10/01/2010
 *      Author: Yuri
 *
 */

#include "PrincipalGui.h"
#include "../TSe.h"

PrincipalGui::PrincipalGui()
{
	tema = new Camada();
	tema->carregaImagem("gui/tema1.bmp",true);
	tamanho = 20;
	dirFonte = new Frase("arial.ttf");

	inicializa();
}

PrincipalGui::PrincipalGui(const char* caminhoTema,int tamanhoTema, const char* caminhoFonte)
{
	tema = new Camada();
	tema->carregaImagem(caminhoTema,true);
	tamanho = tamanhoTema;
	dirFonte = new Frase(caminhoFonte);

	inicializa();
}

void PrincipalGui::inicializa()
{
	idAtual = 0;
	//Nenhum componente ativo
	idAtivo = 0;

	inicial = new Componente();
	inicial->setX(0);

	final = new Componente();
	final->setX(2000);

	inicial->setProximo(final);
	final->setProximo(final);

	ativo = inicial;
}

PrincipalGui::~PrincipalGui()
{
	delete inicial;
	delete final;

	delete dirFonte;
	delete tema;

	for(it = l.begin(); it != l.end(); it++)
	{
		delete *it;
	}
	l.clear();
}

Camada* PrincipalGui::getTema()
{
	return tema;
}
const char* PrincipalGui::getDirFonte(void)
{
	return dirFonte->getConteudo().data();
}
int PrincipalGui::getTamanho()
{
	return tamanho;
}

int PrincipalGui::registra(Componente* componente){
	l.push_back(componente);
	componente->setID(l.size());
	return l.size();
}

void PrincipalGui::desenha(){
	for(it = l.begin(); it != l.end(); it++)
	{
		(*it)->desenha();
	}
}

void PrincipalGui::gerencia(){

	using tse::mouse;

	bool onMouse;

	mouse->setEstado(tse::MOUSE_NORMAL);

	for(it = l.begin(); it != l.end(); it++)
	{

		onMouse = mouse->sobreArea((*it)->getX(),(*it)->getY(),(*it)->getXLimite(),(*it)->getYLimite());

		if(mouse->getPressionado())
		{
			if(onMouse)
			{
				(*it)->clickSobre(mouse->getPressionado());
				setIDAtivo((*it)->getID());
				ativo = (*it);
				//Seleciona o ID
			}
			else
			{
				(*it)->clickFora(mouse->getPressionado());
				setIDAtivo(0);
			}
		}
		else
		{
			if(onMouse)
			{
				(*it)->sobMouse();
			}
			else
			{
				(*it)->semMouse();
			}
		}
		ativo->gerencia();
	}

}


void PrincipalGui::setIDAtivo(int id)
{
	idAtivo = id;
}
int PrincipalGui::getIDAtivo(void)
{
	return this->idAtivo;
}
void PrincipalGui::setAtivo(Componente* componente){
	componente->clickSobre(1);
	componente->setAparecendo(true);
	setIDAtivo(componente->getID());
	ativo = componente;
}
Componente* PrincipalGui::getInicial(void)
{
	return inicial;
}

void PrincipalGui::remove()
{
	l.clear();
}
