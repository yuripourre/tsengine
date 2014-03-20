/*
 * PrincipalControle.cpp
 *
 *
 *      Author: Yuri
 */

#include "PrincipalControle.h"

PrincipalControle::PrincipalControle()
{
	sair = false;
	minimizou = false;
	fechar = false;

	mouse = new Mouse();
	teclado = new Teclado();

	//SDL_EnableUNICODE(SDL_ENABLE);
}

PrincipalControle::~PrincipalControle()
{
	delete teclado;
	delete mouse;
}

SDL_Event PrincipalControle::getSDLEvento()
{
	return event;
}

bool PrincipalControle::getTecla(int input)
{
	if ((event.type == SDL_KEYDOWN)&&(event.key.keysym.sym == input))
	{
		return true;
	}

	return false;
}

Mouse* PrincipalControle::getMouse(void)
{
	return mouse;
}
Teclado* PrincipalControle::getTeclado(void)
{
	return teclado;
}

bool PrincipalControle::fechouJanela(void)
{
	return sair;
}
bool PrincipalControle::getSair(void)
{
	return sair;
}

void PrincipalControle::setSair(bool sair)
{
	this->sair = sair;
}

bool PrincipalControle::getFechar()
{
	return fechar;
}


void PrincipalControle::gerenciaEvento(void)
{

	if(SDL_PollEvent(&event))
	{

		switch(event.type)
		{
		case SDL_QUIT:
			fechar = true;
			break;

		case SDL_MOUSEMOTION:
			mouse->setCoordenadas(event.motion.x , event.motion.y);
			break;

		case SDL_MOUSEBUTTONDOWN:

			if(event.button.button == SDL_BUTTON_LEFT)
			{
				mouse->setPressionado(1);
			}

			else if(event.button.button == SDL_BUTTON_RIGHT)
			{
				mouse->setPressionado(2);
			}
			else if(event.button.button == SDL_BUTTON_MIDDLE)
			{
				mouse->setPressionado(3);
			}
			else
			{
				mouse->setPressionado(0);
			}

			if(event.button.button == SDL_BUTTON_WHEELUP)
			{
				mouse->setRodinhaCima(true);
				break;
			}
			else if(event.button.button == SDL_BUTTON_WHEELDOWN)
			{
				mouse->setRodinhaBaixo(true);
				break;
			}
			break;


		case SDL_MOUSEBUTTONUP:
			switch(event.button.button)
			{

			case SDL_BUTTON_LEFT:
			case SDL_BUTTON_RIGHT:
			case SDL_BUTTON_MIDDLE:
				mouse->setPressionado(0);
				break;

			case SDL_BUTTON_WHEELUP:
				mouse->setRodinhaCima(false);
				break;

			case SDL_BUTTON_WHEELDOWN:

				mouse->setRodinhaBaixo(false);
				break;
			}
			break;

			//Cases do Teclado
			case SDL_KEYDOWN:

				//tecla[event.key.keysym.unicode] = true;

				break;

			case SDL_KEYUP:

				//tecla[event.key.keysym.unicode] = false;

				break;
		}

	}//fecha switch
}//fecha while
