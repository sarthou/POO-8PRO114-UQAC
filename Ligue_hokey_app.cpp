#include "Ligue_hokey.h"

/*CLUB*/

void Ligue_hokey::ajout_club()
{
	system("CLS");
	Club* club = Saisie::saisir_club();
	add_club(club);
	club_a_etudier = club;

	m_next_action.action = Examiner_club;
}

void Ligue_hokey::supprimer_club_a_etudier()
{
	if (club_a_etudier != nullptr)
	{
		remove_club(club_a_etudier);
		club_a_etudier = nullptr;
	}
	m_next_action.action = Retour_menu;
}

/*JOUEUR*/

void Ligue_hokey::ajout_joueur()
{
	system("CLS");
	Joueur* joueur = Saisie::saisir_joueur();
	Contrat* contrat = Saisie::saisir_contrat();
	int err;
	if (joueur->est_autonome())
		err = Club::effectuer_transfert(joueur, nullptr, club_a_etudier, contrat, nullptr);
	else
		err = Club::effectuer_transfert(joueur, nullptr, club_a_etudier, contrat);

	if (err)
	{
		std::cout << "Une erreure est survenue à la saisie du joueur" << std::endl;
		system("PAUSE");
	}

	m_next_action.action = Examiner_club;
}

void Ligue_hokey::supprimer_joueur_a_etudier()
{
	club_a_etudier->remove_joueur(club_a_etudier->get_effectif_index(m_next_action.index));
	m_next_action.action = Examiner_club;
}

void Ligue_hokey::effectuer_un_transfert()
{
	std::vector<Club*> clubs_dest = Club::get_list_without(m_clubs, club_a_etudier);
	if (clubs_dest.size() == 0)
	{
		system("CLS");
		std::cout << "Aucun clubs trouvé pour effectuer le transfert." << std::endl;
		system("PAUSE");
		m_next_action.action = Examiner_joueur;
	}
	else
	{
		system("CLS");
		if (club_a_etudier->get_effectif_index(m_next_action.index)->peut_rompre_contrat())
		{
			Club* club_dest = Ecran::select_club(clubs_dest, true, "Clubs de destinations : ");
			if (club_dest != nullptr)
			{
				m_simu.simuler(club_a_etudier, club_dest);
				remplir_documents_rupture(club_dest);
				m_next_action.action = Examiner_club;

			}
			else
				m_next_action.action = Examiner_joueur;
		}
		else
		{
			std::cout << std::endl << "Ce joueur ne peut pas etre transfere car son contrat n'est pas finis." << std::endl;
			system("PAUSE");
			m_next_action.action = Examiner_joueur;
		}
	}
}

void Ligue_hokey::remplir_documents_rupture(Club* p_club_dest)
{
	int err = -1;

	Contrat* contrat = Saisie::saisir_contrat();
	Rupture* rupture = nullptr;

	if (club_a_etudier->get_effectif_index(m_next_action.index)->est_autonome())
	{
		rupture = Saisie::saisir_rupture();
		err = Club::effectuer_transfert(club_a_etudier->get_effectif_index(m_next_action.index), club_a_etudier, p_club_dest, contrat, rupture);
	}
	else
		err = Club::effectuer_transfert(club_a_etudier->get_effectif_index(m_next_action.index), club_a_etudier, p_club_dest, contrat);

	if (err)
	{
		std::cout << std::endl << "Ce joueur ne peut pas etre transfere." << std::endl;
		system("PAUSE");
	}
	else
		club_a_etudier = p_club_dest;
}

/*ENTRAINEUR*/

void Ligue_hokey::ajouter_entraineur()
{
	system("CLS");
	if (club_a_etudier->get_entraineur() == nullptr)
	{
		Entraineur* entraineur = Saisie::saisir_entraineur();
		club_a_etudier->add_entraineur(entraineur);
	}
	else
	{
		std::cout << "L'equipe possede deja un entraineur" << std::endl << std::endl;
		system("PAUSE");
	}

	m_next_action.action = Examiner_entraineur;
}

void Ligue_hokey::suprimer_entraineur()
{
	club_a_etudier->remove_entraineur();
	m_next_action.action = Examiner_club;
}

/*TITRE*/

void Ligue_hokey::ajouter_titre()
{
	system("CLS");
	Titre* titre = Saisie::saisir_titre();
	club_a_etudier->get_entraineur()->ajout_titre(titre);

	m_next_action.action = Examiner_entraineur;
}

void Ligue_hokey::suprimer_titre()
{
	club_a_etudier->get_entraineur()->remove_titre(m_next_action.index);
	m_next_action.action = Examiner_entraineur;
}

/*PALMARES*/

void Ligue_hokey::ajouter_palmares()
{
	system("CLS");
	Palmares* palmares = Saisie::saisir_palmares();
	club_a_etudier->add_palmares(palmares);

	m_next_action.action = Examiner_club;
}

