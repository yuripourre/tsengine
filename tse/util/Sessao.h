/*
 * Sessao.h
 *
 *  Created on: 27/10/2009
 *      Author: Yuri
 */

#ifndef SESSAO_H_
#define SESSAO_H_

//#include "Principal.h"

class Sessao
{

protected:
	Sessao(int id);
	int id;

public:

	virtual void desenha();
	virtual int gerencia();

	virtual ~Sessao();



};

#endif /* SESSAO_H_ */
