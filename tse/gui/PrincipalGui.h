/*
 * PrincipalGui.h
 *
 *  Created on: 10/01/2010
 *      Author: Yuri
 */

#ifndef PRINCIPAL_GUI_H_
#define PRINCIPAL_GUI_H_

#include "../camada/Camada.h"
#include "../util/Frase.h"

#include "Componente.h"

#include <list>

using namespace std;

class PrincipalGui
{

private:

	list<Componente*> l;
	list<Componente*>::iterator it;

	Camada* tema;
	int tamanho;
	Frase* dirFonte;
	//bool* trava;

	int total;
	//int componenteAtivo;
	int idAtual;
	int idAtivo;

	int antigoX,antigoY;

	Componente* inicial;
	Componente* final;

	Componente* ativo;
	Componente* semiAtivo;

public:

	PrincipalGui();
	PrincipalGui(const char* caminhoTema,int tamanhoTema, const char* caminhoFonte);
	virtual ~PrincipalGui();

	void inicializa();

	Camada* getTema();
	int getTamanho();
	const char* getDirFonte(void);

	void remove();


	int registra(Componente* componente);
	void gerencia();
	void desenha();

	void setIDAtivo(int id);
	int getIDAtivo(void);

	void setAtivo(Componente* componente);
	Componente* getComponenteAtivo(void);

	Componente* getInicial(void);


};

#endif
