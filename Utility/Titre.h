#pragma once

#ifndef TITRE_H
#define TITRE_H

#include <cstdlib>
#include <string>
#include "Palmares.h"
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/base_object.hpp>

class Club;

class Titre : public Palmares
{
public:
	Titre();
	Titre(titre_t p_titre, Club* p_club);
	Titre(titre_t p_titre, std::string p_nom, Club* p_club);
	Titre(titre_t p_titre, std::string p_nom, Date p_date, Club* p_club);
	Titre(titre_t p_titre, std::string p_nom, int p_annee, Club* p_club);
	~Titre();

private:
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive & ar, const unsigned int version) {
	    (void)version;
		ar & boost::serialization::base_object<Palmares>(*this);
		ar & m_club;
	}
	Club* m_club;
};

#endif
