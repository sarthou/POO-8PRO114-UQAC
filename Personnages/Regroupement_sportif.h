#pragma once

#ifndef REGROUPEMENT_SPORTIF_H
#define REGROUPEMENT_SPORTIF_H

#include "..\personnages\Joueur.h"
#include "..\Personnages\Joueur_non_auto.h"
#include "..\Personnages\Staff.h"
#include "..\Personnages\Entraineur.h"

#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

class Regroupement_sportif
{
public:
	Regroupement_sportif();
	~Regroupement_sportif();

	Entraineur* get_entraineur() { return m_entraineur; };
	std::vector<Staff*> get_staff() { return m_staff; };
	std::vector<Staff*> get_staff(role_t p_role);
	std::vector<Joueur*> get_effectif() { return m_effectif; };
	Joueur* get_effectif_index(int p_index) { return m_effectif[p_index]; };

	void add_entraineur(Entraineur* p_entraineur);
	void add_entraineur(string p_nom, string p_lieu_obtention_grade);
	void add_entraineur(string p_nom, string p_prenom, string p_lieu_obtention_grade);
	void add_entraineur(string p_nom, string p_prenom, uint8_t p_age, string p_lieu_obtention_grade);
	void add_staff(Staff* p_staff) { m_staff.push_back(p_staff); };
	void add_staff(role_t p_role);
	void add_staff(string p_nom, role_t p_role);
	void add_staff(string p_nom, string p_prenom, role_t p_role);
	void add_staff(string p_nom, string p_prenom, uint8_t p_age, role_t p_role);
	void add_joueur(Joueur* p_joueur) { m_effectif.push_back(p_joueur); };
	void add_joueur(string p_nom, string p_prenom = "");
	void add_joueur(string p_nom, string p_prenom, uint8_t p_age, float p_taille = 0., float p_poids = 0.);
	void add_joueur(string p_nom, string p_prenom, uint8_t p_age, string p_ville, float p_taille = 0., float p_poids = 0.);

	void remove_entraineur();
	void remove_staff(Staff* p_staff);
	void remove_staff(role_t p_role);
	void remove_staff(string p_nom, role_t p_role);
	void remove_staff(string p_nom, string p_prenom, role_t p_role);
	void remove_staff(string p_nom, string p_prenom, uint8_t p_age, role_t p_role);
	void remove_joueur(Joueur* p_joueur, bool p_delete = true);
	void remove_joueur(string p_nom, string p_prenom = "");
	void remove_joueur(string p_nom, string p_prenom, uint8_t p_age, float p_taille = 0., float p_poids = 0.);
	void remove_joueur(string p_nom, string p_prenom, uint8_t p_age, string p_ville, float p_taille = 0., float p_poids = 0.);

private:
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive & ar, const unsigned int version) {
		ar & m_staff;
		ar & m_entraineur;
		ar & m_effectif;
	}

protected:
	Entraineur* m_entraineur;
	std::vector<Staff*> m_staff;
	std::vector<Joueur*> m_effectif;
};

#endif
