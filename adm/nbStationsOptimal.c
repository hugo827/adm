#include "Header.h"


// j'ai modifier les params pour loi de poisson avec de plus grande valeur et ca a fonctioner. 

int nbStationsOptimal(int nbStationsMin, int nbStationsMax, int tempsSimul, int a, int c, int m, int x0, double paramPrior, double paramOrdi) {

	int nbStations = nbStationsMin;
	bool affiche = false;
	int nbCouts = nbStationsMax - nbStationsMin+1;

	Couts couts[NBCOUTS]; // a changer NBCOUTS a chaque modifie de nbStationMin et nbStationsMAX

	initCouts(couts, NBCOUTS);


	while (nbStations <= nbStationsMax) {
		
		int xn = x0;
		int iCouts = nbStations - nbStationsMin;
		Client* pDebutFile = NULL;
		Couts coutsNbStation = {0};

		Station* pDebutStation = initStations(nbStations);

		int temps = 1;
		while (temps <= tempsSimul) {

			 affiche = temps <= 20 && nbStations == nbStationsMin;
			
			if (affiche) {
				affichageStations(pDebutStation);
			}
			
			
			xn = genererArrivees(a, c, m, xn, &pDebutFile, paramPrior, paramOrdi, affiche);

			if (affiche) {
				affichageFile(pDebutFile);
			}

			
			xn = majStation(pDebutStation, &pDebutFile, xn, a, c, m, &coutsNbStation);


			majFile(pDebutFile);

			if (temps > 10) {
				clientImpatientPart(&coutsNbStation, &pDebutFile);
			}

			if (affiche) {
				affichageStations(pDebutStation);
				affichageFile(pDebutFile);
			}
			

			temps++;
		}
		couts[iCouts] = coutsNbStation;
		couts[iCouts].coutsStationsInoccupee = calculCoutsStationInoccupee(pDebutStation);

		/*
		printf("\n- Couts de nbStation\n"
			"\t - Couts depart ordinaire : %.2lf\n"
			"\t - Couts depart prioritaire : %.2lf\n"
			"\t - Couts station prioritaire : %.2lf\n"
			"\t - Couts station ordinaire : %.2lf\n"
			"\t - Couts station inocupée : %.2lf\n"
			"\t - Couts system ordinaire : %.2lf\n"
			"\t - Couts system absolue : %.2lf\n"
		
		,coutsNbStation.coutsDepartsOrdinaire, coutsNbStation.coutsDepartsPrioritaire, coutsNbStation.coutsStationsPrioritaire, coutsNbStation.coutsStationOrdinaire, coutsNbStation.coutsStationsInoccupee,
			coutsNbStation.coutsSystemOrdinaire, coutsNbStation.coutsSystemPrioritaire);*/
		
		nbStations++;
	}
	

	affichageCouts(nbStationsMin, nbStations, couts);

	return rechercheMin(nbStationsMin, nbStationsMax, couts);
}