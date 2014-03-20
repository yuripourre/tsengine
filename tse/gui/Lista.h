/*
 * Lista.h
 *
 *  Created on: 11/03/2010
 *      Author: Yuri Pourre
 */

#ifndef LISTA_H_
#define LISTA_H_

#include "Elemento.h"

class Lista
{
private:

	int tamanhoFonte;
	int numeroItens;

	Elemento* inicial;
	Elemento* final;

public:
	Lista();
	virtual ~Lista();

	void adiciona(const char* novoItem);

};

#endif /* LISTA_H_ */
