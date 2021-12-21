#include "Header.h"


// j'ai modifier les params pour loi de poisson avec de plus grande valeur et ca a fonctioner. 

int nbStationsOptimal(int nbStationsMin, int nbStationsMax, int tempsSimul, int a, int c, int m, int x0) {

	int nbStations = nbStationsMin;

	int nbCouts = nbStationsMax - nbStationsMin+1;

	Couts couts[NBCOUTS]; // a changer NBCOUTS a chaque modifie de nbStationMin et nbStationsMAX

	initCouts(couts, NBCOUTS);

	while (nbStations <= nbStationsMax) {
		
		int xn = x0;
		int iCouts = nbStations - nbStationsMin;
		Client* pDebutFile = NULL;
		

		Station* pDebutStation = initStations(nbStations);

		int temps = 1;
		while (temps <= tempsSimul) {

			if (temps <= 20 && nbStations == nbStationsMin) {
				affichageStations(pDebutStation);
			}
			
			xn = genererArrivees(a, c, m, xn, &pDebutFile);

			if (temps <= 20 && nbStations == nbStationsMin) {
				affichageFile(pDebutFile);
			}

			xn = majStation(pDebutStation, &pDebutFile, xn, a, c, m, couts[iCouts] );

			majFile(pDebutFile);

			if (temps > 10) {
				couts[iCouts] = clientImpatientPart(couts[iCouts], &pDebutFile);
			}

			if (temps <= 20 && nbStations == nbStationsMin) {
				affichageStations(pDebutStation);
				affichageFile(pDebutFile);
			}


			temps++;
		}

		couts[iCouts].coutsStationsInoccupee = calculCoutsStationInoccupée(pDebutStation);

		nbStations++;
	}


	affichageCouts(nbStationsMin, nbStations, couts);

	return rechercheMin(nbStationsMin, nbStationsMax, couts);
}