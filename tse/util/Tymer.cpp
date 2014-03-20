/*
 * Tymer.cpp
 *
 *  Created on: 26/10/2009
 *      Author: Yuri Pourre
 */

#include "Tymer.h"
#include <SDL/SDL.h>

Tymer::Tymer()
{
	freq = 700;
    tempo = 0;
}
Tymer::Tymer(int freq)
{
	this->freq = freq;
	tempo = 0;
}

Tymer::~Tymer()
{

}

bool Tymer::acionaTymer()
{
	if (tempo + freq > SDL_GetTicks())
	{
		return false;
	}
	tempo = SDL_GetTicks();
	return true;
}

void Tymer::setAtivado(bool ativado)
{
    this->ativado = ativado;
}

bool Tymer::getAtivado() const
{
	return ativado;
}

int Tymer::getFreq() const
{
    return freq;
}

void Tymer::setFreq(int freq)
{
    this->freq = freq;
}
void Tymer::zeraTymer()
{
	tempo = 0;
}
