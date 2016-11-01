#pragma once

#ifndef TITRE_H
#define TITRE_H

#include <cstdlib>
#include <string>
#include "Palmares.h"

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
	Club* m_club;
};

#endif
