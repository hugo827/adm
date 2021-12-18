#include "Header.h"


void initCouts(Couts couts[], int length) {

	for (int i = 0; i < length; i++) {
		couts[i].coutsDepartsOrdinaire = 0;
		couts[i].coutsDepartsPrioritaire = 0;
		couts[i].coutsStationOrdinaire = 0;
		couts[i].coutsStationsPrioritaire = 0;
		couts[i].coutsSystemOrdinaire = 0;
		couts[i].coutsSystemPrioritaire = 0;
		couts[i].coutsStationsInoccupée = 0;
		couts[i].coutsTotal = 0;
	}
	
}