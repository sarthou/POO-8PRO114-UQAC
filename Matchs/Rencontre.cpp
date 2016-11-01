#include "Rencontre.h"

Rencontre::Rencontre(Club* p_club_local, Club* p_club_adverse, struct tm p_date, Arbitre* p_arbitre) : m_date(p_date)
{
	m_club_local = p_club_local;
	m_club_adverse = p_club_adverse;
	m_arbitre = p_arbitre;
	m_match = nullptr;
}

Rencontre::~Rencontre()
{
	delete m_match;
}

void Rencontre::set_match(Match* p_match)
{ 
	m_match = p_match; 
	m_match->set_clubs(m_club_local, m_club_adverse);
}

Rencontre* Rencontre::get_prochaine_rencontre(std::vector<Rencontre*> p_rencontres)
{
	Date date_ref;
	Rencontre* tmp_rencontre = nullptr;
	for (std::vector<Rencontre*>::iterator it = p_rencontres.begin(); it != p_rencontres.end(); ++it)
	{
		if (((*it)->get_match() == nullptr) && ((*it)->get_date() <= date_ref))
		{
			date_ref.set_date((*it)->get_date().get_date());
			tmp_rencontre = (*it);
		}
	}
	return tmp_rencontre;
}