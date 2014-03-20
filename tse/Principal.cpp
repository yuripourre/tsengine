#include "Principal.h"

//Singleton
Principal* Principal::_instancia = 0;

Principal::Principal()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	//Inicia SDL_Random()
	srand(SDL_GetTicks());

	//Inicia a tela
	tela = new Tela();

	//Ativa os Controles
	evento = new PrincipalControle();

	//Ativa o Som
	jukebox = new PrincipalAudio();

	//Ativa os textos SDL_TTF
	texto = new PrincipalTexto();

	//Habilita a PrincipalGui
	gui = new PrincipalGui("gui/tema1.bmp",20,"gui/arial.ttf");

	//Inicia o gerenciador de Memória
	//gerenciadorMemo = new GerenciadorMemo();

	controleFPS = new Tymer(100);

	//controleEventos = new Tymer(400);

}

void Principal::finaliza()
{

	//delete gerenciadorMemo;

	delete controleFPS;

	delete gui;

	delete texto;

	delete jukebox;

	delete evento;

	//delete controleEventos;

	delete tela;

	SDL_Quit();
}

void Principal::atualiza()
{
	//Desenha cursor do Mouse
	evento->getMouse()->desenha();

	SDL_Flip(tela->getScreen());
	SDL_FillRect(tela->getScreen(), NULL, SDL_MapRGB(tela->getScreen()->format, 0, 0, 0));
}


Tela* Principal::getJanela()
{
	return tela;
}
void Principal::setFullScreen(bool fullscreen)
{
	tela->setFullScreen(fullscreen);
}

PrincipalControle* Principal::getEvento()
{
	return evento;
}

//GerenciadorMemo* Principal::getGerenciadorMemoria()
//{
//	return gerenciadorMemo;
//}

PrincipalGui* Principal::getGui()
{
	return gui;
}

Tymer* Principal::getControleFPS(void)
{
	return controleFPS;
}
//Tymer* Principal::getControleEventos(void)
//{
	//return controleEventos;
//}
void Principal::setTitulo(const char* novoTitulo)
{
	tela->setTitulo(novoTitulo);
}
void Principal::setTamanhoJanela(int largura, int altura)
{
	tela->setTamanho(largura,altura);
}

bool Principal::fechouJanela(){
	return evento->getFechar();
}

//Singleton
Principal* Principal::Instancia()
{
	if ( _instancia == 0 )
	{
		_instancia = new Principal();
	}
	return _instancia;
}

