#include "Jogo.h"

Jogo::Jogo()
{
}

Jogo::~Jogo()
{
}

void Jogo::inicializar()
{
	uniInicializar(800, 600, false);

	gJanela.setCorDeFundo(75, 75, 75);

	gRecursos.carregarSpriteSheet("tiro", "assets/tiroSheet.png", 1, 32);
	gRecursos.carregarSpriteSheet("caixa", "assets/caixaSheet.png", 1, 1);

	gRecursos.carregarAudio("tiro", "assets/tiro.wav");
	gRecursos.carregarAudio("bola", "assets/bola.wav");
	gRecursos.carregarAudio("levitar", "assets/levitar.mp3");
	gRecursos.carregarAudio("fundo", "assets/fundo.mp3");

	curandeiro = new Curandeiro();
	guerreiro = new Guerreiro();
	necromante = new Necromante();

	jogador = curandeiro;
	jogador->setPos(gJanela.getLargura() / 2, gJanela.getAltura() / 2);

	GerenciadorObjetos::criarCaixa(new Caixa(100.0f, 100.0f));
	GerenciadorObjetos::criarCaixa(new Caixa(200.0f, 200.0f));

	musica.setAudio("fundo");
	musica.tocar();
}

void Jogo::finalizar()
{
	gRecursos.descarregarTudo();
	uniFinalizar();
}

void Jogo::executar()
{
	while (!gTeclado.soltou[TECLA_ESC] && !gEventos.sair)
	{
		uniIniciarFrame();

		if (jogador->podeTrocar())
		{
			if (gTeclado.pressionou[TECLA_1])
			{
				curandeiro->setAnimacao(jogador->getAnimacao());
				jogador = curandeiro;
			}
			else if (gTeclado.pressionou[TECLA_2])
			{
				guerreiro->setAnimacao(jogador->getAnimacao());
				jogador = guerreiro;
			}
			else if (gTeclado.pressionou[TECLA_3])
			{
				necromante->setAnimacao(jogador->getAnimacao());
				jogador = necromante;
			}
		}

		GerenciadorObjetos::rodar();

		jogador->rodar();

		if (musica.terminouDeTocar())
			musica.tocar();

		uniTerminarFrame();
	}
}

