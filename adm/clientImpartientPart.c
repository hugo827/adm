#include "Header.h"


void clientImpatientPart(Couts* couts, Client** pDebutFile, int afficherArriv) {

	Client* pPrecClient = NULL;
	Client* pFile = *pDebutFile;
	int placeFile = 1;
	int nbrClientPartis=0;

	while (pFile != NULL) {
		if (pFile->tempsPasseFile >= 10 && placeFile > 3) {
			Client* pSauv = pFile;
			pFile = pFile->pSuivClient;
			coutDepartClientImpatient(pSauv, couts);
			*pDebutFile = retirerClientFile(*pDebutFile, pSauv, &pPrecClient);
			nbrClientPartis++;
		}
		else {
			pPrecClient = pFile;
			pFile = pFile->pSuivClient;
		}
		placeFile++;
	}
		if (afficherArriv) {
		printf("Nombre de clients impatients partis: %d\n", nbrClientPartis);
	}

}
