/*
 * CamadaTexto.cpp
 *
 *
 *      Author: Yuri Pourre
 */
#include "CamadaTexto.h"

#include "../TSe.h"
//using namespace peste;
//==============================================================================

CamadaTexto::CamadaTexto()
{
	frase = new Frase();

	inicializar();

	tamanhoFonte = 20;

}

CamadaTexto::CamadaTexto(int conteudo)
{

	this->frase = new Frase(conteudo);

	inicializar();


	tamanhoFonte = 20;

}

CamadaTexto::CamadaTexto(const char* conteudo)
{

	this->frase = new Frase(conteudo);

	inicializar();


	tamanhoFonte = 20;

}

CamadaTexto::CamadaTexto(const char* conteudo, int tamanhoFonte)
{
	this->frase = new Frase(conteudo);

	inicializar();

	this->tamanhoFonte = tamanhoFonte;

}

CamadaTexto::CamadaTexto(const char* conteudo, int tamanhoFonte, const char* arquivoFonte)
{

	this->frase = new Frase(conteudo);

	inicializar();

	carregaFonte(arquivoFonte);

	this->tamanhoFonte = tamanhoFonte;

}

CamadaTexto::CamadaTexto(char c)
{

	frase = new Frase(c);

	inicializar();

	//cursor = 1;
}


void CamadaTexto::carregaFonte(const char* arquivoFonte)
{
	if(arquivoFonte!='\0')
	{
		fonte = TTF_OpenFont( arquivoFonte, tamanhoFonte );
	}
	else
	{
		//Log
		return;
	}
}

void CamadaTexto::inicializar()
{
	corLetras.r = 0;
	corLetras.g = 0;
	corLetras.b = 0;

	corFundo.r = 0;
	corFundo.g = 0;
	corFundo.b = 0;

	render = 0;
}

void CamadaTexto::setRender(int render){
	this->render = render;
}

void CamadaTexto::carregaFonte(const char* arquivoFonte, int tamanhoFonte)
{
	this->tamanhoFonte = tamanhoFonte;

	fonte = TTF_OpenFont( arquivoFonte, this->tamanhoFonte );

	/*
	if(fonte==NULL)
	{
		//LOG
	}
	 */
}

void CamadaTexto::igualaFonte(TTF_Font* fonte)
{
	this->fonte = fonte;
}
TTF_Font* CamadaTexto::getFonte(void)
{
	return fonte;
}

void CamadaTexto::escreve()
{
	if(frase->getConteudo().empty())
	{
		setCoordLimite(0,0);
		return;
	}

	else
	{
		if (render == RENDER_SOLID)
		{
			igualaImagem(TTF_RenderText_Solid( fonte, frase->getConteudo().data(), corLetras ));
		}
		else if (render == RENDER_BLENDED)
		{
			igualaImagem(TTF_RenderText_Blended( fonte , frase->getConteudo().data(), corLetras));
		}
		else if (render == RENDER_SHADED)
		{
			igualaImagem(TTF_RenderText_Shaded( fonte, frase->getConteudo().data(), corLetras , corFundo));
		}

		setCoordLimite(getImagem()->w,getImagem()->h);

	}

}

void CamadaTexto::desenha()
{
	if(getFrase()->getConteudo().empty())
	{
		return;
	}

	if(getAparecendo())
	{
		SDL_Rect rect;

		rect.x = getX();
		rect.y = getY();

		SDL_Rect rect2;

		rect2.x = getXImagem();
		rect2.y = getYImagem();
		rect2.w = getXLimite();
		rect2.h = getYLimite();


		SDL_BlitSurface(getImagem(), &rect2, tse::tela, &rect);
	}
}

Frase* CamadaTexto::getFrase(void)
{
	return frase;
}
const char* CamadaTexto::getConteudo(void)
{
	return frase->getConteudo().data();
}

void CamadaTexto::setCorLetras(int r, int g, int b)
{
	corLetras.r = r%256;
	corLetras.g = g%256;
	corLetras.b = b%256;
	//escreve();
}

void CamadaTexto::setCorLetras(SDL_Color cor)
{
	corLetras.r = cor.r;
	corLetras.g = cor.g;
	corLetras.b = cor.b;
	//escreve();
}

void CamadaTexto::setCorFundo(int r, int g, int b)
{
	corFundo.r = r%256;
	corFundo.g = g%256;
	corFundo.b = b%256;
}

void CamadaTexto::setTamanhoFonte(int tamanhoFonte)
{
	this->tamanhoFonte = tamanhoFonte;
	//escreve();
}

int CamadaTexto::getTamanhoFonte(void)
{
	return tamanhoFonte;
}

CamadaTexto::~CamadaTexto()
{
	TTF_CloseFont(fonte);
	delete frase;
}
void CamadaTexto::setConteudo(const char* novoValor)
{
	frase->setConteudo(novoValor);
	escreve();
}
void CamadaTexto::setConteudo(int novoValor)
{
	frase->setConteudo(itos(novoValor).c_str());
	escreve();
}
