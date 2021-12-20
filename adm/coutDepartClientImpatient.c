#include "Header.h"


Couts coutDepartClientImpatient(Client* pFile, Couts couts) {

	
	int coutsParHeureSystem = 0, coutsParHeureStation = 0;

	rechercheCoutsParHeure(pFile->statut, &coutsParHeureSystem, &coutsParHeureStation);

	int coutsTemps = calculEnFonctionTemps(coutsParHeureSystem, pFile->tempsPasseSystem);

	switch (pFile->statut)
	{
	case 'O' :
		couts.coutsDepartsOrdinaire += 15;
		couts.coutsSystemOrdinaire += coutsTemps;
		break;
	case 'A':
		couts.coutsDepartsPrioritaire += 20;
		couts.coutsSystemPrioritaire += coutsTemps;
		break;
	case 'R':
		couts.coutsDepartsPrioritaire += 20;
		couts.coutsSystemPrioritaire += coutsTemps;
		break;
	}

	return couts;
}
