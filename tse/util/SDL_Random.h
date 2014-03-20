/*
 * SDL_Random.h
 *
 *  Created on: 03/01/2010
 *      Author: Yuri
 */

#ifndef SDL_RANDOM_H_
#define SDL_RANDOM_H_

#include <iostream>
#include <SDL/SDL.h>

int SDL_Random();
int SDL_Random(int mod);
int SDL_Random(int min, int max);

#endif /* SDL_RANDOM_H_ */
