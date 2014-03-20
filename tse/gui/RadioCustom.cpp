/*
 * RadioCustom.cpp
 *
 *  Created on: 15/02/2010
 *      Author: Yuri Pourre
 */

#include "RadioCustom.h"

RadioCustom::RadioCustom()
{
	//idGrupo = new int;
	//*idGrupo = 0;
}

RadioCustom::RadioCustom(int x, int y,int xLimite, int yLimite,const char* normal,const char* sobMouse,const char* clicado,GrupoRadio* grupo):Componente()
{
	//idGrupo = new int;
	//*idGrupo = 0;

	//BotaoCustom(x,y,xLimite,yLimite,normal,sobMouse,clicado,false);

	//Componente();

		setCoordenadas(x,y);
		setCoordLimite(xLimite, yLimite);

		camNormal = new CamadaEstatica(normal);
		camSobMouse = new CamadaEstatica(sobMouse);
		camClicado = new CamadaEstatica(clicado);

		igualaImagem(camNormal->getImagem());

		//registra();

		setGrupo(grupo);

}

RadioCustom::~RadioCustom()
{
	// TODO Auto-generated destructor stub
}

int RadioCustom::getIDGrupo()
{
	return *idGrupo;
}

void RadioCustom::setIDGrupo(int* idGrupo)
{
	int* temp = this->idGrupo;
	this->idGrupo = idGrupo;
	delete temp;
}

//Importante
void RadioCustom::setGrupo(GrupoRadio* grupo)
{
	idGrupo = grupo->getIDAtivo();
}
//Importante

void RadioCustom::letIDGrupo()
{
	*idGrupo = getID();
}

void RadioCustom::sobMouse()
{
	igualaSobMouse();

	if(getIDGrupo()==getID())
	{
		igualaClicado();
		return;
	}

}
void RadioCustom::semMouse()
{
	igualaNormal();


	//setPressionado(false);

	if(getIDGrupo()==getID())
	{
		igualaClicado();
		return;
	}

}

void RadioCustom::clickSobre(int press)
{
	igualaClicado();

	//setPressionado(true);


	if(getIDGrupo()>0)
	{
		letIDGrupo();
	}

}
void RadioCustom::clickFora(int press)
{
	igualaNormal();


	//setPressionado(false);

	if(getIDGrupo()==getID())
	{
		igualaClicado();
		return;
	}

}

void RadioCustom::igualaNormal(void)
{
	if(getImagem()!=camNormal->getImagem())
	{
		igualaImagem(camNormal->getImagem());
	}
}
void RadioCustom::igualaSobMouse(void)
{
	if(getImagem()!=camSobMouse->getImagem())
	{
		igualaImagem(camSobMouse->getImagem());
	}
}
void RadioCustom::igualaClicado(void)
{
	if(getImagem()!=camClicado->getImagem())
	{
		igualaImagem(camClicado->getImagem());
	}
}
