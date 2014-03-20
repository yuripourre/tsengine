/*
 * Componente.h
 *
 *  Created on: 20/01/2010
 *      Author: Yuri Pourre
 */

#ifndef COMPONENTE_H_
#define COMPONENTE_H_

#include "../camada/Camada.h"

class Componente : public Camada{

private:

	int id;
	char tipo;

	//int* idGrupo;

	Componente* proximo;
	Componente* anterior;

public:
	Componente();

	virtual ~Componente();

	//Metodos de Lista da PrincipalGui
	int getID();
	void setID(int id);

	//Besteira
	void setTipo(char tipo);
	char getTipo();

	//int getIDGrupo();
	//void setIDGrupo(int* idGrupo);
	//void letIDGrupo(int idAtivo);

	void setProximo(Componente* proximo);
	Componente* getProximo();

	void setAnterior(Componente* anterior);
	Componente* getAnterior();

	bool registraComponente(void);

	void registra();

	//Métodos de Controle
	virtual void gerencia();
	virtual void sobMouse();
	virtual void semMouse();
	virtual void clickSobre(int press);
	virtual void clickFora(int press);






};

#endif /* COMPONENTE_H_ */
