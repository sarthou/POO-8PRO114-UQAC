#include <cstdio>
#include <cstdlib>
#include <iostream>

#include "Ecrans\Ecran.h"
#include "Ligue_hokey.h"

#include "Personnages\Joueur.h"
#include "Personnages\Joueur_non_auto.h"

int main()
{
	Ligue_hokey ligue;
	
	ligue.run();

	system("PAUSE");

	return 0;
}