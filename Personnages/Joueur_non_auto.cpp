#include "Joueur_non_auto.h"

Joueur_non_auto::Joueur_non_auto(int p_nb_annee_totale, int p_nb_annee_cumules) :
	Joueur() 
{
	m_nb_annee_totale = p_nb_annee_totale;
	m_nb_annee_cumules = p_nb_annee_cumules;
}

Joueur_non_auto::Joueur_non_auto(string p_nom, uint8_t p_age, int p_nb_annee_totale, int p_nb_annee_cumules, string p_ville) :
	Joueur(p_nom, p_age, p_ville) 
{
	m_nb_annee_totale = p_nb_annee_totale;
	m_nb_annee_cumules = p_nb_annee_cumules;
}

Joueur_non_auto::Joueur_non_auto(string p_nom, string p_prenom, uint8_t p_age, float p_taille, float p_poids, int p_nb_annee_totale, int p_nb_annee_cumules) :
	Joueur(p_nom, p_prenom, p_age, p_taille, p_poids) 
{
	m_nb_annee_totale = p_nb_annee_totale;
	m_nb_annee_cumules = p_nb_annee_cumules;
}

Joueur_non_auto::Joueur_non_auto(string p_nom, string p_prenom, uint8_t p_age, string p_ville, float p_taille, float p_poids, int p_nb_annee_totale, int p_nb_annee_cumules) :
	Joueur(p_nom, p_prenom, p_age, p_ville, p_taille, p_poids) 
{
	m_nb_annee_totale = p_nb_annee_totale;
	m_nb_annee_cumules = p_nb_annee_cumules;
}

Joueur_non_auto::~Joueur_non_auto()
{}