/*
 * SDL_Dir.h
 *
 *  Created on: 05/10/2010
 *      Author: Yuri
 */

#ifndef SDL_DIR_H_
#define SDL_DIR_H_

#include <dirent.h>
#include <iostream>
#include <list>
using namespace std;

class SDL_Dir {

private:
	list<string> arquivos;
	list<string> pastas;

protected:
	bool ehPasta(const char* caminho);

public:
	SDL_Dir();
	SDL_Dir(const char *caminho);
	virtual ~SDL_Dir();

	bool listdir(const char* caminho);

	list<string> getArquivos();


};

#endif /* SDL_DIR_H_ */
