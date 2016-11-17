#include "Club.h"

Club::Club()
{
	m_couleur = "";
}

Club::Club(std::string p_nom, std::string p_couleur) : Structure_administrative(p_nom)
{
	m_couleur = p_couleur;
}

Club::Club(std::string p_nom, std::string p_couleur, Date p_date_creation) : Structure_administrative(p_nom, "", "", "", p_date_creation)
{
	m_couleur = p_couleur;
}

Club::Club(std::string p_nom, std::string p_couleur, Date p_date_creation, Stade p_stade, std::string p_ville, std::string p_adresse, std::string p_histoire) : Structure_administrative(p_nom, p_histoire, p_ville, p_adresse, p_date_creation)
{
	m_couleur = p_couleur;
	m_stade = p_stade;
}

Club::Club(const Club& p_club) : Structure_administrative(p_club.get_nom(), p_club.get_histoire(), p_club.get_ville(), p_club.get_adresse(), p_club.get_date())
{
	m_couleur = p_club.get_couleur();
	m_stade = p_club.get_stade();
}

Club::~Club()
{
	for (std::vector<Palmares*>::iterator it = m_palmares.begin(); it != m_palmares.end(); ++it)
		delete *it;

	for (std::vector<Contrat*>::iterator it = m_contrats.begin(); it != m_contrats.end(); ++it)
		delete *it;

	for (std::vector<Rupture*>::iterator it = m_ruptures.begin(); it != m_ruptures.end(); ++it)
		delete *it;
}

/*GET*/

std::vector<Palmares*> Club::get_palmares(titre_t p_titre)
{
	std::vector<Palmares*> liste_staff;
	for (std::vector<Palmares*>::iterator it = m_palmares.begin(); it != m_palmares.end(); ++it)
	{
		if (p_titre == (*it)->get_titre())
			liste_staff.push_back(*it);
	}
	return liste_staff;
}

std::vector<Palmares*> Club::get_palmares(std::string p_nom)
{
	std::vector<Palmares*> liste_staff;
	for (std::vector<Palmares*>::iterator it = m_palmares.begin(); it != m_palmares.end(); ++it)
	{
		if (p_nom == (*it)->get_nom())
			liste_staff.push_back(*it);
	}
	return liste_staff;
}

std::vector<Palmares*> Club::get_palmares(Date p_date)
{
	std::vector<Palmares*> liste_staff;
	for (std::vector<Palmares*>::iterator it = m_palmares.begin(); it != m_palmares.end(); ++it)
	{
		if (p_date == (*it)->get_date())
			liste_staff.push_back(*it);
	}
	return liste_staff;
}

std::vector<Palmares*> Club::get_palmares(int p_annee)
{
	std::vector<Palmares*> liste_staff;
	for (std::vector<Palmares*>::iterator it = m_palmares.begin(); it != m_palmares.end(); ++it)
	{
		if (p_annee == (*it)->get_annee())
			liste_staff.push_back(*it);
	}
	return liste_staff;
}

std::vector<Contrat*> Club::get_contrats(Joueur* p_joueur)
{
	std::vector<Contrat*> liste_contrat;
	for (std::vector<Contrat*>::iterator it = m_contrats.begin(); it != m_contrats.end(); ++it)
	{
		if (p_joueur == (*it)->get_joueur_contractant())
			liste_contrat.push_back(*it);
	}
	return liste_contrat;
}

std::vector<Contrat*> Club::get_contrats(Club* p_club_libere)
{
	std::vector<Contrat*> liste_contrat;
	for (std::vector<Contrat*>::iterator it = m_contrats.begin(); it != m_contrats.end(); ++it)
	{
		if (p_club_libere == (*it)->get_club_libere())
			liste_contrat.push_back(*it);
	}
	return liste_contrat;
}

/*SET*/

void Club::add_palmares(titre_t p_titre, std::string p_nom)
{
	Palmares* tmp_palmares = new Palmares(p_titre, p_nom);
	add_palmares(tmp_palmares);
}

void Club::add_palmares(titre_t p_titre, std::string p_nom, Date p_date)
{
	Palmares* tmp_palmares = new Palmares(p_titre, p_nom, p_date);
	add_palmares(tmp_palmares);
}

void Club::add_palmares(titre_t p_titre, std::string p_nom, int p_annee)
{
	Palmares* tmp_palmares = new Palmares(p_titre, p_nom, p_annee);
	add_palmares(tmp_palmares);
}

void Club::add_contrat(Contrat* p_contrat)
{
	p_contrat->set_club_contractant(this);
	m_contrats.push_back(p_contrat);
}

void Club::add_contrat(int p_duree, Joueur* p_joueur, Club* p_club_libere)
{
	if (p_joueur == nullptr)
		p_joueur = m_effectif.back();

	Contrat* tmp_contrat = new Contrat(p_joueur, this, p_duree, p_club_libere);
	m_contrats.push_back(tmp_contrat);
}

void Club::add_rupture(Rupture* p_rupture)
{ 
	p_rupture->set_club(this);
	m_ruptures.push_back(p_rupture); 
}

void Club::add_rupture(Joueur* p_joueur, Club* p_club, float p_penelite, string p_raison)
{
	(void)p_club;
	Rupture* tmp = new Rupture(p_joueur, this, p_penelite, p_raison);
	add_rupture(tmp);
}

/*remove*/

