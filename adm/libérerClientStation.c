#include "Header.h"


Couts libérerClientStation(Station* pStation, Couts couts) {
	
	Client* pPart = pStation->pClient;

	couts = calculCoutsClientAFinis(couts, pPart);

	pStation->pClient = NULL;
	free(pPart);
	return couts;
}