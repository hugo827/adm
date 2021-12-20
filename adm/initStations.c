#include "Header.h"

Station* initStations(int nbStation) {
	int iStation = 0;
	Station* pPrec = NULL;
	Station* pDebutStations = NULL;
	bool continuer = true;

	while (iStation < nbStation && continuer) {
		Station* pNouv = (Station*) malloc(sizeof(Station));
		continuer = pNouv != NULL; 
		if (continuer) {
			pNouv->pSuivStation = NULL;
			pNouv->pClient = NULL;
			pNouv->tempsInoccupee = -1;

			if (pDebutStations == NULL) {
				pDebutStations = pNouv;	
			}
			else {
				pPrec->pSuivStation = pNouv;
			}
			pPrec = pNouv;
		}
		else {
			printf("\nPlus d'espace m�moire -> cr�ation Station !");
			exit(EXIT_FAILURE);
		}
		iStation++;
	}
	return pDebutStations;
}