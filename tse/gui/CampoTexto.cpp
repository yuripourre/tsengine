/*
 * CampoTexto.cpp
 *
 *
 *      Author: Yuri
 */
#include "CampoTexto.h"

#include "../TSe.h"
using tse::gui;
//using namespace peste;

//TERMINAR
//gerenciaLetra
//andaDireita

CampoTexto::CampoTexto()
{
	setCoordenadas(0,0);
	inicializar("");
}

CampoTexto::CampoTexto(int x, int y,const char* conteudo)
{
	setCoordenadas(x,y);
	inicializar(conteudo);
}

void CampoTexto::inicializar(const char* conteudo)
{

	setCoordLimite(gui->getTamanho()+100,gui->getTamanho());

	CamadaTexto* aux = new CamadaTexto("ABC");
	aux->carregaFonte(gui->getDirFonte(),gui->getTamanho()/2);
	aux->escreve();
	aux->centralizaY(getY(),getY()+getYLimite());

	texto = new CamadaTexto(conteudo);
	texto->carregaFonte(gui->getDirFonte(),gui->getTamanho()/2);
	texto->escreve();

	min = getX() + (gui->getTamanho()/10)+1;
	max = getXLimite()-(gui->getTamanho()/10)-1;
	somaLetras = 0;

	texto->setX(min);

	texto->setY(aux->getY());
	texto->setCoordImagem(0,0);
	texto->setCoordLimite(max,gui->getTamanho());

	delete aux;

	tymerCursor = new Tymer(500);

	ativado = false;

	cursor = new CamadaPrimitiva(tse::primitivas::PRIM_LINHAV);
	cursor->setCoordenadas(texto->getX(),texto->getY());
	//cursor->setCoordLimite(1,texto->getY()+texto->getYLimite()-1);
	cursor->setCoordLimite(1,texto->getY()+gui->getTamanho()/2);

	setCoordImagem(gui->getTamanho()*0,gui->getTamanho()*1);

	tymerTrava = new Tymer(50);

	cont = 0;
	travado = false;

	registra();

}
CampoTexto::~CampoTexto()
{

	delete tymerTrava;
	delete cursor;

	delete tymerCursor;
	delete texto;


}


void CampoTexto::setCor(int r, int g, int b)
{
	cursor->setCor(r,g,b);
	texto->setCorLetras(r,g,b);
	texto->escreve();
}

void CampoTexto::setAtivado(bool ativado)
{
	this->ativado = ativado;
}

void CampoTexto::andaDireita(void)
{

	if(texto->getFrase()->getCursor()<texto->getFrase()->getConteudo().length())
	{
		CamadaTexto* aux = new CamadaTexto(texto->getFrase()->getConteudo().at(texto->getFrase()->getCursor()));
		aux->setTamanhoFonte(gui->getTamanho()/2);
		aux->carregaFonte(gui->getDirFonte());
		aux->escreve();

		texto->getFrase()->setCursorDireita(1);

		//Anda Cursor
		cursor->setX(cursor->getX()+aux->getXLimite());

		if(cursor->getX()>getX()+max)
		{
			texto->setXImagem(texto->getXImagem()+(cursor->getX()-(getX()+max)));
			cursor->setX(getX()+max);
		}

		delete aux;
	}
}

void CampoTexto::andaEsquerda(void)
{

	if(texto->getFrase()->getCursor()>0)
	{
		texto->getFrase()->setCursorEsquerda(1);

		CamadaTexto* aux = new CamadaTexto(texto->getFrase()->getConteudo().at(texto->getFrase()->getCursor()));
		aux->setTamanhoFonte(gui->getTamanho()/2);
		aux->carregaFonte(gui->getDirFonte());
		aux->escreve();

		//Anda Cursor -
		cursor->setX(cursor->getX()-aux->getXLimite());

		if(cursor->getX()<min)
		{
			texto->setXImagem(texto->getXImagem()-(cursor->getX()-(getX()+max)));
			cursor->setX(min);
		}

		delete aux;
	}
	/*

		if(texto->getXLimite()<max-min)
		{

		}

		else
		{
			aux = new CamadaTexto(texto->getFrase()->getConteudo().at(texto->getFrase()->getCursor()-1));
			aux->setTamanhoFonte(gui->getTamanho()/2);
			aux->carregaFonte(gui->getDirFonte());
			aux->escreve();

			texto->getFrase()->setCursorEsquerda(1);

			cursor->setX(cursor->getX()-aux->getXLimite());
		}
	}
	else
	{
		cursor->setX(min);
		texto->getFrase()->setCursor(0);
	}
	 */
}

