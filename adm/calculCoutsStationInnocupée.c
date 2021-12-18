#include "Header.h"



int calculCoutsStationInoccupée(Station* pDebutStation) {
	int couts = 0, coutsParHeure = 18;

	Station* pStation = &pDebutStation;
	while (pStation != NULL) {
		couts += calculCoutEnFonctionTemps(coutsParHeure, pStation->tempsInoccupée);

		pStation = pStation->pSuivStation;
	}

	return couts;
}