void Club::remove_palmares(unsigned int index)
{
	if(index < m_palmares.size())
		remove_palmares(m_palmares[index]);
}

void Club::remove_palmares(Palmares* p_palmares)
{
	for (std::vector<Palmares*>::iterator it = m_palmares.begin(); it != m_palmares.end(); ++it)
	{
		if ((*p_palmares) == (*(*it)))
		{
			Palmares* tmp_palmares = *it;
			m_palmares.erase(it);
			delete tmp_palmares;
			break;
		}
	}
}

void Club::remove_palmares(titre_t p_titre, std::string p_nom)
{
	Palmares* tmp_palmares = new Palmares(p_titre, p_nom);
	remove_palmares(tmp_palmares);
	delete tmp_palmares;
}

void Club::remove_palmares(titre_t p_titre, std::string p_nom, Date p_date)
{
	Palmares* tmp_palmares = new Palmares(p_titre, p_nom, p_date);
	remove_palmares(tmp_palmares);
	delete tmp_palmares;
}

void Club::remove_palmares(titre_t p_titre, std::string p_nom, int p_annee)
{
	Palmares* tmp_palmares = new Palmares(p_titre, p_nom, p_annee);
	remove_palmares(tmp_palmares);
	delete tmp_palmares;
}

/*
*	STATIC
*/
std::vector<Club*> Club::get_list_without(std::vector<Club*>& p_list, Club* p_club)
{
	std::vector<Club*> tmp_list;
	for (std::vector<Club*>::iterator it = p_list.begin(); it != p_list.end(); ++it)
	{
		if ((*(*it)) != (*p_club))
			tmp_list.push_back(*it);
	}
	return tmp_list;
}

int Club::effectuer_transfert(Joueur* p_joueur, Club* p_club_init, Club* p_club_destination, Contrat* p_contrat)
{
	if ((!p_joueur->est_autonome()) && (p_joueur->peut_rompre_contrat()))
	{
		if(p_club_init != nullptr)
			p_club_init->remove_joueur(p_joueur, false);
		p_club_destination->add_joueur(p_joueur);
		p_contrat->set_joueur_contractant(p_joueur);
		p_contrat->set_club_libere(p_club_init);
		p_club_destination->add_contrat(p_contrat);

		Joueur_non_auto* tmp = (Joueur_non_auto*)p_joueur;
		tmp->set_nb_annee_totale(p_contrat->get_duree_contrat());
		tmp->set_nb_annee_cumules(0);
		return 0;
	}
	else
		return -1;
}

int Club::effectuer_transfert(Joueur* p_joueur, Club* p_club_init, Club* p_club_destination, Contrat* p_contrat, Rupture* p_rupture)
{
	if (p_joueur->est_autonome())
	{
		if (p_club_init != nullptr)
		{
			if(p_rupture != nullptr)
				p_club_init->add_rupture(p_joueur, p_club_init, p_rupture->get_penelite(), p_rupture->get_raison());
			p_club_init->remove_joueur(p_joueur, false);
		}
		p_club_destination->add_joueur(p_joueur);
		p_club_destination->add_contrat(p_contrat);
		return 0;
	}
	else
		return -1;
}

Club* Club::get_club_plus_titre(std::vector<Club*>& p_clubs)
{
	Club* club_titre = nullptr;
	if (p_clubs.size())
	{
		for (std::vector<Club*>::iterator it = p_clubs.begin(); it != p_clubs.end(); ++it)
		{
			if (club_titre == nullptr)
				club_titre = *it;
			else if ((*club_titre) < (*(*it)))
				club_titre = *it;
		}
	}
	return club_titre;
}

Entraineur* Club::get_entraineur_titre(std::vector<Club*>& p_club)
{
	Entraineur* enraineur_titre = nullptr;

	if (p_club.size())
	{
		for (std::vector<Club*>::iterator it = p_club.begin(); it != p_club.end(); ++it)
		{
			Entraineur* tmp_entraineur = (*it)->get_entraineur();
			if (tmp_entraineur != nullptr)
			{
				if (enraineur_titre == nullptr)
					enraineur_titre = tmp_entraineur;
				else if (tmp_entraineur > enraineur_titre)
					enraineur_titre = tmp_entraineur;
			}
		}
	}
	return enraineur_titre;
}

/*
* Operateurs
*/

bool Club::operator==(Club const& b) const
{
	return estEgal(b);
}

bool Club::operator!=(Club const& b) const
{
	return !(estEgal(b));
}

bool Club::operator<(Club const& b) const
{
	return est_inf(b);
}

bool Club::operator>(Club const& b) const
{
	return est_sup(b);
}

bool Club::operator<=(Club const& b) const
{
	return !est_sup(b);
}

bool Club::operator>=(Club const& b) const
{
	return !est_inf(b);
}

/*
*private functions
*/

bool Club::estEgal(Club const& b) const
{
	if ((m_nom == b.get_nom()) && (m_couleur == b.get_couleur()) && (m_ville == b.get_ville()) &&
		(m_adresse == b.get_adresse()) && (m_histoire == b.get_histoire()) && (m_date_creation == b.get_date()))
		return true;
	else
		return false;
}

bool Club::est_sup(Club const& b) const
{
	if (m_palmares.size() > b.get_nb_palmares())
		return true;
	else
		return false;
}

bool Club::est_inf(Club const& b) const
{
	if (m_palmares.size() < b.get_nb_palmares())
		return true;
	else
		return false;
}
