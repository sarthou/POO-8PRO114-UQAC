#include "Affichage.h"

int Affichage::afficher_menu(std::vector<Club*> p_club)
{
	int nb_club;
	std::cout << "Ligue de Hokey" << std::endl << std::endl;
	std::cout << "Clubs : " << std::endl;
	nb_club = Affichage::afficher_clubs_index(p_club);

	std::cout << std::endl << std::endl << "Actions : " << std::endl;
	std::cout << "\t0 : Ajouter un club" << std::endl;
	if (nb_club > 0)
		std::cout << "\t1-" << nb_club << " : Examiner un club" << std::endl;
	std::cout << "\t" << nb_club + 1 << " : Statistiques" << std::endl;
	std::cout << "\t" << nb_club + 2 << " : Editer les rencontres" << std::endl;
	std::cout << "\t" << nb_club + 3 << " : Avancer d'un an" << std::endl;
	std::cout << "\t" << nb_club + 4 << " : Quitter" << std::endl;

	return nb_club;
}

/*CLUB*/

void Affichage::afficher_clubs(Club* p_club)
{
	std::cout << "\t" << p_club->get_nom() << " : " << p_club->get_couleur() << " : " << p_club->get_ville() << " : " <<
		p_club->get_annee() << std::endl;
}

void Affichage::afficher_clubs(std::vector<Club*> p_club)
{
	for (std::vector<Club*>::iterator it = p_club.begin(); it != p_club.end(); ++it)
		afficher_clubs(*it);
}

int Affichage::afficher_clubs_index(std::vector<Club*> p_club)
{
	int i = 0;
	for (std::vector<Club*>::iterator it = p_club.begin(); it != p_club.end(); ++it)
	{
		i++;
		std::cout << i << " => ";
		afficher_clubs(*it);
	}
	return i;
}

void Affichage::afficher_clubs_complet(Club* p_club)
{
	std::cout << "Club : " << p_club->get_nom() << std::endl;
	std::cout << "Couleur : "<< p_club->get_couleur() << std::endl;
	std::cout << "Adresse : " << p_club->get_adresse() << " " << p_club->get_ville() << std::endl;
	std::cout << "Cree le : " << date_to_str(p_club->get_date()) << std::endl;
	std::cout << std::endl;
	std::cout << "Historique : " << p_club->get_histoire() << std::endl;

	std::cout << std::endl << "Effectif : " << std::endl;
	afficher_joueurs(p_club->get_effectif());

	std::cout << std::endl << "Staff : " << std::endl;
	afficher_staff(p_club->get_staff());

	std::cout << std::endl << "Palmares : " << std::endl;
	afficher_palmares(p_club->get_palmares());
}

/*JOUEUR*/

void Affichage::afficher_joueurs(Joueur* p_joueur)
{
	std::cout << "\t" << p_joueur->get_nom() << " " << p_joueur->get_prenom() << " : " << std::to_string(p_joueur->get_age()) << " ans : " <<
		std::to_string(p_joueur->get_poids()) << "Kg : " << std::to_string(p_joueur->get_taille()) << "m";
	if(p_joueur->est_autonome())
		std::cout << " autonome" << std::endl;
	else
		std::cout << " non autonome" << std::endl;
}

void Affichage::afficher_joueurs(std::vector<Joueur*> p_joueur)
{
	for (std::vector<Joueur*>::iterator it = p_joueur.begin(); it != p_joueur.end(); ++it)
		afficher_joueurs(*it);
}

int Affichage::afficher_joueurs_index(std::vector<Joueur*> p_joueur)
{
	int i = 0;
	for (std::vector<Joueur*>::iterator it = p_joueur.begin(); it != p_joueur.end(); ++it)
	{
		i++;
		std::cout << i << " => ";
		afficher_joueurs(*it);
	}
	return i;
}

int Affichage::afficher_joueurs_complet(Club* p_club)
{
	std::cout << "Joueurs du club : " << p_club->get_nom() << std::endl << std::endl;
	return afficher_joueurs_index(p_club->get_effectif());
}

/*STAFF*/

void Affichage::afficher_staff(Staff* p_staff)
{
	std::cout << "\t" << p_staff->get_nom() << " " << p_staff->get_prenom() << " : " << role_to_str(p_staff->get_role()) << std::endl;
}

void Affichage::afficher_staff(std::vector<Staff*> p_staff)
{
	for (std::vector<Staff*>::iterator it = p_staff.begin(); it != p_staff.end(); ++it)
		afficher_staff(*it);
}

int Affichage::afficher_staff_index(std::vector<Staff*> p_staff)
{
	int i = 0;
	for (std::vector<Staff*>::iterator it = p_staff.begin(); it != p_staff.end(); ++it)
	{
		i++;
		std::cout << i << " => ";
		afficher_staff(*it);
	}
	return i;
}

/*PALMARES*/
void Affichage::afficher_palmares(Palmares* p_palmares)
{
	std::cout << "\t" << p_palmares->get_nom() << " : " << titre_to_str(p_palmares->get_titre()) << " : " << date_to_str(p_palmares->get_date());
	std::cout << std::endl;
}

void Affichage::afficher_palmares(std::vector<Palmares*> p_palmares)
{
	for (std::vector<Palmares*>::iterator it = p_palmares.begin(); it != p_palmares.end(); ++it)
		afficher_palmares(*it);
}

int Affichage::afficher_palmares_index(std::vector<Palmares*> p_palmares)
{
	int i = 0;
	for (std::vector<Palmares*>::iterator it = p_palmares.begin(); it != p_palmares.end(); ++it)
	{
		i++;
		std::cout << i << " => " ;
		afficher_palmares(*it);
	}
	return i;
}