void Ligue_hokey::suprimer_palmares()
{
	club_a_etudier->remove_palmares(m_next_action.index);
	m_next_action.action = Examiner_palmares;
}

/*CALENDRIER*/

void Ligue_hokey::afficher_calendrier()
{
	system("CLS");
	Club* club_select = Ecran::select_club(m_clubs, true, "Selectionnez un club : ");
	system("CLS");
	if (club_select != nullptr)
	{
		std::vector<Rencontre*> rencontres;
		for (std::vector<Rencontre*>::iterator it = m_calendrier.begin(); it != m_calendrier.end(); ++it)
		{
			if (((*it)->get_club_local() == *club_select) || ((*it)->get_club_adverse() == *club_select))
				rencontres.push_back(*it);
		}
		Affichage::afficher_rencontre(rencontres);
		system("PAUSE");
	}
	m_next_action.action = Editer_rencontre;
}

void Ligue_hokey::ajouter_rencontre()
{
	system("CLS");
	Club* local = Ecran::select_club(m_clubs, true, "Selection du club local : ");
	if (local != nullptr)
	{
		system("CLS");
		std::vector<Club*> clubs_reduit = Club::get_list_without(m_clubs, local);
		Club* adverse = Ecran::select_club(clubs_reduit, true, "Selection du club adverse : ");
		if (adverse != nullptr)
		{
			system("CLS");
			Date date = Saisie::saisir_date("Date de la rencontre :");

			m_calendrier.push_back(new Rencontre(local, adverse, date.get_date()));
		}
	}
	m_next_action.action = Editer_rencontre;
}

/*MATCH*/
void Ligue_hokey::afficher_matchs()
{
	system("CLS");
	std::cout << "Match joues : " << std::endl;
	Affichage::afficher_match(m_calendrier);
	system("PAUSE");
	m_next_action.action = Editer_rencontre;
}

void Ligue_hokey::jouer_prochain_match()
{
	system("CLS");
	Rencontre* tmp_rencontre = Rencontre::get_prochaine_rencontre(m_calendrier);

	if (tmp_rencontre != nullptr)
	{
		
		Match* tmp_match = new Match(tmp_rencontre->edit_club_local(), tmp_rencontre->edit_club_adverse());
		tmp_match->set_equipe_locale(Ecran::ecran_equipe(tmp_rencontre->edit_club_local()));
		tmp_match->set_equipe_adverse(Ecran::ecran_equipe(tmp_rencontre->edit_club_adverse()));
		int choix;
		do
		{
			system("CLS");
			tmp_match->add_new_periode(Saisie::saisir_periode(*tmp_match));
			choix = Saisie::saisir_choix_multiple(1, true, " : Jouer une autre periode");
		} while (choix != 0);
		tmp_rencontre->set_match(tmp_match);
	}
	else
	{
		std::cout << "Pas de match a jouer" << std::endl;
		system("PAUSE");
	}
	m_next_action.action = Editer_rencontre;
}

/*STATS*/

void Ligue_hokey::calculer_statistiques()
{
	Club* club_titre = Club::get_club_plus_titre(m_clubs);
	Entraineur* enraineur_titre = Club::get_entraineur_titre(m_clubs);
	Affichage::afficher_statistiques(club_titre, enraineur_titre);

	Club* tmp_club = Ecran::ecran_stat(m_clubs);
	if (tmp_club != nullptr)
	{
		Date date = Saisie::saisir_date("Date : ");

		float total_reglement = 0.;

		for (std::vector<Club*>::iterator it = m_clubs.begin(); it != m_clubs.end(); ++it)
		{
			std::vector<Contrat*> contrats = (*it)->get_contrats();
			for (std::vector<Contrat*>::iterator iit = contrats.begin(); iit != contrats.end(); ++iit)
			{
				if (((*iit)->get_club_libere() == tmp_club) && (date <= (*iit)->get_date_contrat()))
					total_reglement += (*iit)->get_reglement().get_montant_encaisse();
			}
		}

		std::cout << "total_encaisse : " << total_reglement << std::endl;
		system("PAUSE");
		m_next_action.action = Statistiques;
	}
	else
	{
		m_next_action.action = Retour_menu;
	}

	
}

void Ligue_hokey::avancer_temps()
{
	if (m_clubs.size() != 0)
	{
		for (std::vector<Club*>::iterator it = m_clubs.begin(); it != m_clubs.end(); ++it)
		{
			std::vector<Joueur*> joueurs = (*it)->get_effectif();
			if (joueurs.size() != 0)
			{
				for (std::vector<Joueur*>::iterator iit = joueurs.begin(); iit != joueurs.end(); ++iit)
				{
					if (!(*iit)->est_autonome())
					{
						Joueur_non_auto* tmp_joueur = (Joueur_non_auto*)(*iit);
						tmp_joueur->add_annee_cumules();
					}
				}
			}
		}
	}
	m_next_action.action = Retour_menu;
}