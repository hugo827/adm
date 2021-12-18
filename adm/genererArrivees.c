#include "Header.h"


int genererArrivees(int a, int c, int m, int xn, Client* pDebutFile) {
	double paramPrior = 0.7;
	double paramOrdi = 2;

	int nbArriveesPrioritaire = arriveePrioritaire(paramPrior, a, c, m, &xn);

	int nbArriveesOrdinaire = arriveePrioritaire(paramOrdi, a, c, m, &xn);

	int iP = 0, iO = 0, nbArriveesAbsolue = 0, nbArriveesRelatif = 0;

	if (nbArriveesPrioritaire != 0) {
		while (iP < nbArriveesPrioritaire) {
			// ressortir nbr aleatoire pour definir si prior absolue (30%) ou relatif
			xn = nombreAléatoire(m, a, c, xn);
			char statut;
			double U1 = xn / m;
			if (U1 < 0.3) {
				statut = 'A';
				nbArriveesAbsolue++;
			}
			else {
				statut = 'R';
				nbArriveesRelatif++;
			}

			

			iP++;
		}
	}

	if (nbArriveesOrdinaire != 0) {
		char statut = 'O';
		while (iO < nbArriveesOrdinaire) {
			ajouterClientFile(statut, &pDebutFile);
			iO++;
		}
	}

	printf("<------------------------Affichage du nombre d'arrivées ----------------------->");
	printf("Nombre d'arrivées prioritaire absolue : %d", nbArriveesAbsolue);
	printf("Nombre d'arrivées prioritaire relative : %d", nbArriveesRelatif);
	printf("Nombre d'arrivées ordinaire : %d", nbArriveesOrdinaire);

	return xn;
}
