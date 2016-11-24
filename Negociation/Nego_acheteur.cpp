#include "Nego_acheteur.h"

Nego_acheteur::Nego_acheteur(Club* p_representant, int p_min, int p_max, int p_duree_nego, strategie_t p_strategie) : Negociateur(p_representant, p_min, p_max, p_min, p_duree_nego, p_strategie)
{

}

Nego_acheteur::~Nego_acheteur()
{

}

void Nego_acheteur::negocier()
{
	bool stop = false;
	start_negociation();
	
	m_mutex->synchroniser();
	calcul_montant_courant();
	proposer();
	m_mutex->liberer();

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

int Nego_acheteur::strategie_lineaire(float t)
{
	if (t == -1)
		t = temps_courant();
	
	int b = m_montant_min;
	float a = (m_montant_max - m_montant_min) / (float)m_duree_negociation;
	return (int)(a*t + b);
}

int Nego_acheteur::strategie_franche(float t)
{
	if (t == -1)
		t = temps_courant();

	return (int)((m_montant_max - m_montant_min)*(1 - exp(-t / (m_duree_negociation / 5))) + m_montant_min);
}

int Nego_acheteur::strategie_prudente(float t)
{
	if (t == -1)
		t = temps_courant();

	return (int)((m_montant_max - m_montant_min)*(exp((t - m_duree_negociation) / (m_duree_negociation / 5))) + m_montant_min);
}

int Nego_acheteur::strategie_arctan(float t)
{
	if (t == -1)
		t = temps_courant();

	return m_montant_min + ((atan(t/(m_duree_negociation/20.) - 10) - atan(-10)) / (atan(10) - atan(-10)))*(m_montant_max - m_montant_min);
}

int Nego_acheteur::strategie_poker(float t)
{
	if (t == -1)
		t = temps_courant();

	if (t >= (int)(0.9*m_duree_negociation))
		return m_montant_max;
	else
		return m_montant_min;
}

bool Nego_acheteur::traiter_message()
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
	else if (m_negociation.get_montant() > m_montant_courant)
	{
		proposer();
		return true;
	}
	else if (m_negociation.get_montant() <= m_montant_courant)
	{
		accepter();
		return false;
	}
	else
		return false;
}