#include "Titre.h"

Titre::Titre()
{
	m_club = nullptr;
}

Titre::Titre(titre_t p_titre, Club* p_club) : Palmares(p_titre)
{
	m_club = p_club;
}

Titre::Titre(titre_t p_titre, std::string p_nom, Club* p_club) : Palmares(p_titre, p_nom)
{
	m_club = p_club;
}

Titre::Titre(titre_t p_titre, std::string p_nom, Date p_date, Club* p_club) : Palmares(p_titre, p_nom, p_date)
{
	m_club = p_club;
}

Titre::Titre(titre_t p_titre, std::string p_nom, int p_annee, Club* p_club) : Palmares(p_titre, p_nom, p_annee)
{
	m_club = p_club;
}

Titre::~Titre()
{

}