#include "saisie.h"

Club* Saisie::saisir_club()
{
	clear_buffers();
	string nom = saisir_string("Nom du club : ");
	string couleur = saisir_string("Couleur du club : ");
	string ville = saisir_string("Ville du club : ");
	string adresse = saisir_string("Adresse du club : ");
	string histoire = saisir_string("Histoire du club : ");
	Date date_creation = saisir_date("Date de creation du club : ");

	return new Club(nom, couleur, date_creation, Stade(), ville, adresse, histoire);
}

Joueur* Saisie::saisir_joueur()
{
	clear_buffers();
	string nom = saisir_string("Nom du joueur : ");
	string prenom = saisir_string("Prenom du joueur : ");
	string ville = saisir_string("Ville du joueur : ");
	int age = saisir_int("Age du joueur : ");
	float taille = saisir_float("Taille du joueur : ");
	float poids = saisir_float("Poids du joueur : ");

	char res = ' ';
	do
	{
		std::cout << "Le joueur est-il autonome ? (o / n)" << std::endl;
		std::cin >> res;
	} while ((res != 'o') && (res != 'O') && (res != 'n') && (res != 'N'));

	if((res == 'o') || (res == 'O'))
		return new Joueur_auto(nom, prenom, age, ville, taille, poids);
	else
		return new Joueur_non_auto(nom, prenom, age, ville, taille, poids,0,0);
}

Entraineur* Saisie::saisir_entraineur()
{
	clear_buffers();
	string nom = saisir_string("Nom de l'entraineur : ");
	string prenom = saisir_string("Prenom de l'entraineur : ");;
	string lieu_obtention_grade = saisir_string("Lieu d'obtention du grade : ");

	Entraineur* entraineur = new Entraineur(nom, prenom, lieu_obtention_grade);
	return entraineur;
}

Titre* Saisie::saisir_titre()
{
	clear_buffers();
	string nom = saisir_string("Nom du titre : ");
	Date date = saisir_date("Date : ");

	return new Titre(autre_titre, nom, date, nullptr);
}

Palmares* Saisie::saisir_palmares()
{
	clear_buffers();
	string nom = saisir_string("Nom du titre : ");
	Date date = saisir_date("Date : ");

	return new Palmares(autre_titre, nom, date);
}

Contrat* Saisie::saisir_contrat()
{
	Date date = saisir_date("Date du contrat : ");
	int duree = saisir_int("Duree du contrat : ");
	Reglement reglement = saisir_reglement();

	return  new Contrat(nullptr, nullptr, date.get_date(), duree, reglement);
}

Rupture* Saisie::saisir_rupture()
{
	std::cout << std::endl << "Le joueur etant autonome, un rupture de contrat doit etre realise avec son ancien cub :" << std::endl;
	
	clear_buffers();
	string raison = saisir_string("Raison de la rupture : ");
	float penalite = saisir_float("Penalite : ");

	return  new Rupture(nullptr, nullptr, penalite, raison);
}

Reglement Saisie::saisir_reglement()
{
	std::cout << std::endl << "Saisi du réglement avec l'ancien club :" << std::endl;
	
	float montant_transfert = saisir_float("Montant du transfert : ");
	float montant_encaisse = saisir_float("Montant du encaisse : ");
	int seuil_en_vigueur = saisir_int("Seuil en vigueur : ");
	clear_buffers();
	string description_droits = saisir_string("Description des droits : ");
	
	return Reglement(montant_transfert, montant_encaisse, seuil_en_vigueur, description_droits);
}

Periode Saisie::saisir_periode(Match p_match)
{
	std::cout << std::endl << "Saisi de la periode " << p_match.get_nb_periode()+1 << " :" << std::endl;
	int but_local = saisir_int("But de l'equipe " + p_match.get_club_local().get_nom() + " : ");
	int but_adverse = saisir_int("But de l'equipe " + p_match.get_club_adverse().get_nom() + " : ");
	int duree = saisir_int("Duree de la periode : ");
	return Periode(duree, but_local, but_adverse);
}

/*
*SAISIE ECRANS
*/

int Saisie::saisir_choix_ecran_club()
{
	int choix = -1;
	
	std::cout << std::endl << std::endl << "Actions : " << std::endl;
	std::cout << "\t0 : Ajouter un joueur" << std::endl;
	std::cout << "\t1 : Suprimer ou transferer un joueur" << std::endl;
	std::cout << "\t2 : Editer l'entraineur" << std::endl;
	std::cout << "\t3 : Suprimer le club" << std::endl;
	std::cout << "\t4 : Ajouter un palmares" << std::endl;
	std::cout << "\t5 : Suprimer un palmares" << std::endl;
	std::cout << "\t6 : Retour menu" << std::endl;

	do
	{
		std::cout << "Choix : ";
		choix = saisi_int_secur();
	} while ((choix < 0) || (choix > 6));

	return choix;
}

