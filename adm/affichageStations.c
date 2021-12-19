#include "Header.h"


void affichageStations(Station* pDebutStations) {
	printf("%p", pDebutStations);
	Station* pStation = pDebutStations;
	int i = 1;
	printf("<------------------------Debut affichage station------------------------>\n");
	while (pStation != NULL) {
		if (pStation->pClient == NULL) {
			printf("->Pas de client dans la station %d\n", i);
		}
		else {
			printf("->Client : \n\t - Temps Station Restant : %d\n\t - Temps System : %d \n\t - Temps File : %d\n",
				pStation->pClient->tempsRestantStation, pStation->pClient->tempsPasseSystem, pStation->pClient->tempsPasseFile
				);
		}
		printf("Temps Station inoccupee : %d\n", pStation->tempsInoccupée);

		pStation = pStation->pSuivStation;
		i++;
	}
	printf("<------------------------Fin affichage station------------------------>\n");
}