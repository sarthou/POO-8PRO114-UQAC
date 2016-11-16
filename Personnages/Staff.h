#pragma once

#ifndef STAFF_H
#define STAFF_H

#include <cstdlib>
#include <string>
#include "Personne.h"
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/base_object.hpp>

enum role_t
{
	president, 
	entraineur, 
	secretaire, 
	recruteur, 
	infirmier,
	autre
};

class Staff : public Personne
{
public:
	Staff(std::string p_nom, uint8_t p_age, std::string p_ville = "");
	Staff(role_t p_role);
	Staff(std::string p_nom, role_t p_role);
	Staff(std::string p_nom, std::string p_prenom, role_t p_role);
	Staff(std::string p_nom, std::string p_prenom, uint8_t p_age, role_t p_role);
	Staff(std::string p_nom = "", std::string p_prenom = "", uint8_t p_age = -1, std::string p_ville = "", role_t p_role = autre);
	~Staff();

	role_t get_role() const { return m_role; };
	void set_role(role_t p_role) { m_role = p_role; };

	bool operator==(Staff const& b);
	bool operator!=(Staff const& b);

private:
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive & ar, const unsigned int version) {
	    (void)version;
		ar & boost::serialization::base_object<Personne>(*this);
		ar & m_role;
	}
	role_t m_role;

	bool estEgal(Staff b) const;
};

#endif