int Saisie::saisir_choix_ecran_joueur(int nb_joueur)
{
	int choix = -1;

	std::cout << std::endl << std::endl << "Actions : " << std::endl;
	std::cout << "\t0 : Retour" << std::endl;
	if(nb_joueur > 0)
		std::cout << "\t1-" << nb_joueur << " : Selectionner un joueur" << std::endl;

	do
	{
		std::cout << "Choix : ";
		choix = saisi_int_secur();
	} while ((choix < 0) || (choix > nb_joueur));

	int choix2 = -1;
	if (choix != 0)
	{
		std::cout << std::endl << std::endl << "Actions : " << std::endl;
		std::cout << "\t0 : Retour" << std::endl;
		std::cout << "\t1 : Suprimer" << std::endl;
		std::cout << "\t2 : Transferer" << std::endl;

		do
		{
			std::cout << "Choix : ";
			choix2 = saisi_int_secur();
		} while ((choix2 < 0) || (choix2 > 2));
		if (choix2 == 2)
			choix = -choix;
		else if (choix2 == 0)
			choix = 0;
	}

	return choix;
}

int Saisie::saisir_choix_ecran_entraineur(int nb_titre)
{
	int choix = -1;

	std::cout << std::endl << std::endl << "Actions : " << std::endl;
	std::cout << "\t0 : Retour" << std::endl;
	if (nb_titre > 0)
		std::cout << "\t1-" << nb_titre << " : suprimer titre" << std::endl;
	std::cout << "\t" << nb_titre + 1 << " : Ajouter titre" << std::endl;
	std::cout << "\t" << nb_titre + 2 << " : Suprimer entrainer" << std::endl;

	do
	{
		std::cout << "Choix : ";
		choix = saisi_int_secur();
	} while ((choix < 0) || (choix > nb_titre +2));

	return choix;
}


/*UTILITY*/

int Saisie::saisir_choix_multiple(int nb_element, bool retour, string msg )
{
	int choix = -1;

	std::cout << std::endl << std::endl << "Actions : " << std::endl;
	if(retour)
		std::cout << "\t0 : Retour" << std::endl;
	if (nb_element > 0)
	{
		if (nb_element == 1)
			std::cout << "\t1 " << msg << std::endl;
		else
			std::cout << "\t1-" << nb_element << msg << std::endl;
	}

	do
	{
		std::cout << "Choix : ";
		choix = saisi_int_secur();
	} while ((((choix < 1) || (choix > nb_element)) && (retour == false)) || (((choix < 0) || (choix > nb_element)) && (retour == true)));

	return choix;
}

Date Saisie::saisir_date(string msg)
{
	std::cout << msg << std::endl;
	int annee = -1;
	do
	{
		std::cout << "\tannee ";
		annee = saisi_int_secur();
	} while ((annee > 9999) || (annee < 0));

	int mois = -1;
	do
	{
		std::cout << "\tmois ";
		mois = saisi_int_secur();
	} while ((mois > 12) || (mois < 1));

	int jour = -1;
	do
	{
		std::cout << "\tjour ";
		jour =saisi_int_secur();
	} while ((jour > 31) || (jour < 1));

	std::cout << std::endl;

	return (Date(annee, mois, jour));
}

int Saisie::saisir_int(string msg)
{
	int valeur = -1;
	do
	{
		std::cout << msg;
		valeur = saisi_int_secur();
	} while (valeur == -1);
	std::cout << std::endl;

	return valeur;
}

float Saisie::saisir_float(string msg)
{
	float valeur = -1.;
	do
	{
		std::cout << msg;
		valeur = saisi_float_secur();
	} while (valeur == -1.);
	std::cout << std::endl;

	return valeur;
}

string Saisie::saisir_string(string msg)
{
	string valeur;
	std::cout << msg;
	std::getline(std::cin, valeur);
	std::cout << std::endl;

	return valeur;
}

void Saisie::clear_buffers()
{
	std::cin.clear();
	std::cin.ignore();
}

/*Securisation*/

int Saisie::saisi_int_secur()
{
	int tmp = -1;
	std::cin >> tmp;
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore();
	}
	return tmp;
}

float Saisie::saisi_float_secur()
{
	float tmp = -1.;
	std::cin >> tmp;
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore();
	}
	return tmp;
}