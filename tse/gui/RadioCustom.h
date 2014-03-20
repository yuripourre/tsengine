/*
 * RadioCustom.h
 *
 *  Created on: 15/02/2010
 *      Author: Yuri Pourre
 */

#ifndef RADIOCUSTOM_H_
#define RADIOCUSTOM_H_

#include "Componente.h"
//#include "BotaoCustom.h"
#include "GrupoRadio.h"

class RadioCustom : public Componente{

private:

	int* idGrupo;

	CamadaEstatica* camNormal;
	CamadaEstatica* camSobMouse;
	CamadaEstatica* camClicado;

public:

	RadioCustom();
	RadioCustom(int x, int y,int xLimite, int yLimite,const char* normal,const char* sobMouse,const char* clicado,GrupoRadio* grupo);

	virtual ~RadioCustom();

	void setGrupo(GrupoRadio* grupo);

	int  getIDGrupo();
	void setIDGrupo(int* idGrupo);
	void letIDGrupo();

	void sobMouse();
	void semMouse();
	void clickSobre(int press);
	void clickFora(int press);

	void igualaNormal(void);
	void igualaSobMouse(void);
	void igualaClicado(void);


};

#endif /* RADIOCUSTOM_H_ */
