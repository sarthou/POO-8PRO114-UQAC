#include "Ecran.h"

action_detail_t Ecran::menu(std::vector<Club*> p_club)
{
	system("CLS");
	int choix = -1;
	int nb_club = Affichage::afficher_menu(p_club);

	do
	{
		std::cout << "Choix : ";
		choix = Saisie::saisi_secur<int>();
	} while ((choix < 0) || (choix > nb_club+4));

	action_detail_t action_detail;
	if (choix == 0)
		action_detail.action = Ajouter_club;
	else if(choix == nb_club + 1)
		action_detail.action = Statistiques;
	else if (choix == nb_club + 2)
		action_detail.action = Editer_rencontre;
	else if (choix == nb_club + 3)
		action_detail.action = Avancer_temps;
	else if (choix == nb_club + 4)
		action_detail.action = Quitter;
	else
	{
		action_detail.action = Examiner_club;
		action_detail.index = choix - 1;
	}

	return action_detail;
}

action_detail_t Ecran::ecran_club(Club* p_club)
{
	system("CLS");
	Affichage::afficher_clubs_complet(p_club);

	action_detail_t action_detail;
	action_detail.action = Retour_menu;
	switch (Saisie::saisir_choix_ecran_club())
	{
	case 0:
		action_detail.action = Ajouter_joueur;
		break;
	case 1:
		action_detail.action = Examiner_joueur;
		break;
	case 2:
		if (p_club->get_entraineur() == nullptr)
			action_detail.action = Ajout_entraineur;
		else
			action_detail.action = Examiner_entraineur;
		break;
	case 3:
		action_detail.action = Suprimer_club;
		break;
	case 4:
		action_detail.action = Ajouter_palmares;;
		break;
	case 5:
		action_detail.action = Examiner_palmares;
		break;
	case 6:
		action_detail.action = Retour_menu;
		break;
	default:
		break;
	}

	return action_detail;
}

action_detail_t Ecran::ecran_joueurs(Club* p_club)
{
	system("CLS");
	int nb_joueur = Affichage::afficher_joueurs_complet(p_club);

	action_detail_t action_detail;
	int choix = Saisie::saisir_choix_ecran_joueur(nb_joueur);
	if(choix)
	{
		if (choix > 0)
		{
			action_detail.action = Suprimer_joueur;
			action_detail.index = choix - 1;
		}
		else
		{
			action_detail.action = Transfert_joueur;
			action_detail.index = -choix - 1;
		}
	}
	else
		action_detail.action = Examiner_club;

	return action_detail;
}

action_detail_t Ecran::ecran_entraineur(Entraineur* p_entraineur)
{
	system("CLS");
	int nb_titre = Affichage::afficher_entraineur_complet(p_entraineur);

	action_detail_t action_detail;
	int choix = Saisie::saisir_choix_ecran_entraineur(nb_titre);
	if (choix)
	{
		if(choix == nb_titre + 1)
			action_detail.action = Ajouter_titre;
		else if(choix == nb_titre + 2)
			action_detail.action = Suprimer_Entraineur;
		else
		{
			action_detail.action = Suprimer_titre;
			action_detail.index = choix - 1;
		}
	}
	else
		action_detail.action = Examiner_club;

	return action_detail;
}

action_detail_t Ecran::ecran_palmares(Club* p_club)
{
	system("CLS");
	int nb_palmares = Affichage::afficher_palmares_index(p_club->get_palmares());

	action_detail_t action_detail;
	int choix = Saisie::saisir_choix_multiple(nb_palmares, " : suprimer");
	if (choix)
	{
		action_detail.action = Suprimer_palmares;
		action_detail.index = choix - 1;
	}
	else
		action_detail.action = Examiner_club;

	return action_detail;
}

Club* Ecran::ecran_stat(std::vector<Club*> p_clubs)
{
	Club* tmp_club = nullptr;
	int choix = Saisie::saisir_choix_multiple(1, true, ": Voir montant d'encaisse ");
	if (choix == 1)
		tmp_club = select_club(p_clubs);

	return tmp_club;
}

action_detail_t Ecran::ecran_rencontre()
{
	system("CLS");
	int choix = -1;
	Affichage::afficher_choix_rencontre();

	do
	{
		std::cout << "Choix : ";
		choix = Saisie::saisi_secur<int>();
	} while ((choix < 0) || (choix > 4));

	action_detail_t action_detail;
	if (choix == 0)
		action_detail.action = Retour_menu;
	else if (choix == 1)
		action_detail.action = Ajouter_rencontre;
	else if (choix == 2)
		action_detail.action = Afficher_calendrier;
	else if(choix == 3)
		action_detail.action = Afficher_matchs;
	else
		action_detail.action = Jouer_match;

	return action_detail;
}

Club* Ecran::select_club(std::vector<Club*> p_clubs, bool clear, string msg)
{
	if (!clear)
		system("CLS");

	if(msg != "")
		std::cout << std::endl << msg << std::endl;
	
	Club* select_club = nullptr;
	Affichage::afficher_clubs_index(p_clubs);
	int choix = Saisie::saisir_choix_multiple(p_clubs.size());
	if (choix)
	{
		select_club = p_clubs[choix - 1];
	}

	return select_club;
}

Joueur* Ecran::select_joueur(std::vector<Joueur*> p_joueurs, bool clear, string msg)
{
	if (clear)
		system("CLS");

	if (msg != "")
		std::cout << std::endl << msg << std::endl;

	Joueur* select_joueur = nullptr;
	Affichage::afficher_joueurs_index(p_joueurs);
	int choix = Saisie::saisir_choix_multiple(p_joueurs.size(), false);
	if (choix)
	{
		select_joueur = p_joueurs[choix - 1];
	}

	return select_joueur;
}

Equipe Ecran::ecran_equipe(Club* club_ref)
{
	Joueur* capitaine = select_joueur(club_ref->get_effectif(), true, "Selection du capitaine de l'equipe de " + club_ref->get_nom());
	int nb_gardiens = Saisie::saisir_int("Nombre de gardien :");
	int nb_joueurs = Saisie::saisir_int("Nombre de joueurs sur le terrain :");

	return Equipe(club_ref, nb_joueurs, capitaine, nb_gardiens);
}