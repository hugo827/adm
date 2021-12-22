#include "Header.h"



void affichageCouts(int nbStationsMin, int nbStationsMax, Couts couts[]) {

	int nbCellules = (nbStationsMax - nbStationsMin) + 1;

	for (int iCouts = 0; iCouts < NBCOUTS; iCouts++) {

		couts[iCouts].coutsTotal = (
			couts[iCouts].coutsDepartsOrdinaire
			+ couts[iCouts].coutsDepartsPrioritaire
			+ couts[iCouts].coutsSystemOrdinaire
			+ couts[iCouts].coutsSystemPrioritaire
			+ couts[iCouts].coutsStationOrdinaire
			+ couts[iCouts].coutsStationsPrioritaire
			+ couts[iCouts].coutsStationsInoccupee
			);



		printf(" Pour le nombre de stations  %d : "
				" \n\t - Departs ordinaire : %.2lf" 
				"\n\t - Departs Prioritaire : %.2lf"
				"\n\t - Station ordinaire : %.2lf" 
				"\n\t - Station prioritaire : %.2lf" 
				"\n\t - Systeme ordinaire : %.2lf"  
				"\n\t - System prioritaire : %.2lf" 
				"\n\t - Station inoccupée : %.2lf"
				"\n\t => Couts Total : %.2lf\n"
			"", (nbStationsMin + iCouts), couts[iCouts].coutsDepartsOrdinaire, couts[iCouts].coutsDepartsPrioritaire, couts[iCouts].coutsStationOrdinaire,
			couts[iCouts].coutsStationsPrioritaire, couts[iCouts].coutsSystemOrdinaire, couts[iCouts].coutsSystemPrioritaire, couts[iCouts].coutsStationsInoccupee, couts[iCouts].coutsTotal);
	}
	
}
