#pragma once

#ifndef CLUB_H
#define CLUB_H

#include <cstdlib>
#include <string>
#include <vector>
#include "infrastructure\Stade.h"
#include "Utility\Palmares.h"
#include "Contrat\Contrat.h"
#include "Contrat\Rupture.h"
#include "Utility\Structure_administrative.h"
#include "Personnages\Regroupement_sportif.h"

#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

using std::string;

class Club : public Structure_administrative, public Regroupement_sportif
{
public:
	Club();
	Club(string p_nom, string p_couleur = "");
	Club(string p_nom, string p_couleur, Date p_date_creation);
	Club(string p_nom, string p_couleur, Date p_date_creation, Stade p_stade, string p_ville = "", string p_adresse = "", string p_histoire = "");
	Club(const Club& p_club);
	~Club();

	string get_couleur() const { return m_couleur; };
	Stade get_stade() const { return m_stade; };
	std::vector<Palmares*> get_palmares() { return m_palmares; };
	std::vector<Palmares*> get_palmares(titre_t p_titre);
	std::vector<Palmares*> get_palmares(string p_nom);
	std::vector<Palmares*> get_palmares(Date p_date);
	std::vector<Palmares*> get_palmares(int p_annee);
	unsigned int get_nb_palmares() const { return m_palmares.size(); };
	std::vector<Contrat*> get_contrats() { return m_contrats; };
	std::vector<Contrat*> get_contrats(Joueur* p_joueur);
	std::vector<Contrat*> get_contrats(Club* p_club_libere);
	Contrat* get_contrat_index(int p_index) { return m_contrats[p_index]; };

	void set_couleur(string p_couleur) { m_couleur = p_couleur; };
	void set_stade(Stade p_stade) { m_stade = p_stade; };

	void add_palmares(Palmares* p_palmares) { m_palmares.push_back(p_palmares); };
	void add_palmares(titre_t p_titre, string p_nom = "");
	void add_palmares(titre_t p_titre, string p_nom, Date p_date);
	void add_palmares(titre_t p_titre, string p_nom, int p_annee);
	void add_contrat(Contrat* p_contrat);
	void add_contrat(int p_duree, Joueur* p_joueur = nullptr, Club* p_club_libere = nullptr);
	void add_rupture(Rupture* p_rupture);
	void add_rupture(Joueur* p_joueur, Club* p_club, float p_penelite, string p_raison = "");

	void remove_palmares(unsigned int index);
	void remove_palmares(Palmares* p_palmares);
	void remove_palmares(titre_t p_titre, string p_nom = "");
	void remove_palmares(titre_t p_titre, string p_nom, Date p_date);
	void remove_palmares(titre_t p_titre, string p_nom, int p_annee);

	static std::vector<Club*> get_list_without(std::vector<Club*>& p_list, Club* p_club);
	static int effectuer_transfert(Joueur* p_joueur, Club* p_club_init, Club* p_club_destination, Contrat* p_contrat); //non auto
	static int effectuer_transfert(Joueur* p_joueur, Club* p_club_init, Club* p_club_destination, Contrat* p_contrat, Rupture* p_rupture); //auto
	static Club* get_club_plus_titre(std::vector<Club*>& p_clubs);
	static Entraineur* get_entraineur_titre(std::vector<Club*>& p_clubs);

	bool operator==(Club const& b) const;
	bool operator!=(Club const& b) const;
	bool operator<(Club const& b) const;
	bool operator>(Club const& b) const;
	bool operator<=(Club const& b) const;
	bool operator>=(Club const& b) const;

private:
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive & ar, const unsigned int version) {
	    (void)version;
		ar & boost::serialization::base_object<Structure_administrative>(*this);
		ar & boost::serialization::base_object<Regroupement_sportif>(*this);
		ar & m_couleur;
		ar & m_stade;
		ar & m_palmares;
		ar & m_contrats;
		ar & m_ruptures;
	}

	string m_couleur;
	Stade m_stade;

	std::vector<Palmares*> m_palmares;
	std::vector<Contrat*> m_contrats;
	std::vector<Rupture*> m_ruptures;

	bool estEgal(Club const& b) const;
	bool est_sup(Club const& b) const;
	bool est_inf(Club const& b) const;
};

#endif
