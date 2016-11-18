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

private:
	Negociateur* m_instance;

	int m_montant_courant;
	sujet_t m_sujet_courant;
	Negociateur* m_interlocuteur;
};

#endif
