#include "Header.h"



Couts calculCoutsClientAFinis(Couts couts, Client* pPart) {

	char status = pPart->statut;
	int coutsParHeureSystem, coutsParHeureStation;

	rechercheCoutsParHeure(status, &coutsParHeureSystem, &coutsParHeureStation);

	int coutsTemps = calculEnFonctionTemps(coutsParHeureSystem, pPart->tempsPasseSystem);

	(status == 'O') ? (couts.coutsSystemOrdinaire += coutsTemps) : (couts.coutsSystemPrioritaire += coutsTemps);
	
	coutsTemps = calculCoutsEnFonctionTemps(coutsParHeureStation, pPart->tempsRestantStation);  // probléme tempsRestantStation = pas celui passé ! ?

	(status == 'O') ? (couts.coutsStationOrdinaire += coutsTemps) : (couts.coutsStationsPrioritaire += coutsTemps);
	
	return couts;
}