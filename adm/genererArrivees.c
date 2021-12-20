#include "Header.h"


int genererArrivees(int a, int c, int m, int xn, Client** pDebutFile) {
	double paramPrior = 0.7;
	double paramOrdi = 2;

	int nbArriveesPrioritaire = arriveePrioritaire(paramPrior, a, c, m, &xn);

	int nbArriveesOrdinaire = arriveeOrdinaire(paramOrdi, a, c, m, &xn);

	int iP = 0, iO = 0, nbArriveesAbsolue = 0, nbArriveesRelatif = 0;

	if (nbArriveesPrioritaire != 0) {
		while (iP < nbArriveesPrioritaire) {
			// ressortir nbr aleatoire pour definir si prior absolue (30%) ou relatif
			xn = nombreAleatoire(m, a, c, xn);
			char statut;
			double U1 =  ((double)xn / (double)m);
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
			*pDebutFile = ajouterClientFile(statut, pDebutFile);
			iO++;
		}
	}
	if(nbArriveesAbsolue != 0) {
		char statut = 'A';
		int i = 0;
		while (i < nbArriveesAbsolue) {
			*pDebutFile = ajouterClientFile(statut, pDebutFile);
			i++;
		}
	}

	if (nbArriveesRelatif != 0) {
		char statut = 'R';
		int i = 0;
		while (i < nbArriveesRelatif) {
			*pDebutFile = ajouterClientFile(statut, pDebutFile);
			i++;
		}
	}


	printf("<------------------------Affichage du nombre d'arrivees ----------------------->\n");
	printf("Nombre d'arrivees prioritaire absolue : %d\n", nbArriveesAbsolue);
	printf("Nombre d'arrivees prioritaire relative : %d\n", nbArriveesRelatif);
	printf("Nombre d'arrivees ordinaire : %d\n", nbArriveesOrdinaire);

	return xn;
}
