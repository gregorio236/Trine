#ifndef GERENCIADORCOLISAO_H
#define GERENCIADORCOLISAO_H

#include <vector>
using namespace std;

#include "libUnicornio.h"
#include "Jogo.h"
#include "Caixa.h"

static class GerenciadorColisao
{
public:
	GerenciadorColisao();
	~GerenciadorColisao();

	static bool testarComJogador(Caixa* caixa, float dx, float dy);
	static bool testarComCaixas(float dx, float dy);
	static bool testarComCaixas(Caixa* caixa, float dx, float dy);
};

#endif