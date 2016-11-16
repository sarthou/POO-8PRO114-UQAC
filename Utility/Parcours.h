#pragma once

#ifndef PARCOURS_H
#define PARCOURS_H

#include "Date.h"
#include <string>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

class Parcours
{
public:
	Parcours();
	Parcours(std::string p_nom_club);
	Parcours(std::string p_nom_club, Date p_date);
	Parcours(std::string p_nom_club, int p_annee);
	Parcours(std::string p_nom_club, int p_annee, int p_mois);
	Parcours(std::string p_nom_club, int p_annee, int p_mois, int p_jour);
	~Parcours();

	Date get_date_passage() const { return m_date_passage; };
	int get_annee_passage() const { return m_date_passage.get_annee(); };
	std::string get_nom_club() const  { return m_nom_club; };

	void set_date_passage(struct tm p_date) { m_date_passage = p_date; };
	void set_date_passage(int p_annee);
	void set_date_passage(int p_annee, int p_mois);
	void set_date_passage(int p_annee, int p_mois, int p_jour);
	void set_nom_club(std::string p_nom) { m_nom_club = p_nom; };

	bool operator==(Parcours const& b) const;
	bool operator!=(Parcours const& b) const;

private:
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive & ar, const unsigned int version) {
	    (void)version;
		ar & m_date_passage;
		ar & m_nom_club;
	}
	Date m_date_passage;
	std::string m_nom_club;

	bool estEgal(Parcours b) const;
};

#endif
