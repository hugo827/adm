#include "Header.h"


int nbStationsOptimal(int nbStationsMin, int nbStationsMax, int tempsSimul, int a, int c, int m, int x0) {

	int nbStations = nbStationsMin;

	int nbCouts = nbStationsMax - nbStationsMin + 1;

	Couts couts[NBCOUTS]; // a changer NBCOUTS a chaque modifie de nbStationMin et nbStationsMAX

	initCouts(couts, NBCOUTS);

	while (nbStations < nbStationsMax) {
		
		int xn = x0;
		int iCouts = nbStations - nbStationsMin;
		Client* pDebutFile = NULL;


		Station* pDebutStation = initStations(nbStations);

		int temps = 1;
		while (temps <= tempsSimul) {

			if (temps <= 20 && nbStations == nbStationsMin) {
				affichageStations(&pDebutStation);
			}

			générerArrivéers(a, c, m, &xn);

			if (temps <= 20 && nbStations == nbStationsMin) {
				affichageFile(&pDebutFile);
			}

			majStation(&pDebutFile, &pDebutStation, &xn, a, c, m, couts[iCouts] );

			majFile(&pDebutFile);

			if (temps > 10) {
				clientImpatientPart(couts[iCouts], &pDebutStation);
			}

			if (temps <= 20 && nbStations == nbStationsMin) {
				affichageFileEtStations(&pDebutFile, &pDebutStation);
			}


			temps++;
		}

		couts[iCouts].coutsStationsInoccupée = calculCoutsStationInoccupée(&pDebutStation);

		nbStations++;
	}


	affichageCouts(nbStationsMin, nbStations, couts);

	return rechercheMin(nbStationsMin, nbStations, couts);
}