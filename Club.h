#pragma once

#ifndef CLUB_H
#define CLUB_H

#include <cstdlib>
#include <string>
#include <vector>
#include "personnages\Joueur.h"
#include "Personnages\Joueur_non_auto.h"
#include "Personnages\Staff.h"
#include "Personnages\Entraineur.h"
#include "Utility\Date.h"
#include "infrastructure\Stade.h"
#include "Utility\Palmares.h"
#include "Contrat\Contrat.h"
#include "Contrat\Rupture.h"

using std::string;

class Club
{
public:
	Club();
	Club(string p_nom, string p_couleur = "");
	Club(string p_nom, string p_couleur, Date p_date_creation);
	Club(string p_nom, string p_couleur, Date p_date_creation, Stade p_stade, string p_ville = "", string p_adresse = "", string p_histoire = "");
	Club(const Club& p_club);
	~Club();

	string get_nom() const { return m_nom; };
	string get_histoire() const { return m_histoire; };
	string get_couleur() const { return m_couleur; };
	string get_ville() const  { return m_ville; };
	string get_adresse() const { return m_adresse; };
	Date get_date() const  { return m_date_creation; };
	int get_annee() const { return m_date_creation.get_annee(); };
	Stade get_stade() const { return m_stade; };
	Entraineur* get_entraineur() { return m_entraineur; };
	std::vector<Staff*> get_staff() { return m_staff; };
	std::vector<Staff*> get_staff(role_t p_role);
	std::vector<Joueur*> get_effectif() { return m_effectif; };
	Joueur* get_effectif_index(int p_index) { return m_effectif[p_index]; };
	std::vector<Palmares*> get_palmares() { return m_palmares; };
	std::vector<Palmares*> get_palmares(titre_t p_titre);
	std::vector<Palmares*> get_palmares(string p_nom);
	std::vector<Palmares*> get_palmares(Date p_date);
	std::vector<Palmares*> get_palmares(int p_annee);
	unsigned int get_nb_palmares() const { return m_palmares.size(); };
	std::vector<Contrat*> get_contrats() { return m_contrats; };
	std::vector<Contrat*> get_contrats(Joueur* p_joueur);
	std::vector<Contrat*> get_contrats(Club* p_club_libere);
	Contrat* get_contrat_index(int p_index) { return m_contrats[p_index]; };

	void set_nom(string p_nom) { m_nom = p_nom; };
	void set_histoire(string p_histoire) { m_histoire = p_histoire; };
	void set_couleur(string p_couleur) { m_couleur = p_couleur; };
	void set_ville(string p_ville) { m_ville = p_ville; };
	void set_adresse(string p_adresse) { m_adresse = p_adresse; };
	void set_date(Date p_date) { m_date_creation = p_date; };
	void set_date(int p_annee) { m_date_creation.set_date(p_annee); };
	void set_stade(Stade p_stade) { m_stade = p_stade; };

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
	void add_palmares(Palmares* p_palmares) { m_palmares.push_back(p_palmares); };
	void add_palmares(titre_t p_titre, string p_nom = "");
	void add_palmares(titre_t p_titre, string p_nom, Date p_date);
	void add_palmares(titre_t p_titre, string p_nom, int p_annee);
	void add_contrat(Contrat* p_contrat);
	void add_contrat(int p_duree, Joueur* p_joueur = nullptr, Club* p_club_libere = nullptr);
	void add_rupture(Rupture* p_rupture);
	void add_rupture(Joueur* p_joueur, Club* p_club, float p_penelite, string p_raison = "");

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
	void remove_palmares(unsigned int index);
	void remove_palmares(Palmares* p_palmares);
	void remove_palmares(titre_t p_titre, string p_nom = "");
	void remove_palmares(titre_t p_titre, string p_nom, Date p_date);
	void remove_palmares(titre_t p_titre, string p_nom, int p_annee);

	static std::vector<Club*> get_list_without(std::vector<Club*> p_list, Club* p_club);
	static int effectuer_transfert(Joueur* p_joueur, Club* p_club_init, Club* p_club_destination, Contrat* p_contrat); //non auto
	static int effectuer_transfert(Joueur* p_joueur, Club* p_club_init, Club* p_club_destination, Contrat* p_contrat, Rupture* p_rupture); //auto
	static Club* get_club_plus_titre(std::vector<Club*> p_clubs);
	static Entraineur* get_entraineur_titre(std::vector<Club*> p_clubs);

	bool operator==(Club const& b) const;
	bool operator!=(Club const& b) const;
	bool operator<(Club const& b) const;
	bool operator>(Club const& b) const;
	bool operator<=(Club const& b) const;
	bool operator>=(Club const& b) const;

private:
	string m_histoire;
	string m_nom;
	string m_couleur;
	string m_ville;
	string m_adresse;

	Date m_date_creation;
	Stade m_stade;

	Entraineur* m_entraineur;
	std::vector<Staff*> m_staff;
	std::vector<Joueur*> m_effectif;
	std::vector<Palmares*> m_palmares;
	std::vector<Contrat*> m_contrats;
	std::vector<Rupture*> m_ruptures;

	bool estEgal(Club b) const;
	bool est_sup(Club b) const;
	bool est_inf(Club b) const;
};

#endif
