#include "Header.h"


void clientImpatientPart(Couts* couts, Client** pDebutFile) {

	Client* pPrecClient = NULL;
	Client* pFile = *pDebutFile;
	int placeFile = 1;

	while (pFile != NULL) {
		if (pFile->tempsPasseFile >= 10 && placeFile > 3) {
			Client* pSauv = pFile;
			pFile = pFile->pSuivClient;
			coutDepartClientImpatient(pSauv, couts);
			*pDebutFile = retirerClientFile(*pDebutFile, pSauv, &pPrecClient);
		}
		else {
			pPrecClient = pFile;
			pFile = pFile->pSuivClient;
		}
		placeFile++;
	}

}