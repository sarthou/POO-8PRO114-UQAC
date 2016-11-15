#pragma once

#include <string>
#include "../Utility/Date.h"
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

#ifndef REGLEMENT_H
#define REGLEMENT_H

using std::string;

class Reglement
{
public:
	Reglement(int p_seuil_en_vigueur = -1, string p_description_droits = "");
	Reglement(float p_montant_transfert, float p_montant_encaisse, int p_seuil_en_vigueur = -1, string p_description_droits = "");
	~Reglement();

	void set_seuil_en_vigueur(int p_seuil_en_vigueur) { m_seuil_en_vigueur = p_seuil_en_vigueur; };
	void set_description_droit(string p_description_droits) { m_description_droits = p_description_droits; };
	void set_montants(float p_montant_transfert, float p_montant_encaisse = -1);

	int get_seuil_en_vigueur() { return m_seuil_en_vigueur; };
	string get_description_droit() { return m_description_droits; };
	float get_montant_transfert() { return m_montant_transfert; };
	float get_montant_encaisse() { return m_montant_encaisse; };
	float get_montant_restant() { return m_montant_restant; };

private:
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive & ar, const unsigned int version) {
		ar & m_seuil_en_vigueur;
		ar & m_description_droits;
		ar & m_montant_transfert;
		ar & m_montant_encaisse;
		ar & m_montant_restant;
	}
	int m_seuil_en_vigueur;
	string m_description_droits;
	float m_montant_transfert;
	float m_montant_encaisse;
	float m_montant_restant;
};

#endif
