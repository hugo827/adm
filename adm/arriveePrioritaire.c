#include "Header.h"


int arriveePrioritaire(double paramPrior, int a, int c, int m, int* xn) {

	(*xn) = nombreAleatoire(a, c, m, (*xn));

	double U1 = ((double)(*xn) / (double)m);

	int nbArriv�esP= 0;

	double p0 = loiPoisson(paramPrior, 0);
	double p1 = loiPoisson(paramPrior, 1);
	double p2 = loiPoisson(paramPrior, 2);
	double p3 = loiPoisson(paramPrior, 3);

	double pTotal = p0;

	if (U1 < pTotal) nbArriv�esP = 0;
	else {
		pTotal += p1;
		if (U1 < pTotal)nbArriv�esP = 1;
		else {
			pTotal += p2;
			if (U1 < pTotal)nbArriv�esP = 2;
			else {
				pTotal += p3;
				if (U1 < pTotal)nbArriv�esP = 3;
				else nbArriv�esP = 4;
			}
		}
	}
	return nbArriv�esP;
}