void CampoTexto::insereLetra(char letra)
{

	CamadaTexto* aux;

	aux = new CamadaTexto(texto->getFrase()->insereCursor(letra));
	texto->escreve();

	aux->setTamanhoFonte(gui->getTamanho()/2);
	aux->carregaFonte(gui->getDirFonte());
	aux->escreve();

	//Anda com o cursor
	cursor->setX(cursor->getX()+aux->getXLimite());

	if(cursor->getX()>getX()+max)
	{
		texto->setXImagem(texto->getXImagem()+(cursor->getX()-(getX()+max)));
		cursor->setX(getX()+max);
	}
	else
	{
		texto->setXLimite(getX()+max-min);
	}
	delete aux;

}
void CampoTexto::apagaLetraBackSpace(void)
{

	if(texto->getFrase()->getCursor()>0)
	{
		CamadaTexto* aux = new CamadaTexto(texto->getFrase()->apagaBackSpace());
		texto->escreve();

		aux->setTamanhoFonte(gui->getTamanho()/2);
		aux->carregaFonte(gui->getDirFonte());
		aux->escreve();
		cursor->setX(cursor->getX()-aux->getXLimite());

		delete aux;
	}

}
void CampoTexto::apagaLetraDelete(void)
{
	texto->getFrase()->apagaDel();
	texto->escreve();
}
void CampoTexto::inicioTexto(void)
{
	texto->setXImagem(0);

	texto->getFrase()->setCursor(0);
	texto->setXLimite(getX()+max-min);

	cursor->setX(min);
}
void CampoTexto::finalTexto(void)
{

	//TERMINAR
	int diferenca = texto->getImagem()->w>max-min;
	//Se o texto ultrapassar o campo
	if(diferenca>0)
	{
		cursor->setX(max);
		texto->setX(min-diferenca);
		//andaDireita();
	}
}

void CampoTexto::gerenciaLetra(Uint16 letra)
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

void CampoTexto::gerencia(void)
{

	using namespace tse::teclas;
	using tse::evento;

	if(evento->getSDLEvento().key.type == SDL_KEYUP)
	{
		travaS = 0;
		return;
	}


	if(evento->getSDLEvento().type == SDL_KEYDOWN)
	{
		gerenciaInput((Uint16)evento->getSDLEvento().key.keysym.unicode);
		cursor->setAparecendo(true);
	}
	if(evento->getTecla(TSK_DELETE))
	{
		gerenciaInput(TSK_DELETE);
	}

	if(evento->getTecla(TSK_BACKSPACE))
	{
		gerenciaInput(TSK_BACKSPACE);
	}


	if(evento->getTecla(TSK_HOME))
	{
		gerenciaInput(TSK_HOME);
	}

	if(evento->getTecla(TSK_END))
	{
		gerenciaInput(TSK_END);
	}

	//Rápido demais
	//if(tecla[SETA_DIREITA])
	if(evento->getTecla(TSK_SETA_DIREITA))
	{
		gerenciaInput(TSK_SETA_DIREITA);
	}

	//if(tecla[SETA_ESQUERDA])
	if(evento->getTecla(TSK_SETA_ESQUERDA))
	{
		gerenciaInput(TSK_SETA_ESQUERDA);
	}

}

void CampoTexto::desenha()
{
	int i;

	int metadeGui = gui->getTamanho()/2;
	int metadeBotao = getXLimite()/2;

	//Início
	gui->getTema()->desenhaSimples(getX(),getY(),getXImagem(),getYImagem(),metadeGui,gui->getTamanho(),tse::tela);

	//Meio
	for(i=0;i<(metadeBotao-metadeGui+1);i++)
	{
		gui->getTema()->desenhaSimples((getX()+metadeGui-1)+i,getY(),getXImagem()+metadeGui-1,getYImagem(),1,gui->getTamanho(),tse::tela);
		gui->getTema()->desenhaSimples((getX()+metadeBotao)+i,getY(),getXImagem()+metadeGui,getYImagem(),1,gui->getTamanho(),tse::tela);
	}

	//Fim
	gui->getTema()->desenhaSimples(getX()+getXLimite()-metadeGui+1,getY(),getXImagem()+metadeGui+1,getYImagem(),metadeGui-1,gui->getTamanho(),tse::tela);

	if(!texto->getFrase()->getConteudo().empty())
	{
		texto->desenha();
		//Terminar!
		//texto->desenhaSimples(texto->getX(),texto->getY(),0,0,(gui->getTamanho()/10),getYLimite(),tela);

		//Não esquecer
		//setCoordLimite(getImagem()->w,getImagem()->h)
	}

	if(ativado)
	{
		if(tymerCursor->acionaTymer())
		{
			cursor->mudaAparecendo();
		}
		if(piscaCursor)
		{
			cursor->setAparecendo(true);
			piscaCursor = false;
		}
		cursor->desenhaPrimitiva();
	}


}
void CampoTexto::gerenciaInput(int letra)
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

void CampoTexto::sobMouse(){tse::mouse->setEstado(tse::MOUSE_TEXTO);}
void CampoTexto::semMouse(){}
void CampoTexto::clickSobre(int press)
{

	//CamadaTexto* aux;
	//aux = new CamadaTexto(texto->getFrase()->getConteudo().at(texto->getFrase()->getConteudo().length()-1));
	//aux = new CamadaTexto(texto->getFrase()->getConteudo().at(2));
	//aux->igualaFonte(texto->getFonte());
	//aux->setTamanhoFonte(gui->getTamanho()/2);
	//aux->carregaFonte(gui->getDirFonte());
	//aux->escreve();


	//cursor->setX(aux->getXLimite());

	SDL_EnableUNICODE(SDL_ENABLE);

	setAtivado(true);

}
void CampoTexto::clickFora(int press)
{
	SDL_EnableUNICODE(SDL_DISABLE);
}
