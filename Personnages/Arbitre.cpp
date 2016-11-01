#include "Arbitre.h"

Arbitre::Arbitre(std::string p_nom, string p_lieu_obtention, int p_expérience) : Joueur(p_nom)
{
	m_lieu_obtention = p_lieu_obtention;
	m_expérience = p_expérience;
}

Arbitre::Arbitre(std::string p_nom, string p_lieu_obtention, int p_expérience, uint8_t p_age, std::string p_ville) : Joueur(p_nom, p_age, p_ville)
{
	m_lieu_obtention = p_lieu_obtention;
	m_expérience = p_expérience;
}

Arbitre::Arbitre(std::string p_nom, std::string p_prenom, string p_lieu_obtention, int p_expérience, uint8_t p_age, std::string p_ville, float p_taille, float p_poids) : 
	Joueur(p_nom, p_prenom, p_age, p_ville, p_taille, p_poids)
{
	m_lieu_obtention = p_lieu_obtention;
	m_expérience = p_expérience;
}

Arbitre::~Arbitre()
{

}