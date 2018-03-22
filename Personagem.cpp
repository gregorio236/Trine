#include "Personagem.h"

float Personagem::x = 0.0f;
float Personagem::y = 0.0f;
float Personagem::vel = 2.0f;
bool Personagem::parado = true;
bool Personagem::trocar = true;

Personagem::Personagem()
{

}

Personagem::~Personagem()
{

}

int Personagem::getX()
{
	return x;
}

int Personagem::getY()
{
	return y;
}

int Personagem::getAnimacao()
{
	return sprite.getAnimacao();
}

bool Personagem::podeTrocar()
{
	return trocar;
}

void Personagem::setPos(int x, int y)
{
	this->x = x;
	this->y = y;
}

void Personagem::setAnimacao(int anim)
{
	sprite.setAnimacao(anim);
}

void Personagem::poder()
{

}

void Personagem::rodar()
{
	inputs();
	if (!parado)
		animar();
	desenhar();
}

void Personagem::inputs()
{
	if (gMouse.pressionou[BOTAO_MOUSE_ESQ])
	{
		poder();
	}

	if (gTeclado.segurando[TECLA_D])
	{
		deslocamentoX(x, vel);
		sprite.setAnimacao(DIREITA);
	}
	else if (gTeclado.segurando[TECLA_A])
	{
		deslocamentoX(x, -vel);
		sprite.setAnimacao(ESQUERDA);
	}
	else if (gTeclado.segurando[TECLA_W])
	{
		deslocamentoY(y, -vel);
		sprite.setAnimacao(CIMA);
	}
	else if (gTeclado.segurando[TECLA_S])
	{
		deslocamentoY(y, vel);
		sprite.setAnimacao(BAIXO);
	}
	else
	{
		parado = true;
		sprite.setFrame(0);
		return;
	}

	parado = false;
}

void Personagem::animar()
{
	sprite.avancarAnimacao();
}

void Personagem::desenhar()
{
	sprite.desenhar(x, y);
}

void Personagem::deslocamentoX(float & x, float vel)
{
	x += vel;
	float tam = sprite.getLargura() / 2;
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

void Personagem::deslocamentoY(float & y, float vel)
{
	y += vel;
	float tam = sprite.getAltura() / 2;
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
