#include "Necromante.h"

Necromante::Necromante()
{
	gRecursos.carregarSpriteSheet("necromante", "assets/necromanteSheet.png", 4, 4);

	sprite.setSpriteSheet("necromante");
	sprite.setEscala(3.0f, 3.0f);

	som.setAudio("levitar");
}

Necromante::~Necromante()
{

}

void Necromante::poder()
{
	pegar();
}

void Necromante::inputs()
{
	if (gMouse.pressionou[BOTAO_MOUSE_ESQ])
	{
		poder();
	}
	else if (gMouse.segurando[BOTAO_MOUSE_ESQ])
	{
		levitar();
	}
	else if (gMouse.soltou[BOTAO_MOUSE_ESQ])
	{
		soltar();
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

void Necromante::pegar()
{
	caixa = GerenciadorObjetos::pegaCaixa(gMouse.x, gMouse.y);
	if (caixa != nullptr)
	{
		caixa->setEscala(1.5f);
		trocar = false;
		som.tocar();
	}
}

void Necromante::levitar()
{
	if (caixa != nullptr)
	{
		caixa->setPosicao(gMouse.x, gMouse.y);

		if (som.terminouDeTocar())
			som.tocar();
	}
}

void Necromante::soltar()
{
	if (caixa != nullptr)
	{
		caixa->setEscala(3.0f);
		caixa = nullptr;
		trocar = true;
		som.parar();
	}
}
