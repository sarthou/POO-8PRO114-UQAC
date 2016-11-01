#include "Reglement.h"

Reglement::Reglement(int p_seuil_en_vigueur, string p_description_droits)
{
	m_seuil_en_vigueur = p_seuil_en_vigueur;
	m_description_droits = p_description_droits;
	m_montant_transfert = -1;
	m_montant_encaisse = -1;
	m_montant_restant = -1;
}

Reglement::Reglement(float p_montant_transfert, float p_montant_encaisse, int p_seuil_en_vigueur, string p_description_droits)
{
	m_seuil_en_vigueur = p_seuil_en_vigueur;
	m_description_droits = p_description_droits;
	m_montant_transfert = p_montant_transfert;
	m_montant_encaisse = p_montant_encaisse;
	m_montant_restant = p_montant_transfert - p_montant_encaisse;
}

Reglement::~Reglement()
{
}

void Reglement::set_montants(float p_montant_transfert, float p_montant_encaisse)
{
	m_montant_transfert = p_montant_transfert;
	if (p_montant_encaisse == -1)
	{
		m_montant_encaisse = p_montant_transfert;
		m_montant_restant = 0;
	}
	else
	{
		if (p_montant_encaisse > p_montant_encaisse)
		{
			m_montant_encaisse = p_montant_transfert;
			m_montant_restant = 0;
		}
		else
		{
			m_montant_encaisse = p_montant_encaisse;
			m_montant_restant = m_montant_transfert - m_montant_encaisse;
		}
	}
}