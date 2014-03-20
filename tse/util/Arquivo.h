/*
 * Arquivo.h
 *
 *      Created on: 22/08/2009 (+ou-)
 *      Author: Yuri
 */

#ifndef _ARQUIVO_H_
#define _ARQUIVO_H_

#include <fstream>
using namespace std;

class Arquivo
{

private:
	char * conteudo;
	char * caminho;
	long tamanho;
	fstream ifs;

public:
	Arquivo();
	//ArquivoEntrada(char* caminho);
	~Arquivo();

	bool abrirArquivo();

	long getTamanho();

	void lerArquivo(char* buffer);

	void escreverNoFim(char* frase);
	void escreverNoInicio(char* frase);


	//void escreve no fim
	//fstream io_data("arquivo.txt", ios_base::app | ios_base::out);

};
#endif
/*
// Copy a file
#include <fstream>
using namespace std;

int main () {

  char * buffer;
  long size;

  ifstream infile ("test.txt",ifstream::binary);
  ofstream outfile ("new.txt",ofstream::binary);

  // get size of file
  infile.seekg(0,ifstream::end);
  size=infile.tellg();
  infile.seekg(0);

  // allocate memory for file content
  buffer = new char [size];

  // read content of infile
  infile.read (buffer,size);

  // write to outfile
  outfile.write (buffer,size);

  // release dynamically-allocated memory
  delete[] buffer;

  outfile.close();
  infile.close();
  return 0;
}
 */
