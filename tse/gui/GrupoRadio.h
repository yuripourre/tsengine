/*
 * GrupoRadio.h
 *
 *  Created on: 09/02/2010
 *      Author: Yuri Pourre
 */

#ifndef GRUPORADIO_H_
#define GRUPORADIO_H_

class GrupoRadio {

private:

	int elementoAtivo;

public:

	GrupoRadio();
	virtual ~GrupoRadio();

	int getElementoAtivo();
	int* getIDAtivo();
	void setElementoAtivo(int idElemento);
	//void setAtivo(RadioCustom* elemento);


	//void insereElemento(BotaoCustom* elemento);

};

#endif /* GRUPORADIO_H_ */
