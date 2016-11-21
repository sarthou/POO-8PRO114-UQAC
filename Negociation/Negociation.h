#pragma once

#ifndef NEGOCIATION_H
#define NEGOCIATION_H

#include "Message.h"

class Negociateur;

class Negociation
{
public:
	Negociation(Negociateur* p_instance);
	~Negociation();

	Message* proposer_offre(int p_montant);
	Message* accepter_offre();
	Message* refuser_offre();

	int recevoir_message(Message* p_message);

	Negociateur* get_interlocuteur() { return m_interlocuteur; };
	Message* get_reponse() { return m_reponse; };
	sujet_t get_sujet() { return m_sujet_courant; };
	int get_montant() { return m_montant_courant; };

	void set_interlocuteur(Negociateur* p_interlocuteur) { m_interlocuteur = p_interlocuteur; };

private:
	Negociateur* m_instance;

	Message* m_reponse;

	int m_montant_courant;
	sujet_t m_sujet_courant;
	Negociateur* m_interlocuteur;
};

#endif
