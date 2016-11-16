#pragma once

#ifndef JOUEUR_NON_AUTO_H
#define JOUEUR_NON_AUTO_H

#include "Joueur.h"
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

using std::string;

class Joueur_non_auto : public Joueur
{
public : 
	Joueur_non_auto(int p_nb_annee_totale = 1, int p_nb_annee_cumules = 0);
	Joueur_non_auto(string p_nom, uint8_t p_age, int p_nb_annee_totale = 1, int p_nb_annee_cumules = 0, string p_ville = "");
	Joueur_non_auto(string p_nom, string p_prenom, uint8_t p_age, float p_taille, float p_poids = 0., int p_nb_annee_totale = 1, int p_nb_annee_cumules = 0);
	Joueur_non_auto(string p_nom, string p_prenom = "", uint8_t p_age = 0, string p_ville = "", float p_taille = 0., float p_poids = 0., int p_nb_annee_totale = 1, int p_nb_annee_cumules = 0);
	~Joueur_non_auto();

	void set_nb_annee_totale(int p_nb_annee) { m_nb_annee_totale = p_nb_annee; };
	void set_nb_annee_cumules(int p_nb_annee) { m_nb_annee_cumules = p_nb_annee; };
	void add_annee_cumules(int p_nb_annee = 1) { m_nb_annee_cumules += p_nb_annee; };

	int get_nb_annee_totale() { return m_nb_annee_totale; };
	int get_nb_annee_cumules() { return m_nb_annee_cumules; };
	int get_nb_annee_restante() { return ((m_nb_annee_totale - m_nb_annee_cumules) > 0) ? (m_nb_annee_totale - m_nb_annee_cumules) : 0; };

	bool peut_rompre_contrat() { return ((m_nb_annee_totale - m_nb_annee_cumules) > 0) ? false : true; };
	bool est_autonome() { return false; };

private:
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive & ar, const unsigned int version) {
	    (void)version;
		ar & boost::serialization::base_object<Joueur>(*this);
		ar & m_nb_annee_totale;
		ar & m_nb_annee_cumules;
	}
	int m_nb_annee_totale;
	int m_nb_annee_cumules;
};

#endif
