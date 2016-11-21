#pragma once

#ifndef NEGO_ACHETEUR_H
#define NEGO_ACHETEUR_H

#include "Negociateur.h"

class Nego_acheteur : public Negociateur
{
public:
	Nego_acheteur(Club* p_representant, int p_min, int p_max, int p_duree_nego = 8, strategie_t p_strategie = lineaire);
	~Nego_acheteur();

	void negocier();

	void set_interlocuteur(Negociateur* p_interlocuteur) { m_negociation.set_interlocuteur(p_interlocuteur); };

private:
	int strategie_lineaire();
	int strategie_franche();
	int strategie_prudente();
	int strategie_arctan();
	int strategie_poker();

	bool traiter_message();
};

#endif
