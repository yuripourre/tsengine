/*
 * BotaoCustom.h
 *
 *  Created on: 24/01/2010
 *      Author: Yuri
 */

#ifndef BOTAOCUSTOM_H_
#define BOTAOCUSTOM_H_

#include "../camada/CamadaTexto.h"
#include "Componente.h"


class BotaoCustom : public Componente{

private:

	bool pressionado;

	bool trava;

	CamadaEstatica* camNormal;
	CamadaEstatica* camSobMouse;
	CamadaEstatica* camClicado;


public:

	BotaoCustom();

	BotaoCustom(int x, int y,const char* normal,const char* sobMouse,const char* clicado,bool fundoRosa);

	virtual ~BotaoCustom();

	void desenha();
	void gerencia();
	void sobMouse();
	void semMouse();
	void clickSobre(int press);
	void clickFora(int press);

	//void setRotulo(const char* conteudo);
	bool getPressionado();
	bool getTrava();

	void setTrava(bool trava);
	void setPressionado(bool press);

	void setBotao(int x, int y,int xLimite, int yLimite,const char* normal,const char* sobMouse,const char* clicado);

	void igualaNormal(void);
	void igualaSobMouse(void);
	void igualaClicado(void);

};

#endif /* BOTAOCUSTOM_H_ */
