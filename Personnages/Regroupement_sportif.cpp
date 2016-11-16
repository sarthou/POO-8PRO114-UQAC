#include "Regroupement_sportif.h"

Regroupement_sportif::Regroupement_sportif()
{
	m_entraineur = nullptr;
}

Regroupement_sportif::~Regroupement_sportif()
{
	for (std::vector<Joueur*>::iterator it = m_effectif.begin(); it != m_effectif.end(); ++it)
		delete *it;

	for (std::vector<Staff*>::iterator it = m_staff.begin(); it != m_staff.end(); ++it)
		delete *it;

	if (m_entraineur != nullptr)
		delete m_entraineur;
}

/*GET*/

std::vector<Staff*> Regroupement_sportif::get_staff(role_t p_role)
{
	std::vector<Staff*> liste_staff;
	for (std::vector<Staff*>::iterator it = m_staff.begin(); it != m_staff.end(); ++it)
	{
		if (p_role == (*it)->get_role())
			liste_staff.push_back(*it);
	}
	return liste_staff;
}

/*SET*/

void Regroupement_sportif::add_entraineur(Entraineur* p_entraineur)
{
	m_entraineur = p_entraineur;
	add_staff(p_entraineur->get_nom(), p_entraineur->get_prenom(), p_entraineur->get_role());
}

void Regroupement_sportif::add_entraineur(std::string p_nom, std::string p_lieu_obtention_grade)
{
	Entraineur* entraineur = new Entraineur(p_nom, p_lieu_obtention_grade);
	add_entraineur(entraineur);
}

void Regroupement_sportif::add_entraineur(std::string p_nom, std::string p_prenom, std::string p_lieu_obtention_grade)
{
	Entraineur* entraineur = new Entraineur(p_nom, p_prenom, p_lieu_obtention_grade);
	add_entraineur(entraineur);
}

void Regroupement_sportif::add_entraineur(std::string p_nom, std::string p_prenom, uint8_t p_age, std::string p_lieu_obtention_grade)
{
	Entraineur* entraineur = new Entraineur(p_nom, p_prenom, p_age, p_lieu_obtention_grade);
	add_entraineur(entraineur);
}

void Regroupement_sportif::add_staff(role_t p_role)
{
	Staff* tmp_staff = new Staff(p_role);
	add_staff(tmp_staff);
}

void Regroupement_sportif::add_staff(std::string p_nom, role_t p_role)
{
	Staff* tmp_staff = new Staff(p_nom, p_role);
	add_staff(tmp_staff);
}

void Regroupement_sportif::add_staff(std::string p_nom, std::string p_prenom, role_t p_role)
{
	Staff* tmp_staff = new Staff(p_nom, p_prenom, p_role);
	add_staff(tmp_staff);
}

void Regroupement_sportif::add_staff(std::string p_nom, std::string p_prenom, uint8_t p_age, role_t p_role)
{
	Staff* tmp_staff = new Staff(p_nom, p_prenom, p_age, p_role);
	add_staff(tmp_staff);
}

void Regroupement_sportif::add_joueur(std::string p_nom, std::string p_prenom)
{
	Joueur* tmp_joueur = new Joueur(p_nom, p_prenom);
	add_joueur(tmp_joueur);
}

void Regroupement_sportif::add_joueur(std::string p_nom, std::string p_prenom, uint8_t p_age, float p_taille, float p_poids)
{
	Joueur* tmp_joueur = new Joueur(p_nom, p_prenom, p_age, p_taille, p_poids);
	add_joueur(tmp_joueur);
}

void Regroupement_sportif::add_joueur(std::string p_nom, std::string p_prenom, uint8_t p_age, std::string p_ville, float p_taille, float p_poids)
{
	Joueur* tmp_joueur = new Joueur(p_nom, p_prenom, p_age, p_ville, p_taille, p_poids);
	add_joueur(tmp_joueur);
}

/*remove*/

void Regroupement_sportif::remove_entraineur()
{
	delete m_entraineur;
	remove_staff(entraineur);
	m_entraineur = nullptr;
}

void Regroupement_sportif::remove_staff(Staff* p_staff)
{
	for (std::vector<Staff*>::iterator it = m_staff.begin(); it != m_staff.end(); ++it)
	{
		if (*p_staff == **it)
		{
			Staff* tmp_staff = *it;
			m_staff.erase(it);
			delete tmp_staff;
			break;
		}
	}
}

void Regroupement_sportif::remove_staff(role_t p_role)
{
	for (std::vector<Staff*>::iterator it = m_staff.begin(); it != m_staff.end(); ++it)
	{
		if (p_role == (*it)->get_role())
		{
			Staff* tmp_staff = *it;
			m_staff.erase(it);
			delete tmp_staff;
			break;
		}
	}
}

void Regroupement_sportif::remove_staff(std::string p_nom, role_t p_role)
{
	Staff* tmp_staff = new Staff(p_nom, p_role);
	remove_staff(tmp_staff);
	delete tmp_staff;
}

void Regroupement_sportif::remove_staff(std::string p_nom, std::string p_prenom, role_t p_role)
{
	Staff* tmp_staff = new Staff(p_nom, p_prenom, p_role);
	remove_staff(tmp_staff);
	delete tmp_staff;
}

void Regroupement_sportif::remove_staff(std::string p_nom, std::string p_prenom, uint8_t p_age, role_t p_role)
{
	Staff* tmp_staff = new Staff(p_nom, p_prenom, p_age, p_role);
	remove_staff(tmp_staff);
	delete tmp_staff;
}

void Regroupement_sportif::remove_joueur(Joueur* p_joueur, bool p_delete)
{
	for (std::vector<Joueur*>::iterator it = m_effectif.begin(); it != m_effectif.end(); ++it)
	{
		if (*p_joueur == **it)
		{
			Joueur* tmp_joueur = *it;
			m_effectif.erase(it);
			if (p_delete)
				delete tmp_joueur;
			break;
		}
	}
}

void Regroupement_sportif::remove_joueur(std::string p_nom, std::string p_prenom)
{
	Joueur* tmp_joueur = new Joueur(p_nom, p_prenom);
	remove_joueur(tmp_joueur);
	delete tmp_joueur;
}

void Regroupement_sportif::remove_joueur(std::string p_nom, std::string p_prenom, uint8_t p_age, float p_taille, float p_poids)
{
	Joueur* tmp_joueur = new Joueur(p_nom, p_prenom, p_age, p_taille, p_poids);
	remove_joueur(tmp_joueur);
	delete tmp_joueur;
}

void Regroupement_sportif::remove_joueur(std::string p_nom, std::string p_prenom, uint8_t p_age, std::string p_ville, float p_taille, float p_poids)
{
	Joueur* tmp_joueur = new Joueur(p_nom, p_prenom, p_age, p_ville, p_taille, p_poids);
	remove_joueur(tmp_joueur);
	delete tmp_joueur;
}
