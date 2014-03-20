/*
 * Som.cpp
 *
 *
 *      Author: Yuri
 */

#include "Som.h"

Som::Som(const char* arquivo)
{
	carregaSom(arquivo);
	pista = -1;
}

Som::Som()
{
	pista = -1;
}


int Som::carregaSom( const char* arquivo)
{
	audio = Mix_LoadWAV( arquivo );
	if( audio != NULL )
	{
		//LOG
	}
	return -1;
}

void Som::tocaSom ( int novaPista , int loops)
{
	pista = Mix_PlayChannel(novaPista, audio , loops);
}

void Som::tocaSom (int loops)
{
	Mix_PlayChannel(pista, audio , loops);
}
void Som::tocaSom ()
{
	Mix_PlayChannel(pista, audio , 0);
}

int Som::getPista(void)
{
	return pista;
}

Som::~Som()
{
	if( audio != NULL )
	{
		Mix_FreeChunk(audio);
	}
}
