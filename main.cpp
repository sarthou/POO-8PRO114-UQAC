#include <cstdio>
#include <cstdlib>
#include <iostream>

#include "Ecrans\Ecran.h"
#include "Ligue_hokey.h"

#include <fstream>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/throw_exception.hpp>
#include "Utility\export.h"

#define BOOST_ALL_NO_LIB

int main()
{
	Ligue_hokey ligue;

	std::ifstream ifs("fichierDeSerialisation.txt");
	try
	{
		boost::archive::text_iarchive ia(ifs);
		ia >> ligue;
	}
	catch (boost::archive::archive_exception e)
	{
		std::cerr << "Erreur lors de l'ouverture du fichier de serialisation ou lors de la deserialization\n";
		std::cerr << "Une application vide est donc chargee\n";
		system("PAUSE");
	}
	
	ligue.run();

	std::ofstream ofs("fichierDeSerialisation.txt");
	try
	{
		boost::archive::text_oarchive oa(ofs);
		oa << ligue;
	}
	catch (boost::archive::archive_exception e)
	{
		std::cerr << "Erreur lors de la création du fichier de serialisation ou lors de la serialization\n";
		std::cerr << "Une application vide est donc chargee à la prochaine execution\n";
	}

	system("PAUSE");

	return 0;
}