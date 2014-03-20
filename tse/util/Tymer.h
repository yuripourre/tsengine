/*
 * Tymer.h
 *
 *  Created on: 26/10/2009
 *      Author: Yuri Pourre
 */

#ifndef TYMER_H_
#define TYMER_H_

class Tymer
{

private:

	bool ativado;
	int freq;
	unsigned int tempo;

public:

	Tymer();
	Tymer(int freq);
	virtual ~Tymer();

	//Gets
	bool getAtivado() const;
	int getFreq() const;

	//Sets
	void setAtivado(bool ativado);
	void setFreq(int freq);

	bool acionaTymer();

	int getTicks();

	void zeraTymer();

};

#endif /* TYMER_H_ */
