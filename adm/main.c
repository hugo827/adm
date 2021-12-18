#include "Header.h"


void main(void) {
	
	printf("<--------------------Debut du programme-------------------->");

	int a = 10;
	int c = 10;
	int m = 10;
	int x0 = 10;
	int nbStationsMin = 2;
	int nbStationsMax = 5;
	int tempsSimul = 500;

	int nb = nbStationsOptimal(nbStationsMin, nbStationsMax, tempsSimul, a, c, m, x0);

	printf("\n => Le nombre de stations optimal est : %d", nb);

	printf("<--------------------Fin du programme-------------------->");

}