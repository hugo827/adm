#include "Header.h"


void affichageStations(Station* pDebutStations) {

	Station* pStation = pDebutStations;

	while (pStation != NULL) {
		if (pStation->pClient == NULL) {
			printf("Pas de client dans la station");
		}
		else {
			printf("Client : \n\t - Temps Station Restant : %d\n\t - Temps System : %d \n\t - Temps File : %d\n",
				pStation->pClient->tempsRestantStation, pStation->pClient->tempsPasseSystem, pStation->pClient->tempsPasseFile
				);
		}
		printf("Temps Station inoccupée : %d", pStation->tempsInoccupée);

		pStation = pStation->pSuivStation;
	}
}