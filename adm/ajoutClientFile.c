#include "Header.h"

Client* ajouterClientFile(char statut, Client* pDebutFile) {

	Client* pNouv = (Client*)malloc(sizeof(Client));
	if (pNouv == NULL) {
		printf("Plus d'espaces mémoire -> partie ajouterClientFile");
		exit(EXIT_FAILURE);
	}
	else {
		Client* pFile = pDebutFile;
		pNouv->statut = statut;
		pNouv->pSuivClient = NULL;
		Client* pPrecClient = NULL;
		switch (statut) {
		case 'O' :
			while (pFile != NULL) {
				pPrecClient = pFile;
				pFile = pFile->pSuivClient;
			}
			
			if (pFile == pDebutFile) {
				pNouv->pSuivClient = pDebutFile;
				pDebutFile = pNouv;
			}
			else {
				pPrecClient->pSuivClient = pNouv;
				pNouv->pSuivClient = pFile;
			}
			break;
		case 'A':
			while (pFile != NULL && pFile->statut == 'A') {
				pPrecClient = pFile;
				pFile = pFile->pSuivClient;
			}
			if (pFile == pDebutFile) {
				pNouv->pSuivClient = pDebutFile;
				pDebutFile = pNouv;
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
			if (pFile == pDebutFile) {
				pNouv->pSuivClient = pDebutFile;
				pDebutFile = pNouv;
			}
			else {
				pPrecClient->pSuivClient = pNouv;
				pNouv->pSuivClient = pFile;
			}

			break;
		}
	}

	return pDebutFile;
}