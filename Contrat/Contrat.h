#pragma once

#ifndef CONTRAT_H
#define CONTRAT_H

#include "Reglement.h"
#include "../Personnages/Joueur.h"
#include "../Utility/Date.h"
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

class Club;

class Contrat
{
public:
	Contrat(Joueur* p_joueur_contractant = nullptr, Club* p_club_contractant = nullptr, int p_duree_contrat = 0, Club* p_club_libere = nullptr);
	Contrat(Joueur* p_joueur_contractant, Club* p_club_contractant, struct tm p_date_contrat, Club* p_club_libere = nullptr, int p_duree_contrat = -1);
	Contrat(Joueur* p_joueur_contractant, Club* p_club_contractant, struct tm p_date_contrat, int p_duree_contrat = -1, Club* p_club_libere = nullptr);
	Contrat(Joueur* p_joueur_contractant, Club* p_club_contractant, struct tm p_date_contrat, int p_duree_contrat, Reglement p_reglement, Club* p_club_libere = nullptr);
	Contrat(Joueur* p_joueur_contractant, Club* p_club_contractant, struct tm p_date_contrat, struct tm p_date_entree, Club* p_club_libere = nullptr, int p_duree_contrat = -1);
	Contrat(Joueur* p_joueur_contractant, Club* p_club_contractant, struct tm p_date_contrat, struct tm p_date_entree, int p_duree_contrat = -1, Club* p_club_libere = nullptr);
	Contrat(Joueur* p_joueur_contractant, Club* p_club_contractant, struct tm p_date_contrat, struct tm p_date_entree, Reglement p_reglement, Club* p_club_libere = nullptr, int p_duree_contrat = -1);
	Contrat(Joueur* p_joueur_contractant, Club* p_club_contractant, struct tm p_date_contrat, struct tm p_date_entree, Reglement p_reglement, int p_duree_contrat = -1, Club* p_club_libere = nullptr);
	~Contrat();

	Joueur* get_joueur_contractant() { return m_joueur_contractant; };
	Club* get_club_contractant() { return m_club_contractant; };
	Club* get_club_libere() { return m_club_libere; };
	int get_duree_contrat() const { return m_duree_contrat; };
	struct tm get_date_entree() { return m_date_entree.get_date(); };
	int get_annee_entree() const { return m_date_entree.get_annee(); };
	struct tm get_date_contrat() { return m_date_contrat.get_date(); };
	int get_annee_contrat() const { return m_date_contrat.get_annee(); };
	Reglement get_reglement() const { return m_reglement; };

	void set_joueur_contractant(Joueur* p_joueur_contractant) { m_joueur_contractant = p_joueur_contractant; };
	void set_club_contractant(Club* p_club_contractant) { m_club_contractant = p_club_contractant; };
	void set_club_libere(Club* p_club_libere) { m_club_libere = p_club_libere; };
	void set_duree_contrat(int p_duree) { m_duree_contrat = p_duree; };
	void set_date_entree(struct tm p_date) { m_date_entree.set_date(p_date); };
	void set_date_entree(int p_annee) { m_date_entree.set_date(p_annee); };
	void set_date_contrat(struct tm p_date) { m_date_contrat.set_date(p_date); };
	void set_date_contrat(int p_annee) { m_date_contrat.set_date(p_annee); };
	void set_reglement(Reglement p_reglement) { m_reglement = p_reglement; };

private:
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive & ar, const unsigned int version) {
		ar & m_joueur_contractant;
		ar & m_club_contractant;
		ar & m_club_libere;
		ar & m_duree_contrat;
		ar & m_date_entree;
		ar & m_date_contrat;
		ar & m_reglement;
	}
	Joueur* m_joueur_contractant;
	Club* m_club_contractant;
	Club* m_club_libere;
	int m_duree_contrat;
	Date m_date_entree;
	Date m_date_contrat;
	Reglement m_reglement;
};

#endif
