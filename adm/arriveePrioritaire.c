#include "Header.h"


int arriveePrioritaire(double paramPrior, unsigned long int a, unsigned long int c, unsigned long int m, unsigned long int* xn) {
	
	unsigned long int xTemps = *xn;

	unsigned long int temp = nombreAleatoire(a, c, m, xTemps);

	*xn = temp;
	double U1 = 0;
	U1 = ((double)(temp) / (double)m);
	
	int nbArrivéesP= 0;

	double p0 = loiPoisson(paramPrior, 0);
	double p1 = loiPoisson(paramPrior, 1);
	double p2 = loiPoisson(paramPrior, 2);
	double p3 = loiPoisson(paramPrior, 3);

	double pTotal = p0;
	//printf("xn = %d -- un = %.5lf -- m = %d -- p0 = %.4lf -- p1 = %.4lf \n", temp, U1, m, p0,p1);
	if (U1 < pTotal)
	{
		nbArrivéesP = 0;
	}
	else
	{
		pTotal += p1;
		
		if (U1 < pTotal)
		{
			nbArrivéesP = 1;
		}
		else 
		{
			pTotal += p2;
			
			if (U1 < pTotal) 
			{
				nbArrivéesP = 2;
			}
			else
			{
				pTotal += p3;
				
				if (U1 < pTotal)
				{
					nbArrivéesP = 3;
				}
				else
				{
					nbArrivéesP = 4;
				}
			}
		}
	}
	return nbArrivéesP;
}