/*
 * Botao.h
 *
 *  Created on: 10/01/2010
 *      Author: Yuri
 */

#ifndef BOTAO_H_
#define BOTAO_H_

#include "../camada/CamadaTexto.h"
#include "Componente.h"


class Botao : public Componente{

private:

	CamadaTexto* rotulo;
	bool pressionado;

public:

	Botao();
	Botao(const char* conteudo);
	Botao(int x, int y, const char* conteudo);
	virtual ~Botao();

	void inicializar(void);

	void desenha();
	void gerencia();

	void setRotulo(const char* conteudo);
	bool getPressionado(void);

	void sobMouse();
	void semMouse();
	void clickSobre(int press);
	void clickFora(int press);

};

#endif /* BOTAO_H_ */
