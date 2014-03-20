/*
 * GerenciadorCamadas.h
 *
 *  Created on: Nov 24, 2010
 *      Author: Yuri
 */

#ifndef GERENCIADORCAMADAS_H_
#define GERENCIADORCAMADAS_H_
#include <list>
#include "Camada.h"

class GerenciadorCamadas {

private:
	std::list<Camada*> l;

	bool deleteTudo( Camada* cam )
	{
		delete cam;
		return true;
	}

public:
	GerenciadorCamadas();

	~GerenciadorCamadas(){
		removeTudo();
	}

	void adiciona(Camada* cam){
		this->l.push_back(cam);
	}

	void removeTudo(){
		l.remove_if( deleteTudo );
	}

};

#endif /* GERENCIADORCAMADAS_H_ */
