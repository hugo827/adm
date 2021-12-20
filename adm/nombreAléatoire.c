#include "Header.h"


int nombreAleatoire(int m, int a, int c, int xn) {
	xn = (((a * xn) + c) % m);
	printf("\nXN -> %d\n", xn);
	return xn;
}