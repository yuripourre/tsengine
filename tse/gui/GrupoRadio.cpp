/*
 * GrupoRadio.cpp
 *
 *  Created on: 09/02/2010
 *      Author: Yuri Pourre
 */

#include "GrupoRadio.h"

GrupoRadio::GrupoRadio()
{
	elementoAtivo = 1;
}

GrupoRadio::~GrupoRadio()
{
	// TODO Auto-generated destructor
}

int GrupoRadio::getElementoAtivo()
{
	return elementoAtivo;
}
int* GrupoRadio::getIDAtivo()
{
	return &elementoAtivo;
}

void GrupoRadio::setElementoAtivo(int idElemento)
{
	elementoAtivo = idElemento;
}
//void GrupoRadio::setAtivo(RadioCustom* elemento)
//{
//	elementoAtivo = elemento->getID();
//}

