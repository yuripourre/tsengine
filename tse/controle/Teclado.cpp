/*
 * Teclado.cpp
 *
 *
 *      Author: Yuri
 */
#include "Teclado.h"


Teclado::Teclado()
{
	capsLockPersiste = false;
	numeroTeclas = 305;
	tecla = new bool[numeroTeclas];
	trava = new bool[numeroTeclas];
}
Teclado::~Teclado()
{
	delete []trava;
	delete []tecla;
}

bool* Teclado::getTeclas()
{
	return tecla;
}

void Teclado::setTecla(int indice, bool press)
{
	tecla[indice] = press;

	if(!press)
	{
		trava[indice] = false;
	}
}


bool Teclado::getTecla(int indice)
{
	if (tecla[indice])
	{
		return true;
	}
	else
		return false;
}

bool* Teclado::getTravas()
{
	return trava;
}
void Teclado::setTrava(int indice, bool press)
{
	trava[indice] = press;
}
bool Teclado::getTrava(int indice)
{
	if (trava[indice])
	{
		return true;
	}
	else
		return false;
}

int Teclado::getNumeroTeclas(void)
{
	return numeroTeclas;
}

bool Teclado::getCima(void)
{
	return tecla[295];
}
bool Teclado::getBaixo(void)
{
	return tecla[296];
}
bool Teclado::getDireita(void)
{
	return tecla[297];
}
bool Teclado::getEsquerda(void)
{
	return tecla[298];
}
bool Teclado::getShiftE(void)
{
	return tecla[299];
}
bool Teclado::getShiftD(void)
{
	return tecla[300];
}
bool Teclado::getAltE(void)
{
	return tecla[303];
}
bool Teclado::getAltD(void)
{
	return tecla[304];
}
bool Teclado::getCtrlE(void)
{
	return tecla[301];
}
bool Teclado::getCtrlD(void)
{
	return tecla[302];
}

bool Teclado::getCapsLock(void)
{
	return tecla[294];
}
bool Teclado::getCapsLockPersiste(void)
{
	return capsLockPersiste;
}

bool Teclado::getPrintScreen(void)
{
	return tecla[293];
}
bool Teclado::getF(int posit)
{
	return tecla[277+posit];
}

bool Teclado::getMaiusculo(void)
{
	if((tecla[299]==true)||(tecla[300]==true)||(tecla[294]==true))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Teclado::setCapsLockPersiste(void)
{
	if(capsLockPersiste == true)
	{
		capsLockPersiste = false;
		return;
	}
	if(capsLockPersiste == false)
	{
		capsLockPersiste = true;
	}

}
bool Teclado::getApostrofo(void)
{
	return apostrofo;
}
bool Teclado::getAcentoCircunflexo(void)
{
	return acentoCircunflexo;
}

bool Teclado::getAcentoGrave(void)
{
	return acentoGrave;
}
bool Teclado::getTil(void)
{
	return til;
}
bool Teclado::getTrema(void)
{
	return trema;
}
bool Teclado::getAcentoAgudo(void)
{
	return acentoAgudo;
}

void Teclado::setApostrofo(bool persiste)
{
	apostrofo = persiste;
}
void Teclado::setAcentoCircunflexo(bool persiste)
{
	acentoCircunflexo = persiste;
}
void Teclado::setAcentoGrave(bool persiste)
{
	acentoGrave = persiste;
}
void Teclado::setTil(bool persiste)
{
	til = persiste;
}
void Teclado::setTrema(bool persiste)
{
	trema = persiste;
}
void Teclado::setAcentoAgudo(bool persiste)
{
	acentoAgudo = persiste;
}
//Setinhas do Teclado
void Teclado::setCima(bool press)
{
	tecla[295] = press;
}
void Teclado::setBaixo(bool press)
{
	tecla[296] = press;
}
void Teclado::setDireita(bool press)
{
	tecla[297] = press;
}
void Teclado::setEsquerda(bool press)
{
	tecla[298] = press;
}
