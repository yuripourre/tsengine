/*
 * CampoTexto.h
 *
 *
 *      Author: Yuri
 */

#ifndef _CAMPOTEXTO_H_
#define _CAMPOTEXTO_H_

#include "../camada/CamadaPrimitiva.h"

#include "../camada/CamadaTexto.h"
#include "../util/Tymer.h"

#include "Componente.h"

class CampoTexto: public Componente{

private:

	CamadaTexto* texto;

	Tymer* tymerCursor;
	CamadaPrimitiva* cursor;

	Tymer* tymerTrava;
	int cont;

	int somaLetras;

	int travaS;

	bool travado;
	bool miniTrava;

	int min,max;

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

	CampoTexto();
	CampoTexto(int x, int y,const char* conteudo);
	void inicializar(const char* conteudo);
	~CampoTexto();

	void insereLetra(char letra);
	void apagaLetraBackSpace(void);
	void apagaLetraDelete(void);

	void inicioTexto(void);
	void finalTexto(void);

	void andaDireita(void);
	void andaEsquerda(void);

	void setAtivado(bool ativar);
	void desenha();

	void setCor(int r, int g, int b);

	void gerencia();
	void sobMouse();
	void semMouse();
	void clickSobre(int press);
	void clickFora(int press);

	void gerenciaLetra(Uint16 letra);
	void gerenciaInput(int letra);

};
#endif
