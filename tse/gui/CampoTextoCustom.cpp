/*
 * CampoTextoCustom.cpp
 *
 *
 *      Author: Yuri
 */
#include "CampoTextoCustom.h"

#include "../TSe.h"
using namespace tse;

CampoTextoCustom::CampoTextoCustom(int x,  int y)
{
	setCoordenadas(x,y);
	setCoordLimite(gui->getTamanho()+100,20);

	maxLength = 15;

	tymerCursor = new Tymer(500);

	ativado = false;

	cursor = 0;

	cursorImg = new Camada(getX(),getY()-3);
	cursorImg->carregaImagem("new/gui/texto/cursor.png");

	tymerTrava = new Tymer(50);

	cont = 0;
	travado = false;

	registra();

}
CampoTextoCustom::~CampoTextoCustom()
{

	delete tymerCursor;

	delete cursorImg;

	delete tymerTrava;

}

void CampoTextoCustom::setAtivado(bool ativado)
{
	this->ativado = ativado;
}

void CampoTextoCustom::insereLetra(char letra)
{
	if(texto.length()<maxLength)
		texto+=letra;
}
void CampoTextoCustom::andaDireita(void)
{

}

void CampoTextoCustom::andaEsquerda(void)
{
	apagaLetraBackSpace();
}
void CampoTextoCustom::apagaLetraBackSpace(void)
{
	texto = texto.substr(0,texto.length()-1);
}
void CampoTextoCustom::apagaLetraDelete(void)
{

}
void CampoTextoCustom::inicioTexto(void)
{

}
void CampoTextoCustom::finalTexto(void)
{

}

void CampoTextoCustom::gerenciaLetra(Uint16 letra)
{
	using namespace tse::teclas;

	switch(letra)
	{

	case TSK_DELETE:
		apagaLetraDelete();
		break;

	case TSK_BACKSPACE:
		apagaLetraBackSpace();
		break;

	case TSK_SETA_DIREITA:
		andaDireita();
		break;

	case TSK_SETA_ESQUERDA:
		andaEsquerda();
		break;

	case TSK_HOME:
		inicioTexto();
		break;

	case TSK_END:
		finalTexto();
		break;

	case '\'':
		apostrofo = true;
		break;

	case'`':
		grave = true;
		break;

	case'^':
		circunflexo = true;
		break;

	case'\"':
		aspasDupla = true;
		break;

	default:

		if((letra>=32)&&(letra<=180))
		{
			insereLetra(letra);
		}

		else{}
		break;

	}
	/*
	if((letra>=ESPACO)&&(letra<=125))
	{
		insereLetra(letra);
	}
	 */
}

void CampoTextoCustom::gerencia(void)
{

	if(evento->getSDLEvento().key.type == SDL_KEYUP)
	{
		travaS = 0;
		return;
	}



	if(evento->getSDLEvento().type == SDL_KEYDOWN)
	{
		gerenciaInput((Uint16)evento->getSDLEvento().key.keysym.unicode);
		cursorImg->setAparecendo(true);
	}

}

void CampoTextoCustom::desenha()
{
	if(!texto.empty())
	{
		desenhaTexto();
	}
	else{
		cursorImg->setX(getX());
	}

	if(ativado)
	{
		if(tymerCursor->acionaTymer())
		{
			cursorImg->mudaAparecendo();
		}
		if(piscaCursor)
		{
			cursorImg->setAparecendo(true);
			piscaCursor = false;
		}
		cursorImg->desenha();
	}


}
void CampoTextoCustom::gerenciaInput(Uint16 letra)
{
	//Se for uma nova letra
	if(travaS!=letra)
	{
		//Adiciona no campo
		gerenciaLetra(letra);
		//Armazena a letra
		travaS = letra;
		//Trava o ttttttttt
		travado = true;
		//Zera o contador
		cont = 0;
	}

	if(tymerTrava->acionaTymer())
	{
		if(!travado)
		{
			gerenciaLetra(letra);
		}
		else
		{
			if(travaS==letra)
			{
				cont++;
			}

			if(cont>=10)
			{
				travado = false;
				cont = 0;
			}
		}
	}
}

void CampoTextoCustom::sobMouse(){mouse->setEstado(tse::MOUSE_TEXTO);}
void CampoTextoCustom::semMouse(){}
void CampoTextoCustom::clickSobre(int press)
{

	SDL_EnableUNICODE(SDL_ENABLE);

	setAtivado(true);

}
void CampoTextoCustom::clickFora(int press)
{
	SDL_EnableUNICODE(SDL_DISABLE);
}

void CampoTextoCustom::desenhaTexto(){

	string path;

	Camada* aux = new Camada();

	if(getAparecendo()){

		int ultimoX = getX();

		for (unsigned int i=0; i < texto.length(); i++){

			if((texto.at(i)>='a')&&(texto.at(i)<='z')){
				path  = "new/gui/texto/min";
				path += texto.at(i);
				path += ".png";
				aux->setCoordenadas(ultimoX,getY()+2);
			}
			else if((texto.at(i)>='A')&&(texto.at(i)<='Z')){
				path  = "new/gui/texto/mai";
				path += texto.at(i);
				path += ".png";
				aux->setCoordenadas(ultimoX,getY());
			}

			aux->carregaImagem(path.c_str());
			aux->desenha();

			ultimoX = aux->getX()+aux->getXLimite();
			path = "";

		}

		cursorImg->setX(ultimoX);

	}
	delete aux;
}
