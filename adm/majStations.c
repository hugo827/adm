#include "Header.h"


int majStation(Station* pDebutStation, Client** pDebutFile, unsigned long int xn, unsigned long int a, unsigned long int c, unsigned long int m, Couts* couts, bool affiche) {

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
		if (pStation->pClient != NULL && pStation->pClient->tempsRestantStation == 0) {
			libClient(pStation, couts);
		}

		// si il y a un client dispo dans la file->il se met à la station
		if (pStation->pClient == NULL) {

			if (*pDebutFile != NULL) {
				pStation->pClient = *pDebutFile;
				*pDebutFile = pStation->pClient->pSuivClient;
				if (pStation->pClient->tempsRestantStation == -1) {
					int duree = genererDuree(&xn, a, c, m);
					pStation->pClient->tempsRestantStation = duree;

					//rajout cout station par rapport à la durée calculée
					int coutsParHeureSystem, coutsParHeureStation;
					char statut = pStation->pClient->statut;
					rechercheCoutsParHeure(statut, &coutsParHeureSystem, &coutsParHeureStation);
					double coutsTemps = calculEnFonctionTemps(coutsParHeureStation, duree);
					if (pStation->pClient->statut == 'O') {
						(couts->coutsStationOrdinaire += coutsTemps);
					}
					else {
						(couts->coutsStationsPrioritaire += coutsTemps);
						int j = 0;
					}
				}
			}
		}
		else {
			if (pStation->pClient != NULL && pStation->pClient->statut == 'O' && *pDebutFile != NULL) {
					Change* pNouv = (Change*)malloc(sizeof(Change));

				if (pNouv != NULL) {

					if (pDebutChangement == NULL) { 
						pNouv->pPrec = NULL; 
						pDebutChangement = pNouv;
					}
					else { 
						pNouv->pPrec = pChange;
						pChange->pSuivChange = pNouv;
					}

						pNouv->pStation = pStation;
						pNouv->pSuivChange = NULL;
						pChange = pNouv;
				}
				else {
					printf("plus d'espace mémoire -> partie majStation");
				}
			}
		}
		pStation = pStation->pSuivStation;
	}
	
	
	// !!! boucle pour remplacer les ordinaires par des absolus
	while ( (*pDebutFile) != NULL && (*pDebutFile)->statut != 'O' && (*pDebutFile)->statut != 'C' && pDebutChangement != NULL) {

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

		if(pModification != NULL) {
			// a voir 
			pClient = pModification->pStation->pClient;
			if (affiche) {
				printf("\n ==> Ejection ordinaire (%c) par absolue en station\n", pClient->statut);
			}
			pClient->statut = 'C';
			Client* pFile = *pDebutFile;
			Client* pPrec = NULL;
			
			
			while (pFile != NULL && (pFile->statut == 'A' || pFile->statut == 'C')) {
				pPrec = pFile;
				pFile = pFile->pSuivClient;
			}

			if (pFile == *pDebutFile) {
				pClient->pSuivClient = *pDebutFile;
				*pDebutFile = pClient;
			}
			else {
				pPrec->pSuivClient = pClient;
				pClient->pSuivClient = pFile;
			}
			
			pModification->pStation->pClient = *pDebutFile;
			*pDebutFile = (*pDebutFile)->pSuivClient;
			

			if (pModification->pStation->pClient->tempsRestantStation == -1) {
				int duree = genererDuree(&xn, a, c, m);
				pModification->pStation->pClient->tempsRestantStation = duree;
			}

			if (pModification == pDebutChangement) {
				
				pDebutChangement = pModification->pSuivChange;
				//pDebutChangement->pPrec = NULL;
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

	Client* pFile = *pDebutFile;
	while (pFile != NULL && (pFile->statut == 'A' || pFile->statut == 'C')) {
		if (pFile->statut == 'C') {
			pFile->statut = 'A';
		}
		pFile = pFile->pSuivClient;
	}

	//Changement !
	Change* pLib = pDebutChangement;
	while (pLib != NULL) {
		Change* pSauv = pLib;
		pLib = pLib->pSuivChange;
		free(pSauv);
	}

	return xn;
}
