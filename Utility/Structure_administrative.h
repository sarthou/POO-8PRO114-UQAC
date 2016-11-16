#pragma once

#ifndef STRUCTURE_ADMIN_H
#define STRUCTURE_ADMIN_H

#include "Date.h"
#include <string>
using std::string;

#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

class Structure_administrative
{
public:
	Structure_administrative(string p_nom = "", string p_histoire = "", string p_ville = "", string p_adresse = "");
	Structure_administrative(string p_nom, string p_histoire, string p_ville, string p_adresse, Date p_date);
	~Structure_administrative();

	string get_nom() const { return m_nom; };
	string get_histoire() const { return m_histoire; };
	string get_ville() const { return m_ville; };
	string get_adresse() const { return m_adresse; };
	Date get_date() const { return m_date_creation; };
	int get_annee() const { return m_date_creation.get_annee(); };

	void set_nom(string p_nom) { m_nom = p_nom; };
	void set_histoire(string p_histoire) { m_histoire = p_histoire; };
	void set_ville(string p_ville) { m_ville = p_ville; };
	void set_adresse(string p_adresse) { m_adresse = p_adresse; };
	void set_date(Date p_date) { m_date_creation = p_date; };
	void set_date(int p_annee) { m_date_creation.set_date(p_annee); };

private:
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive & ar, const unsigned int version) {
		ar & m_histoire;
		ar & m_nom;
		ar & m_ville;
		ar & m_adresse;
		ar & m_date_creation;
	}
protected:
	string m_histoire;
	string m_nom;
	string m_ville;
	string m_adresse;

	Date m_date_creation;
};

#endif
