/*
 * PrincipalControle.h
 *
 *
 *      Author: Yuri
 */

#ifndef _PRINCIPALCONTROLE_H_
#define _PRINCIPALCONTROLE_H_

#include <SDL/SDL.h>

#include "Teclado.h"
#include "Mouse.h"

class PrincipalControle {

private:

	SDL_Event event;

	Mouse* mouse;
	Teclado* teclado;

	bool sair;
	bool minimizou;
	bool unicode;

	bool fechar;
	//char key;

	//map<Uint16, bool> tecli;

public:

	PrincipalControle();
	~PrincipalControle();


	Mouse* getMouse(void);
	Teclado* getTeclado(void);

	void gerenciaEvento(void);

	//void gerenciaEscrita(void);

	//SDL_Event getEventoSDL(void);
	//void setEscreveTexto(bool ativar);

	SDL_Event getSDLEvento();

	bool getSair(void);
	void setSair(bool sair);

	void setUnicode(bool unicode);

	//map<Uint16, bool> getMapa(void);
	//bool getTecla(SDLKey input);
	bool getTecla(int input);

	bool fechouJanela(void);
	void fechaJanela(void);

	bool getFechar(void);





};
//==============================================================================
#endif
