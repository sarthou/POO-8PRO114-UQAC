#pragma once

#ifndef MESSAGE_H
#define MESSAGE_H

class Negociateur;

enum sujet_t
{
	offre,
	acceptation,
	rejet,
	erreur
};

class Message
{
public:
	Message(Negociateur* p_emetteur = nullptr, sujet_t p_sujet = erreur, int p_montant = -1);
	~Message();

	Negociateur* get_emetteur() { return m_emetteur; };
	int get_montant() { return m_montant; };
	sujet_t get_sujet() { return m_sujet; };

	void set_emetteur(Negociateur* p_emetteur) { m_emetteur = p_emetteur; };
	void set_montant(int p_montant) { m_montant = p_montant; };
	void set_sujet(sujet_t p_sujet) { m_sujet = p_sujet; };

private:
	Negociateur* m_emetteur;
	int m_montant;
	sujet_t m_sujet;
};

#endif
