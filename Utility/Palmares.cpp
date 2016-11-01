#include "Palmares.h"

Palmares::Palmares()
{
	m_titre = autre_titre;
	m_nom = "";
}

Palmares::Palmares(titre_t p_titre, std::string p_nom)
{
	m_titre = p_titre;
	m_nom = p_nom;
}

Palmares::Palmares(titre_t p_titre, std::string p_nom, Date p_date) : m_date(p_date)
{
	m_titre = p_titre;
	m_nom = p_nom;
}

Palmares::Palmares(titre_t p_titre, std::string p_nom, int p_annee) : m_date(p_annee)
{
	m_titre = p_titre;
	m_nom = p_nom;
}

Palmares::~Palmares()
{

}

bool Palmares::operator==(Palmares const& b) const
{
	return estEgal(b);
}

bool Palmares::operator!=(Palmares const& b) const
{
	return !(estEgal(b));
}

bool Palmares::estEgal(Palmares b) const
{
	if ((m_titre == b.get_titre()) && (m_nom == b.get_nom()) && (m_date == b.get_date()))
		return true;
	else
		return false;
}