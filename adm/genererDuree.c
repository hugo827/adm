#include "Header.h"


int genererDuree(int* xn, int a,int c, int m) {
	int durée;

	(*xn) = nombreAléatoire(m, a, c, *xn);

	double u1 = (*xn) / m;
	

	if (u1 < 0.38) //r=24
		durée = 1;
	else {
		if (u1 < 0.67) durée = 2; //r=18
		else {
			if (u1 < 0.85) durée = 3; //r=11
			else {
				if (u1 < 0.92) durée = 4;
				else {
					if (u1 < 0.97) durée = 5;
					else durée = 6;
				}
			}
		}
	}

	return durée;	
}