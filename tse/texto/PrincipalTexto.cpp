/*
 * PrincipalTexto.cpp
 *
 *  Created on: 11/03/2010
 *      Author: Yuri Pourre
 */

#include "PrincipalTexto.h"
#include <SDL/SDL_ttf.h>

PrincipalTexto::PrincipalTexto()
{
	TTF_Init();
}

PrincipalTexto::~PrincipalTexto()
{
	TTF_Quit();
}
