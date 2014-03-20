/*
 * Teclado.h
 *
 *
 *      Author: Yuri
 */
#ifndef TECLADO_H_
#define TECLADO_H_

class Teclado{

private:
	//Ascii + Caracteres Extras

	int numeroTeclas;

	bool* tecla;
	bool* trava;

	//Teclas Persistentes

	bool apostrofo;         // 39
	bool acentoCircunflexo; // 94
	bool acentoGrave;       // 96
	bool til;               // 126
	bool trema;             // 168
	bool acentoAgudo;       // 180
	bool capsLockPersiste;  //Persistente

public:
	//Construtor
	Teclado();
	~Teclado();

	bool* getTeclas();
	bool getTecla(int indice);
	void setTecla(int indice, bool press);

	bool* getTravas();
	void setTrava(int indice, bool press);
	bool getTrava(int indice);

	int getNumeroTeclas(void);


	bool getCima(void);
	bool getBaixo(void);
	bool getDireita(void);
	bool getEsquerda(void);

	bool getShiftD(void);
	bool getShiftE(void);
	bool getAltD(void);
	bool getAltE(void);
	bool getCtrlD(void);
	bool getCtrlE(void);
	bool getCapsLock(void);
	bool getCapsLockPersiste(void);
	bool getPrintScreen(void);
	bool getF(int posit);

	bool getApostrofo(void);
	bool getAcentoCircunflexo(void);
	bool getAcentoGrave(void);
	bool getTil(void);
	bool getTrema(void);
	bool getAcentoAgudo(void);

	bool getMaiusculo(void);


	void setCima(bool press);
	void setBaixo(bool press);
	void setDireita(bool press);
	void setEsquerda(bool press);

	void setCapsLockPersiste(void);
	void setApostrofo(bool persiste);
	void setAcentoCircunflexo(bool persiste);
	void setAcentoGrave(bool persiste);
	void setTil(bool persiste);
	void setTrema(bool persiste);
	void setAcentoAgudo(bool persiste);


	/*
	 * Teclas Ascii
	 *
	 * 000 Nulo
	 *
	 * 008 Backspace
	 * 009 TAB
	 *
	 * 013 Enter
	 *
	 * 015 Shift
	 *
	 * 027 Escape
	 *
	 * 032 Espaço
	 * 033 !
	 * 034 "
	 * 035 #
	 * 036 $
	 * 037 %
	 * 038 &
	 * 039 '
	 * 040 (
	 * 041 )
	 * 042 *
	 * 043 +
	 * 044 , ( vírgula )
	 * 045 - ( hífen )
	 * 046 . ( ponto )
	 * 047 / ( barra )
	 * 048 0
	 * 049 1
	 * 050 2
	 * 051 3
	 * 052 4
	 * 053 5
	 * 054 6
	 * 055 7
	 * 056 8
	 * 057 9
	 * 058 :
	 * 059 ;
	 * 060 <
	 * 061 =
	 * 062 >
	 * 063 ?
	 * 064 @
	 * 065 A
	 * 066 B
	 * 067 C
	 * 090 Z
	 * 091 [
	 * 092 \
	 * 093 ]
	 * 094 ^ ( acento circunflexo )
	 * 095 _ (underline)
	 * 096 ` ( acento grave )
	 * 097 a
	 * 098 b
	 * 099 c
	 * 122 z
	 * 123 {
	 * 124 |
	 * 125 }
	 * 126 ~
	 * 127 Delete
	 * 168 ¨ ( trema )
	 * 172 ¬
	 * 180 ´ ( acento agudo )
	 *
	 *
	 *
	 * 256 TN 0
	 * 265 TN 9
	 * 266 TN DIVIDE
	 * 267 TN ENTER
	 * 268 TN =
	 * 269 TN -
	 * 270 TN *
	 * 271 TN .
	 * 272 TN +
	 * 273 INSERT
	 * 274 HOME
	 * 275 PAGEUP
	 * 276 PAGEDOWN
	 * 277 END
	 * 278 F1
	 * 292 F15
	 * 293 PRINT SCREEN
	 * 294 CAPS LOCK
	 * 295 SETINHA CIMA
	 * 296 SETINHA BAIXO
	 * 297 SETINHA DIREITA
	 * 298 SETINHA ESQUERDA
	 * 299 SHIFT ESQUERDO
	 * 300 SHIFT DIREITO
	 * 301 CONTROL ESQUERDO
	 * 302 CONTROL DIREITO
	 * 303 ALT ESQUERDO
	 * 304 ALT DIREITO
	 */



};

//==============================================================================

#endif
