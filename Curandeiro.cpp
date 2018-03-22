#include "Curandeiro.h"

Curandeiro::Curandeiro()
{
	gRecursos.carregarSpriteSheet("curandeiro", "assets/curandeiroSheet.png", 4, 4);

	sprite.setSpriteSheet("curandeiro");
	sprite.setEscala(3.0f, 3.0f);

	som.setAudio("tiro");
}

Curandeiro::~Curandeiro()
{

}

void Curandeiro::poder()
{
	Vetor2D direcao;
	direcao.x = gMouse.x - x;
	direcao.y = gMouse.y - y;
	GerenciadorObjetos::criarTiro(x, y, direcao);

	som.tocar();
}
