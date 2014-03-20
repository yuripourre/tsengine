/*
 * Mouse.cpp
 *
 *
 *      Author: Yuri
 */

#include "Mouse.h"

#include "../TSe.h"
//using namespace peste;

Mouse::Mouse()
{

	setCoordenadas(100,100);
	setCoordLimite(32,32);
	setCoordImagem(0,0);

	xCursor = 0;
	yCursor = 0;

	pressionado = 0;

	normal = new CamadaEstatica();
	texto = new CamadaEstatica("gui/cursor/texto.png");
	ocupado = new CamadaEstatica("gui/cursor/ocupado.png");
	ajuda = new CamadaEstatica("gui/cursor/ajuda.png");
	mover = new CamadaEstatica("gui/cursor/mover.png");
	horizontal = new CamadaEstatica("gui/cursor/horizontal.png");
	vertical = new CamadaEstatica("gui/cursor/vertical.png");
	diagonalP = new CamadaEstatica("gui/cursor/diagonalp.png");
	diagonalS = new CamadaEstatica("gui/cursor/diagonals.png");

	extra = new CamadaEstatica("gui/cursor/normal.png");
	normal->igualaImagem(extra);

	setEstado(tse::MOUSE_NORMAL);
	SDL_ShowCursor(SDL_DISABLE);

	centralizaX(0,tse::larguraTela);
	centralizaY(0,tse::alturaTela);

}

Mouse::~Mouse()
{
	delete extra;

	delete diagonalS;
	delete diagonalP;
	delete vertical;
	delete horizontal;
	delete mover;
	delete ajuda;
	delete ocupado;
	delete texto;
	delete normal;
}

void Mouse::setPressionado(int pressionado)
{
	this->pressionado = pressionado;
	//1 = esquerda
	//2 = direita
	//3 = meio
}
int Mouse::getPressionado(void)
{
	return pressionado;
	//1 = esquerda
	//2 = direita
	//3 = meio
}
bool Mouse::getRodinhaBaixo()
{
	return rodinhaBaixo;
}
bool Mouse::getRodinhaCima()
{
	return rodinhaCima;
}

void Mouse::setRodinhaBaixo(bool press)
{
	rodinhaBaixo = press;
}
void Mouse::setRodinhaCima(bool press)
{
	rodinhaCima = press;
}
void Mouse::setEstado(int estadoMouse)
{
	estado = estadoMouse;
	switch (estado)
	{
	case tse::MOUSE_AJUDA:
		igualaImagem(ajuda->getImagem());
		//Deslocar o offset do Cursor.
		break;
	case tse::MOUSE_DIAGONALP:
		igualaImagem(diagonalP->getImagem());
		break;
	case tse::MOUSE_DIAGONALS:
		igualaImagem(diagonalS->getImagem());
		break;
	case tse::MOUSE_MOVER:
		igualaImagem(mover->getImagem());
		break;
	case tse::MOUSE_NORMAL:
		igualaImagem(normal->getImagem());
		break;
	case tse::MOUSE_OCUPADO:
		igualaImagem(ocupado->getImagem());
		break;
	case tse::MOUSE_TEXTO:
		igualaImagem(texto->getImagem());
		break;
	}
}
void Mouse::setCursor(CamadaEstatica* cursor){
	normal->igualaImagem(cursor);
}
void Mouse::normalCursor(){
	normal->igualaImagem(extra);
}
bool Mouse::sobreArea(int xq, int yq, int limxq, int limyq)
{
	int x = this->x+xCursor;
	int y = this->y+yCursor;

	if((x<xq)||(x>xq + limxq))
	{
		return false;
	}
	if((y<yq)||(y>yq + limyq))
	{
		return false;
	}

	return true;
}
bool Mouse::sobreBox(Camada* b)
{
	int x = this->x+xCursor;
	int y = this->y+yCursor;

	int xq = b->getX();
	int yq = b->getY();
	int limxq = b->getXLimite();
	int limyq = b->getYLimite();

	if((x<xq)||(x>xq + limxq))
	{
		return false;
	}
	if((y<yq)||(y>yq + limyq))
	{
		return false;
	}

	return true;
}
bool Mouse::sobreIso(Camada *b){

	int my = b->getYLimite()/2;
	int mx = b->getXLimite()/2;

	int x = this->x+xCursor-b->getX();
	int y = this->y+yCursor-b->getY();

	if(y>+my)
		y=my-(y-my);

	if(x>mx+1+(2*y))
		return false;
	else if(x<mx-1-(2*y))
		return false;
	else
		return true;

}

bool Mouse::sobreCirculo(Camada *b){

	int my = b->getY()+b->getYLimite()/2;
	int mx = b->getX()+b->getXLimite()/2;

	int x = this->x+xCursor;
	int y = this->y+yCursor;

	//(x-x0)^2+(y-y0)^2 < raio

	if((x-mx)*(x-mx)+(y-my)*(y-my)<=mx)
		return true;
	else
		return false;

}

bool Mouse::sobreCor(Camada *b, int red, int green, int blue){

	SDL_Color no;
	no.r = red;
	no.g = green;
	no.b = blue;

	SDL_Color pic;

	if(sobreBox(b)){

		pic = getPixel(x,y,b->getImagem());

		if((no.r!=pic.r)&&
		   (no.g!=pic.g)&&
		   (no.b!=pic.b)){
			return true;
		}
	}

	return false;

}
