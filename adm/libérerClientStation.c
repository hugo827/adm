#include "Header.h"


void lib�rerClientStation(Station* pStation, Couts* couts) {
	
	Client* pPart = pStation->pClient;

	calculCoutsClientAFinis(couts, pPart);
	
	pStation->pClient = NULL;
	free(pPart);
	
}