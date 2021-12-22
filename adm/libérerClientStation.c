#include "Header.h"


void libererClientStation(Station* pStation, Couts* couts) {
	
	Client* pPart = pStation->pClient;

	calculCoutsClientAFinis(couts, pPart);
	
	pStation->pClient = NULL;
	free(pPart);
	
}
