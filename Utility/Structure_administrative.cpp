#include "Structure_administrative.h"

Structure_administrative::Structure_administrative(string p_nom, string p_histoire, string p_ville, string p_adresse)
{
	m_nom = p_nom;
	m_ville = p_ville;
	m_adresse = p_adresse;
	m_histoire = p_histoire;
}

Structure_administrative::Structure_administrative(string p_nom, string p_histoire, string p_ville, string p_adresse, Date p_date) : m_date_creation(p_date)
{
	m_nom = p_nom;
	m_ville = p_ville;
	m_adresse = p_adresse;
	m_histoire = p_histoire;
}

Structure_administrative::~Structure_administrative()
{

}