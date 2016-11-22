#pragma once

#ifndef SAISIE_H
#define SAISIE_H

#include <cstdlib>
#include <string>
#include <vector>
#include <iostream>

#include "..\Personnages\Joueur.h"
#include "..\Personnages\Joueur_non_auto.h"
#include "..\Personnages\Staff.h"
#include "..\Personnages\Entraineur.h"

#include "..\Utility\Date.h"
#include "..\Utility\Palmares.h"
#include "..\Utility\Parcours.h"
#include "..\Utility\Titre.h"

#include "..\Contrat\Contrat.h"

#include "..\Matchs\Rencontre.h"

#include "..\infrastructure\Stade.h"

#include "../Negociation/Nego_vendeur.h"
#include "../Negociation/Nego_acheteur.h"

#include "..\Club.h"

class Saisie
{
public:
	Saisie() {};
	~Saisie() {};

	static Club* saisir_club();
	static Joueur* saisir_joueur();
	static Entraineur* saisir_entraineur();
	static Titre* saisir_titre();
	static Palmares* saisir_palmares();
	static Contrat* saisir_contrat(int p_montant = -1);
	static Rupture* saisir_rupture();
	static Reglement saisir_reglement(int p_montant);
	static Periode saisir_periode(Match p_match);
	static Nego_vendeur* saisir_nego_vendeur(Club* p_ref);
	static Nego_acheteur* saisir_nego_acheteur(Club* p_ref);

	static int saisir_choix_ecran_club();
	static int saisir_choix_ecran_joueur(int nb_joueur);
	static int saisir_choix_ecran_entraineur(int nb_titre);
	static int saisir_choix_multiple(int nb_element, bool retour = true, string msg = " : selectionner");
	static strategie_t saisir_strategie();

	static Date saisir_date(string msg);
	static int saisir_int(string msg);
	static float saisir_float(string msg);
	static string saisir_string(string msg);
	static void clear_buffers();

	static int saisi_int_secur();
	static float saisi_float_secur();

};

#endif
