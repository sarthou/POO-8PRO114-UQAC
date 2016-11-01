#include "Personne.h"

Personne::Personne()
{
	m_nom = "";
	m_prenom = "";
	m_age = 0;
	m_ville_naissance = "";
}

Personne::Personne(std::string p_nom, uint8_t p_age, std::string p_ville)
{
	m_nom = p_nom;
	m_prenom = "";
	m_age = p_age;
	m_ville_naissance = p_ville;
}

Personne::Personne(std::string p_nom, std::string p_prenom, uint8_t p_age, std::string p_ville)
{
	m_nom = p_nom;
	m_prenom = p_prenom;
	m_age = p_age;
	m_ville_naissance = p_ville;
}

Personne::~Personne()
{

}