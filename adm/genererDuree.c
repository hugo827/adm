#include "Header.h"


int genererDuree(unsigned long int* xn, unsigned long int a, unsigned long int c, unsigned long int m) {
	int duree;
	unsigned long int xTemp;
	xTemp = nombreAleatoire(m, a, c, *xn);

	double u1 = ((double)(xTemp) /(double)m);
	
	*xn = xTemp;

	if (u1 < 0.38) //r=24
	{
		duree = 1;
	}
	else {
		if (u1 < 0.67) {
			duree = 2;
		} //r=18
		else {
			if (u1 < 0.85) {
				duree = 3;
			} //r=11
			else {
				if (u1 < 0.92) {
					duree = 4;
				}
				else {
					if (u1 < 0.97) {
						duree = 5;
					}
					else {
						duree = 6;
					}
				}
			}
		}
	}

	return duree;
}
