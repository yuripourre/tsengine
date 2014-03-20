/*
 * Arquivo.cpp
 *
 *      Created on: 22/08/2009 (+ou-)
 *      Author: Yuri
 */

#include <fstream>

using namespace std;
/*
Arquivo::Arquivo()
{
	//infile.open ("test.txt", ifstream::in);
}
Arquivo::~Arquivo()
{
	ifs.close();
}
bool Arquivo::abrirArquivo()
{
	ifs.open ( caminho ,ifstream::binary);
	if (ifs.is_open())
	{
		ifs.seekg(0,ifstream::end);
		tamanho = ifs.tellg();
		ifs.seekg(0);
		return true;
	}
	return false;
}

long Arquivo::getTamanho(void)
{
	return tamanho;
}
 */
void lerArquivo(char* caminho , char* buffer)
{
	long tamanho;
	fstream is;

	is.open (caminho, ios::binary );

	// get length of file:
	is.seekg (0, ios::end);
	tamanho = is.tellg();
	is.seekg (0, ios::beg);

	// allocate memory:
	buffer = new char [tamanho];

	// read data as a block:
	is.read (buffer,tamanho);
	is.close();
}

void escreverNoFim(char* caminho , char* buffer)
{
	long tamanho;

	fstream os(caminho, ios_base::app | ios_base::out);

	os.write (buffer,tamanho);
	os.close();
}

