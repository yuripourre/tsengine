/*
 * Sessao.cpp
 *
 *  Created on: 27/10/2009
 *      Author: Yuri
 */

#include "Sessao.h"

Sessao::Sessao(int id)
{
	this->id = id;
}

void Sessao::desenha(){}
int Sessao::gerencia(){return id;}

Sessao::~Sessao()
{

}
