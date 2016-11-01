#include "Equipe.h"

Equipe::Equipe(Club* p_club_ref, Joueur* p_capitaine, int p_nb_gardiens)
{
	m_club_ref = p_club_ref;
	m_capitaine = p_capitaine;
	m_nb_gardiens = p_nb_gardiens;
	m_nb_joueurs_terrain = m_club_ref->get_effectif().size();
}

Equipe::Equipe(Club* p_club_ref, int p_nb_joueurs_terrain, Joueur* p_capitaine, int p_nb_gardiens)
{
	m_club_ref = p_club_ref;
	m_capitaine = p_capitaine;
	m_nb_gardiens = p_nb_gardiens;
	m_nb_joueurs_terrain = p_nb_joueurs_terrain;
}

Equipe::~Equipe()
{

}

void Equipe::set_nb_joueurs(int p_nb_joueur)
{ 
	if(p_nb_joueur == -1)
		m_nb_joueurs_terrain = m_club_ref->get_effectif().size();
	else
		m_nb_joueurs_terrain = p_nb_joueur; 
}