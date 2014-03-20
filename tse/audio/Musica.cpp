/*
 * Musica.cpp
 *
 *
 *      Author: Yuri
 */

#include "Musica.h"
Musica::Musica(){
}
Musica::Musica(const char *arquivo){
	carregaMusica(arquivo);
}

bool Musica::carregaMusica( const char *arquivo )
{
	if( audio != NULL )
	{
		audio = Mix_LoadMUS(arquivo);
		return true;
	}

	return false;
}

void Musica::tocaMusica ()
{
	Mix_PlayMusic(audio , 0);
}

void Musica::tocaMusica (int vezes)
{
	//loops 0 = infinito;
	Mix_PlayMusic(audio , vezes);
}

Musica::~Musica()
{
	if(audio!=NULL)
	Mix_FreeMusic(audio);
}
