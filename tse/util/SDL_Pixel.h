/*
 * SDL_Pixel.h
 *
 *  Created on: Feb 17, 2011
 *      Author: Yuri
 */

#ifndef SDL_PIXEL_H_
#define SDL_PIXEL_H_

#include <SDL/SDL.h>

Uint32 get_pixel32( SDL_Surface *surface, int x, int y );

void put_pixel32( SDL_Surface *surface, int x, int y, Uint32 pixel );

SDL_Color getPixel(int x, int y,SDL_Surface *TMPSurface);

void putPixel(SDL_Surface *surface, int x, int y, Uint32 pixel);

#endif /* SDL_PIXEL_H_ */
