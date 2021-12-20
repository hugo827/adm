#include "Header.h"


void majStation(Station* pDebutStation, Client* pDebutFile, int* xn, int a, int c, int m, Couts couts) {

	Station* pStation = pDebutStation;
	Change* pDebutChangement = NULL; 
	Change* pChange = pDebutChangement;

	while (pStation != NULL) {
		if (pStation->pClient != NULL) {
			pStation->pClient->tempsPasseSystem++;
			pStation->pClient->tempsRestantStation--;
		}
		else {
			pStation->tempsInoccupee++;
		}


		// Si client à fini son temps à la station
		if (pStation->pClient->tempsRestantStation == 0) couts = libérerClientStation(pStation, couts);

		// si il y a un client dispo dans la file->il se met à la station
		if (pStation->pClient == NULL) {

			if (pDebutFile != NULL) {
				pStation->pClient = pDebutFile;
				pDebutFile = pDebutFile->pSuivClient;
				if (pStation->pClient->tempsRestantStation == -1) {
					int duree = genererDuree(&xn, a, c, m);
					pStation->pClient->tempsRestantStation = duree;
				}
			}
			else {
				if (pStation->pClient->statut == 'O') {
					Change* pNouv = (Change*)malloc(sizeof(Change));

					if (pNouv != NULL) {
						if (pDebutChangement == NULL) pNouv->pPrec = NULL;
						else pNouv->pPrec = pChange;

						pNouv->pStation = pStation;
						pNouv->pSuivChange = NULL;
						pChange->pSuivChange = pNouv;
						pChange = pNouv;
					}
					else {
						printf("plus d'espace mémoire -> partie majStation");
					}
				}
			}

			pStation = pStation->pSuivStation;
		}
	}
	
	
	// !!! boucle pour remplacer les ordinaires par des absolus
	while (pDebutFile != NULL && pDebutFile->statut != 'O' && pDebutChangement != NULL) {

		pChange = pDebutChangement;
		int tempsRestantMax = 0;
		Change* pModification = NULL;
		Client* pClient = NULL;

		while (pChange != NULL) {
			pClient = pChange->pStation->pClient;

			if (pClient->tempsRestantStation > tempsRestantMax) {
				tempsRestantMax = pClient->tempsRestantStation;
				pModification = pChange;
			}
			pChange = pChange->pSuivChange;
		}

		// a voir 
		pClient = pModification->pStation->pClient;
		pClient->statut = 'A';
		Client* pFile = pDebutFile;
		Client* pPrec = NULL;

		while (pFile != NULL && pFile->statut == 'A') {
			pPrec = pFile;
			pFile = pFile->pSuivClient;
		}

		if (pFile == pDebutFile) {
			pClient->pSuivClient = pDebutFile;
			pDebutFile = pClient;
		}
		else {
			pPrec->pSuivClient = pClient;
			pClient->pSuivClient = pFile;
		}

		pModification->pStation->pClient = pDebutFile;
		pDebutFile = pDebutFile->pSuivClient;

		if (pModification->pStation->pClient == -1) {
			int duree = genererDuree(&xn, a, c, m);
			pModification->pStation->pClient->tempsRestantStation = duree;
		}

		if (pModification == pDebutChangement) {
			pModification->pSuivChange->pPrec = NULL;
			pDebutChangement = pModification->pSuivChange;
		}
		else {

			pModification->pPrec->pSuivChange = pModification->pSuivChange;

			if (pModification->pSuivChange != NULL) {
				pModification->pSuivChange->pPrec = pModification->pPrec;
			}
		}
		free(pModification);	
	}
}