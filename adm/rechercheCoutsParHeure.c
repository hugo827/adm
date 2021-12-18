#include "Header.h"



void rechercheCoutsParHeure(char status, int* coutsParHeureSystem, int* coutsParHeureStation) {

	// init avec les valeurs de absolue

	*coutsParHeureSystem = 45;
	*coutsParHeureStation = 32;

	switch (status)
	{
	case 'O' : 
		*coutsParHeureSystem = 25;
		*coutsParHeureStation = 30;
		break;
	case 'R':
		*coutsParHeureSystem = 35;
		break;
	}
}