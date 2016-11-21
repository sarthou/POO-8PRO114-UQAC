#pragma once

#ifndef NEGO_VENDEUR_H
#define NEGO_VENDEUR_H

#include "Negociateur.h"

class Nego_vendeur : public Negociateur
{
public:
	Nego_vendeur(Club* p_representant, int p_min, int p_max, int p_duree_nego = 8, strategie_t p_strategie = lineaire);
	~Nego_vendeur();

	void negocier();

private:
	int strategie_lineaire();
	int strategie_franche();
	int strategie_prudente();
	int strategie_arctan();
	int strategie_poker();

	bool traiter_message();
};

#endif
