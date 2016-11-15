#pragma once

#ifndef RENCONTRE_H
#define RENCONTRE_H

#include "..\Utility\Date.h"
#include "Match.h"
#include "..\Personnages\Arbitre.h"
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

class Club;

class Rencontre
{
public:
	Rencontre();
	Rencontre(Club* p_club_local, Club* p_club_adverse, struct tm p_date, Arbitre* p_arbitre = nullptr);
	~Rencontre();

	void set_date_rencontre(struct tm p_date) { m_date.set_date(p_date); };
	void set_date_rencontre(int p_annee) { m_date.set_date(p_annee); };
	void set_club_local(Club* p_club) { m_club_local = p_club; };
	void set_club_adverse(Club* p_club) { m_club_adverse = p_club; };
	void set_match(Match* p_match);
	void set_arbitre(Arbitre* p_arbitre) { m_arbitre = p_arbitre; };

	Match* get_match() const { return m_match; };
	Date get_date() const { return m_date; };
	Club get_club_local() const { return *m_club_local; };
	Club get_club_adverse() const { return *m_club_adverse; };
	Club* edit_club_local() { return m_club_local; };
	Club* edit_club_adverse() { return m_club_adverse; };
	Arbitre get_arbitre() const { return *m_arbitre; };

	static Rencontre* get_prochaine_rencontre(std::vector<Rencontre*> p_rencontres);

private:
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive & ar, const unsigned int version) {
		ar & m_date;
		ar & m_club_local;
		ar & m_club_adverse;
		ar & m_match;
		ar & m_arbitre;
	}
	Date m_date;
	Club* m_club_local;
	Club* m_club_adverse;
	Match* m_match;
	Arbitre* m_arbitre;
};


#endif
