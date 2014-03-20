/*
 * Personagem.cpp
 *
 *  Created on: 29/10/2009
 *      Author: Yuri
 */

#include "Personagem.h"

Personagem::Personagem()
{

}

Personagem::~Personagem()
{
	// TODO Auto-generated destructor stub
}

void Personagem::setDirecao(char direcao)
{
	this->direcao = direcao;
}
void Personagem::setEstado(char estado)
{
	this->estado = estado;
}

char Personagem::getEstado(void)
{
	return estado;
}
char Personagem::getDirecao(void)
{
	return direcao;
}
