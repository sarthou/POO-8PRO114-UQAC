#include <cstdio>
#include <cstdlib>
#include <iostream>

#include "Ecrans\Ecran.h"
#include "Ligue_hokey.h"

#include <fstream>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include "Utility\export.h"

#define BOOST_ALL_NO_LIB

int main()
{
	Ligue_hokey ligue;

	{
		std::ifstream ifs("fichierDeSerialisation.txt");
		if (ifs.is_open())
		{
			boost::archive::text_iarchive ia(ifs);
			ia >> ligue;
		}
	}
	
	ligue.run();

	system("PAUSE");

	std::ofstream ofs("fichierDeSerialisation.txt");
	boost::archive::text_oarchive oa(ofs);
	oa << ligue;

	return 0;
}