#include "Header.h"


void affichageStations(Station* pDebutStations) {
	printf("%p", pDebutStations);
	Station* pStation = pDebutStations;
	// initalisation numéro de station
	int i = 1;
	printf("<------------------------Debut affichage station------------------------>\n");
	//Tant qu'il reste des stations à parcourir
	while (pStation != NULL) {
		if (pStation->pClient == NULL) {
			printf("->Pas de client dans la station %d\n", i);
		}
		else {
			printf("->Client : \n\t - Temps Station Restant : %d\n\t - Temps System : %d \n\t - Temps File : %d\n",
				pStation->pClient->tempsRestantStation, pStation->pClient->tempsPasseSystem, pStation->pClient->tempsPasseFile
				);
		}
		//a afficher que la station soit inoccupée ou pas
		printf("Temps Station inoccupee : %d\n", pStation->tempsInoccupee);
		
		// passe à la station suivante
		pStation = pStation->pSuivStation;
		i++;
	}
}
