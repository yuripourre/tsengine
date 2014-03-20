/*
 * Elemento.h
 *
 *  Created on: 24/02/2010
 *      Author: Yuri Pourre
 */

#ifndef ELEMENTO_H_
#define ELEMENTO_H_

#include "../camada/CamadaTexto.h"
#include "../camada/Camada.h"

class Elemento
{

private:

	CamadaTexto* rotulo;

	Elemento* anterior;
	Elemento* proximo;

	Camada* fundo;//Box Colorida

public:

	Elemento(const char* rotulo);
	Elemento(const char* rotulo,int tamanhoFonte);
	Elemento(const char* rotulo,int tamanhoFonte,const char* arquivoFonte);

	void inicializar();

	Camada* getFundo();

	void setProximo(Elemento* proximo);
	void setAnterior(Elemento* anterior);

	virtual ~Elemento();

};

#endif /* ELEMENTO_H_ */
