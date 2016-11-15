#pragma once

#ifndef JOUEUR_H
#define JOUEUR_H

#include <cstdlib>
#include <string>
#include <vector>
#include "Personne.h"
#include "..\Utility\Parcours.h"
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

using std::string;

class Joueur : public Personne
{
public:
	Joueur();
	Joueur(string p_nom, uint8_t p_age, string p_ville = "");
	Joueur(string p_nom, string p_prenom, uint8_t p_age, float p_taille, float p_poids = 0.);
	Joueur(string p_nom, string p_prenom = "", uint8_t p_age = 0, string p_ville = "", float p_taille = 0., float p_poids = 0.);
	~Joueur();

	float get_taille() const { return m_taille; };
	float get_poids() const { return m_poids; };

	void set_taille(float p_taille) { m_taille = p_taille; };
	void set_poids(float p_poids) { m_poids = p_poids; };

	std::vector<Parcours*> get_parcour() { return m_parcours; };
	std::vector<Parcours*> get_parcour(string p_nom_club);
	std::vector<Parcours*> get_parcour(Date p_date);
	std::vector<Parcours*> get_parcour(int p_annee);

	void add_parcour(Parcours* p_parcours) { m_parcours.push_back(p_parcours); };
	void add_parcour(string p_club_nom);
	void add_parcour(string p_club_nom, Date p_date);
	void add_parcour(string p_club_nom, int p_annee);
	void add_parcour(string p_club_nom, int p_annee, int p_mois);
	void add_parcour(string p_club_nom, int p_annee, int p_mois, int p_jour);

	void remove_parcour(int p_index);
	void remove_parcour(Parcours* p_parcours);

	virtual bool peut_rompre_contrat() { return false; };
	virtual bool est_autonome() { return true; };

	bool operator==(Joueur const& b);
	bool operator!=(Joueur const& b);

private:
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive & ar, const unsigned int version) {
		ar & boost::serialization::base_object<Personne>(*this);
		ar & m_taille;
		ar & m_poids;
		ar & m_parcours;
	}
	float m_taille;
	float m_poids;
	std::vector<Parcours*> m_parcours;

	bool estEgal(Joueur b) const;
};

class Joueur_auto : public Joueur
{
public:
	Joueur_auto() : Joueur() {};
	Joueur_auto(string p_nom, uint8_t p_age, string p_ville = "") : Joueur(p_nom, p_age, p_ville) {};
	Joueur_auto(string p_nom, string p_prenom, uint8_t p_age, float p_taille, float p_poids = 0.) : Joueur(p_nom, p_prenom, p_age, p_taille, p_poids) {};
	Joueur_auto(string p_nom, string p_prenom = "", uint8_t p_age = 0, string p_ville = "", float p_taille = 0., float p_poids = 0.) : Joueur(p_nom, p_prenom, p_age, p_ville, p_taille, p_poids) {};
	~Joueur_auto() {};

	bool peut_rompre_contrat() { return true; };
	bool est_autonome() { return true; };
private:
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive & ar, const unsigned int version) {
		ar & boost::serialization::base_object<Joueur>(*this);
	}
};

#endif
