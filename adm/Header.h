#pragma once
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

typedef struct client Client;
typedef struct station Station;
typedef struct couts Couts;


struct client {
		char statut;
		int tempsPasseSystem;
		int tempsPasseFile;
		int tempsRestantStation;
		Client* pSuivClient;
};


struct station {
	Client* pClient;
	int tempsInoccupée;
	Station* pSuivStation;
};


struct couts {
	int coutsDepartsOrdinaire;
	int coutsDepartsPrioritaire;
	int coutsSystemOrdinaire;
	int coutsSystemPrioritaire;
	int coutsStationOrdinaire;
	int coutsStationsPrioritaire;
	int coutsStationsInoccupée;
	int coutsTotal;
};

#define NBCOUTS 5


int nbStationsOptimal(int nbStationsMin, int nbStationsMax, int tempsSimul, int a, int c, int m, int x0);

void initCouts(Couts couts[], int length);

void affichageCouts(int nbStationsMin, int nbStationsMax, Couts couts[]);

int calculCoutsStationInoccupée(Station* pDebutStation);

Couts calculCoutsClientAFinis(Couts couts, Client* pPart);

int genererDuree(int* xn, int a, int c, int m);