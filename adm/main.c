#include "Header.h"


void main(void) {
	
	printf("<--------------------Debut du programme-------------------->");

	int a = 9;
	int c = 17;
	int m = 100;
	int x0 = 30;
	int nbStationsMin = 2;
	int nbStationsMax = 5;
	int tempsSimul = 500;

	printf("\n Vaux valeur :" 
		"\n\t - a : %d "
		"\n\t - c : %d "
		"\n\t - m : %d "
		"\n\t - x0 : %d "
		"\n\t - nbStationsMin : %d "
		"\n\t - nbStationMax : %d "
		"\n\t - temps Simulation : %d \n\n",
		 a, c, m, x0, nbStationsMin, nbStationsMax, tempsSimul
	);

	int nb = nbStationsOptimal(nbStationsMin, nbStationsMax, tempsSimul, a, c, m, x0);

	printf("\n => Le nombre de stations optimal est : %d\n\n", nb);

	printf("<--------------------Fin du programme-------------------->");

}