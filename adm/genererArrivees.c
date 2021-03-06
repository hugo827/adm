#include "Header.h"


int genererArrivees(unsigned long int a, unsigned long int c, unsigned long int m, unsigned long int xn, Client** pDebutFile, double paramPrior, double paramOrdi, bool affiche) {


	int nbArriveesPrioritaire = arriveePrioritaire(paramPrior, a, c, m, &xn);

	int nbArriveesOrdinaire = arriveeOrdinaire(paramOrdi, a, c, m, &xn);

	int iP = 0, iO = 0, nbArriveesAbsolue = 0, nbArriveesRelatif = 0;

	if (nbArriveesPrioritaire != 0) {
		while (iP < nbArriveesPrioritaire) {
			// ressortir nbr aleatoire pour definir si prior absolue (30%) ou relatif
			unsigned long int xnTemp = nombreAleatoire(m, a, c, xn);
			xn = xnTemp;
			char statut;
			double U1 =  (double)((double)xn / (double)m);
			
			if (U1 < 0.8) {
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

	if (affiche) {
		printf("<------------------------Affichage du nombre d'arrivees ----------------------->\n");
		printf("Nombre d'arrivees prioritaire absolue : %d\n", nbArriveesAbsolue);
		printf("Nombre d'arrivees prioritaire relative : %d\n", nbArriveesRelatif);
		printf("Nombre d'arrivees ordinaire : %d\n", nbArriveesOrdinaire);
	}

	return xn;
}
