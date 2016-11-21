#pragma once

#ifndef NEGOCIATEUR_H
#define NEGOCIATEUR_H

#include "Negociation.h"
#include "../Club.h"
#include "../Ecrans/Affichage.h"
#include "../Utility/Mutex.h"
#include <vector>
#include <ctime>
#include <string>
#include <ctime>

enum strategie_t
{
	lineaire,
	franche,
	prudente,
	arctan,
	poker
};

class Negociateur
{
public:
	Negociateur(Club* p_representant, int p_min, int p_max, int p_montant_courant, int p_duree_nego = 8, strategie_t p_strategie = lineaire);
	~Negociateur();

	void poster_message(Message* p_message);

	virtual void negocier() = 0;

	std::string get_nom_representant() { return m_representant->get_nom(); };
	void set_mutex(Mutex* p_mutex) { m_mutex = p_mutex; };

protected:
	int m_montant_min;
	int m_montant_max;
	int m_montant_courant;
	int m_duree_negociation;
	clock_t m_debut_negociation;
	strategie_t m_strategie;
	Club* m_representant;
	Negociation m_negociation;
	std::vector<Message*> m_file;
	Mutex* m_mutex;

	void start_negociation();
	float temps_courant();
	bool trop_tard();

	void calcul_montant_courant();
	virtual int strategie_lineaire() = 0;
	virtual int strategie_franche() = 0;
	virtual int strategie_prudente() = 0;
	virtual int strategie_arctan() = 0;
	virtual int strategie_poker() = 0;

	void proposer();
	void refuser();
	void accepter();
	void repondre();
};

#endif
