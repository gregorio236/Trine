#include "GerenciadorColisao.h"

GerenciadorColisao::GerenciadorColisao()
{

}

GerenciadorColisao::~GerenciadorColisao()
{

}

bool GerenciadorColisao::testarComJogador(Caixa* caixa, float dx, float dy)
{
	Personagem* j = Jogo::getJogador();
	if (uniTestarColisaoSpriteComSprite(caixa->getSprite(), dx, dy, 0.0f,
		j->getSprite(), j->getX(), j->getY(), 0.0f))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool GerenciadorColisao::testarComCaixas(float dx, float dy)
{
	return false;
}

bool GerenciadorColisao::testarComCaixas(Caixa * caixa, float dx, float dy)
{
	return false;
}
