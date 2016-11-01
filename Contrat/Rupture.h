#pragma once

#ifndef RUPTURE_H
#define RUPTURE_H

#include "..\Personnages\Joueur.h"
#include <string>
using std::string;

class Club;

class Rupture
{
public:
	Rupture(Joueur* p_joueur, Club* p_club, float p_penelite, string p_raison = "");
	~Rupture() {};

	Joueur* get_joueur() { return m_joueur; };
	Club* get_club() { return m_club; };
	float get_penelite() { return m_penelite; };
	string get_raison() { return m_raison; };

	void set_raison(string p_raison) { m_raison = p_raison; };
	void set_club(Club* p_club) { m_club = p_club; };
	void set_joueur(Joueur* p_joueur) { m_joueur = p_joueur; };

private:
	Joueur* m_joueur;
	Club* m_club;
	float m_penelite;
	string m_raison;
};
#endif