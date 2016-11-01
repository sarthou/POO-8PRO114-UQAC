#include "Entraineur.h"

Entraineur::Entraineur() : Staff(entraineur)
{
	m_lieu_obtention_grade = "";
}

Entraineur::Entraineur(std::string p_nom, std::string p_lieu_obtention_grade) : Staff(p_nom, entraineur)
{
	m_lieu_obtention_grade = p_lieu_obtention_grade;
}

Entraineur::Entraineur(std::string p_nom, std::string p_prenom, std::string p_lieu_obtention_grade) : Staff(p_nom, p_prenom, entraineur)
{
	m_lieu_obtention_grade = p_lieu_obtention_grade;
}

Entraineur::Entraineur(std::string p_nom, std::string p_prenom, uint8_t p_age, std::string p_lieu_obtention_grade) : Staff(p_nom, p_prenom, p_age, entraineur)
{
	m_lieu_obtention_grade = p_lieu_obtention_grade;
}

Entraineur::Entraineur(std::string p_nom, std::string p_prenom, uint8_t p_age, std::string p_ville, std::string p_lieu_obtention_grade) : Staff(p_nom, p_prenom, p_age, p_ville, entraineur)
{
	m_lieu_obtention_grade = p_lieu_obtention_grade;
}

Entraineur::Entraineur(const Entraineur& p_entraineur) : Staff(p_entraineur.get_nom(), p_entraineur.get_prenom(), p_entraineur.get_age(), p_entraineur.get_ville_naissance(), entraineur)
{
	m_lieu_obtention_grade = p_entraineur.get_lieu_obtention();
}

Entraineur::~Entraineur()
{
	for (std::vector<Titre*>::iterator it = m_titres.begin(); it != m_titres.end(); ++it)
		delete *it;
}

std::vector<Titre*> Entraineur::get_titre(Date p_date)
{
	std::vector<Titre*> liste_titre;
	for (std::vector<Titre*>::iterator it = m_titres.begin(); it != m_titres.end(); ++it)
	{
		if(p_date == (*it)->get_date())
			liste_titre.push_back(*it);
	}

	return liste_titre;
}

std::vector<Titre*> Entraineur::get_titre(int annee)
{
	std::vector<Titre*> liste_titre;
	for (std::vector<Titre*>::iterator it = m_titres.begin(); it != m_titres.end(); ++it)
	{
		if (annee == (*it)->get_annee())
			liste_titre.push_back(*it);
	}

	return liste_titre;
}

std::vector<Titre*> Entraineur::get_titre(titre_t p_titre)
{
	std::vector<Titre*> liste_titre;
	for (std::vector<Titre*>::iterator it = m_titres.begin(); it != m_titres.end(); ++it)
	{
		if (p_titre == (*it)->get_titre())
			liste_titre.push_back(*it);
	}

	return liste_titre;
}

void Entraineur::ajout_titre(Titre* p_titre)
{
	m_titres.push_back(p_titre);
}

void Entraineur::ajout_titre(titre_t p_titre, Club* p_club)
{
	Titre* tmp_titre = new Titre(p_titre, p_club);
	ajout_titre(tmp_titre);
}

void Entraineur::ajout_titre(titre_t p_titre, std::string p_nom, Club* p_club)
{
	Titre* tmp_titre = new Titre(p_titre, p_nom, p_club);
	ajout_titre(tmp_titre);
}

void Entraineur::ajout_titre(titre_t p_titre, std::string p_nom, Date p_date, Club* p_club)
{
	Titre* tmp_titre = new Titre(p_titre, p_nom, p_date, p_club);
	ajout_titre(tmp_titre);
}

void Entraineur::ajout_titre(titre_t p_titre, std::string p_nom, int p_annee, Club* p_club)
{
	Titre* tmp_titre = new Titre(p_titre, p_nom, p_annee, p_club);
	ajout_titre(tmp_titre);
}

void Entraineur::remove_titre(int index)
{
	remove_titre(m_titres[index]);
}

void Entraineur::remove_titre(Titre* p_titre)
{
	for (std::vector<Titre*>::iterator it = m_titres.begin(); it != m_titres.end(); ++it)
	{
		if (*p_titre == **it)
		{
			Titre* tmp_titre =  *it;
			m_titres.erase(it);
			delete tmp_titre;
			break;
		}
	}
}

bool Entraineur::operator<(Entraineur const& b)
{
	return est_inf(b);
}

bool Entraineur::operator>(Entraineur const& b)
{
	return est_sup(b);
}

bool Entraineur::operator<=(Entraineur const& b)
{
	return !est_sup(b);
}

bool Entraineur::operator>=(Entraineur const& b)
{
	return !est_inf(b);
}

bool Entraineur::est_sup(Entraineur b) const
{
	if (m_titres.size() > b.get_nb_titres())
		return true;
	else
		return false;
}

bool Entraineur::est_inf(Entraineur b) const
{
	if (m_titres.size() < b.get_nb_titres())
		return true;
	else
		return false;
}