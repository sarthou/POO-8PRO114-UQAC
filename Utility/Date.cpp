#include "Date.h"

Date::Date()
{
	set_at_current_time(&m_date);
	m_annee = m_date.tm_year;
	m_mois = m_date.tm_mon;
	m_jour = m_date.tm_mday;
}

Date::Date(struct tm p_date)
{
	m_date = p_date;
	m_annee = m_date.tm_year;
	m_mois = m_date.tm_mon;
	m_jour = m_date.tm_mday;
}

Date::Date(int p_annee)
{
	set_at_current_time(&m_date);
	set_date(p_annee);
	m_annee = m_date.tm_year;
	m_mois = m_date.tm_mon;
	m_jour = m_date.tm_mday;
}

Date::Date(int p_annee, int p_mois)
{
	set_at_current_time(&m_date);
	set_date(p_annee, p_mois);
	m_annee = m_date.tm_year;
	m_mois = m_date.tm_mon;
	m_jour = m_date.tm_mday;
}

Date::Date(int p_annee, int p_mois, int p_jour)
{
	set_at_current_time(&m_date);
	set_date(p_annee, p_mois, p_jour);
	m_annee = m_date.tm_year;
	m_mois = m_date.tm_mon;
	m_jour = m_date.tm_mday;
}

Date::~Date()
{

}

struct tm Date::get_date()
{ 
	m_date.tm_year = m_annee;
	m_date.tm_mon = m_mois;
	m_date.tm_mday = m_jour;
	return m_date; 
}

void Date::set_date(struct tm p_date)
{ 
	m_date = p_date; 
	m_annee = m_date.tm_year;
	m_mois = m_date.tm_mon;
	m_jour = m_date.tm_mday;
};

void Date::set_date(int p_annee)
{
	m_date.tm_year = p_annee;
	m_annee = m_date.tm_year;
}

void Date::set_date(int p_annee, int p_mois)
{
	m_date.tm_year = p_annee;
	m_annee = m_date.tm_year;
	m_date.tm_mon = p_mois;
	m_mois = m_date.tm_mon;
}

void Date::set_date(int p_annee, int p_mois, int p_jour)
{
	m_date.tm_year = p_annee;
	m_annee = m_date.tm_year;
	m_date.tm_mon = p_mois;
	m_mois = m_date.tm_mon;
	m_date.tm_mday = p_jour;
	m_jour = m_date.tm_mday;
}

bool Date::operator==(Date const& b) const
{
	return estEgal(b);
}

bool Date::operator!=(Date const& b) const
{
	return !(estEgal(b));
}

bool Date::operator>(Date const& b) const
{
	return estSup(b);
}

bool Date::operator<(Date const& b) const
{
	return estInf(b);
}

bool Date::operator>=(Date const& b) const
{
	return (!estInf(b));
}

bool Date::operator<=(Date const& b) const
{
	return (!estSup(b));
}

/*
*
* Private functions
*
*/

struct tm Date::get_current_time()
{
	time_t date;
	struct tm * tmp_time = nullptr;
	time(&date);
	localtime_s(tmp_time, &date);

	return *tmp_time;
}

void Date::set_at_current_time(struct tm* p_date)
{
	time_t date;
	time(&date);
	localtime_s(p_date, &date);
}

bool Date::estEgal(Date b) const
{
	if ((m_annee == b.get_annee()) && (m_mois == b.get_mois()) && (m_jour == b.get_jour()))
		return true;
	else
		return false;
}

bool Date::estSup(Date b) const
{
	if ((m_annee > b.get_annee()) && (m_mois > b.get_mois()) && (m_jour > b.get_jour()))
		return true;
	else
		return false;
}

bool Date::estInf(Date b) const
{
	if ((m_annee < b.get_annee()) && (m_mois < b.get_mois()) && (m_jour < b.get_jour()))
		return true;
	else
		return false;
}