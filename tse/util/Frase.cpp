/*
 * Frase.cpp
 *
 *  Created on: 31/12/2009
 *      Author: Yuri
 */

#include "Frase.h"
#include "Util.h"

Frase::Frase()
{
	cursor = 0;
}

Frase::Frase(int conteudo)
{
	string temp = itos(conteudo);
	this->conteudo = temp;

	cursor = 0;
}

Frase::Frase(const char* conteudo)
{
	string aux = conteudo;
	if(!aux.empty())
	{
		setConteudo(conteudo);
	}
	cursor = aux.size();
}

Frase::Frase(char c)
{
	//conteudo.clear();
	conteudo.insert(conteudo.end(),c);
	cursor = 1;
}

Frase::~Frase()
{

}

void Frase::setConteudo(const char* novoValor)
{
	conteudo.clear();

	conteudo = novoValor;
}

void Frase::trim()
{
	std::remove(conteudo.begin(),conteudo.end(), ' ');

	while(conteudo.at(0)==' ')
	{
		conteudo.erase(1,1);
	}
	while(conteudo.at(conteudo.length())==' ')
	{
		conteudo.erase(conteudo.length(),1);
	}
}
string Frase::getConteudo(void)
{
	return conteudo;
}
unsigned int Frase::getCursor(void)
{
	return cursor;
}

void Frase::insereFinal(char letra)
{
	conteudo+=letra;
	cursor++;
}

void Frase::insereFinal(string palavra)
{
	conteudo+=palavra;
	cursor+=palavra.length();
}

void Frase::insereFinal(int numero)
{
	string aux = itos(numero);
	conteudo+=aux;
	cursor+=aux.length();
}

void Frase::insereInicio(char letra)
{
	conteudo.insert(conteudo.begin(),letra);
	cursor++;
}

char Frase::insereCursor(char letra)
{
	string aux = "";
	aux.insert(aux.begin(),letra);

	if(cursor>=conteudo.length())
	{
		conteudo.insert(conteudo.end(),letra);
		cursor = conteudo.length();
	}
	else
	{
		conteudo.insert(cursor,aux);
	}
	setCursorDireita(1);

	return letra;
}

char Frase::apagaBackSpace(void)
{
	char apagada = '\0';
	if(cursor>0)
	{
		apagada = conteudo.at(cursor-1);
		conteudo.erase(cursor-1,1);
		cursor--;
	}
	return apagada;
}

void Frase::apagaDel(void)
{
	conteudo.erase(cursor,1);
}

void Frase::apagaConteudo(void)
{
	conteudo.erase();
}

void Frase::setCursor(int cursor)
{
	this->cursor = cursor;
}

void Frase::setCursorDireita(int acressimo)
{
	if(cursor<conteudo.length())
		this->cursor += acressimo;
}

void Frase::setCursorEsquerda(int decressimo)
{
	if(cursor>0)
		this->cursor -= decressimo;
}
