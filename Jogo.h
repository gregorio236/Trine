#ifndef JOGO_H
#define JOGO_H

#include <vector>
using namespace std;

#include "libUnicornio.h"

#include "Personagem.h"
#include "Curandeiro.h"
#include "Guerreiro.h"
#include "Necromante.h"
#include "GerenciadorObjetos.h"

class Jogo
{
public:
	Jogo();
	~Jogo();

	void inicializar();
	void finalizar();

	void executar();

private:
	Personagem * jogador;
	Curandeiro* curandeiro;
	Guerreiro* guerreiro;
	Necromante* necromante;

	Som musica;
};

#endif