/*
 * Componente.cpp
 *
 *  Created on: 20/01/2010
 *      Author: Yuri Pourre
 */

#include "Componente.h"

#include "../TSe.h"

Componente::Componente()
{
	id = 0;
	//idGrupo = new int;
	//*idGrupo = 0;
}

Componente::~Componente()
{
	// TODO Auto-generated destructor stub
}
int Componente::getID()
{
	return this->id;
}
void Componente::setID(int id)
{
	this->id = id;
}
/*
int Componente::getIDGrupo()
{
	return *idGrupo;
}

void Componente::setIDGrupo(int* idGrupo)
{
	int* temp = this->idGrupo;
	this->idGrupo = idGrupo;
	delete temp;
}

void Componente::letIDGrupo(int idAtivo)
{
 *idGrupo = idAtivo;
}
 */
void Componente::setProximo(Componente* proximo)
{
	this->proximo = proximo;
}
Componente* Componente::getProximo()
{
	return proximo;
}

void Componente::setAnterior(Componente* anterior)
{
	this->anterior = anterior;
}
Componente* Componente::getAnterior()
{
	return anterior;
}

void Componente::setTipo(char tipo)
{
	this->tipo = tipo;
}

char Componente::getTipo()
{
	return tipo;
}

void Componente::registra()
{
	if(!getID())
	{
		setID(tse::gui->registra(this));
	}
}

/*
bool Componente::registraComponente()
{
	if(!getID())
	{
		setID(gui->geraID());

		Componente* atual = gui->getInicial();
		//Componente* prox = inicial->getProximo();

		for(;;)
		{

			//if(componente->getX()>=atual->getX())
			//{
			//if(componente->getX()<=prox->getX())
			//{
			if(!atual->getProximo()->getID())
			{
				setProximo(atual->getProximo());
				setAnterior(atual);

				atual->setProximo(this);
				atual->getProximo()->setAnterior(this);
				//}
				return true;
			}
			//}

			atual = atual->getProximo();

			//if(!atual->getID())
			//{
			//	break;
			//}

			//prox = atual->getProximo();
		}

	}
	return false;
}
*/

void Componente::gerencia(){}
void Componente::sobMouse(){}
void Componente::semMouse(){}
void Componente::clickSobre(int press){}
void Componente::clickFora(int press){}
