#include "Date.h"

Date::Date()
{
	set_at_current_time(&m_date);
}

Date::Date(struct tm p_date)
{
	m_date = p_date;
}

Date::Date(int p_annee)
{
	set_at_current_time(&m_date);
	set_date(p_annee);
}

Date::Date(int p_annee, int p_mois)
{
	set_at_current_time(&m_date);
	set_date(p_annee, p_mois);
}

Date::Date(int p_annee, int p_mois, int p_jour)
{
	set_at_current_time(&m_date);
	set_date(p_annee, p_mois, p_jour);
}

Date::~Date()
{

}

void Date::set_date(int p_annee)
{
	m_date.tm_year = p_annee;
}

void Date::set_date(int p_annee, int p_mois)
{
	m_date.tm_year = p_annee;
	m_date.tm_mon = p_mois;
}

void Date::set_date(int p_annee, int p_mois, int p_jour)
{
	m_date.tm_year = p_annee;
	m_date.tm_mon = p_mois;
	m_date.tm_mday = p_jour;
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
	if ((m_date.tm_year == b.get_annee()) && (m_date.tm_mon == b.get_mois()) && (m_date.tm_mday == b.get_jour()))
		return true;
	else
		return false;
}

bool Date::estSup(Date b) const
{
	if ((m_date.tm_year > b.get_annee()) && (m_date.tm_mon > b.get_mois()) && (m_date.tm_mday > b.get_jour()))
		return true;
	else
		return false;
}

bool Date::estInf(Date b) const
{
	if ((m_date.tm_year < b.get_annee()) && (m_date.tm_mon < b.get_mois()) && (m_date.tm_mday < b.get_jour()))
		return true;
	else
		return false;
}