#include "Header.h"


void main(void) {
	
	printf("<--------------------Debut du programme-------------------->");
	int m = 63, a = 13, c = 19, x0 = 35;

	int nbStationsMin = 3;
	int nbStationsMax = 15;
	int tempsSimul = 500;
	double paramPrior = 2;
	double paramOrdi = 5;



	printf("\n vos valeur :" 
		"\n\t - a : %d "
		"\n\t - c : %d "
		"\n\t - m : %d "
		"\n\t - x0 : %d "
		"\n\t - nbStationsMin : %d "
		"\n\t - nbStationMax : %d "
		"\n\t - temps Simulation : %d \n\n",
		 a, c, m, x0, nbStationsMin, nbStationsMax, tempsSimul
	);

	int nb = nbStationsOptimal(nbStationsMin, nbStationsMax, tempsSimul, a, c, m, x0, paramPrior, paramOrdi);

	printf("\n => Le nombre de stations optimal est : %d\n\n", nb);

	printf("<--------------------Fin du programme-------------------->");

}