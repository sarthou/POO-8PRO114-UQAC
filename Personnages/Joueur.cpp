#include "Joueur.h"

Joueur::Joueur()
{
	
}

Joueur::Joueur(std::string p_nom, uint8_t p_age, std::string p_ville) : Personne(p_nom, p_age, p_ville)
{
	m_taille = -1.;
	m_poids = -1.;
}

Joueur::Joueur(std::string p_nom, std::string p_prenom, uint8_t p_age, std::string p_ville, float p_taille, float p_poids) : Personne(p_nom, p_prenom, p_age, p_ville)
{
	m_taille = p_taille;
	m_poids = p_poids;
}

Joueur::Joueur(std::string p_nom, std::string p_prenom, uint8_t p_age, float p_taille, float p_poids) : Personne(p_nom, p_prenom, p_age)
{
	m_taille = p_taille;
	m_poids = p_poids;
}

Joueur::~Joueur()
{
	if (m_parcours.size() != 0)
	{
		for (std::vector<Parcours*>::iterator it = m_parcours.begin(); it != m_parcours.end(); ++it)
			delete *it;
	}
}

std::vector<Parcours*> Joueur::get_parcour(std::string p_nom_club)
{
	std::vector<Parcours*> liste_parcour;
	for (std::vector<Parcours*>::iterator it = m_parcours.begin(); it != m_parcours.end(); ++it)
	{
		if (p_nom_club == (*it)->get_nom_club())
			liste_parcour.push_back(*it);
	}
	return liste_parcour;
}

std::vector<Parcours*> Joueur::get_parcour(Date p_date)
{
	std::vector<Parcours*> liste_parcour;
	for (std::vector<Parcours*>::iterator it = m_parcours.begin(); it != m_parcours.end(); ++it)
	{
		if (p_date == (*it)->get_date_passage())
			liste_parcour.push_back(*it);
	}
	return liste_parcour;
}

std::vector<Parcours*> Joueur::get_parcour(int p_annee)
{
	std::vector<Parcours*> liste_parcour;
	for (std::vector<Parcours*>::iterator it = m_parcours.begin(); it != m_parcours.end(); ++it)
	{
		if (p_annee == (*it)->get_annee_passage())
			liste_parcour.push_back(*it);
	}
	return liste_parcour;
}

void Joueur::add_parcour(std::string p_club_nom)
{
	Parcours *tmp_parcour = new Parcours(p_club_nom);
	m_parcours.push_back(tmp_parcour);
}

void Joueur::add_parcour(std::string p_club_nom, Date p_date)
{
	Parcours *tmp_parcour = new Parcours(p_club_nom, p_date);
	m_parcours.push_back(tmp_parcour);
}

void Joueur::add_parcour(std::string p_club_nom, int p_annee)
{
	Parcours *tmp_parcour = new Parcours(p_club_nom, p_annee);
	m_parcours.push_back(tmp_parcour);
}

void Joueur::add_parcour(std::string p_club_nom, int p_annee, int p_mois) 
{
	Parcours *tmp_parcour = new Parcours(p_club_nom, p_annee, p_mois);
	m_parcours.push_back(tmp_parcour);
}

void Joueur::add_parcour(std::string p_club_nom, int p_annee, int p_mois, int p_jour)
{
	Parcours *tmp_parcour = new Parcours(p_club_nom, p_annee, p_mois, p_jour);
	m_parcours.push_back(tmp_parcour);
}

/*REMOVE*/

void Joueur::remove_parcour(int p_index)
{
	remove_parcour(m_parcours[p_index]);
}

void Joueur::remove_parcour(Parcours* p_parcours)
{
	for (std::vector<Parcours*>::iterator it = m_parcours.begin(); it != m_parcours.end(); ++it)
	{
		if (*p_parcours == **it)
		{
			Parcours* tmp_parcour = *it;
			m_parcours.erase(it);
			delete tmp_parcour;
			break;
		}
	}
}

bool Joueur::operator==(Joueur const& b)
{
	return estEgal(b);
}

bool Joueur::operator!=(Joueur const& b)
{
	return !(estEgal(b));
}

bool Joueur::estEgal(Joueur b) const
{
	if ((m_nom == b.get_nom()) && (m_prenom == b.get_prenom()) && (m_age == b.get_age()) && (m_poids == b.get_poids()) && (m_taille == b.get_taille()))
		return true;
	else
		return false;
}