#pragma once

#ifndef AFFICHAGE_H
#define AFFICHAGE_H

#include <cstdlib>
#include <string>
#include <vector>
#include <iostream>

#include "..\Personnages\Joueur.h"
#include "..\Personnages\Staff.h"
#include "..\Personnages\Entraineur.h"

#include "..\Utility\Date.h"
#include "..\Utility\Palmares.h"
#include "..\Utility\Parcours.h"
#include "..\Utility\Titre.h"

#include "..\infrastructure\Stade.h"

#include "..\Matchs\Rencontre.h"

#include "../Negociation/Message.h"
#include "../Negociation/Negociateur.h"

#include "..\Club.h"

class Affichage
{
public: 
	Affichage() {};
	~Affichage() {};

	static int afficher_menu(std::vector<Club*> p_club);

	static void afficher_clubs(Club* p_club);
	static void afficher_clubs(std::vector<Club*> p_club);
	static int afficher_clubs_index(std::vector<Club*> p_club);
	static void afficher_clubs_complet(Club* p_club);

	static void afficher_joueurs(Joueur* p_joueur);
	static void afficher_joueurs(std::vector<Joueur*> p_joueur);
	static int afficher_joueurs_index(std::vector<Joueur*> p_joueur);
	static int afficher_joueurs_complet(Club* p_club);

	static void afficher_staff(Staff* p_staff);
	static void afficher_staff(std::vector<Staff*> p_staff);
	static int afficher_staff_index(std::vector<Staff*> p_staff);

	static void afficher_palmares(Palmares* p_palmares);
	static void afficher_palmares(std::vector<Palmares*> p_palmares);
	static int afficher_palmares_index(std::vector<Palmares*> p_palmares);

	static void afficher_titre(Titre* p_titre);
	static void afficher_titre(std::vector<Titre*> p_titre);
	static int afficher_titres_index(std::vector<Titre*> p_titre);

	static void afficher_rencontre(Rencontre* p_rencontre);
	static void afficher_rencontre(std::vector<Rencontre*> p_rencontre);
	static int afficher_rencontre_index(std::vector<Rencontre*> p_rencontre);
	static void afficher_choix_rencontre();

	static void afficher_match(Match* p_match);
	static void afficher_match(std::vector<Rencontre*> p_rencontres);

	static int afficher_entraineur_complet(Entraineur* entraineur);

	static void afficher_statistiques(Club* p_club_titre, Entraineur* p_enraineur_titre);

	static void afficher_message(Message* p_message);

	static std::string date_to_str(Date p_date);
	static std::string role_to_str(role_t p_role);
	static std::string titre_to_str(titre_t p_titre);

};

#endif
