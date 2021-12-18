#include "Header.h"


int rechercheMin(int nbStationsMin, int nbStations, Couts couts[]) {
	int i = 1, nbCellulesCouts = nbStations - nbStationsMin + 1, nbStationsOptimal = nbStationsMin, coutTotalMin = couts[0].coutsTotal;

	while (i < nbCellulesCouts) {
		if (couts[i].coutsTotal < coutTotalMin) {
			coutTotalMin = couts[i].coutsTotal;
			nbStationsOptimal = nbStationsMin + i;
		}
		i++;
	}
	return nbStationsOptimal;
}