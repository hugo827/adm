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
				" \n\t - Departs ordinaire : %d" 
				"\n\t - Departs Prioritaire : %d"
				"\n\t - Station ordinaire : %d" 
				"\n\t - Station prioritaire : %d" 
				"\n\t - Systeme ordinaire : %d"  
				"\n\t - System prioritaire : %d" 
				"\n\t - Station inoccupée : %d"
				"\n\t => Couts Total : %d\n"
			"", (nbStationsMin + iCouts), couts[iCouts].coutsDepartsOrdinaire, couts[iCouts].coutsDepartsPrioritaire, couts[iCouts].coutsStationOrdinaire,
			couts[iCouts].coutsStationsPrioritaire, couts[iCouts].coutsSystemOrdinaire, couts[iCouts].coutsSystemPrioritaire, couts[iCouts].coutsStationsInoccupee, couts[iCouts].coutsTotal);
	}
	
}
