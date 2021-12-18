#include "Header.h"


void affichageFile(Client* pDebutFile) {
	Client* pFile = pDebutFile;

	printf("<------------------ affichage file----------------->");
	while (pFile != NULL) {
		printf(" - Temps Station : %d  --- Temps System : %d --- Temps File : %d\n", pFile->tempsRestantStation, pFile->tempsPasseSystem, pFile->tempsPasseFile);
		pFile = pFile->pSuivClient;
	}
}