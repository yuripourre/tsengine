/*
 * AreaUtil.h
 *
 *  Created on: 08/11/2009
 *      Author: Yuri
 */

#ifndef AREAUTIL_H_
#define AREAUTIL_H_

#include "AreaColisao.h"

class AreaUtil {
private:

	int areas;
	AreaColisao *vetor;


public:

	AreaUtil();
	AreaUtil(int areas);

	virtual ~AreaUtil();
	void setNumeroAreas(int areas);

	AreaColisao getArea(int indice);
	void setArea(int indice, int x1, int y1, int x2,int y2);

};

#endif /* AREAUTIL_H_ */
