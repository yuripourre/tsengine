/*
 * Tela.h
 *
 *  Created on: 21/12/2009
 *      Author: Yuri Pourre
 */

#ifndef TELA_H_
#define TELA_H_

//Icone
#include "../camada/Camada.h"
//Barra de Título
#include "../util/Frase.h"

class Tela
{

private:

	//int largura;
	int largura;
	int altura;
	int bitsdeCor;

	bool fullscreen;
	bool center;

	int posX;
	int posY;

	//Camada de Vídeo
	SDL_Surface* screen;

	Frase* titulo;

	CamadaEstatica* icon;

protected:
	void criaJanela();

public:
	Tela();
	Tela(int width, int height);

	void atualiza();
	void Inicializa();

	SDL_Surface* getScreen();
	void setFullScreen(bool fullscreen);
	int getAltura();
	int getLargura();

	void setTamanho(int largura, int altura);


	Frase* getTitulo();
	void setTitulo(const char* novoTitulo);


	virtual ~Tela();
};

#endif /* TELA_H_ */
