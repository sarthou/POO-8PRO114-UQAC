#include "Nego_vendeur.h"

Nego_vendeur::Nego_vendeur(Club* p_representant, int p_min, int p_max, int p_duree_nego, strategie_t p_strategie) : Negociateur(p_representant, p_min, p_max, p_max, p_duree_nego, p_strategie)
{

}

Nego_vendeur::~Nego_vendeur()
{

}

void Nego_vendeur::negocier()
{
	bool stop = false;
	start_negociation();

	do
	{
		m_mutex->synchroniser();
		for (std::vector<Message*>::iterator it = m_file.begin(); it != m_file.end(); ++it)
		{
			m_negociation.recevoir_message(*it);
			stop = !traiter_message();
			if (stop)
				break;
		}
		m_file.clear();
		m_mutex->liberer();
	} while (!stop);
}

int Nego_vendeur::strategie_lineaire(float t)
{
	if (t == -1)
		t = temps_courant();
	
	int b = m_montant_max;
	float a = (m_montant_min - m_montant_max) / (float)m_duree_negociation;
	return (int)(a*t + b);
}

int Nego_vendeur::strategie_franche(float t)
{
	if (t == -1)
		t = temps_courant();
	
	float b = (m_montant_min - m_montant_max / (float)(m_duree_negociation + 1)) * ((m_duree_negociation + 1) / (float)m_duree_negociation);
	float a = m_montant_max - b;
	return (int)(a/(t + 1) + b);
}

int Nego_vendeur::strategie_prudente(float t)
{
	if (t == -1)
		t = temps_courant();
	
	return 0;
}

int Nego_vendeur::strategie_arctan(float t)
{
	if (t == -1)
		t = temps_courant();
	
	return 0;
}

int Nego_vendeur::strategie_poker(float t)
{
	if (t == -1)
		t = temps_courant();
	
	if (t >= (int)(0.9*m_duree_negociation))
		return m_montant_min;
	else
		return m_montant_max;
}

bool Nego_vendeur::traiter_message()
{
	calcul_montant_courant();
	m_fin_negociation = clock();
	if (m_negociation.get_sujet() == rejet)
		return false;
	else if (m_negociation.get_sujet() == erreur)
		return false;
	else if (m_negociation.get_sujet() == acceptation)
		return false;
	else if (trop_tard())
	{
		refuser();
		return false;
	}
	else if (m_negociation.get_montant() < m_montant_courant)
	{
		proposer();
		return true;
	}
	else if (m_negociation.get_montant() >= m_montant_courant)
	{
		accepter();
		return false;
	}
	else
		return false;
}