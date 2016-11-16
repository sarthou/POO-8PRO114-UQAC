#pragma once

#include <cstdlib>
#include <ctime>

#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

#ifndef DATE_H
#define DATE_H

class Date
{
public:
	Date();
	Date(struct tm p_date);
	Date(int p_annee);
	Date(int p_annee, int p_mois);
	Date(int p_annee, int p_mois, int p_jour);
	~Date();

	struct tm get_date();
	int get_annee() const { return m_annee; };
	int get_mois() const  { return m_mois; };
	int get_jour() const { return m_jour; };

	void set_date(struct tm p_date);
	void set_date(int p_annee);
	void set_date(int p_annee, int p_mois);
	void set_date(int p_annee, int p_mois, int p_jour);

	bool operator==(Date const& b) const;
	bool operator!=(Date const& b) const;
	bool operator>(Date const& b) const;
	bool operator<(Date const& b) const;
	bool operator>=(Date const& b) const;
	bool operator<=(Date const& b) const;
	
private:
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive & ar, const unsigned int version) {
	    (void)version;
		ar & m_annee;
		ar & m_mois;
		ar & m_jour;
	}
	struct tm m_date;
	int m_annee;
	int m_mois;
	int m_jour;

	struct tm get_current_time();
	void set_at_current_time(struct tm* p_date);
	bool estEgal(Date b) const;
	bool estSup(Date b) const;
	bool estInf(Date b) const;
};

#endif
