#include "Simu_negociation.h"

Simu_negociation::Simu_negociation()
{
	m_acheteur = nullptr;
	m_vendeur = nullptr;

	m_nb_thread = 2;

	m_threads = new HANDLE[m_nb_thread];

	m_id_thread_vendeur = new DWORD();
	m_id_thread_acheteur = new DWORD();

	montant_final = -1;
}

Simu_negociation::~Simu_negociation()
{
	delete m_threads;
	delete m_id_thread_vendeur;
	delete m_id_thread_acheteur;

	if (m_acheteur != nullptr)
		delete m_acheteur;

	if (m_vendeur != nullptr)
		delete m_vendeur;
}

DWORD WINAPI thread_vendeur(LPVOID p_vendeur)
{
	std::cout << "entree dans le thread: vente\n" << std::endl;
	((Nego_vendeur*)p_vendeur)->negocier();
	std::cout << "sortie du thread: vente \n" << std::endl;
	return 0;
}

DWORD WINAPI thread_acheteur(LPVOID p_acheteur)
{
	std::cout << "entree dans le thread: achat\n" << std::endl;
	((Nego_acheteur *)p_acheteur)->negocier();
	std::cout << "sortie du thread: achat\n" << std::endl;
	return 0;
}

bool Simu_negociation::simuler(Club* p_vendeur, Club* p_acheteur)
{
	m_acheteur = Saisie::saisir_nego_acheteur(p_acheteur);
	m_vendeur = Saisie::saisir_nego_vendeur(p_vendeur);
	m_acheteur->set_interlocuteur(m_vendeur);

	m_acheteur->set_mutex(&mutex);
	m_vendeur->set_mutex(&mutex);

	m_threads[0] = CreateThread(0, 0, thread_acheteur, m_acheteur, 0, m_id_thread_acheteur);
	m_threads[1] = CreateThread(0, 0, thread_vendeur, m_vendeur, 0, m_id_thread_vendeur);

	WaitForMultipleObjects(m_nb_thread, m_threads, true, INFINITE);

	bool concluant = false;
	if ((m_acheteur->get_sujet() == acceptation) && (m_vendeur->get_sujet() == acceptation) && (m_vendeur->get_montant() == m_acheteur->get_montant()))
	{
		concluant = true;
		montant_final = m_vendeur->get_montant();
	}
	else
		montant_final = -1;

	delete m_acheteur;
	m_acheteur = nullptr;
	delete m_vendeur;
	m_vendeur = nullptr;

	return concluant;
}