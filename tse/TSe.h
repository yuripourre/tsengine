/*
 * TSe.h
 *
 *  Created on: 03/01/2010
 *      Author: Yuri
 */

#ifndef TSENGINE_H_
#define TSENGINE_H_

#include "Principal.h"

namespace tse {

//extern SDLKey* uniTec;
extern Uint8* tecla;

extern Uint16 uniCod;
//extern bool* trava;
//extern bool* sairf;

extern Principal* principal;

//extern GerenciadorMemo* gerenciadorMemo;
extern PrincipalControle* evento;
extern PrincipalGui* gui;
extern SDL_Surface* tela;

extern Mouse* mouse;

extern int alturaTela;
extern int larguraTela;



extern void gerenciaEventos();
extern void atualizaTela();
extern void fechar();


//extern void iniciaPeste();

namespace primitivas
{
	enum prim
	{
		PRIM_PIXEL = 40,
		PRIM_BOX,
		PRIM_RECT,
		PRIM_LINHAH,
		PRIM_LINHAV,
		PRIM_LINHA,
		PRIM_LINHA_AA,
		PRIM_CIRCULO,
		PRIM_CIRCULO_AA,
		PRIM_CIRCULO_PREENCHIDO,
		PRIM_ELIPSE,
		PRIM_ELIPSE_AA,
		PRIM_ELIPSE_PREENCHIDA

	};
};

enum estadosMouse
{
	MOUSE_NORMAL = 89,
	MOUSE_TEXTO,
	MOUSE_OCUPADO,
	MOUSE_AJUDA,
	MOUSE_MOVER,
	MOUSE_HORIZONTAL,
	MOUSE_VERTICAL,
	MOUSE_DIAGONALP,
	MOUSE_DIAGONALS,

};

enum componentesGui
{
	GUI_BOTAO = 48,
	GUI_CAMPOTEXTO,
	GUI_RADIO,
	GUI_RADIO_CUSTOM,
	GUI_MENU,
	GUI_CAIXAMARCACAO,
	GUI_CAIXASELECAO,
	GUI_JANELA_ALERTA,
	GUI_JANELA_SIM_NAO

};

	namespace teclas
	{
		enum TSKeys
		{

			TSK_BACKSPACE = SDLK_BACKSPACE,

			TSK_ENTER = SDLK_RETURN,
			TSK_ESC = SDLK_ESCAPE,

			TSK_ESPACO = SDLK_SPACE,
			TSK_DELETE = SDLK_DELETE,


			TSK_NUMERICO_0 = SDLK_KP0,
			TSK_NUMERICO_1 = SDLK_KP1,
			TSK_NUMERICO_2 = SDLK_KP2,
			TSK_NUMERICO_3 = SDLK_KP3,
			TSK_NUMERICO_4 = SDLK_KP4,
			TSK_NUMERICO_5 = SDLK_KP5,
			TSK_NUMERICO_6 = SDLK_KP6,
			TSK_NUMERICO_7 = SDLK_KP7,
			TSK_NUMERICO_8 = SDLK_KP8,
			TSK_NUMERICO_9 = SDLK_KP9,
			TSK_NUMERICO_PONTO = SDLK_KP_PERIOD,
			TSK_NUMERICO_DIVIDE = SDLK_KP_DIVIDE,

			TSK_NUMERICO_MAIS = SDLK_KP_PLUS,
			TSK_NUMERICO_ENTER = SDLK_KP_ENTER,
			TSK_NUMERICO_IGUAL = SDLK_KP_EQUALS,

			TSK_NUMERICO_MENOS = SDLK_KP_MINUS,
			TSK_NUMERICO_MULTIPLICA = SDLK_KP_MULTIPLY,

			TSK_INSERT = SDLK_INSERT,
			TSK_HOME = SDLK_HOME,
			TSK_PAGE_UP = SDLK_PAGEUP,
			TSK_PAGE_DOWN = SDLK_PAGEDOWN,
			TSK_END = SDLK_END,

			TSK_F1 = SDLK_F1,
			TSK_F2 = SDLK_F2,
			TSK_F3 = SDLK_F3,
			TSK_F4 = SDLK_F4,
			TSK_F5 = SDLK_F5,
			TSK_F6 = SDLK_F6,
			TSK_F7 = SDLK_F7,
			TSK_F8 = SDLK_F8,
			TSK_F9 = SDLK_F9,
			TSK_F10 = SDLK_F10,
			TSK_F11 = SDLK_F11,
			TSK_F12 = SDLK_F12,
			TSK_F13 = SDLK_F13,
			TSK_F14 = SDLK_F14,
			TSK_F15 = SDLK_F15,

			TSK_PRINT_SCREEN = SDLK_PRINT,
			TSK_CAPS_LOCK = SDLK_CAPSLOCK,

			TSK_SETA_CIMA = SDLK_UP,
			TSK_SETA_BAIXO = SDLK_DOWN,
			TSK_SETA_DIREITA = SDLK_RIGHT,
			TSK_SETA_ESQUERDA = SDLK_LEFT,
			TSK_SHIFT_ESQUERDA = SDLK_LSHIFT,
			TSK_SHIFT_DIREITA = SDLK_RSHIFT,
			TSK_CTRL_ESQUERDA = SDLK_LCTRL,
			TSK_CTRL_DIREITA = SDLK_RCTRL,
			TSK_ALT_ESQUERDA = SDLK_LALT,
			TSK_ALT_DIREITA = SDLK_RALT,

			TSK_A = SDLK_a,
			TSK_B = SDLK_b,
			TSK_C = SDLK_c,
			TSK_D = SDLK_d,
			TSK_E = SDLK_e,
			TSK_F = SDLK_f,
			TSK_G = SDLK_g,
			TSK_H = SDLK_h,
			TSK_I = SDLK_i,
			TSK_J = SDLK_j,
			TSK_K = SDLK_k,
			TSK_L = SDLK_l,
			TSK_M = SDLK_m,
			TSK_N = SDLK_n,
			TSK_O = SDLK_o,
			TSK_P = SDLK_p,
			TSK_Q = SDLK_q,
			TSK_R = SDLK_r,
			TSK_S = SDLK_s,
			TSK_T = SDLK_t,
			TSK_U = SDLK_u,
			TSK_W = SDLK_w,
			TSK_V = SDLK_v,
			TSK_X = SDLK_x,
			TSK_Y = SDLK_y,
			TSK_Z = SDLK_z

		};
	};

};

#endif /* TSENGINE_H_ */
