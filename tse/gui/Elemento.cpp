/*
 * Elemento.cpp
 *
 *  Created on: 24/02/2010
 *      Author: Yuri Pourre
 */

#include "Elemento.h"
#include "../TSe.h"
using tse::gui;

Elemento::Elemento(const char* rotulo)
{
	this->rotulo = new CamadaTexto(rotulo,gui->getTamanho()/2,gui->getDirFonte());
	inicializar();
}

Elemento::Elemento(const char* rotulo,int tamanhoFonte)
{
	this->rotulo = new CamadaTexto(rotulo,tamanhoFonte,gui->getDirFonte());
	inicializar();
}

Elemento::Elemento(const char* rotulo,int tamanhoFonte,const char* arquivoFonte)
{
	this->rotulo = new CamadaTexto(rotulo,tamanhoFonte,arquivoFonte);
	inicializar();
}

Elemento::~Elemento()
{
	delete rotulo;
	delete fundo;
}

void Elemento::inicializar()
{
	fundo = new Camada();
}

Camada* Elemento::getFundo()
{
	return fundo;
}

void Elemento::setAnterior(Elemento* anterior)
{
	this->anterior = anterior;
}
void Elemento::setProximo(Elemento* proximo)
{
	this->proximo = proximo;
}
