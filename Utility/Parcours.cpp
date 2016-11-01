#include "Parcours.h"

Parcours::Parcours()
{
	m_nom_club = "";
}

Parcours::Parcours(std::string p_nom_club)
{
	m_nom_club = p_nom_club;
}

Parcours::Parcours(std::string p_nom_club, Date p_date) : m_date_passage(p_date)
{
	m_nom_club = p_nom_club;
}

Parcours::Parcours(std::string p_nom_club, int p_annee) : m_date_passage(p_annee)
{
	m_nom_club = p_nom_club;
}

Parcours::Parcours(std::string p_nom_club, int p_annee, int p_mois) : m_date_passage(p_annee, p_mois)
{
	m_nom_club = p_nom_club;
}

Parcours::Parcours(std::string p_nom_club, int p_annee, int p_mois, int p_jour) : m_date_passage(p_annee, p_mois, p_jour)
{
	m_nom_club = p_nom_club;
}

Parcours::~Parcours()
{

}

void Parcours::set_date_passage(int p_annee)
{
	m_date_passage.set_date(p_annee);
}

void Parcours::set_date_passage(int p_annee, int p_mois)
{
	m_date_passage.set_date(p_annee, p_mois);
}

void Parcours::set_date_passage(int p_annee, int p_mois, int p_jour)
{
	m_date_passage.set_date(p_annee, p_mois, p_jour);
}

bool Parcours::operator==(Parcours const& b) const
{
	return estEgal(b);
}

bool Parcours::operator!=(Parcours const& b) const
{
	return !(estEgal(b));
}

bool Parcours::estEgal(Parcours b) const
{
	if ((m_date_passage == b.get_date_passage()) && (m_nom_club == b.get_nom_club()))
		return true;
	else
		return false;
}