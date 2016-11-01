#pragma once

#include <cstdlib>
#include <string>

#ifndef PERSONNE_H
#define PERSONNE_H

class Personne
{
public:
	Personne();
	Personne(std::string p_nom, uint8_t p_age, std::string p_ville = "");
	Personne(std::string p_nom, std::string p_prenom = "", uint8_t p_age = 0, std::string p_ville = "");
	~Personne();

	std::string get_nom() const { return m_nom; };
	std::string get_prenom() const { return m_prenom; };
	std::string get_nom_complet() const { return (m_nom + " : " + m_prenom); };
	std::string get_ville_naissance() const { return m_ville_naissance; };
	uint8_t get_age() const { return m_age; };

	void set_nom(std::string p_nom) { m_nom = p_nom; };
	void set_prenom(std::string p_prenom) { m_prenom = p_prenom; };
	void set_age(uint8_t p_age) { m_age = p_age; };
	void set_ville_naissance(std::string p_ville) { m_ville_naissance = p_ville; };

protected:
	std::string m_nom;
	std::string m_prenom;
	uint8_t m_age;
	std::string m_ville_naissance;

};

#endif
