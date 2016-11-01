#include "Rupture.h"

Rupture::Rupture(Joueur* p_joueur, Club* p_club, float p_penelite, string p_raison)
{
	m_joueur = p_joueur;
	m_club = p_club;
	m_penelite = p_penelite;
	m_raison = p_raison;
}