/*
 * Cliente.h
 *
 *      Created on: 22/08/2009 (+ou-)
 *      Author: Yuri
 */

#ifndef _CLIENTE_H_
#define _CLIENTE_H_

//Includes Comuns
#include <iostream>
#include <unistd.h>

//Includes Windows
#ifndef unix
#include <winsock2.h>

//Includes Linux
#else
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#endif

#include "../util/Frase.h"

class Cliente{

private :

#ifndef unix
	WSADATA wsa_data;
#endif

	int conexao;

	int porta;

	int tamanhoMsgReceb;

	int tamanhoMsgEnviada;

	char* IPChar;

	struct sockaddr_in servidor;

	struct sockaddr_in cliente;

	const struct sockaddr* pontSock;

	int meusocket;

	char* msgEnviada;

	char* msgRecebida;

	//string mensagem;

	Frase* mensagem;

	string msgRec;

	//Tymer tymerCliente;

public:

	Cliente();

	~Cliente();

	struct sockaddr_in getServidor(void);

	void setConexao(int conex);

	int getConexao(void);

	void setMsgEnviada(char novoValor []);

	void setTamanhoMsgRecebida(int tamanho);

	void setTamanhoMsgEnviada(int tamanho);

	int getTamanhoMsgRecebida(void);

	int getTamanhoMsgEnviada(void);

	void setSockServer(struct sockaddr_in aux);

	char* getMsgEnviada(void);

	char* getMsgRecebida(void);

	void setMeuSocket(int valor);

	int getMeuSocket(void);

	int iniciaSockClient(void);

	void enviaMsg(void);

	const struct sockaddr* getPontSock(void);

	void enviaTymered(void);

	void recebeMensagem(void);

	//Envia "Cliente!"
	void enviaMsg(int numero);


	int ReadLine();
	int WriteLine(const char* msg);

	string getMsgRec();


};
#endif
