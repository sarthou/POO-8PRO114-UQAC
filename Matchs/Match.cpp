#include "Match.h"

Match::Match(Club* p_club_local, Club* p_club_adverse) : m_equipe_locale(p_club_local), m_equipe_adverse(p_club_adverse)
{
	m_resultat.nb_but_adverse = 0;
	m_resultat.nb_but_local = 0;
}

Match::~Match()
{

}

void Match::set_equipe_locale(Joueur* p_capitaine, int p_nb_gardiens, int p_nb_joueurs_terrain)
{
	m_equipe_locale.set_capitaine(p_capitaine);
	m_equipe_locale.set_nb_gardiens(p_nb_gardiens);
	if (p_nb_joueurs_terrain == -1)
		m_equipe_locale.set_nb_joueurs();
	else
		m_equipe_locale.set_nb_joueurs(p_nb_joueurs_terrain);
}

void Match::set_equipe_adverse(Joueur* p_capitaine, int p_nb_gardiens, int p_nb_joueurs_terrain)
{
	m_equipe_adverse.set_capitaine(p_capitaine);
	m_equipe_adverse.set_nb_gardiens(p_nb_gardiens);
	if (p_nb_joueurs_terrain == -1)
		m_equipe_adverse.set_nb_joueurs();
	else
		m_equipe_adverse.set_nb_joueurs(p_nb_joueurs_terrain);
}

void Match::add_new_periode(int p_duree, int p_but_local, int p_but_adverse)
{
	Periode tmp_periode(p_duree, p_but_local, p_but_adverse);
	m_periodes.push_back(tmp_periode);
	m_resultat.nb_but_local += p_but_local;
	m_resultat.nb_but_adverse += p_but_adverse;
}

void Match::add_new_periode(Periode p_periode)
{ 
	m_periodes.push_back(p_periode); 
	m_resultat.nb_but_local += p_periode.get_but_local();
	m_resultat.nb_but_adverse += p_periode.get_but_adverse();
}

void Match::add_but_local(int nb_but)
{
	if (m_periodes.size() != 0)
	{
		m_resultat.nb_but_local += nb_but;
		m_periodes.back().add_but_local(nb_but);
	}
}

void Match::add_but_adverse(int nb_but)
{
	if (m_periodes.size() != 0)
	{
		m_resultat.nb_but_adverse += nb_but;
		m_periodes.back().add_but_adverse(nb_but);
	}
}

void Match::set_clubs(Club* p_club_local, Club* p_club_adverse)
{
	m_equipe_adverse.set_club_ref(p_club_adverse);
	m_equipe_locale.set_club_ref(p_club_local);
}