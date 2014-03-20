/*
 * Som.h
 *
 *
 *      Author: Yuri
 */
#ifndef _SOM_H_
#define _SOM_H_

#include <SDL/SDL_mixer.h>

class Som
{

private:

	Mix_Chunk *audio;
	int pista;

public:

	Som(const char* arquivo);
	Som();
	~Som();

	int carregaSom( const char* arquivo );

	int getPista(void);

	void setPista(int canal);
	void tocaSom(int novaPista, int loops);
	void tocaSom(int loops);
	void tocaSom();


};
//==============================================================================

#endif
