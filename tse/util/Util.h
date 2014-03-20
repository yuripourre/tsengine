/*
 * Util.h
 *
 *  Created on: 07/01/2010
 *      Author: Yuri
 */

#ifndef UTIL_H_
#define UTIL_H_

#include <iostream>
#include <sstream>
#include <string>

using std::string;

int stoi(string buffer);

string itos(int valor);

int expInt(int base, int expoente);

/*
int operator ^(int base, int expoente){
	return expInt(base, expoente);
}
*/

#endif /* SDL_RANDOM_H_ */
