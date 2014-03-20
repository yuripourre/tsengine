/*
 * CamadaTexto.h
 *
 *
 *      Author: Yuri Pourre
 */
#ifndef _CAMADATEXTO_H_
#define _CAMADATEXTO_H_

#include "Camada.h"
#include "../util/Frase.h"
#include "../util/Util.h"

#include <SDL/SDL_ttf.h>
//==============================================================================
class CamadaTexto: public Camada{

private:

	SDL_Color corLetras;
	SDL_Color corFundo;

	TTF_Font  *fonte;

	Frase* frase;

	int render;
	int tamanhoFonte;

public:

	CamadaTexto();
	~CamadaTexto();

	CamadaTexto(int conteudo);
	CamadaTexto(const char* conteudo);
	CamadaTexto(const char* conteudo, int tamanhoFonte);

	//Muito Importante
	CamadaTexto(int tamanhoFonte, const char* arquivoFonte);
	//Criar uma camadaTexto Aux com um caracter qualquer
	//Definir as coordenadas

	CamadaTexto(const char* conteudo, int tamanhoFonte, const char* arquivoFonte);

	CamadaTexto(char c);

	void inicializar(void);

	void desenha(void);

	void carregaFonte(const char* arquivoFonte);
	void carregaFonte(const char* arquivoFonte, int tamanhoFonte);

	TTF_Font* getFonte(void);

	void igualaFonte(TTF_Font* fonte);

	void setRender(int render);

	void escreve(void);


	void setConteudo(const char* novoValor);
	void setConteudo(int novoValor);

	Frase* getFrase(void);
	const char* getConteudo(void);

	void apagaConteudo();
	//void insereNoFinal(string novoValor);
	//void insereNoFinal(char c);

	void setCorLetras(int r, int g, int b);
	void setCorLetras(SDL_Color cor);

	void setCorFundo(int r, int g, int b);


	void setTamanhoFonte(int tamanhoFonte);

	int getTamanhoFonte(void);

	void ajustaCamada();

	enum render{
		RENDER_SOLID = 0,
		RENDER_SHADED = 1,
		RENDER_BLENDED = 2

	};

};

//==============================================================================

#endif
