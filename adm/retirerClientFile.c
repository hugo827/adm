#include "Header.h"


Client* retirerClientFile(Client* pDebutFile, Client* pClientImpatient, Client** pPrecClient) {

	(*pPrecClient)->pSuivClient = pClientImpatient->pSuivClient;

	free(pClientImpatient);

	return pDebutFile;
}
