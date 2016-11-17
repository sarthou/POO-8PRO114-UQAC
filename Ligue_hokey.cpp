#include "Ligue_hokey.h"
//#include "Utility\export.h"

Ligue_hokey::Ligue_hokey()
{
	m_next_action.action = Retour_menu;
	club_a_etudier = nullptr;
}

Ligue_hokey::~Ligue_hokey()
{
	for (std::vector<Club*>::iterator it = m_clubs.begin(); it != m_clubs.end(); ++it)
		delete *it;

	for (std::vector<Rencontre*>::iterator it = m_calendrier.begin(); it != m_calendrier.end(); ++it)
		delete *it;
}

/*ADD*/

void Ligue_hokey::add_club(Club* p_club)
{
	m_clubs.push_back(p_club);
}

void Ligue_hokey::add_club(std::string p_nom, std::string p_couleur)
{
	Club* tmp_club = new Club(p_nom, p_couleur);
	m_clubs.push_back(tmp_club);
}

void Ligue_hokey::add_club(std::string p_nom, std::string p_couleur, Date p_date_creation)
{
	Club* tmp_club = new Club(p_nom, p_couleur, p_date_creation);
	m_clubs.push_back(tmp_club);
}

void Ligue_hokey::add_club(std::string p_nom, std::string p_couleur, Date p_date_creation, Stade p_stade)
{
	Club* tmp_club = new Club(p_nom, p_couleur, p_date_creation, p_stade);
	m_clubs.push_back(tmp_club);
}

void Ligue_hokey::add_club(std::string p_nom, std::string p_couleur, Date p_date_creation, Stade p_stade, std::string p_ville, std::string p_adresse, std::string p_histoire)
{
	Club* tmp_club = new Club(p_nom, p_couleur, p_date_creation, p_stade, p_ville, p_adresse, p_histoire);
	m_clubs.push_back(tmp_club);
}

/*REMOVE*/

void Ligue_hokey::remove_club(Club* p_club)
{
	for (std::vector<Club*>::iterator it = m_clubs.begin(); it != m_clubs.end(); ++it)
	{
		if ((*p_club) == (*(*it)))
		{
			Club* tmp_club = *it;
			m_clubs.erase(it);
			delete tmp_club;
			break;
		}
	}
}

void Ligue_hokey::remove_club(std::string p_nom, std::string p_couleur)
{
	Club* tmp_club = new Club(p_nom, p_couleur);
	remove_club(tmp_club);
	delete tmp_club;
}

void Ligue_hokey::remove_club(std::string p_nom, std::string p_couleur, Date p_date_creation)
{
	Club* tmp_club = new Club(p_nom, p_couleur, p_date_creation);
	remove_club(tmp_club);
	delete tmp_club;
}

void Ligue_hokey::remove_club(std::string p_nom, std::string p_couleur, Date p_date_creation, Stade p_stade)
{
	Club* tmp_club = new Club(p_nom, p_couleur, p_date_creation, p_stade);
	remove_club(tmp_club);
	delete tmp_club;
}

void Ligue_hokey::remove_club(std::string p_nom, std::string p_couleur, Date p_date_creation, Stade p_stade, std::string p_ville, std::string p_adresse, std::string p_histoire)
{
	Club* tmp_club = new Club(p_nom, p_couleur, p_date_creation, p_stade, p_ville, p_adresse, p_histoire);
	remove_club(tmp_club);
	delete tmp_club;
}

void Ligue_hokey::add_rencontre(Club* p_local, Club* p_adverse, struct tm p_date)
{
	m_calendrier.push_back(new Rencontre(p_local, p_adverse, p_date));
}

/*APP*/

void Ligue_hokey::run()
{
	do
	{
		switch (m_next_action.action)
		{
		case Retour_menu:
			m_next_action = Ecran::menu(get_clubs());
			club_a_etudier = nullptr;
			break;

		case Ajouter_club:
			ajout_club();
			break;

		case Statistiques:
			calculer_statistiques();
			break;

		case Examiner_club:
			if(club_a_etudier == nullptr)
				club_a_etudier = get_clubs_index(m_next_action.index);
			m_next_action = Ecran::ecran_club(club_a_etudier);
			break;

		case Suprimer_club:
			supprimer_club_a_etudier();
			break;

		case Ajouter_joueur:
			ajout_joueur();
			break;

		case Examiner_joueur:
			m_next_action = Ecran::ecran_joueurs(club_a_etudier);
			break;

		case Suprimer_joueur:
			supprimer_joueur_a_etudier();
			break;

		case Transfert_joueur:
			effectuer_un_transfert();
			break;

		case Ajout_entraineur:
			ajouter_entraineur();
			break;

		case Examiner_entraineur:
			if (club_a_etudier->get_entraineur() != nullptr)
				m_next_action = Ecran::ecran_entraineur(club_a_etudier->get_entraineur());
			else
				m_next_action.action = Examiner_club;
			break;

		case Suprimer_Entraineur:
			suprimer_entraineur();
			break;

		case Ajouter_titre:
			ajouter_titre();
			break;

		case Suprimer_titre:
			suprimer_titre();
			break;

		case Ajouter_palmares:
			ajouter_palmares();
			break;

		case Examiner_palmares:
			m_next_action = Ecran::ecran_palmares(club_a_etudier);
			break;

		case Suprimer_palmares:
			suprimer_palmares();
			break;

		case Afficher_calendrier:
			afficher_calendrier();
			break;

		case Ajouter_rencontre:
			ajouter_rencontre();
			break;

		case Editer_rencontre:
			m_next_action = Ecran::ecran_rencontre();
			break;

		case Afficher_matchs:
			afficher_matchs();
			break;

		case Jouer_match:
			jouer_prochain_match();
			break;

		case Avancer_temps:
			avancer_temps();
			break;
			
		default:
			break;


		}


	} while (m_next_action.action != Quitter);
}


