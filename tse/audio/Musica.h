/*
 * Musica.h
 *
 *
 *      Author: Yuri
 */

#ifndef _MUSICA_H_
#define _MUSICA_H_

#include <SDL/SDL_mixer.h>

class Musica
{

private:

	Mix_Music *audio;

public:

	bool carregaMusica( const char *arquivo );

	void tocaMusica();
	void tocaMusica(int vezes);

	Musica();
	Musica(const char *arquivo);
	~Musica();

};
//==============================================================================

#endif
