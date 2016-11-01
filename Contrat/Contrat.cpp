#include "Contrat.h"

Contrat::Contrat(Joueur* p_joueur_contractant, Club* p_club_contractant, int p_duree_contrat, Club* p_club_libere)
{
	m_joueur_contractant = p_joueur_contractant;
	m_club_contractant = p_club_contractant;
	m_club_libere = p_club_libere;
	m_duree_contrat = p_duree_contrat;
}

Contrat::Contrat(Joueur* p_joueur_contractant, Club* p_club_contractant, struct tm p_date_contrat, Club* p_club_libere, int p_duree_contrat) : m_date_contrat(p_date_contrat)
{
	m_joueur_contractant = p_joueur_contractant;
	m_club_contractant = p_club_contractant;
	m_club_libere = p_club_libere;
	m_duree_contrat = p_duree_contrat;
}

Contrat::Contrat(Joueur* p_joueur_contractant, Club* p_club_contractant, struct tm p_date_contrat, int p_duree_contrat, Club* p_club_libere) : m_date_contrat(p_date_contrat)
{
	m_joueur_contractant = p_joueur_contractant;
	m_club_contractant = p_club_contractant;
	m_club_libere = p_club_libere;
	m_duree_contrat = p_duree_contrat;
}

Contrat::Contrat(Joueur* p_joueur_contractant, Club* p_club_contractant, struct tm p_date_contrat, int p_duree_contrat, Reglement p_reglement, Club* p_club_libere) : m_date_contrat(p_date_contrat)
{
	m_joueur_contractant = p_joueur_contractant;
	m_club_contractant = p_club_contractant;
	m_club_libere = p_club_libere;
	m_duree_contrat = p_duree_contrat;
	m_reglement = p_reglement;
}

Contrat::Contrat(Joueur* p_joueur_contractant, Club* p_club_contractant, struct tm p_date_contrat, struct tm p_date_entree, Club* p_club_libere, int p_duree_contrat) : m_date_contrat(p_date_contrat), m_date_entree(p_date_entree)
{
	m_joueur_contractant = p_joueur_contractant;
	m_club_contractant = p_club_contractant;
	m_club_libere = p_club_libere;
	m_duree_contrat = p_duree_contrat;
}

Contrat::Contrat(Joueur* p_joueur_contractant, Club* p_club_contractant, struct tm p_date_contrat, struct tm p_date_entree, int p_duree_contrat, Club* p_club_libere) : m_date_contrat(p_date_contrat), m_date_entree(p_date_entree)
{
	m_joueur_contractant = p_joueur_contractant;
	m_club_contractant = p_club_contractant;
	m_club_libere = p_club_libere;
	m_duree_contrat = p_duree_contrat;
}

Contrat::Contrat(Joueur* p_joueur_contractant, Club* p_club_contractant, struct tm p_date_contrat, struct tm p_date_entree, Reglement p_reglement, Club* p_club_libere, int p_duree_contrat) : m_date_contrat(p_date_contrat), m_date_entree(p_date_entree)
{
	m_joueur_contractant = p_joueur_contractant;
	m_club_contractant = p_club_contractant;
	m_club_libere = p_club_libere;
	m_duree_contrat = p_duree_contrat;
	m_reglement = p_reglement;
}

Contrat::Contrat(Joueur* p_joueur_contractant, Club* p_club_contractant, struct tm p_date_contrat, struct tm p_date_entree, Reglement p_reglement, int p_duree_contrat, Club* p_club_libere) : m_date_contrat(p_date_contrat), m_date_entree(p_date_entree)
{
	m_joueur_contractant = p_joueur_contractant;
	m_club_contractant = p_club_contractant;
	m_club_libere = p_club_libere;
	m_duree_contrat = p_duree_contrat;
	m_reglement = p_reglement;
}

Contrat::~Contrat()
{
}