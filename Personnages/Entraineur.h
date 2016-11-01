#pragma once

#ifndef ENTRAINEUR_H
#define ENTRAINEUR_H

#include <cstdlib>
#include <string>
#include <vector>
#include "Staff.h"
#include "../Utility/Titre.h"
#include "../Utility/Date.h"

class Entraineur : public Staff
{
public:
	Entraineur();
	Entraineur(std::string p_nom, std::string p_lieu_obtention_grade);
	Entraineur(std::string p_nom, std::string p_prenom, std::string p_lieu_obtention_grade);
	Entraineur(std::string p_nom, std::string p_prenom, uint8_t p_age, std::string p_lieu_obtention_grade);
	Entraineur(std::string p_nom, std::string p_prenom, uint8_t p_age, std::string p_ville, std::string p_lieu_obtention_grade);
	Entraineur(const Entraineur& p_entraineur);
	~Entraineur();

	void set_lieu_obtention(std::string p_lieu_obtention) { m_lieu_obtention_grade = p_lieu_obtention; };
	std::string get_lieu_obtention() const { return m_lieu_obtention_grade; };
	unsigned int get_nb_titres() const { return m_titres.size(); };

	std::vector<Titre*> get_titre() { return m_titres; };
	std::vector<Titre*> get_titre(Date p_date);
	std::vector<Titre*> get_titre(int annee);
	std::vector<Titre*> get_titre(titre_t p_titre);

	void ajout_titre(Titre* p_titre);
	void ajout_titre(titre_t p_titre, Club* p_club);
	void ajout_titre(titre_t p_titre, std::string p_nom, Club* p_club);
	void ajout_titre(titre_t p_titre, std::string p_nom, Date p_date, Club* p_club);
	void ajout_titre(titre_t p_titre, std::string p_nom, int p_annee, Club* p_club);

	void remove_titre(int index);
	void remove_titre(Titre* p_titre);

	bool operator<(Entraineur const& b);
	bool operator>(Entraineur const& b);
	bool operator<=(Entraineur const& b);
	bool operator>=(Entraineur const& b);

private:
	std::string m_lieu_obtention_grade;
	std::vector<Titre*> m_titres;

	bool est_sup(Entraineur b) const;
	bool est_inf(Entraineur b) const;
};

#endif
