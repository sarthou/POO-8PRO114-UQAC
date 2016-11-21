#include "Negociateur.h"

Negociateur::Negociateur(Club* p_representant, int p_min, int p_max, int p_montant_courant, int p_duree_nego, strategie_t p_strategie) : m_negociation(this)
{
	m_montant_min = p_min;
	m_montant_max = p_max;
	m_montant_courant = p_montant_courant;
	m_duree_negociation = p_duree_nego;
	m_representant = p_representant;
	m_strategie = p_strategie;
}

Negociateur::~Negociateur()
{

}

void Negociateur::poster_message(Message* p_message)
{
	Affichage::afficher_message(p_message);
	m_file.push_back(p_message);
}

void Negociateur::start_negociation()
{
	m_debut_negociation = clock();
}

float Negociateur::temps_courant()
{
	return (float)(clock() - m_debut_negociation);
}

bool Negociateur::trop_tard()
{
	if (temps_courant() > m_duree_negociation)
		return true;
	else
		return false;
}

void Negociateur::calcul_montant_courant()
{
	switch (m_strategie)
	{
	case lineaire: m_montant_courant = strategie_lineaire(); break;
	case prudente: m_montant_courant = strategie_prudente(); break;
	case franche: m_montant_courant = strategie_franche(); break;
	case arctan: m_montant_courant = strategie_arctan(); break;
	case poker: m_montant_courant = strategie_poker(); break;
	default: m_montant_courant = strategie_lineaire(); break;
	}
}

void Negociateur::proposer()
{
	m_negociation.proposer_offre(m_montant_courant);
	repondre();
}

void Negociateur::refuser()
{
	m_negociation.refuser_offre();
	repondre();
}

void Negociateur::accepter()
{
	m_negociation.accepter_offre();
	repondre();
}

void Negociateur::repondre()
{
	if ((m_negociation.get_interlocuteur() != nullptr) && (m_negociation.get_reponse() != nullptr))
	{
		Negociateur* interlocuteur = m_negociation.get_interlocuteur();
		interlocuteur->poster_message(m_negociation.get_reponse());
	}
}