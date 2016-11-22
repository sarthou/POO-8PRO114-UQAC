#pragma once

#ifndef SIMU_NEGO
#define SIMU_NEGO

#include "Nego_vendeur.h"
#include "Nego_acheteur.h"
#include "..\Utility\Mutex.h"
#include "../Ecrans/saisie.h"

class Simu_negociation
{
public:
	Simu_negociation();
	~Simu_negociation();

	bool simuler(Club* p_vendeur, Club* p_acheteur);

	int get_montant_final() { return montant_final; };

private:
	Mutex mutex;
	Nego_acheteur* m_acheteur;
	Nego_vendeur* m_vendeur;

	int m_nb_thread;
	HANDLE* m_threads;
	DWORD* m_id_thread_vendeur;
	DWORD* m_id_thread_acheteur;

	int montant_final;
};

#endif
