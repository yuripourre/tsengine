/*
 * Lista.cpp
 *
 *  Created on: 11/03/2010
 *      Author: Yuri Pourre
 */

#include "Lista.h"

Lista::Lista()
{
	//tamanhoFonte = gui->fonte;
	numeroItens = 0;

	inicial = new Elemento("");
	final = new Elemento("");
}

Lista::~Lista()
{
	// TODO Auto-generated destructor stub
}

void Lista::adiciona(const char* novoItem)
{
	Elemento* aux = new Elemento(novoItem);
	aux->setAnterior(inicial);
	aux->setProximo(final);
}
