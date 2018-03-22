#ifndef CURANDEIRO_H
#define CURANDEIRO_H

#include "Personagem.h"
#include "GerenciadorObjetos.h"

class Curandeiro : public Personagem
{
public:
	Curandeiro();
	~Curandeiro();

protected:
	virtual void poder();

private:
	Som som;
};

#endif