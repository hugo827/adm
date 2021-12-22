#pragma once
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

typedef struct client Client;
typedef struct station Station;
typedef struct couts Couts;
typedef struct change Change;


struct client {
		char statut;
		int tempsPasseSystem;
		int tempsPasseFile;
		int tempsRestantStation;
		Client* pSuivClient;
};


struct station {
	Client* pClient;
	int tempsInoccupee;
	Station* pSuivStation;
};


struct couts {
	double coutsDepartsOrdinaire;
	double coutsDepartsPrioritaire;
	double coutsSystemOrdinaire;
	double coutsSystemPrioritaire;
	double coutsStationOrdinaire;
	double coutsStationsPrioritaire;
	double coutsStationsInoccupee;
	double coutsTotal;
};

struct change {
	Change* pPrec;
	Station* pStation;
	Change* pSuivChange;
};

#define NBCOUTS 4
#define EXIT_FAILURE 1
#define EXIT_SUCCES 0


int nbStationsOptimal(int nbStationsMin, int nbStationsMax, int tempsSimul, int a, int c, int m, int x0, double paramPrior, double paramOrdi );

void initCouts(Couts couts[], int length);

void affichageCouts(int nbStationsMin, int nbStationsMax, Couts couts[]);

double calculCoutsStationInoccupee(Station* pDebutStation);

double calculEnFonctionTemps(int coutsParHeure, int temps);

void calculCoutsClientAFinis(Couts* couts, Client* pPart);

int genererDuree(int* xn, int a, int c, int m);

int nombreAleatoire(int m, int a, int c,int xn);

double loiPoisson(double param, int k);

void affichageStations(Station* pDebutStations);

void affichageFile(Client* pDebutFile);

int rechercheMin(int nbStationsMin, int nbStationsMax, Couts couts[]);

Station* initStations(int nbStation);

void majFile(Client* pDebutClient);

int majStation(Station* pDebutStation, Client** pDebutFile, int xn, int a, int c, int m, Couts* couts); 

void libClient(Station* pStation, Couts* couts);

int genererArrivees(int a, int c, int m, int xn, Client** pDebutFile, double paramPrior, double paramOrdi, bool affiche);

int arriveePrioritaire(double paramPrior, int a, int c, int m, int* xn);

int arriveeOrdinaire(double paramOrd, int a, int c, int m, int* xn);

Client* ajouterClientFile(char statut, Client** pDebutFile);

void clientImpatientPart(Couts* couts, Client** pDebutFile, int affiche);

Client* retirerClientFile(Client* pDebutFile, Client* pClientImpatient, Client** pPrecClient);

void coutDepartClientImpatient(Client* pFile, Couts* couts);

void rechercheCoutsParHeure(char statut, int* coutsParHeureSystem, int* coutsParHeureStation);