/*TITRE*/

void Affichage::afficher_titre(Titre* p_titre)
{
	std::cout << "\t" << p_titre->get_nom() << " : " << titre_to_str(p_titre->get_titre()) << " : " << date_to_str(p_titre->get_date());
	std::cout << std::endl;
}

void Affichage::afficher_titre(std::vector<Titre*> p_titre)
{
	for (std::vector<Titre*>::iterator it = p_titre.begin(); it != p_titre.end(); ++it)
		afficher_titre(*it);
}

int Affichage::afficher_titres_index(std::vector<Titre*> p_titre)
{
	int i = 0;
	for (std::vector<Titre*>::iterator it = p_titre.begin(); it != p_titre.end(); ++it)
	{
		i++;
		std::cout << i << " => ";
		afficher_titre(*it);
	}
	return i;
}

/*ENTRAINEUR*/

int Affichage::afficher_entraineur_complet(Entraineur* entraineur)
{
	std::cout << "Entraineur : " << entraineur->get_nom_complet() << std::endl << std::endl;
	return afficher_titres_index(entraineur->get_titre());
}

void Affichage::afficher_statistiques(Club* p_club_titre, Entraineur* p_enraineur_titre)
{
	system("CLS");
	std::cout << "Statistiques" << std::endl << std::endl;

	std::cout << "Meilleur joueur :" << std::endl;
	if (p_club_titre == nullptr)
		std::cout << "Pas de club" << std::endl << std::endl;
	else
		std::cout << "Club : " << p_club_titre->get_nom() << " : " << p_club_titre->get_nb_palmares() << " palmares" << std::endl << std::endl;

	std::cout << "Meilleur entraineur :" << std::endl;
	if (p_enraineur_titre == nullptr)
		std::cout << "Pas d'entraineur" << std::endl << std::endl;
	else
		std::cout << "Entraineur : " << p_enraineur_titre->get_nom() << " : " << p_enraineur_titre->get_nb_titres() << " titres " << std::endl << std::endl;
}

/*RENCONTRE*/

void Affichage::afficher_rencontre(Rencontre* p_rencontre)
{
	std::cout << "\t" << p_rencontre->get_club_local().get_nom() << " VS " << p_rencontre->get_club_adverse().get_nom() << " : " << date_to_str(p_rencontre->get_date());
	std::cout << std::endl;
}

void Affichage::afficher_rencontre(std::vector<Rencontre*> p_rencontre)
{
	for (std::vector<Rencontre*>::iterator it = p_rencontre.begin(); it != p_rencontre.end(); ++it)
		afficher_rencontre(*it);
}

int Affichage::afficher_rencontre_index(std::vector<Rencontre*> p_rencontre)
{
	int i = 0;
	for (std::vector<Rencontre*>::iterator it = p_rencontre.begin(); it != p_rencontre.end(); ++it)
	{
		i++;
		std::cout << i << " => ";
		afficher_rencontre(*it);
	}
	return i;
}

void Affichage::afficher_choix_rencontre()
{
	std::cout << std::endl << std::endl << "Actions : " << std::endl;
	std::cout << "\t0 : Retour" << std::endl;
	std::cout << "\t1 : Ajouter une rencontre" << std::endl;
	std::cout << "\t2 : Examiner les rencontres" << std::endl;
	std::cout << "\t3 : Voir les matchs joues" << std::endl;
	std::cout << "\t4 : Jouer le prochain match" << std::endl;
}

/*MATCH*/
void Affichage::afficher_match(Match* p_match)
{
	std::cout << "\t" << p_match->get_club_local().get_nom() << " VS " << p_match->get_club_adverse().get_nom() << " : " << p_match->get_nb_but_local() <<
		" a " << p_match->get_nb_but_adverse();
}

void Affichage::afficher_match(std::vector<Rencontre*> p_rencontres)
{
	for (std::vector<Rencontre*>::iterator it = p_rencontres.begin(); it != p_rencontres.end(); ++it)
	{
		if ((*it)->get_match() != nullptr)
		{
			afficher_match((*it)->get_match());
			std::cout << " : " << date_to_str((*it)->get_date()) << std::endl;
		}
	}
}

/* negociation*/

void Affichage::afficher_message(Message* p_message)
{
	string nom = p_message->get_emetteur()->get_nom_representant();
	switch (p_message->get_sujet())
	{
	case offre:
		std::cout << "@" << nom << " | OFFRE  | " << p_message->get_montant() << std::endl;
		break;
	case acceptation:
		std::cout << "@" << nom << " | ACCEPT | " << p_message->get_montant() << std::endl;
		break;
	case rejet:
		std::cout << "@" << nom << " | REJET  | " << std::endl;
		break;
	case erreur:
		std::cout << "@" << nom << " | ERREUR | " << std::endl;
		break;
	}
}

/*UTILITY*/

std::string Affichage::date_to_str(Date p_date)
{
	std::string tmp = std::to_string(p_date.get_annee()) + " - " + std::to_string(p_date.get_mois()) + " - " + std::to_string(p_date.get_jour());
	return (tmp);
}

std::string Affichage::role_to_str(role_t p_role)
{
	switch (p_role)
	{
	case entraineur:
		return "entraineur";
	case president:
		return "president";
	case secretaire:
		return "secretaire";
	case recruteur:
		return "recruteur";
	case infirmier:
		return "infirmier";
	default:
		return "-";
	}
}

std::string Affichage::titre_to_str(titre_t p_titre)
{
	switch (p_titre)
	{
	case coupe:
		return "coupe";
	case championnat:
		return "championnat";
	default:
		return "-";
	}
}