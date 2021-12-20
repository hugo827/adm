#include "Header.h"


int arriveeOrdinaire(double paramOrd, int a, int c, int m, int* xn) {

	int nbArriveesO = 0;
	int xTemps = *xn;

	xTemps = nombreAleatoire(a, c, m, *xn);
	

	double U1 = ((double)(xTemps) / (double)m);
	*xn = xTemps;

	
	//calculer les proba pour chaque nbr d'arrivées
	double p0 = loiPoisson(paramOrd, 0);
	double p1 = loiPoisson(paramOrd, 1);
	double p2 = loiPoisson(paramOrd, 2);
	double p3 = loiPoisson(paramOrd, 3);
	double p4 = loiPoisson(paramOrd, 4);
	double p5 = loiPoisson(paramOrd, 5);


	// initialiser premiere proba 
	double pTotal = p0;
	if (U1 < pTotal) nbArriveesO = 0;
	else {
		pTotal += p1;
		if (U1 < pTotal) nbArriveesO = 1;
		else {
			pTotal += p2;
			if (U1 < pTotal) nbArriveesO = 2;
			else {
				pTotal += p3;
				if (U1 < pTotal)nbArriveesO = 3;
				else {
					pTotal += p4;
					if (U1 < pTotal) nbArriveesO = 4;
					else {
						pTotal += p5;
						if (U1 < pTotal) nbArriveesO = 5;
						else nbArriveesO = 6; // au dela de 6 arrivées, les proba sont presque nulles
					}
				}
			}
		}
	}

	return nbArriveesO;
}