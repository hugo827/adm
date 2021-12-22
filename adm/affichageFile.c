#include "Header.h"


void affichageFile(Client* pDebutFile) {
	Client* pFile = pDebutFile;

	printf("<------------------ affichage file----------------->\n");
	if (pFile == NULL) {
		printf("Pas de file\n");
	}
	while (pFile != NULL) {
		printf("Statut : %c - Temps Station : %d  --- Temps System : %d --- Temps File : %d\n",pFile->statut, pFile->tempsRestantStation, pFile->tempsPasseSystem, pFile->tempsPasseFile);
		pFile = pFile->pSuivClient;
	}
	
}
