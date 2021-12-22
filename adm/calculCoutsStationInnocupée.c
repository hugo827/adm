#include "Header.h"



double calculCoutsStationInoccupee(Station* pDebutStation) {
	double couts = 0;
	int coutsParHeure = 18;

	Station* pStation = pDebutStation;
	while (pStation != NULL) {
		int temps = pStation->tempsInoccupee;
		couts += calculEnFonctionTemps(coutsParHeure, temps);

		pStation = pStation->pSuivStation;
	}

	return couts;
}