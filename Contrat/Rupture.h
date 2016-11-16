#pragma once

#ifndef RUPTURE_H
#define RUPTURE_H

#include "..\Personnages\Joueur.h"
#include <string>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

using std::string;

class Club;

class Rupture
{
public:
	Rupture(Joueur* p_joueur = nullptr, Club* p_club = nullptr, float p_penelite = 0, string p_raison = "");
	~Rupture() {};

	Joueur* get_joueur() { return m_joueur; };
	Club* get_club() { return m_club; };
	float get_penelite() { return m_penelite; };
	string get_raison() { return m_raison; };

	void set_raison(string p_raison) { m_raison = p_raison; };
	void set_club(Club* p_club) { m_club = p_club; };
	void set_joueur(Joueur* p_joueur) { m_joueur = p_joueur; };

private:
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive & ar, const unsigned int version) {
	    (void)version;
		ar & m_joueur;
		ar & m_club;
		ar & m_penelite;
		ar & m_raison;
	}
	Joueur* m_joueur;
	Club* m_club;
	float m_penelite;
	string m_raison;
};
#endif