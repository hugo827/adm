#include "Header.h"


Couts clientImpatientPart(Couts couts, Client** pDebutFile) {

	Client* pPrecClient = NULL;
	Client* pFile = *pDebutFile;
	int placeFile = 1;

	while (pFile != NULL) {
		if (pFile->tempsPasseFile >= 10 && placeFile > 3) {
			couts = coutDepartClientImpatient(pFile, couts);
			*pDebutFile = retirerClientFile(*pDebutFile, pFile, &pPrecClient);
		}
		else {
			pPrecClient = pFile;
		}
		pFile = pFile->pSuivClient;
		placeFile++;
	}

	return couts;
}