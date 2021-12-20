#include "Header.h"

Client* ajouterClientFile(char statut, Client** pDebutFile) {

	Client* pNouv = (Client*)malloc(sizeof(Client));
	if (pNouv == NULL) {
		printf("Plus d'espaces mémoire -> partie ajouterClientFile\n");
		exit(EXIT_FAILURE);
	}
	else {
		printf("Ajout client file %p\n", pDebutFile);
		Client* pFile = *pDebutFile;
		printf("pfile %p\n", pFile);
		pNouv->statut = statut;
		pNouv->pSuivClient = NULL;
		Client* pPrecClient = NULL;
		pNouv->tempsPasseFile = 0;
		pNouv->tempsRestantStation = -1;
		pNouv->tempsPasseSystem = 0;
		switch (statut) {
		case 'O' :
			while (pFile != NULL) {
				pPrecClient = pFile;
				pFile = pFile->pSuivClient;
			}
			//il n'y a personne dans la file
			if (pFile == *pDebutFile) {
				*pDebutFile = pNouv;
				pNouv->pSuivClient = NULL;
			}
			// le client ira en bout de file car il est ordinaire
			else {
				pPrecClient->pSuivClient = pNouv;
				pNouv->pSuivClient = NULL;
			}
			break;
		case 'A':
			while (pFile != NULL && pFile->statut == 'A') {
				pPrecClient = pFile;
				pFile = pFile->pSuivClient;
			}
			if (pFile == *pDebutFile) {
				pNouv->pSuivClient = *pDebutFile;
				*pDebutFile = pNouv;
			}
			else {
				pPrecClient->pSuivClient = pNouv;
				pNouv->pSuivClient = pFile;
			}
			

			break;
		case 'R':

			while (pFile != NULL && pFile->statut == 'O') {
				pPrecClient = pFile;
				pFile = pFile->pSuivClient;
			}
			if (pFile == *pDebutFile) {
				pNouv->pSuivClient = *pDebutFile;
				*pDebutFile = pNouv;
			}
			else {
				pPrecClient->pSuivClient = pNouv;
				pNouv->pSuivClient = pFile;
			}

			break;
		}
	}

	return *pDebutFile;
}
