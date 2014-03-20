/*
 * Servidor.cpp
 *
 *      Created on: 22/08/2009 (+ou-)
 *      Author: Yuri
 */

#ifdef unix
#include "ServidorUnix.h"
#else
#include "Servidor.h"
#endif

Servidor::Servidor() {

        conexao = -1;

        porta = 8767;


        tamanhoMsgReceb = 0;

        tamanho  = sizeof(struct sockaddr_in);

        tamanhoMsg = 512;

        msgBuffer = new char[tamanhoMsg];

        msgRecebida = new char[tamanhoMsg];

        servidor.sin_family = AF_INET;
        servidor.sin_addr.s_addr = htonl(INADDR_ANY);
        servidor.sin_port = htons(porta);

        pontSock = (struct sockaddr *)const_cast <struct sockaddr_in*>(&servidor);
        pontClient = (struct sockaddr *)&cliente;
}

struct sockaddr_in Servidor::getCliente(void)
{
       return cliente;
}

void Servidor::setConexao(int conex){
     conexao = conex;
}

int Servidor::getConexao(void){
     return conexao;
}

void Servidor::setMsgBuffer(char novoValor [])
{

  int n=0;

  do {

    msgBuffer[n] = novoValor[n];

  } while (novoValor[n++] != '\0');

}


char* Servidor::getMsgBuffer(void)
{
      char *vetor;
      vetor = (char*) malloc(tamanhoMsg * sizeof (int));
      vetor = &msgBuffer[0];


      return vetor;
}

char* Servidor::getMsgRecebida(void)
{
      char *vetor;
      vetor = (char*) malloc(tamanhoMsg * sizeof (int));
      vetor = &msgRecebida[0];


      return vetor;
}

void Servidor::setTamanhoMsgRecebida(int tamanho)
{
     tamanhoMsgReceb = tamanho;
}

int Servidor::getTamanhoMsgRecebida(void)
{
    return tamanhoMsgReceb;
}

int Servidor::getTamanhoMsg(void)
{
    return tamanhoMsg;
}

const struct sockaddr* Servidor::getPontSock(void)
{
       return pontSock;
}

struct sockaddr* Servidor::getPontClient(void)
{
       return pontClient;
}

void Servidor::setSockServer(struct sockaddr_in aux)
{
    servidor.sin_family = AF_INET;
    servidor.sin_addr.s_addr = htonl(INADDR_ANY);
    servidor.sin_port = htons(porta);
}


void Servidor::setMeuSocket(int valor)
{
     meusocket = valor;
}

int Servidor::getMeuSocket(void)
{
     return meusocket;
}

void Servidor::iniciaSockServer(void)
{
    WSAStartup(MAKEWORD(2, 0), &wsa_data);

    meusocket = socket(AF_INET,SOCK_STREAM,0);

    memset(servidor.sin_zero,'\0', sizeof(servidor.sin_zero));

    bind(meusocket, pontSock, sizeof(struct sockaddr));

    listen(meusocket,1);
}
