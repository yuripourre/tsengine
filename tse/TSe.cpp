/*
 * TSe.cpp
 *
 *  Created on: 03/01/2010
 *      Author: Yuri
 */

#include "TSe.h"

namespace tse
{

Principal* principal = Principal::Instancia();
PrincipalControle* evento = principal->getEvento();
SDL_Surface* tela = principal->getJanela()->getScreen();

bool* uniTec = principal->getEvento()->getTeclado()->getTeclas();
bool* trava = principal->getEvento()->getTeclado()->getTravas();

Uint8* tecla = SDL_GetKeyState(NULL);

Mouse* mouse = evento->getMouse();

int alturaTela = principal->getJanela()->getAltura();
int larguraTela = principal->getJanela()->getLargura();
PrincipalGui* gui = principal->getGui();

//GerenciadorMemo* gerenciadorMemo = principal->getGerenciadorMemoria();

void gerenciaEventos()
{
	evento->gerenciaEvento();
}
void atualizaTela()
{
	principal->atualiza();
}



}
