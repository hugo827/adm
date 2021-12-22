#include "Header.h"



void calculCoutsClientAFinis(Couts* couts, Client* pPart) {

	char status = pPart->statut;
	int coutsParHeureSystem, coutsParHeureStation;

	rechercheCoutsParHeure(status, &coutsParHeureSystem, &coutsParHeureStation);

	double coutsTemps = calculEnFonctionTemps(coutsParHeureSystem, pPart->tempsPasseSystem);

	if (status == 'O')  (couts->coutsSystemOrdinaire += coutsTemps); 
	else (couts->coutsSystemPrioritaire += coutsTemps);
	
	coutsTemps = calculEnFonctionTemps(coutsParHeureStation, pPart->tempsRestantStation);  // probléme tempsRestantStation = pas celui passé ! ?

	if (status == 'O') (couts->coutsStationOrdinaire += coutsTemps);
	else (couts->coutsStationsPrioritaire += coutsTemps);
	
}