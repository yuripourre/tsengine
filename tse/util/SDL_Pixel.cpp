
#include "SDL_Pixel.h"

Uint32 get_pixel32( SDL_Surface *surface, int x, int y )
{
	//Convert the pixels to 32 bit
	Uint32 *pixels = (Uint32 *)surface->pixels;

	//Get the requested pixel
	return pixels[ ( y * surface->w ) + x ];
}

void put_pixel32( SDL_Surface *surface, int x, int y, Uint32 pixel )
{
	//Convert the pixels to 32 bit
	Uint32 *pixels = (Uint32 *)surface->pixels;

	//Set the pixel
	pixels[ ( y * surface->w ) + x ] = pixel;
}


SDL_Color getPixel(int x, int y,SDL_Surface *TMPSurface)
{
	int bpp = TMPSurface->format->BytesPerPixel;
	SDL_Color color;
	Uint32 tmp;

	/* Aqui p � o endere�o para o pixel que queremos recuperar */
	Uint8 *p = (Uint8 *)TMPSurface->pixels + y * TMPSurface->pitch + x * bpp;

	switch(bpp) {
	case 1:
		tmp = *p;
		break;

	case 2:
		tmp = *(Uint16 *)p;
		break;
	case 3:
		if(SDL_BYTEORDER == SDL_BIG_ENDIAN)
		{
			tmp = p[0] << 16 | p[1] << 8 | p[2];
		}else{
			tmp = p[0] | p[1] << 8 | p[2] << 16;
		}

		break;
	case 4:
		tmp = *(Uint32 *)p;
		break;
	default:
		tmp = 0;       /* n�o deve acontecer, mas evitamos as advert�ncias */
		break;
	}

	SDL_GetRGB(tmp, TMPSurface->format, &color.r, &color.g, &color.b);

	return color;
}

void putPixel(SDL_Surface *surface, int x, int y, Uint32 pixel)
{
	int bpp = surface->format->BytesPerPixel;
	// Here p is the address to the pixel we want to set
	Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;

	switch(bpp)
	{
	case 1:
		*p = pixel;
		break;
	case 2:
		*(Uint16 *)p = pixel;
		break;
	case 3:
		if(SDL_BYTEORDER == SDL_BIG_ENDIAN)
		{
			p[0] = (pixel >> 16) & 0xff;
			p[1] = (pixel >> 8) & 0xff;
			p[2] = pixel & 0xff;
		} else {
			p[0] = pixel & 0xff;
			p[1] = (pixel >> 8) & 0xff;
			p[2] = (pixel >> 16) & 0xff;
		}
		break;
	case 4:
		*(Uint32 *)p = pixel;
		break;
	}
}
