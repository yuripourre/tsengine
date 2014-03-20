/*
 * Cliente.cpp
 *
 *      Created on: 22/08/2009 (+ou-)
 *      Author: Yuri
 */

//#ifndef unix
#include "Cliente.h"
//#end	if
//#include "ClienteUnix.h"

//-lws2_32 para compilar =======================================================

Cliente::Cliente(){

	//conexao = -1;

	porta = 8767;

	IPChar = new char[15];
	IPChar = "127.0.0.1";

	tamanhoMsgEnviada = 16;

	msgEnviada = new char[tamanhoMsgEnviada];

	msgRecebida = new char[128];

	mensagem = new Frase("Cliente!");

	tamanhoMsgReceb = 0;

	servidor.sin_family = AF_INET;
	servidor.sin_addr.s_addr = inet_addr(IPChar);
	servidor.sin_port = htons(porta);

	pontSock = (struct sockaddr *)const_cast <struct sockaddr_in*>(&servidor);

	conexao = iniciaSockClient();

}

struct sockaddr_in Cliente::getServidor(void)
{
	return servidor;
}

const struct sockaddr* Cliente::getPontSock(void)
{
	return pontSock;
}

void Cliente::setConexao(int conex)
{
	conexao = conex;
}

int Cliente::getConexao(void){
	return conexao;
}

void Cliente::setMsgEnviada(char novoValor [])
{
	int n=0;
	do
	{
		msgEnviada[n] = novoValor[n];
	} while (novoValor[n++] != '\0');
}



char* Cliente::getMsgEnviada(void)
{
	return &msgEnviada[0];
}


/*
const char* Cliente::getMsgEnviada(void)
{
	return &mensagem->getConteudo().c_str();
}
 */


char* Cliente::getMsgRecebida(void)
{
	char *vetor;
	vetor = new char[tamanhoMsgReceb];
	vetor = &msgRecebida[0];

	return vetor;
}

void Cliente::setTamanhoMsgRecebida(int tamanho)
{
	tamanhoMsgReceb = tamanho;
}

void Cliente::setTamanhoMsgEnviada(int tamanho)
{
	tamanhoMsgEnviada = tamanho;
}

int Cliente::getTamanhoMsgRecebida(void)
{
	return tamanhoMsgReceb;
}
int Cliente::getTamanhoMsgEnviada(void)
{
	return tamanhoMsgEnviada;
}


void Cliente::setSockServer(struct sockaddr_in aux)
{
	servidor.sin_family = AF_INET;
	servidor.sin_addr.s_addr = htonl(inet_addr(IPChar));
	servidor.sin_port = htons(porta);
}


void Cliente::setMeuSocket(int valor)
{
	meusocket = valor;
}

int Cliente::getMeuSocket(void)
{
	return meusocket;
}

#ifndef unix
int Cliente::iniciaSockClient(void)
{

	WSAStartup(MAKEWORD(2, 0), &wsa_data);

	meusocket = (socket(AF_INET,SOCK_STREAM,0));
	memset(&(servidor.sin_zero),'\0', sizeof(servidor.sin_zero));
	return connect(meusocket, pontSock,sizeof(struct sockaddr));

}
#else
int Cliente::iniciaSockClient(void)
{

	meusocket = (socket(AF_INET,SOCK_STREAM,0));
	memset(&(servidor.sin_zero),'\0', sizeof(servidor.sin_zero));
	if(conexao = (connect(meusocket, pontSock,sizeof(struct sockaddr)))!=0)
	{
		return -1;
	}
	return 0;
}
#endif

void Cliente::enviaMsg(void)
{
	send(meusocket, msgEnviada, tamanhoMsgEnviada, 0);
}

void Cliente::enviaMsg(int numero)
{
	send(meusocket, mensagem->getConteudo().data(), mensagem->getConteudo().length(), 0);
}


/*
void Cliente::enviaTymered()
{
	if(tymerCliente.acionaTymer())
	{
		send(meusocket, msgEnviada, tamanhoMsgEnviada, 0);
	}
}
 */
void Cliente::recebeMensagem(void)
{
	tamanhoMsgReceb = recv(meusocket, msgRecebida, tamanhoMsgReceb, 0);
}

Cliente::~Cliente()
{
	delete msgEnviada;

	delete msgRecebida;
}

//int ReadLine()
//{
int Cliente::ReadLine()
{
	msgRec.clear();

	char c;

	int tamanho;

	while (1)
	{

		switch(recv(meusocket, &c, 1, 0))
		{
		case 0:
			return 0;

		case -1:
			return -1;

		}

		msgRec += c;
		if (c == '\n')
		{
			break;
		}
		tamanho++;
	}

	return tamanho;
}

string Cliente::getMsgRec()
{
	return msgRec;
}

int Cliente::WriteLine(const char* msg)
{
	mensagem->setConteudo(msg);
	mensagem->insereFinal('\n');
	return send(meusocket, mensagem->getConteudo().c_str(), mensagem->getConteudo().length(), 0);
}
