#pragma once

#ifndef LIGUE_HOKEY_H
#define LIGUE_HOKEY_H

#include <cstdlib>
#include <string>
#include <vector>
#include "Club.h"
#include "Ecrans\Ecran.h"
#include "Matchs\Rencontre.h"
#include "Negociation\Simu_negociation.h"

#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/vector.hpp>

class Ligue_hokey
{
public:
	Ligue_hokey();
	~Ligue_hokey();

	std::vector<Club*> get_clubs() { return m_clubs; };
	Club* get_clubs_index(int index) { return m_clubs[index]; };

	void add_club(Club* p_club);
	void add_club(std::string p_nom, std::string p_couleur = "");
	void add_club(std::string p_nom, std::string p_couleur, Date p_date_creation);
	void add_club(std::string p_nom, std::string p_couleur, Date p_date_creation, Stade p_stade);
	void add_club(std::string p_nom, std::string p_couleur, Date p_date_creation, Stade p_stade, std::string p_ville = "", std::string p_adresse = "", std::string p_histoire = "");

	void remove_club(Club* p_club);
	void remove_club(std::string p_nom, std::string p_couleur = "");
	void remove_club(std::string p_nom, std::string p_couleur, Date p_date_creation);
	void remove_club(std::string p_nom, std::string p_couleur, Date p_date_creation, Stade p_stade);
	void remove_club(std::string p_nom, std::string p_couleur, Date p_date_creation, Stade p_stade, std::string p_ville = "", std::string p_adresse = "", std::string p_histoire = "");

	void add_rencontre(Club* p_local, Club* p_adverse, struct tm p_date);

	void run();

private:
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive & ar, const unsigned int version) {
	    (void)version;
		ar & m_clubs;
		ar & m_calendrier;
	}

	std::vector<Club*> m_clubs;
	std::vector<Rencontre*> m_calendrier; 
	action_detail_t m_next_action;
	Club* club_a_etudier;
	Simu_negociation m_simu;

	void ajout_club();
	void supprimer_club_a_etudier();

	void ajout_joueur();
	void supprimer_joueur_a_etudier();
	void effectuer_un_transfert();
	void remplir_documents_rupture(Club* p_club_dest, int p_montant = -1);

	void ajouter_entraineur();
	void suprimer_entraineur();

	void ajouter_titre();
	void suprimer_titre();

	void ajouter_palmares();
	void suprimer_palmares();

	void afficher_calendrier();
	void ajouter_rencontre();

	void afficher_matchs();
	void jouer_prochain_match();

	void calculer_statistiques();

	void avancer_temps();
};


#endif
