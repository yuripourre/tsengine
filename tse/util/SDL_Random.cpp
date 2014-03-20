/*
 * SDL_Random.cpp
 *
 *  Created on: 03/01/2010
 *      Author: Yuri
 */

#include "SDL_Random.h"

int SDL_Random()
{
	int r = rand();

	return r;
}

int SDL_Random(int mod)
{
	return SDL_Random()%mod;
}

int SDL_Random(int min, int max)
{
	return min+SDL_Random()%(max-min+1);
}
