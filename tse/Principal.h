/*
 * Principal.cpp
 *
 *      Author: Yuri Pourre
 */

#ifndef PRINCIPAL_H_
#define PRINCIPAL_H_

//Lista de módulos utilizados
#include "video/Tela.h"
#include "controle/PrincipalControle.h"

#include "util/Frase.h"
#include "util/SDL_Random.h"
#include "util/Util.h"

#include "camada/CamadaTextoRelativa.h"
#include "camada/CamadaPrimitiva.h"
//Personagem inclui todas as camadas relativas a imagem
//Mas será modificada
#include "inteligencia/Personagem.h"

#include "audio/PrincipalAudio.h"

#include "texto/PrincipalTexto.h"

#include "gui/PrincipalGui.h"
#include "gui/Botao.h"
#include "gui/BotaoCustom.h"
#include "gui/CampoTexto.h"
#include "gui/CampoTextoCustom.h"
#include "gui/RadioCustom.h"
#include "gui/GrupoRadio.h"

//#include "memoria/GerenciadorMemo.h"


//==============================================================================
class Principal
{

private:

	static Principal *_instancia;

	//Camada de Vídeo
	Tela* tela;
	SDL_Surface* screen;

	//Controle de Eventos
	PrincipalControle* evento;

	//Camada de Texto (SDL_ttf)
	PrincipalTexto* texto;

	//Camada de Audio (SDL_mixer)
	PrincipalAudio* jukebox;

	//Gerenciador de Memória
	//GerenciadorMemo* gerenciadorMemo;

	//PESTEngine PrincipalGui
	PrincipalGui* gui;

	//Tymer para controle de FPS
	Tymer* controleFPS;

	//Tymer para controle de Eventos
	//Tymer* controleEventos;


protected:
	Principal();

public:

	static Principal* Instancia();

	void atualiza();

	void finaliza();

	Tela* getJanela();

	void setTitulo(const char* novoTitulo);
	void setTamanhoJanela(int largura, int altura);
	void setFullScreen(bool fullscreen);

	PrincipalControle* getEvento(void);

	//GerenciadorMemo* Principal::getGerenciadorMemoria();

	PrincipalGui* getGui();

	Tymer* getControleFPS(void);
	//Tymer* getControleEventos(void);

	bool fechouJanela(void);

};

//==============================================================================
#endif
