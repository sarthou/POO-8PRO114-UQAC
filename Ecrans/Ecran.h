#pragma once

#ifndef ECRAN_H
#define ECRAN_H

#include <cstdlib>
#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>

#include "Affichage.h"
#include "saisie.h"

enum action_t
{
	Retour_menu,
	Quitter,
	Statistiques,
	Ajouter_joueur,
	Examiner_joueur,
	Suprimer_joueur,
	Transfert_joueur,
	Ajouter_club,
	Examiner_club,
	Suprimer_club,
	Ajout_entraineur,
	Examiner_entraineur,
	Suprimer_Entraineur,
	Ajouter_titre,
	Suprimer_titre,
	Ajouter_palmares,
	Examiner_palmares,
	Suprimer_palmares,
	Ajouter_rencontre,
	Editer_rencontre,
	Afficher_calendrier,
	Afficher_matchs,
	Jouer_match,
	Avancer_temps
};

struct action_detail_t
{
	int index;
	action_t action;
};

class Ecran
{
public:
	Ecran() {};
	~Ecran() {};

	static action_detail_t menu(std::vector<Club*> p_club);
	static action_detail_t ecran_club(Club* p_club);
	static action_detail_t ecran_joueurs(Club* p_club);
	static action_detail_t ecran_entraineur(Entraineur* p_entraineur);
	static action_detail_t ecran_palmares(Club* p_club);
	static Club* ecran_stat(std::vector<Club*> p_clubs);
	static action_detail_t ecran_rencontre();
	
	static Club* select_club(std::vector<Club*> p_clubs, bool clear = false, string msg = "");
	static Joueur* select_joueur(std::vector<Joueur*> p_joueurs, bool clear = false, string msg = "");

	static Equipe ecran_equipe(Club* club_ref);
};

#endif
