#include "Header.h"



double calculCoutsStationInoccupée(Station* pDebutStation) {
	int couts = 0, coutsParHeure = 18;

	Station* pStation = pDebutStation;
	while (pStation != NULL) {
		int temps = pStation->tempsInoccupee;
		couts += calculEnFonctionTemps(coutsParHeure, temps);

		pStation = pStation->pSuivStation;
	}

	return couts;
}