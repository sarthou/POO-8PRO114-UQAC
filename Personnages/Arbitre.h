#pragma once

#ifndef ARBITRE_H
#define ARBITRE_H

#include "Joueur.h"
#include <string>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

using std::string;

class Arbitre : public Joueur
{
public:
	Arbitre(std::string p_nom = "", string p_lieu_obtention = "", int p_expérience = 0);
	Arbitre(std::string p_nom, string p_lieu_obtention, int p_expérience, uint8_t p_age, std::string p_ville = "");
	Arbitre(std::string p_nom, std::string p_prenom = "", string p_lieu_obtention = "", int p_expérience = 0, uint8_t p_age = 0, std::string p_ville = "", float p_taille = 0., float p_poids = 0.);
	~Arbitre();

	void set_lieu_experience(string p_lieu_obtention) { m_lieu_obtention = p_lieu_obtention; };
	void set_experience(int p_experience) { m_expérience = p_experience; };

	string get_lieu_obtention() { return m_lieu_obtention; };
	int get_experience() { return m_expérience; };

private:
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive & ar, const unsigned int version) {
		ar & boost::serialization::base_object<Joueur>(*this);
		ar & m_lieu_obtention;
		ar & m_expérience;
	}
	string m_lieu_obtention;
	int m_expérience;
};

#endif
