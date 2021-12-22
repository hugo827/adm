#include "Header.h"


void libClient(Station* pStation, Couts* couts) {
	
	Client* pPart = pStation->pClient;

	calculCoutsClientAFinis(couts, pPart);
	
	pStation->pClient = NULL;
	free(pPart);
	
}
