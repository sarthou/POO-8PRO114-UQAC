#include "Message.h"

Message::Message(Negociateur* p_emetteur, sujet_t p_sujet, int p_montant)
{
	m_emetteur = p_emetteur;
	m_montant = p_montant;
	m_sujet = p_sujet;
}

Message::~Message()
{

}