#pragma once

#ifndef STADE_H
#define STADE_H

#include <cstdlib>
#include <string>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

enum qualite_terrain_t
{
	gazon,
	tartan,
	inconnu
};

class Stade
{
public:
	Stade(std::string p_nom, std::string p_adresse);
	Stade(std::string p_nom = "", int p_capacite = -1, std::string p_adresse  ="", qualite_terrain_t p_qualite_terrain = inconnu);
	~Stade();

	int get_capacite() const { return m_capacite; };
	qualite_terrain_t get_qualite_terrain() const { return m_qualite_terrain; };
	std::string get_nom_stade() const { return m_nom; };
	std::string get_adresse() const { return m_adresse; };

	void set_capacite(int p_capacite) { m_capacite = p_capacite; };
	void set_qualite_terrain(qualite_terrain_t p_qualite) { m_qualite_terrain = p_qualite; };
	void set_nom_stade(std::string p_nom) { m_nom = p_nom; };
	void set_adresse(std::string p_adresse) { m_adresse = p_adresse; };

	bool operator==(Stade const& b);
	bool operator!=(Stade const& b);

private:
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive & ar, const unsigned int version) {
	    (void)version;
		ar & m_capacite;
		ar & m_qualite_terrain;
		ar & m_nom;
		ar & m_adresse;
	}
	int m_capacite;
	qualite_terrain_t m_qualite_terrain;
	std::string m_nom;
	std::string m_adresse;

	bool estEgal(Stade b) const;
};

#endif
