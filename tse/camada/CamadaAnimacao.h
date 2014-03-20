/*
 * CamadaAnimacao.h
 *
 *
 *      Author: `Yuri
 */

#ifndef CAMADAANIMACAO_H_
#define CAMADAANIMACAO_H_

#include "Camada.h"
#include "../util/Tymer.h"

class CamadaAnimacao : public Camada{

protected:
	//Animação
	int	fatorAnima;
	int	modAnima;
	//int freqAnima;

	bool ativaAnima;
	bool positivoAnima;
	bool animaEmX;
	bool oscilarAnima;
	bool once;

	//Fade
	//int freqFade;
	//int	fatorFade;

	//bool ativaFade;
	//bool fade;
	//bool fadeIn;
	//bool oscilarFade;


	Tymer* tymerAnima;

    //Tymer tymerFade;


public:

	CamadaAnimacao();
	~CamadaAnimacao();

	void setAnimaEmX();
	void setAnimaEmY();

	void acionaAnimacao();
	//void acionaFade();

	void setAtivaAnima(bool aciona);
	//void setAtivaFade(bool aciona);

	void setNumeroFrames(int mod);

	void setFrequenciaAnima(int frequencia);
	//void setFrequenciaFade(int frequencia);

	void setFatorAnima(int fator);

	//void setFade(bool aciona);

	void setOscilarAnima(bool aciona);

	int getFatorAnima();

};

//==============================================================================

#endif
