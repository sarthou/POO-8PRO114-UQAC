#pragma once

#ifndef PALMARES_H
#define PALMARES_H

#include <cstdlib>
#include <string>
#include "Date.h"

enum titre_t
{
	coupe,
	championnat,
	autre_titre
};

class Palmares
{
public:
	Palmares();
	Palmares(titre_t p_titre, std::string p_nom = "");
	Palmares(titre_t p_titre, std::string p_nom, Date p_date);
	Palmares(titre_t p_titre, std::string p_nom, int p_annee);
	~Palmares();

	void set_titre(titre_t p_titre) { m_titre = p_titre; };
	void set_nom(std::string p_nom) { m_nom = p_nom; };
	void set_date(Date p_date) { m_date = p_date; };
	void set_date(int p_annee) { m_date.set_date(p_annee); };
	void set_date(struct tm p_date) { m_date.set_date(p_date); };

	titre_t get_titre() const { return m_titre; };
	std::string get_nom() const { return m_nom; };
	Date get_date() const { return m_date; };
	int get_annee() const { return m_date.get_annee(); }

	bool operator==(Palmares const& b) const;
	bool operator!=(Palmares const& b) const;

private:
	titre_t m_titre;
	std::string m_nom;
	Date m_date;

	bool estEgal(Palmares b) const;
};

#endif
