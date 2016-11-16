#pragma once

#ifndef EQUIPE_H
#define EQUIPE_H

#include "Club.h"
#include "Personnages\Joueur.h"
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

class Equipe
{
public:
	Equipe(Club* p_club_ref, Joueur* p_capitaine = nullptr, int p_nb_gardiens = 1);
	Equipe(Club* p_club_ref, int p_nb_joueurs_terrain, Joueur* p_capitaine = nullptr, int p_nb_gardiens = 1);
	~Equipe();

	Club* get_club_ref() { return m_club_ref; };
	Joueur* get_capitaine() { return m_capitaine; };
	int get_nb_gardiens() { return m_nb_gardiens; };
	int get_nb_joueur() { return m_nb_joueurs_terrain; };

	void set_club_ref(Club* p_club) { m_club_ref = p_club; };
	void set_capitaine(Joueur* p_capitaine) { m_capitaine = p_capitaine; };
	void set_nb_gardiens(int p_nb_gardiens = 1) { m_nb_gardiens = p_nb_gardiens; };
	void set_nb_joueurs(int p_nb_joueur = -1);

private:
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive & ar, const unsigned int version) {
	    (void)version;
		ar & m_club_ref;
		ar & m_capitaine;
		ar & m_nb_gardiens;
		ar & m_nb_joueurs_terrain;
	}
	Club* m_club_ref;
	Joueur* m_capitaine;
	int m_nb_gardiens;
	int m_nb_joueurs_terrain;
};

#endif
