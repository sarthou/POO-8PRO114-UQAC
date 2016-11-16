#pragma once

#ifndef MATCH_H
#define MATCH_H

#include "..\Equipe.h"
#include "Periode.h"
#include <vector>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

class Club;
class Joueur;

typedef struct
{
	int nb_but_local;
	int nb_but_adverse;
private:
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive &ar, const unsigned int version)
	{
	    (void)version;
		ar & nb_but_local;
		ar & nb_but_adverse;
	}
}Resultat;

class Match
{
public:
	Match(Club* p_club_local = nullptr, Club* p_club_adverse = nullptr);
	~Match();

	void set_equipe_locale(Equipe p_equipe) { m_equipe_locale = p_equipe; };
	void set_equipe_adverse(Equipe p_equipe) { m_equipe_adverse = p_equipe; };
	void set_equipe_locale(Joueur* p_capitaine, int p_nb_gardiens = 1, int p_nb_joueurs_terrain = -1);
	void set_equipe_adverse(Joueur* p_capitaine, int p_nb_gardiens = 1, int p_nb_joueurs_terrain = -1);
	void add_new_periode(int p_duree, int p_but_local, int p_but_adverse);
	void add_new_periode(Periode p_periode);
	void add_but_local(int nb_but = 1);
	void add_but_adverse(int nb_but = 1);
	void set_clubs(Club* p_club_local, Club* p_club_adverse);

	Equipe get_equipe_locale() const { return m_equipe_locale; };
	Equipe get_equipe_adverse() const { return m_equipe_adverse; };
	Club get_club_local() { return *(m_equipe_locale.get_club_ref()); };
	Club get_club_adverse() { return *(m_equipe_adverse.get_club_ref()); };
	Resultat get_resultat() const { return m_resultat; };
	int get_nb_but_local() const { return m_resultat.nb_but_local; };
	int get_nb_but_adverse() const { return m_resultat.nb_but_adverse; };
	std::vector<Periode> get_periodes() const { return m_periodes; };
	Periode get_periode(int index) const { return m_periodes[index]; };
	int get_nb_periode() const { return m_periodes.size(); };

private:
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive & ar, const unsigned int version) {
		(void)version;
		ar & m_resultat;
		ar & m_equipe_locale;
		ar & m_equipe_adverse;
		ar & m_periodes;
	}
	Resultat m_resultat;
	Equipe m_equipe_locale;
	Equipe m_equipe_adverse;
	std::vector<Periode> m_periodes;
};

#endif
