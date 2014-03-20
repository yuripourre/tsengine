/*
 * Personagem.h
 *
 *  Created on: 29/10/2009
 *      Author: Yuri
 */

#ifndef _PERSONAGEM_H_
#define _PERSONAGEM_H_

#include "../camada/CamadaMovel.h"

class Personagem : public CamadaMovel{

protected:
	char estado;
	char direcao;

public:
	Personagem();
	virtual ~Personagem();

	void setDirecao(char direcao);
	void setEstado(char estado);

	char getEstado(void);
	char getDirecao(void);

	//Específicos
	void gerencia(void);
	//Vê o evento e direção e chama funções.

	void anda(void);
	void para(void);

	enum estados{

		ESTADO_ANDANDO = 'w',//Walking
		ESTADO_ATACANDO = 'a', //Attacking
		ESTADO_APANHANDO = 'h', //Hitted
		ESTADO_ESPERANDO = 'n', //Waiting(None)
		ESTADO_ESPECIAL = 's', //Special
		ESTADO_MORRENDO = 'd' //Dying
	};

	enum direcoes{

		DIRECAO_LESTE = 'l',
		DIRECAO_OESTE = 'o',
		DIRECAO_NORTE = 'n',
		DIRECAO_SUL = 's',

		DIRECAO_NORDESTE = 'e',
		DIRECAO_NOROESTE = 'w',
		DIRECAO_SUDOESTE = 'h',
		DIRECAO_SUDESTE = 't',

	};

};

#endif /* PERSONAGEM_H_ */
