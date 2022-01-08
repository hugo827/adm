#include "Header.h"


void main(void) {
	
	printf("<--------------------Debut du programme-------------------->");
	unsigned long int m = 65536, a = 55557, c = 44445, x0 = 827;

	int nbStationsMin = 3;
	int nbStationsMax = 15;
	int tempsSimul = 500;
	double paramPrior = 0.7;
	double paramOrdi = 2.0;



	printf("\n vos valeur :" 
		"\n\t - a : %d "
		"\n\t - c : %d "
		"\n\t - m : %d "
		"\n\t - x0 : %d "
		"\n\t - nbStationsMin : %d "
		"\n\t - nbStationMax : %d "
		"\n\t - paramPrior : %.2lf "
		"\n\t - paramOrdi : %.2lf "
		"\n\t - temps Simulation : %d \n\n"
		"\nAfin d'apercevoir des couts de departs nous avons laisse le nombre de stations minium a 3 biens que le calcul dit que le nombre de stations minimum est a 6\n\n",
		 a, c, m, x0, nbStationsMin, nbStationsMax, paramPrior, paramOrdi, tempsSimul
	);

	int nb = nbStationsOptimal(nbStationsMin, nbStationsMax, tempsSimul, a, c, m, x0, paramPrior, paramOrdi);

	printf("\n => Le nombre de stations optimal est : %d\n\n", nb);

	printf("<--------------------Fin du programme-------------------->");

}