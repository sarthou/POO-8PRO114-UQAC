#include "Staff.h"

Staff::Staff(std::string p_nom, uint8_t p_age, std::string p_ville) : Personne(p_nom, p_age, p_ville)
{
	m_role = autre;
}

Staff::Staff(role_t p_role)
{
	m_role = p_role;
}

Staff::Staff(std::string p_nom, role_t p_role) : Personne(p_nom)
{
	m_role = p_role;
}

Staff::Staff(std::string p_nom, std::string p_prenom, role_t p_role) : Personne(p_nom, p_prenom)
{
	m_role = p_role;
}

Staff::Staff(std::string p_nom, std::string p_prenom, uint8_t p_age, role_t p_role) : Personne(p_nom, p_prenom, p_age)
{
	m_role = p_role;
}

Staff::Staff(std::string p_nom, std::string p_prenom, uint8_t p_age, std::string p_ville, role_t p_role) : Personne(p_nom, p_prenom, p_age, p_ville)
{
	m_role = p_role;
}

Staff::~Staff()
{

}

bool Staff::operator==(Staff const& b)
{
	return estEgal(b);
}

bool Staff::operator!=(Staff const& b)
{
	return !(estEgal(b));
}

bool Staff::estEgal(Staff b)  const
{
	if ((m_nom == b.get_nom()) && (m_prenom == b.get_prenom()) && (m_age == b.get_age()) && (m_role == b.get_role()) && (m_ville_naissance == b.get_ville_naissance()))
		return true;
	else
		return false;
}