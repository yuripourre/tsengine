/*
 * Frase.h
 *
 *  Created on: 31/12/2009
 *      Author: Yuri
 */

#ifndef FRASE_H_
#define FRASE_H_

#include <iostream>
#include <string>

using std::string;

class Frase
{

private:

	string conteudo;

	unsigned int cursor;

public:
	Frase();
	//Frase(string conteudo);
	Frase(int conteudo);
	Frase(const char* conteudo);
	Frase(char c);
	virtual ~Frase();

	//void setConteudo(string novoValor);
	void setConteudo(const char* novoValor);
	void trim();


	string getConteudo(void);
	unsigned int getCursor(void);

	void insereFinal(string palavra);
	void insereFinal(int numero);
	void insereFinal(char letra);
	void insereInicio(char letra);
	char insereCursor(char letra);


	char apagaBackSpace(void);
	void apagaDel(void);
	void apagaConteudo(void);

	void setCursor(int cursor);
	void setCursorDireita(int acressimo);
	void setCursorEsquerda(int decressimo);

};

#endif
