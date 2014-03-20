/*
 * Servidor.h
 *
 *      Created on: 22/08/2009 (+ou-)
 *      Author: Yuri
 */

#ifndef _SERVIDOR_H_
#define _SERVIDOR_H_

//Includes Comuns
#include <iostream>
#include <unistd.h>
#include <string.h>

#include <winsock2.h>
WSADATA wsa_data;

//Includes Linux
//#include <sys/types.h>
//#include <sys/socket.h>
//#include <arpa/inet.h>


#define TAMANHO_MESG 513

class Servidor{

private :

	int conexao;

	int porta;

	int tamanhoMsgReceb;

	int tamanhoMsg;

	int meusocket;

	//Estruturas Privadas//
	struct sockaddr_in servidor;

	struct sockaddr_in cliente;

	const struct sockaddr* pontSock;

	struct sockaddr* pontClient;

	char* msgBuffer;
	char* msgRecebida;

	//char msgBuffer[TAMANHO_MESG];


public:

	int tamanho;

	Servidor();

	struct sockaddr_in getCliente(void);

	void setConexao(int conex);

	int getConexao();

	void setMsgBuffer(char novoValor []);     //igual ao setConteudo da CamadaTexto.cpp

	char* Servidor::getMsgRecebida(void);

	char* getMensagem(void);

	void setTamanhoMsgRecebida(int tamanho);

	int getTamanhoMsgRecebida(void);

	int getTamanhoMsg(void);

	void setSockServer(struct sockaddr_in aux);

	char* getMsgBuffer(void);


	void setMeuSocket(int valor);

	int getMeuSocket(void);

	void iniciaSockServer(void);

	const struct sockaddr* getPontSock(void);

	struct sockaddr* getPontClient(void);
};

#endif

