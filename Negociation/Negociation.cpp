#include "Negociation.h"

Negociation::Negociation(Negociateur* p_instance)
{
	m_instance = p_instance;
	m_montant_courant = -1;
	m_sujet_courant = erreur;
	m_interlocuteur = nullptr;
}

Negociation::~Negociation()
{

}

Message* Negociation::proposer_offre(int p_montant)
{
	m_montant_courant = p_montant;
	return new Message(m_instance, offre, p_montant);
}

Message* Negociation::accepter_offre()
{
	return new Message(m_instance, acceptation, m_montant_courant);
}

Message* Negociation::refuser_offre()
{
	return new Message(m_instance, rejet);
}

int Negociation::recevoir_message(Message* p_message)
{
	m_interlocuteur = p_message->get_emetteur();
	m_sujet_courant = p_message->get_sujet();
	m_montant_courant = p_message->get_montant();

	if (m_sujet_courant == erreur)
		return -1;
	else 
		return 0;
}