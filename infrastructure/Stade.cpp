#include "Stade.h"

Stade::Stade(std::string p_nom, std::string p_adresse)
{
	m_capacite = -1;
	m_qualite_terrain = inconnu;
	m_nom = p_nom;
	m_adresse = p_adresse;
}

Stade::Stade(std::string p_nom, int p_capacite, std::string p_adresse, qualite_terrain_t p_qualite_terrain)
{
	m_capacite = p_capacite;
	m_qualite_terrain = p_qualite_terrain;
	m_nom = p_nom;
	m_adresse = p_adresse;
}

Stade::~Stade()
{

}

bool Stade::operator==(Stade const& b)
{
	return estEgal(b);
}

bool Stade::operator!=(Stade const& b)
{
	return !(estEgal(b));
}

bool Stade::estEgal(Stade b) const
{
	if ((m_capacite == b.get_capacite()) && (m_qualite_terrain == b.get_qualite_terrain()) && (m_nom == b.get_nom_stade()) && (m_adresse == b.get_adresse()))
		return true;
	else
		return false;
}