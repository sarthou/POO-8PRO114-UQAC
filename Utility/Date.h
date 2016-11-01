#pragma once

#include <cstdlib>
#include <ctime>

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

	struct tm get_date() const  { return m_date; };
	int get_annee() const { return m_date.tm_year; };
	int get_mois() const  { return m_date.tm_mon; };
	int get_jour() const { return m_date.tm_mday; };

	void set_date(struct tm p_date) { m_date = p_date; };
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
	struct tm m_date;

	struct tm get_current_time();
	void set_at_current_time(struct tm* p_date);
	bool estEgal(Date b) const;
	bool estSup(Date b) const;
	bool estInf(Date b) const;
};

#endif
