#ifndef PERSONAGEM_H
#define PERSONAGEM_H

#include <vector>
using namespace std;

#include "libUnicornio.h"

enum animacao
{
	DIREITA,
	BAIXO,
	ESQUERDA,
	CIMA
};

class Personagem
{
public:
	Personagem();
	~Personagem();

	Sprite getSprite();
	int getX();
	int getY();

	int getAnimacao();

	bool podeTrocar();

	void setPos(int x, int y);

	void setAnimacao(int anim);
	virtual void rodar();

protected:
	static bool parado;
	static bool trocar;

	Sprite sprite;
	static float x, y;
	static float vel;

	virtual void poder();
	virtual void inputs();
	virtual void animar();
	virtual void desenhar();

	void deslocamentoX(float &x, float vel);
	void deslocamentoY(float &y, float vel);
};

#endif