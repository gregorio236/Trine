#include "Caixa.h"

Caixa::Caixa(float x, float y)
{
	this->x = x;
	this->y = y;

	sprite.setSpriteSheet("caixa");
	sprite.setEscala(3.0f, 3.0f);
}

Caixa::~Caixa()
{
}

Sprite Caixa::getSprite()
{
	return sprite;
}

float Caixa::getX()
{
	return x;
}

float Caixa::getY()
{
	return y;
}

void Caixa::setPosicao(float x, float y)
{
	deslocamentoX(this->x, x - this->x);
	deslocamentoY(this->y, y - this->y);
}

void Caixa::animar()
{
	sprite.avancarAnimacao();
}

void Caixa::desenhar()
{
	sprite.desenhar(x, y);
}

void Caixa::deslocamentoX(float & x, float vel)
{
	x += vel;
	float tam = sprite.getLarguraOriginal() * 3 / 2;
	if (vel < 0)
	{
		if (x < tam)
		{
			x = tam;
		}
	}
	else
	{
		if (x > gJanela.getLargura() - tam)
		{
			x = gJanela.getLargura() - tam;
		}
	}
}

void Caixa::deslocamentoY(float & y, float vel)
{
	y += vel;
	float tam = sprite.getAlturaOriginal() * 3 / 2;
	if (vel < 0)
	{
		if (y < tam)
		{
			y = tam;
		}
	}
	else
	{
		if (y > gJanela.getAltura() - tam)
		{
			y = gJanela.getAltura() - tam;
		}
	}
}