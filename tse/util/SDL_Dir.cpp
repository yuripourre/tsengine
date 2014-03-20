/*
 * SDL_Dir.cpp
 *
 *  Created on: 05/10/2010
 *      Author: Yuri
 */

#include "SDL_Dir.h"

SDL_Dir::SDL_Dir() {
	// TODO Auto-generated constructor stub
}
SDL_Dir::SDL_Dir(const char *caminho){
	listdir(caminho);
}

SDL_Dir::~SDL_Dir() {
	// TODO Auto-generated destructor stub
}

bool SDL_Dir::listdir(const char *caminho)
{
	/*
	 * adapted from listdir of
	 * Danny Battison - gabehabe@hotmail.com
	 */
	string testep;

	DIR *pdir = NULL;
	pdir = opendir (caminho);
	struct dirent *pent = NULL;
	if (!pdir)
	{
		return false;
	}

	while (pent = readdir(pdir))
	{
		if (!pent)
		{
			return false;
		}
		testep=caminho;
		testep+="\\";
		testep+=pent->d_name;

		if(ehPasta(testep.data()))
			pastas.push_back(pent->d_name);
		else
			arquivos.push_back(pent->d_name);
	}

	closedir (pdir);
	return true;
}

bool SDL_Dir::ehPasta(const char* caminho)
{
	DIR *pdir = NULL;
	pdir = opendir (caminho);
	if (!pdir)
	{
		return false;
	}
	closedir (pdir);
	return true;
}

list<string> SDL_Dir::getArquivos(){
	return arquivos;
}
