#include "Header.h"


Client* retirerClientFile(Client* pDebutFile, Client* pClientImpatient, Client* pPrecClient) {


	if (pClientImpatient == pDebutFile) pDebutFile = pClientImpatient->pSuivClient;
	else pPrecClient->pSuivClient = pClientImpatient->pSuivClient;

	free(pClientImpatient);

	return pDebutFile;
}