/*
 * CamadaMovel.h
 *
 *
 *      Author: Yuri
 */
#ifndef _CAMADAMOVEL_H_
#define _CAMADAMOVEL_H_

#include "CamadaAnimacao.h"

class CamadaMovel : public CamadaAnimacao{

private:

	int maxX;
	int minX;

	int maxY;
	int minY;

	int fatorX;
	int fatorY;

	bool positivoEmX;
	bool positivoEmY;

	bool moveEmX;
	bool moveEmY;

	bool oscilarX;
	bool oscilarY;

	Tymer* tymerX;
	Tymer* tymerY;


public:

	CamadaMovel();
	~CamadaMovel();

	//Sets
	void setMaxX(int max);
	void setMaxY(int max);

	void setMinX(int min);
	void setMinY(int min);

	void setFreqX(int frequencia);
	void setFreqY(int frequencia);

	void setOscilarX(bool aciona);
	void setOscilarY(bool aciona);

	void setMoveEmX(bool aciona);
	void setMoveEmY(bool aciona);

	//Gets
	int getMaxX(void);
	int getMaxY(void);

	int getMinX(void);
	int getMinY(void);

	int getFreqX(void);
	int getFreqY(void);

	bool getOscilarX(void);
	bool getOscilarY(void);

	bool getMoveEmX(void);
	bool getMoveEmY(void);

	bool getPositivoEmX(void);
	bool getPositivoEmY(void);

	//Movimentos
	void acionaMovimentoX();
	void acionaMovimentoY();

};

//==============================================================================

#endif
