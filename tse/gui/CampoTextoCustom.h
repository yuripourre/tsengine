/*
 * CampoTextoCustom.h
 *
 *
 *      Author: Yuri
 */

#ifndef _CAMPOTEXTOCUSTOM_H_
#define _CAMPOTEXTOCUSTOM_H_

#include "../util/Tymer.h"

#include "Componente.h"
#include "../camada/CamadaEstatica.h"

#include <string>

using namespace std;

class CampoTextoCustom: public Componente{

private:

	Camada* cursorImg;
	unsigned int cursor;

	string texto;
	unsigned int maxLength;



	Tymer* tymerCursor;
	Tymer* tymerTrava;
	int cont;

	int somaLetras;

	int travaS;

	bool travado;

	bool piscaCursor;

	bool ativado;

	bool apostrofo;
	bool agudo;
	bool grave;
	bool circunflexo;
	bool trema;
	bool aspasDupla;
	bool aspasSimples;

public:

	CampoTextoCustom(int x, int y);
	~CampoTextoCustom();

	void insereLetra(char letra);
	void apagaLetraBackSpace(void);
	void apagaLetraDelete(void);

	void inicioTexto(void);
	void finalTexto(void);

	void andaDireita(void);
	void andaEsquerda(void);

	void setAtivado(bool ativar);
	void desenha();

	void gerencia();
	void sobMouse();
	void semMouse();
	void clickSobre(int press);
	void clickFora(int press);

	void gerenciaLetra(Uint16 letra);
	void gerenciaInput(Uint16 letra);

protected:

	void desenhaTexto();

};
#endif
